#define _CRT_SECURE_NO_WARNINGS 1
#include"Contact.h"
void menu()
{
	printf("*****************************\n");
	printf("****1.add      2.del     ****\n");
	printf("****3.search   4. modify ****\n");
	printf("****5.show     6.empty   ****\n");
	printf("****7.sort     0. exit   ****\n");
	printf("*****************************\n");

}
void test()
{
	int input = 0;
    Contact con;//ͨѶ¼
	InitContact(&con);//��ʼ��ͨѶ¼
	do
	{
		menu();
		printf("��ѡ��:>");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			AddContact(&con);
			break;
		case DEL:
			DelContact(&con);
			break;
		case MODIFY:
			break;
		case SEARCH:
			break;
		case SHOW:
			ShowContact(&con);
			break;
		case SORT:
			break;
		case EMPTY:
			break;
		case EXIT:
			printf("�˳�ͨѶ¼\n");
			break;
		default:
			printf("ѡ�����\n");

		}
	} while (input);
}
int main()
{
	test();
	return 0;
}