#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//int main()
//{
//	int num = 10;
//	int count = 0;
//	while (num)
//	{
//		if (num % 2 == 1)
//		{
//			count++;
//		}
//		num = num / 2;
//		
//	}
//	printf("��������1�ĸ���=%d\n", count);
//	return 0;
//}

//����int��32λ������m��n�Ķ����Ʊ��ʽ�У��ж��ٸ�λ��bit����ͬ
//����һ��
//#include<stdio.h>
//int cal_diff(int m, int n)
//{
//	int count = 0;
//	int i = 0; 
//	for (i = 0; i < 32; i++)
//	{//ȡ��m��n��Ӧλֵ�ıȽ�
//		if (((m >> i) & 1) != ((n >> i) & 1))
//		{
//			count++;
//		}
//	}
//	return count;
//}
//int main()
//{
//	int m = 0;
//	int n = 0;
//	scanf("%d%d", &m, &n);
//	printf("%d��%d�в�ͬ��λ��:%d\n", m, n, cal_diff(m,n));
//	return 0;
//}
//

//��������
#include<stdio.h>
int cal_diff(int m, int n)
{
	//����ǲ�ͬλ
	int ret = m^n;
	int count = 0;
	while (ret)
	{
		ret = ret&(ret - 1);
		count++;
	}
	return count;
}
int main()
{
	int m = 0;
	int n = 0;
	scanf("%d%d", &m, &n);
	printf("%d��%d�в�ͬ��λ��:%d\n", m, n, cal_diff(m,n));
	return 0;
}