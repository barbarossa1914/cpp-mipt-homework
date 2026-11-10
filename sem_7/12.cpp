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
    if (inputfile == 0)
    {
        printf("Can't open the file: %s\n", filename);
        exit(1);
    }
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

void swap_red_blue(Color* data, int width, int height)
{
    for (int j = 0; j < height; j++)
    {
        for (int i = 0; i < width; i++)
        {
            unsigned char temp = data[i + width * j].r;
            data[i + width * j].r = data[i + width * j].b;
            data[i + width * j].b = temp;
        }
    }
}

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        printf("Error!\n");
        printf("To use this program: ./swap <ppm image>\n");
        exit(1);
    }
    
    int width, height;
    Color* data = load_image(argv[1], &width, &height);

    swap_red_blue(data, width, height);
    save_image("result.ppm", data, width, height);
    
    free(data);
    return 0;
}