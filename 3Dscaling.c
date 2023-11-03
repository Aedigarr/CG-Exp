#include <stdio.h>
#include <graphics.h>


void scale3D(float points[][3], int num_points, float sx, float sy, float sz) {
    for (int i = 0; i < num_points; i++) {
        points[i][0] *= sx; 
        points[i][1] *= sy; 
        points[i][2] *= sz; 
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");


    float points[4][3];
    printf("Enter the coordinates of the 3D object points (x y z) -\n");
    for (int i = 0; i < 4; i++) {
        printf("Point %d: ", i + 1);
        scanf("%f %f %f", &points[i][0], &points[i][1], &points[i][2]);
    }


    float sx, sy, sz;
    printf("Enter the scaling factor in x-direction: ");
    scanf("%f", &sx);
    printf("Enter the scaling factor in y-direction: ");
    scanf("%f", &sy);
    printf("Enter the scaling factor in z-direction: ");
    scanf("%f", &sz);


    scale3D(points, 4, sx, sy, sz);


    printf("\nScaled 3D object points -\n");
    for (int i = 0; i < 4; i++) {
        printf("Point %d: %.2f %.2f %.2f\n", i + 1, points[i][0], points[i][1], points[i][2]);
    }

    delay(5000);
    closegraph();
    return 0;
}
