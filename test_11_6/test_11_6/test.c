#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//ָ������
//int main()
//{
//	int a[4] = { 1, 2, 3, 4 };
//	int *ptr1 = (int *)(&a + 1);
//	int *ptr2 = (int *)((int)a + 1);
//	printf("%x,%x", ptr1[-1], *ptr2);
//	return 0;
//}
//int main()
//{
//	int a[5] = { 1, 2, 3, 4, 5 };
//	int *ptr = (int *)(&a + 1);
//	printf("%d,%d", *(a + 1), *(ptr - 1));
//	return 0;
//}
//

//��д������
//unsigned int reverse_bit(unsigned int value)
//��������ķ���ֵvalue�Ķ�����λģʽ�����ҷ�ת���ֵ
//�磺
//��32λ������25���ֵ�������и�λ��
//00000000000000000000000000011001
//��ת�󣺣�2550136832��
//10011000000000000000000000000000
//���������أ�
//2550136832
//��һ��
//#include<stdio.h>
//#include<math.h>

//unsigned int reverse_bits(unsigned int n)
//{
//	unsigned int sum = 0;
//	int i = 0;
//	for (i = 0; i < 32; i++)
//	{
//		sum += ((n >> i) & 1)*pow(2, 31 - i);
//	}
//	return sum;
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	printf("%u\n", reverse_bits(n));
//	return 0;
//}
//������
//#include<stdio.h>
//unsigned int reverse_bits(unsigned int n)
//{
//	unsigned int ret = 0;
//	int i = 0;
//	for (i = 0; i < 32; i++)
//	{
//		ret <<= 1;
//		ret |= (n >> i) & 1;
//	}
//	return ret;
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	printf("%u\n", reverse_bits(n));
//	return 0;
//}
//��ʹ�ã�a + b�� / 2���ַ�ʽ������������ƽ��ֵ
//
//#include<stdio.h>
//int ave(int a, int b)
//{
//	return (a + b) >> 1;
//}
//int ave2(int a, int b)
//{
//	return (a&b) + ((a^b) >> 1);
//}
//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d %d", &a, &b);
//	printf("%d\n", ave(a, b));
//	printf("%d\n", ave2(a, b));
//
//	return 0;
//}
//���ʵ�֣�
//һ��������ֻ��һ�����ֳ�����һ�Ρ������������ֶ��ǳɶԳ��ֵġ�
//���ҳ�������֡���ʹ��λ���㣩
//#include<stdio.h>
//int main()
//{
//	int arr[] = { 1, 3, 5, 1, 3 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int i = 0;
//	int ret = 0;
//	for (i = 0; i < sz; i++)
//	{
//		ret ^= arr[i];
//	}
//	printf("%d\n", ret);
//	return 0;
//}
//��һ���ַ����������Ϊ:"student a am i",
//	���㽫��������ݸ�Ϊ"i am a student".
//	Ҫ��
//	����ʹ�ÿ⺯����
//	ֻ�ܿ������޸��ռ䣨�ռ�������ַ����ĳ����޹أ���

//int search(int a[3][3], int row, int col, int k, int *px, int *py)
//{
//	int i = 0;
//	int j = col - 1;
//	while (i < row &&j >= 0)
//	{
//		if (a[i][j])
//		{
//			*px = i;
//			*py = j;
//			return 1;
//		}
//		else if (a[i][j])
//		{//��ǰԪ��С��k,������
//			i++;
//		}
//		else
//		{
//			//��ǰԪ�ش���k,������
//			j--;
//		}
//	}
//	*px = -1;
//	*py = -1;
//	return 0;
//}
//int search 
//int main()
//{
//	int a[3][3] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
//
//}