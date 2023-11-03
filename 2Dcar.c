#include <graphics.h>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");


    rectangle(100, 300, 400, 400);


    line(100, 300, 250, 200);
    line(250, 200, 400, 300);


    circle(150, 400, 30);
    circle(350, 400, 30);

    delay(5000);
    closegraph();
    return 0;
}
