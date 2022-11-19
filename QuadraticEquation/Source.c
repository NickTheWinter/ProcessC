#include "Header.h"
int main(int argc, char* argv[])
{
	FILE* file;
	char* temp = strtok(argv[0], ";");
	char* ca = temp;

	temp = strtok(NULL, ";");
	char* cb = temp;
	temp = strtok(NULL, ";");
	char* cc = temp;
	temp = strtok(NULL, ";");

	file = fopen(temp, "w+t");
	float a, b, c;
	a = atof(ca);
	b = atof(cb);
	c = atof(cc);

	QuadraticEquation(a, b, c, file);

}
void QuadraticEquation(float a, float b, float c, FILE* file)
{
	float x1, x2, discriminant;
	discriminant = powf(b, 2.0) - 4 * a * c;

	if (discriminant < 0)
	{
		fprintf(file, "��� �������\n");
	}
	if (discriminant == 0)
	{
		x1 = (-b) / (2 * a);
		fprintf(file, "������������ ����� %f\n", discriminant);
		fprintf(file, "x1 = %f", x1);
	}
	if (discriminant > 0)
	{
		x1 = ((-b) - sqrt(discriminant)) / (2 * a);
		x2 = ((-b) + sqrt(discriminant)) / (2 * a);

		fprintf(file, "������������ ����� %f\n", discriminant);
		fprintf(file, "x1 = %f, x2 = %f", x1, x2);
	}
}