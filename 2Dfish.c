#include <graphics.h>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");


    ellipse(200, 200, 0, 360, 50, 100);


    line(150, 200, 100, 250);
    line(150, 200, 100, 150);


    circle(230, 180, 5);

    delay(5000);
    closegraph();
    return 0;
}
