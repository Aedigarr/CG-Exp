#include <stdio.h>
#include <graphics.h>


void floodfill8(int x, int y, int fill_color, int old_color) {
    if (getpixel(x, y) == old_color) {
        delay(1);
        putpixel(x, y, fill_color);
        floodfill8(x + 1, y, fill_color, old_color);
        floodfill8(x - 1, y, fill_color, old_color);
        floodfill8(x, y + 1, fill_color, old_color);
        floodfill8(x, y - 1, fill_color, old_color);
        floodfill8(x + 1, y + 1, fill_color, old_color);
        floodfill8(x - 1, y - 1, fill_color, old_color);
        floodfill8(x - 1, y + 1, fill_color, old_color);
        floodfill8(x + 1, y - 1, fill_color, old_color);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");


    int points[] = {100, 100, 200, 50, 300, 100, 250, 200, 150, 200, 100, 100};
    drawpoly(6, points);
    int fill_color = 10; 
    int x = 200, y = 150; 
    int old_color = 0; 

    floodfill8(x, y, fill_color, old_color);

    delay(5000);
    closegraph();
    return 0;
}
