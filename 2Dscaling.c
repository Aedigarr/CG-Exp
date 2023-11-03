#include <stdio.h>
#include <graphics.h>


void scale(int points[][2], int num_points, float sx, float sy) {
    for (int i = 0; i < num_points; i++) {
        points[i][0] = points[i][0] * sx; 
        points[i][1] = points[i][1] * sy; 
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");


    int triangle[3][2];
    printf("Enter the coordinates of the first point of the triangle (x y): ");
    scanf("%d %d", &triangle[0][0], &triangle[0][1]);
    printf("Enter the coordinates of the second point of the triangle (x y): ");
    scanf("%d %d", &triangle[1][0], &triangle[1][1]);
    printf("Enter the coordinates of the third point of the triangle (x y): ");
    scanf("%d %d", &triangle[2][0], &triangle[2][1]);


    drawpoly(3, (int *)triangle);


    float sx, sy;
    printf("Enter the scaling factor in x-direction: ");
    scanf("%f", &sx);
    printf("Enter the scaling factor in y-direction: ");
    scanf("%f", &sy);


    scale(triangle, 3, sx, sy);


    drawpoly(3, (int *)triangle);

    delay(5000);
    closegraph();
    return 0;
}
