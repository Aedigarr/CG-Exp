#include <stdio.h>
#include <graphics.h>
#include <math.h>


void rotate(int *x, int *y, float angle) {
    float rad = angle * (M_PI / 180.0); 
    int x_new = round((*x) * cos(rad) - (*y) * sin(rad)); 
    int y_new = round((*x) * sin(rad) + (*y) * cos(rad)); 
    *x = x_new;
    *y = y_new;
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");


    int x1, y1, x2, y2;
    printf("Enter the coordinates of the starting point of the line (x y): ");
    scanf("%d %d", &x1, &y1);
    printf("Enter the coordinates of the ending point of the line (x y): ");
    scanf("%d %d", &x2, &y2);


    line(x1, y1, x2, y2);


    float angle;
    printf("Enter the angle of rotation in degrees: ");
    scanf("%f", &angle);


    rotate(&x1, &y1, angle);
    rotate(&x2, &y2, angle);


    line(x1, y1, x2, y2);

    delay(5000);
    closegraph();
    return 0;
}
