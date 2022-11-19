#include "Header.h"

int main() {
	setlocale(LC_ALL, "Rus");
	FILE* abc;
	PROCESS_INFORMATION processInfo = { 0 };
	STARTUPINFO startUp = { 0 };

	ZeroMemory(&startUp, sizeof(startUp));
	startUp.cb = sizeof(startUp);
	ZeroMemory(&processInfo, sizeof(processInfo));

	char abcRoot[] = "abc.txt";
	float a, b, c;
	if ((abc = fopen(abcRoot, "r")) == NULL)
	{
		getchar();
		return 0;
	}
	else
	{
		char i = 0;
		while ((fscanf(abc, "%f;%f;%f", &a, &b, &c)) != EOF)
		{
			i++;
		}
	}
	char* text = malloc(100);
	snprintf(text, 50, "%f%c%f%c%f%c%s%c", a, ';', b, ';', c, ';', "roots.txt", ';');
	BOOL bo = CreateProcessA("..\\x64\\Debug\\QuadraticEquation.exe", text, NULL, NULL, FALSE, NULL, NULL, NULL, &startUp, &processInfo);
	WaitForSingleObject(processInfo.hProcess, INFINITE);
	HANDLE roots;
	if ((roots = fopen("roots.txt", "r")) != NULL)
	{
		char text[256];
		while ((fgets(text, 256, roots)) != NULL)
		{
			printf("%s", text);
		}
	}
}
