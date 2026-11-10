#include <stdio.h>
#include <stdlib.h>

struct color
{
    unsigned char r, g, b;
};
typedef struct color Color;

Color* load_image(char* filename, int* pwidth, int* pheight)
{
    FILE* inputfile = fopen(filename, "rb");
    fscanf(inputfile, "P6\n%d %d\n255\n", pwidth, pheight);
    Color* data = (Color*)malloc(sizeof(Color) * (*pwidth) * (*pheight));
    fread(data, sizeof(Color), (*pwidth) * (*pheight), inputfile);
    fclose(inputfile);
    return data;
}

void save_image(char* filename, Color* data, int width, int height)
{
    FILE* outputfile = fopen(filename, "wb");
    fprintf(outputfile, "P6\n%d %d\n255\n", width, height);
    fwrite(data, sizeof(Color), height * width, outputfile);
    fclose(outputfile);
}

void to_grayscale(Color* data, int width, int height)
{
    for (int j = 0; j < height; j++)
    {
        for (int i = 0; i < width; i++)
        {
            int gray = (int)(0.299 * data[i + width * j].r + 
                             0.587 * data[i + width * j].g + 
                             0.114 * data[i + width * j].b);
            data[i + width * j].r = gray;
            data[i + width * j].g = gray;
            data[i + width * j].b = gray;
        }
    }
}

int main(int argc, char** argv)
{
    int width, height;
    Color* data = load_image(argv[1], &width, &height);

    to_grayscale(data, width, height);
    save_image("result.ppm", data, width, height);
    
    free(data);
    return 0;
}
