#define _CRT_SECURE_NO_WARNINGS 1
//1.ʵ��һ�����������������ַ����е�k���ַ���
//ABCD����һ���ַ��õ�BCDA
//ABCD���������ַ��õ�CDAB
//˼·������һ�Σ�������ַ���ǰŲ��һ��λ�ã���һ���ַ��ŵ�ĩβ
//#include<stdio.h>
//void left_rotate(char* str, int k)
//{
//	//k�ֲ���
//	while (k--)
//	{
//		//��ʱ�����һ��λ�õ�����
//		char temp = *str;
//		//һ�ֲ���������һ��
//		char *cur = str;
//		//�����һ���ַ�Ϊ��Ч�ַ�
//		while (*(cur + 1) != '\0')
//		{
//			//��һ��λ�õ�������ǰŲ��һ��
//			*cur = *(cur + 1);
//			cur++;
//		}
//		//��һ��λ�õ����ݷ���ĩβ
//		*cur = temp;
//	}
//}
//int main()
//{
//	char arr[100];
//	int k = 0;
//	scanf("%s", arr);
//	scanf("%d", &k);
//	left_rotate(arr, k);
//	printf("%s\n", arr);
//	return 0;
//}
//����k�Σ�
//��һ�Σ���תǰk��Ԫ��
//�ڶ��Σ���תʣ��Ԫ��
//�����Σ��ַ���������ת
//#include<stdio.h>
//#include<string.h>
//void* reverse(char* start, char* end)
//{
//	while (start < end)
//	{
//		char temp = *start;
//		*start = *end;
//		*end = temp;
//		start++;
//		end--;
//	}
//}
//void left_rotate(char* str, int k)
//{
	//k = k%strlen(str);
	////��һ�Σ���ת1~k
	//reverse(str, str + k - 1);
	////�ڶ��Σ���תʣ��Ԫ��
	//reverse(str + k, str + strlen(str) - 1);
	////������ת
	//reverse(str, str + strlen(str) - 1);

//}
//int main()
//{
//	char arr[100];
//	int k = 0;
//	scanf("%s", arr);
//	scanf("%d", &k);
//	left_rotate(arr, k);
//	printf("%s\n", arr);
//	return 0;
//}
//#include<stdio.h>
//#include<string.h>
//int is_rotate(char* dest, char* rotate)
//{
//	if (strlen(dest) != strlen(rotate))
//	{
//		return 0;
//	}
//	int len = strlen(rotate);
//	while (len--)
//	{
//		//������תһ��
//		right_rotate(rotate, 1);
//		//�Ƚ���ת֮��������Ƿ����Ҫ��
//		if (!strcmp(dest, rotate))
//		{
//			return 1;
//		}
//	}
//	//��ת֮�󣬵ò�����dest��ͬ������
//	return 0;
//}
//�����ƴ��˼�룬�ж�rotate�Ƿ�Ϊdest���Ӵ�
#include<stdio.h>
#include<string.h>
int is_rotate(char* dest, char* rotate)
{
	if (strlen(dest) != strlen(rotate));
	{
		return 0;
	}
	//ƴ��dest
	strncat(dest, dest, strlen(dest));
	//�ж�rotate�Ƿ�Ϊdest���Ӵ�
	if (strstr(dest, rotate) != NULL)
	{
		return 1;
	}
	return 0;
}
//int main()
//{
//	char dset[100] = { 0 };
//	char rotate[100] = { 0 };
//	scanf("%s", dest);
//	scanf("%s", rotate);
//	printf("%d\n", is_rotate(dest, rotate));
//	return 0;
//}
//1.һ��������ֻ�����������ǳ���һ�Σ� 
//�����������ֶ����������Ρ�
//�ҳ����������֣����ʵ�֡�
//˼·������ҳ������г���һ�ε�Ԫ�أ�����Ľ���Ͳ���˳���޹�
//������У�����1��λ��������Ԫ�ص�ǰλһ����Ϊ0����һ����Ϊ1
//1.����������г���1��λ�ã�������ֳ�����������
//2.ÿ���������п϶���һ��Ԫ��ֻ����һ�Σ�����Ԫ�ض��ǳɶԳ���
//3.ÿ����������ȥ��������㣬�ҳ��������ֵ�Ԫ��
//#include<stdio.h>
//int main()
//{
//	int arr[] = { 1, 2, 3, 2, 4, 5, 4, 1 };
//	//���浥�����ֵ�Ԫ�ص������
//	int ret = 0;
//	//����������г���1��λ��
//	int pos;
//	//���浥�����ֵ�Ԫ�ص�ֵ
//	int x = 0;
//	int y = 0;
//	int i;
//	int len = 0;
//	//������Ԫ�ص������
//	for (i = 0; i < len; i++)
//	{
//		ret ^= arr[i];
//	}
//	//Ѱ��������г���1��λ��
//	for (i = 0; i < 32; i++)
//	{
//		if (((ret >> i) & 1) == 1)
//		{
//			//�������1��λ��
//			pos = i;
//			break;
//		}
//	}
//	//����posλ�Ƿ�Ϊ1��������ֳ�����������
//	//�������������п϶���һ��Ԫ��ֻ����һ��
//	for (i = 0; i < len; i++)
//	{
//		//�ж�posλ�Ƿ�Ϊ1
//		if (((arr[i] >> pos) & 1) == 1)
//		{
//			//posλΪ1��������
//			x ^= arr[i];
//		}
//		else
//		{
//			//posλΪ0��������
//			y ^= arr[i];
//		}
//	}
//	printf("%d,%d\n", x, y);
//
//	return 0;
//}
//2.����ˮ��1ƿ��ˮ1Ԫ��2����ƿ���Ի�һƿ��ˮ��
//��20Ԫ�����Զ�����ˮ��
//���ʵ�֡�
#include<stdio.h>
int main()
{
	int money = 0;
	int total = 0;
	int empty = 0;
	scanf("%d", &money);
	total = money;
	empty = money;
	while (empty > 1)
	{
		//��ǰ�ܻ���ƿ��
		total += empty / 2;
		//��һ�ο��õĿ�ƿ���������ܻ��Ŀ�ƿ
		empty = empty / 2 + empty % 2;
	}
	printf("%d\n", total);
	return 0;
}