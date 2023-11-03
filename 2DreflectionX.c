#include <stdio.h>
#include <graphics.h>


void reflectX(int *y) {
    *y = -*y; 
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "";


    int x1 = 100, y1 = 100;
    int x2 = 200, y2 = 200;


    line(x1, y1, x2, y2);


    reflectX(&y1);
    reflectX(&y2);


    line(x1, y1, x2, y2);

    delay(5000);
    closegraph();
    return 0;
}
