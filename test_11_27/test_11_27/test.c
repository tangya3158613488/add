#define _CRT_SECURE_NO_WARNINGS 1
#include"SeqList.h"

SeqList s;
void Test1()
{
	SeqListInit(&s, 8);
    SeqListPushBack(&s, 4);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 56);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 30);
	SeqListPushBack(&s, 3);
    SeqListPopBack(&s);
	SeqListInsert(&s, 2, 5);
	SeqListPopFront(&s);
	SeqListErase(&s, 2);
	SeqListSize(&s);
	SeqListEmpty(&s);
	SeqListModify(&s, 1,3);
	SeqListBubbleSort(&s);
	SeqListBinaryFind(&s, 56);

	SeqListRemoveAll(&s, 3);

	SeqListPrint(&s);
	SeqListDestory(&s);

}

int main()
{
	Test1();
	return 0;
}