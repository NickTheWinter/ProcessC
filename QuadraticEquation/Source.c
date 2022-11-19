#include "Header.h"
int main(int argc, char* argv[])
{
	char* ca, cb, cc;
	FILE* file;
	char* temp = strtok(argv[0], ";");
	ca = temp;
	temp = strtok(NULL, ";");
	cb = temp;
	temp = strtok(NULL, ";");
	cc = temp;
	temp = strtok(NULL, ";");
	if (file = fopen(temp, "w") != NULL)
	{

		float a, b, c;
		a = atof(ca);
		b = atof(cb);
		c = atof(cc);
		QuadraticEquation(a, b, c, file);
	}
}
void QuadraticEquation(float a, float b, float c, FILE* file)
{
	float x1, x2, discriminant;
	discriminant = powf(b, 2.0) - 4 * a * c;
	if (discriminant < 0)
	{
		fprintf(file, "Нет решений\n");
	}
	if (discriminant == 0)
	{
		x1 = (-b) / (2 * a);
		fprintf(file, "Дискриминант равен %f\n", discriminant);
		fprintf(file, "x1 = %f", x1);
	}
	if (discriminant > 0)
	{
		x1 = ((-b) - sqrt(discriminant)) / (2 * a);
		x2 = ((-b) + sqrt(discriminant)) / (2 * a);
		fprintf(file, "Дискриминант равен %f\n", discriminant);
		fprintf(file, "x1 = %f, x2 = %f", x1, x2);
	}
}