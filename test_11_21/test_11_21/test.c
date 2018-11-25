#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//int main()
//{
//	int a = 10000;
//	FILE* pf = fopen("test.txt", "rb");
//	fwrite(&a, 4, 1, pf);
//	fclose(pf);
//	pf=NULL;
//	return 0;
//}
#include<stdio.h>
#include<errno.h>
#include<string.h>
#include<stdlib.h>
struct Stu
{
	char name[20];
	int age;
}s;
int main()
{
	FILE* pf = fopen("test.txt", "w");
	if (pf == NULL)
	{
		printf("%s\n", strerror(errno));
		return 0;
	}
	//д
	fprintf(pf, "%s %d", s.name, s.age);
	fclose(pf);
	pf = NULL;
	return 0;
}