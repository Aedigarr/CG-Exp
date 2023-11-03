#include <stdio.h>
#include <graphics.h>


void boundaryfill4(int x, int y, int fill_color, int boundary_color) {
    if ((getpixel(x, y) != boundary_color) && (getpixel(x, y) != fill_color)) {
        delay(1);
        putpixel(x, y, fill_color);
        boundaryfill4(x + 1, y, fill_color, boundary_color);
        boundaryfill4(x - 1, y, fill_color, boundary_color);
        boundaryfill4(x, y + 1, fill_color, boundary_color);
        boundaryfill4(x, y - 1, fill_color, boundary_color);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");


    int points[] = {100, 100, 200, 50, 300, 100, 250, 200, 150, 200, 100, 100};
    drawpoly(6, points);
    int fill_color = 10; 
    int x = 200, y = 150; 
    int boundary_color = 15; 

    boundaryfill4(x, y, fill_color, boundary_color);

    delay(5000);
    closegraph();
    return 0;
}
