

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Vector {
	int x_axis;
	int y_axis;
	int z_axis;

	struct Vector(*vector_sum)(struct Vector* self, struct Vector* other);

	double (*vector_length)(struct Vector* self);
	double (*vector_scalar)(struct Vector* self, struct Vector* other);
} Vector;


static double vector_length(Vector* self) {
	return sqrt(pow(self->x_axis, 2) + pow(self->y_axis, 2) + pow(self->z_axis, 2));
}

static double vector_scalar(Vector* self, Vector* other) {
	return self->x_axis * other->x_axis + self->y_axis * other->y_axis + self->z_axis * other->z_axis;
}


Vector vector_sum(Vector* self, Vector* other) {
	Vector result;
	result.x_axis = self->x_axis + other->x_axis;
	result.y_axis = self->y_axis + other->y_axis;
	result.z_axis = self->z_axis + other->z_axis;

	// Przypisz wskaźniki funkcji do nowego wektora
	result.vector_length = self->vector_length;
	result.vector_sum = self->vector_sum;

	return result;
}



int main() {
	//objects initiation.
	Vector vector1 = { 1, 5, 0, NULL, NULL };
	Vector vector2 = { 8, -5, 10, NULL, NULL };



	//assign objects to method (lenght).
	vector1.vector_length = vector_length;
	vector2.vector_length = vector_length;

	printf("Vector1 length = %f\n", vector1.vector_length(&vector1));
	printf("Vector2 length = %f\n", vector2.vector_length(&vector2));



	//assign objects 
	vector2.vector_sum = vector_sum;
	vector1.vector_sum = vector_sum;

	Vector sum = vector1.vector_sum(&vector1, &vector2);

	printf("Sum vector: (%d, %d, %d)\n", sum.x_axis, sum.y_axis, sum.z_axis);
	printf("Sum vector length = %f\n", sum.vector_length(&sum));



	//assing objects to method (scalar).
	vector1.vector_scalar = vector_scalar;
	vector2.vector_scalar = vector_scalar;

	double scalar = vector1.vector_scalar(&vector1, &vector2);

	printf("Vector scalar = %f\n\n", scalar);


	return 0;
}

