#include <gd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char* argv[]) {
    int n = atoi(argv[1]), a = atoi(argv[2]), b = atoi(argv[3]);
    int width = 600, height = 400;

    gdImagePtr im = gdImageCreateTrueColor(width, height);
    int white = gdImageColorAllocate(im, 255, 255, 255);
    gdImageFilledRectangle(im, 0, 0, width - 1, height - 1, white);

    srand(time(NULL));

    for (int i = 0; i < n; i++) {
        int color = gdImageColorAllocate(im, rand() % 256, rand() % 256, rand() % 256);
        int x = rand() % width, y = rand() % height;
        int r = a + rand() % (b - a + 1);
        gdImageFilledEllipse(im, x, y, r * 2, r * 2, color);
    }

    FILE* f = fopen("circles.png", "wb");
    gdImagePng(im, f);
    fclose(f);
    gdImageDestroy(im);
}