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

unsigned char clamp(double val)
{
    if (val > 255.0) return 255;
    if (val < 0.0) return 0;
    return (unsigned char)val;
}

void apply_sepia(Color* data, int width, int height)
{
    for (int j = 0; j < height; j++)
    {
        for (int i = 0; i < width; i++)
        {
            double r = data[i + width * j].r;
            double g = data[i + width * j].g;
            double b = data[i + width * j].b;
            
            double new_r = 0.393 * r + 0.769 * g + 0.189 * b;
            double new_g = 0.349 * r + 0.686 * g + 0.168 * b;
            double new_b = 0.272 * r + 0.534 * g + 0.131 * b;
            
            data[i + width * j].r = clamp(new_r);
            data[i + width * j].g = clamp(new_g);
            data[i + width * j].b = clamp(new_b);
        }
    }
}

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        printf("Error!\n");
        printf("To use this program: ./sepia <ppm image>\n");
        exit(1);
    }
    
    int width, height;
    Color* data = load_image(argv[1], &width, &height);

    apply_sepia(data, width, height);
    save_image("result.ppm", data, width, height);
    
    free(data);
    return 0;
}