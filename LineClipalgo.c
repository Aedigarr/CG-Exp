#include <graphics.h>
#include <stdio.h>

#define true 1
#define false 0

float xmin, ymin, xmax, ymax;

int cliptest(float p, float q, float *t1, float *t2) {
    float t;
    int result = true;
    if (p < 0.0) {
        t = q / p;
        if (t > *t2) result = false;
        else if (t > *t1) *t1 = t;
    } else if (p > 0.0) {
        t = q / p;
        if (t < *t1) result = false;
        else if (t < *t2) *t2 = t;
    } else if (q < 0.0) result = false;
    return result;
}

void liangBarsky(float x0, float y0, float x1, float y1) {
    float dx = x1 - x0, dy = y1 - y0, t0 = 0, t1 = 1;
    if (cliptest(-dx, x0 - xmin, &t0, &t1) && cliptest(dx, xmax - x0, &t0, &t1) && cliptest(-dy, y0 - ymin, &t0, &t1) && cliptest(dy, ymax - y0, &t0, &t1)) {
        if (t1 < 1) {
            x1 = x0 + t1 * dx;
            y1 = y0 + t1 * dy;
        }
        if (t0 > 0) {
            x0 = x0 + t0 * dx;
            y0 = y0 + t0 * dy;
        }
        setcolor(RED);
        line(x0, y0, x1, y1);
    } else {
        printf("Line lies outside the clipping window.\n");
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    xmin = 100, ymin = 100, xmax = 300, ymax = 300; 
    rectangle(xmin, ymin, xmax, ymax); 

    float x0, y0, x1, y1;
    printf("Enter the coordinates of the starting point of the line (x0 y0): ");
    scanf("%f %f", &x0, &y0);
    printf("Enter the coordinates of the ending point of the line (x1 y1): ");
    scanf("%f %f", &x1, &y1);
    printf("Original Line Coordinates: (%f,%f) to (%f,%f)\n", x0, y0, x1, y1);
    setcolor(WHITE);
    line(x0, y0, x1, y1); 
    liangBarsky(x0, y0, x1, y1);

    delay(5000);
    closegraph();
    return 0;
}
