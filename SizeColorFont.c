#include <graphics.h>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
    outtextxy(100, 100, "This is the default font style with size 2");

    settextstyle(DEFAULT_FONT, HORIZ_DIR, 4);
    outtextxy(100, 200, "This is the default font style with size 4");

    setcolor(RED);
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 3);
    outtextxy(100, 300, "This is red text with size 3");

    setcolor(BLUE);
    settextstyle(GOTHIC_FONT, HORIZ_DIR, 3);
    outtextxy(100, 400, "This is blue Gothic font with size 3");

    delay(5000);
    closegraph();
    return 0;
}
