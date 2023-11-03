#include <graphics.h>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");


    line(100, 400, 300, 400); 
    line(100, 400, 100, 200); 
    line(300, 400, 300, 200); 
    line(100, 200, 300, 200); 


    line(100, 200, 200, 100);
    line(200, 100, 300, 200);


    rectangle(160, 400, 240, 300);


    rectangle(120, 250, 180, 300);
    line(150, 250, 150, 300);
    line(120, 275, 180, 275);

    delay(5000);
    closegraph();
    return 0;
}
