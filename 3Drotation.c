#include <stdio.h>
#include <graphics.h>
#include <math.h>


void rotate3D(float points[][3], int num_points, float angle_x, float angle_y, float angle_z) {
    float cos_x = cos(angle_x);
    float sin_x = sin(angle_x);
    float cos_y = cos(angle_y);
    float sin_y = sin(angle_y);
    float cos_z = cos(angle_z);
    float sin_z = sin(angle_z);

    for (int i = 0; i < num_points; i++) {
        float x = points[i][0];
        float y = points[i][1];
        float z = points[i][2];


        float new_y = y * cos_x - z * sin_x;
        float new_z = y * sin_x + z * cos_x;
        y = new_y;
        z = new_z;


        float new_x = x * cos_y + z * sin_y;
        new_z = -x * sin_y + z * cos_y;
        x = new_x;
        z = new_z;


        new_x = x * cos_z - y * sin_z;
        new_y = x * sin_z + y * cos_z;
        points[i][0] = new_x;
        points[i][1] = new_y;
        points[i][2] = z;
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // 3D object points from user input
    float points[4][3];
    printf("Enter the coordinates of the 3D object points (x y z) -\n");
    for (int i = 0; i < 4; i++) {
        printf("Point %d: ", i + 1);
        scanf("%f %f %f", &points[i][0], &points[i][1], &points[i][2]);
    }

    // Rotation angles from user input
    float angle_x, angle_y, angle_z;
    printf("Enter the rotation angle around x-axis in radians: ");
    scanf("%f", &angle_x);
    printf("Enter the rotation angle around y-axis in radians: ");
    scanf("%f", &angle_y);
    printf("Enter the rotation angle around z-axis in radians: ");
    scanf("%f", &angle_z);

    // Perform rotation
    rotate3D(points, 4, angle_x, angle_y, angle_z);

    // Display the rotated 3D object
    printf("\nRotated 3D object points -\n");
    for (int i = 0; i < 4; i++) {
        printf("Point %d: %.2f %.2f %.2f\n", i + 1, points[i][0], points[i][1], points[i][2]);
    }

    delay(5000);
    closegraph();
    return 0;
}
