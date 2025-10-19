
#include <string.h> 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Defining macros.
#define PI 3.14159265358979323846

struct Vector {
	int x_axis;
	int y_axis; 
	int z_axis;
};

int main() {

	struct Vector vector1 { 5, 5, 7 };

	//Calculing vector_length.
	double vector_magnitude = sqrt(pow(vector1.x_axis, 2) + pow(vector1.y_axis, 2) + pow(vector1.z_axis, 2));
	printf("vector value = %f, \n", vector_magnitude);


	//Calculing direction (yaw).
	double yaw = atan2(vector1.x_axis, vector1.y_axis);
	double angle_xy = yaw * (180 / PI); 		//Representation of yaw in degrees.
	printf("direction of XY (yaw) = %.2f degrees\n ", angle_xy);


	//Caculing inlination (pitch) relative to XY vector (yaw).
	double horizontal_magnitude = sqrt(pow(vector1.x_axis, 2) + pow(vector1.y_axis, 2));
	double pitch = atan2(vector1.z_axis, horizontal_magnitude);
	double inclination = pitch * (180 / PI);	//Representation of pitch in degrees.
	printf("angle of inclination = %f, \n", inclination);
}


