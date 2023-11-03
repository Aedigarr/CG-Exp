#include <stdio.h>
#include <conio.h>
#include <graphics.h>


void translate3D(int points[][3], int num_points, int tx, int ty, int tz) {
    for (int i = 0; i < num_points; i++) {
        points[i][0] += tx; 
        points[i][1] += ty; 
        points[i][2] += tz; 
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    
    int points[4][3];
    printf("Enter the coordinates of the 3D object points (x y z) -\n");
    for (int i = 0; i < 4; i++) {
        printf("Point %d: ", i + 1);
        scanf("%d %d %d", &points[i][0], &points[i][1], &points[i][2]);
    }


    int tx, ty, tz;
    printf("Enter the translation factor in x-direction: ");
    scanf("%d", &tx);
    printf("Enter the translation factor in y-direction: ");
    scanf("%d", &ty);
    printf("Enter the translation factor in z-direction: ");
    scanf("%d", &tz);


    translate3D(points, 4, tx, ty, tz);


    printf("\nTranslated 3D object points -\n");
    for (int i = 0; i < 4; i++) {
        printf("Point %d: %d %d %d\n", i + 1, points[i][0], points[i][1], points[i][2]);
    }

    delay(5000);
    closegraph();
    return 0;
}
