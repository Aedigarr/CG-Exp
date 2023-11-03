#include <graphics.h>

void drawLineBresenham(int x0, int y0, int x1, int y1) {
    int dx, dy, p, x, y;
    dx = x1 - x0;
    dy = y1 - y0;
    x = x0;
    y = y0;
    p = 2 * dy - dx;
    while (x < x1) {
        if (p >= 0) {
            putpixel(x, y, WHITE);
            y = y + 1;
            p = p + 2 * dy - 2 * dx;
        } else {
            putpixel(x, y, WHITE);
            p = p + 2 * dy;
        }
        x = x + 1;
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int x0, y0, x1, y1;
    printf("Enter the coordinates of the starting point (x0 y0): ");
    scanf("%d %d", &x0, &y0);

    printf("Enter the coordinates of the ending point (x1 y1): ");
    scanf("%d %d", &x1, &y1);

    drawLineBresenham(x0, y0, x1, y1);
    delay(5000);
    closegraph();
    return 0;
}
