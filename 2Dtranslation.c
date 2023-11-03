#include <stdio.h>
#include <graphics.h>


void translate(int points[][2], int num_points, int tx, int ty) {
    for (int i = 0; i < num_points; i++) {
        points[i][0] += tx; 
        points[i][1] += ty; 
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


    int tx, ty;
    printf("Enter the translation factor in x-direction: ");
    scanf("%d", &tx);
    printf("Enter the translation factor in y-direction: ");
    scanf("%d", &ty);


    translate(triangle, 3, tx, ty);


    drawpoly(3, (int *)triangle);

    delay(5000);
    closegraph();
    return 0;
}
