#include <graphics.h>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");


    circle(100, 100, 20);


    line(100, 120, 100, 180);


    line(100, 140, 80, 120);
    line(100, 140, 120, 120);


    line(100, 180, 80, 220);
    line(100, 180, 120, 220);

    delay(5000);
    closegraph();
    return 0;
}
