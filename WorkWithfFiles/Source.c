#include "Header.h"

int main() {
	setlocale(LC_ALL, "Rus");
	FILE* abc;
	PROCESS_INFORMATION processInfo = {0};
	STARTUPINFO startUp = { 0 };

	ZeroMemory(&startUp, sizeof(startUp));
	startUp.cb = sizeof(startUp);
	ZeroMemory(&processInfo, sizeof(processInfo));

	char abcRoot[] = "abc.txt";
	float a, b, c;
	if ((abc = fopen(abcRoot, "r")) == NULL)
	{
		printf("Не удалось открыть файл");
		getchar();
		return 0;
	}
	else
	{
		char i = 0;
		printf("Считывание из файла abc.txt\n");
		while ((fscanf(abc, "%f;%f;%f", &a, &b, &c)) != EOF)
		{

			printf("a = %f\nb = %f\nc = %f", a, b, c);
			i++;
		}
	}
	char* text = malloc(100);
	snprintf(text, 50, "%f%c%f%c%f%c%s%c", a, ';', b, ';', c, ';', "roots.txt",';');
	BOOL bo = CreateProcessA("..\\x64\\Debug\\QuadraticEquation.exe", text, NULL, NULL, FALSE, NULL, NULL, NULL, &startUp, &processInfo);
	WaitForSingleObject(processInfo.hProcess, INFINITE);
}
