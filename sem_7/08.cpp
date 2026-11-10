#include <gd.h>

int main() {
    gdImagePtr im = gdImageCreateTrueColor(600, 400);

    int white = gdImageColorAllocate(im, 255, 255, 255);
    int red = gdImageColorAllocate(im, 190, 0, 41);

    gdImageFilledRectangle(im, 0, 0, 599, 399, white);
    gdImageFilledEllipse(im, 300, 200, 240, 240, red);

    FILE* f = fopen("flag.png", "wb");
    gdImagePng(im, f);
    fclose(f);
    gdImageDestroy(im);
}