#include <stdio.h>
#include <graphics.h>
#include <math.h>

void drawLineDDA(int X0, int Y0, int X1, int Y1) {
    int dx = X1 - X0;
    int dy = Y1 - Y0;
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
    float Xinc = dx / (float) steps;
    float Yinc = dy / (float) steps;
    float X = X0;
    float Y = Y0;
    for (int i = 0; i <= steps; i++) {
        putpixel(round(X), round(Y), WHITE);
        X += Xinc;
        Y += Yinc;
        delay(100); 
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    int X0, Y0, X1, Y1;
    
    printf("Enter endpoint A coordinates (X0, Y0): ");
    scanf("%d %d", &X0, &Y0);
    printf("Enter endpoint B coordinates (X1, Y1): ");
    scanf("%d %d", &X1, &Y1);
    
    drawLineDDA(X0, Y0, X1, Y1);
    
    delay(5000);
    closegraph();
    return 0;
}
