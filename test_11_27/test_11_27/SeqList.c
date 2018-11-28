#define _CRT_SECURE_NO_WARNINGS 1
#include"SeqList.h"
void SeqListInit(SeqList* ps, size_t capacity)
{
	assert(ps);
	ps->_array=(SLDataType*)malloc(sizeof(SLDataType)*capacity);
	ps->_size = 0;
	ps->_capacity = capacity;
}

void SeqListDestory(SeqList* ps)
{
	assert(ps);
	if (ps->_array)
	{
		free(ps->_array);
		ps->_array = NULL;
		ps->_capacity = ps->_size = 0;
	}
}


void CheckCapacity(SeqList* ps)
{
	if (ps->_size == ps->_capacity)
	{
		ps->_capacity *= 2;
		ps->_array = realloc(ps->_array, ps->_capacity*sizeof(SLDataType));
		assert(ps->_array);
	}
}


void SeqListPushBack(SeqList* ps,SLDataType x)
{
	assert(ps);
	CheckCapacity(ps);
	ps->_array[ps->_size++] = x;
}

void SeqListPopBack(SeqList* ps)
{
	assert(ps && ps->_size > 0);
	ps->_size--;
}

void SeqListInsert(SeqList* ps, size_t pos, SLDataType x)
{
	assert(ps && pos <= ps->_size);
	CheckCapacity(ps);
	size_t end = ps->_size;
	while (end > pos)
	{
		ps->_array[end] = ps->_array[end - 1];
		--end;
	}
	ps->_array[pos] = x;
	ps->_size++;

}

void SeqListPopFront(SeqList* ps)
{
	assert(ps);
	size_t begin = 0;
	while (begin < ps->_size - 1)
	{
		ps->_array[begin] = ps->_array[begin + 1];
			++begin;
	}
	--ps->_size;
}

void SeqListErase(SeqList* ps, size_t pos)
{
	assert(ps && pos < ps->_size);
	size_t begin = pos;
	while (begin < ps->_size - 1)
	{
		ps->_array[begin] = ps->_array[begin + 1];
		++begin;
	}
	--ps->_size;

}

int SeqListFind(SeqList*ps, SLDataType x)
{
	assert(ps);
	for (size_t i = 0; i < ps->_size; i++)
	{
		if (ps->_array[i] == x)
		{
			return i;
		}
	}
	return -1;

}


size_t SeqListSize(SeqList* ps)
{
	assert(ps);
	printf("%d\n", ps->_size);
	return 0;
}


//非空返回1，空返回0
int SeqListEmpty(SeqList* ps)
{
	assert(ps);
	return ps->_size > 0 ? 1 : 0;
}

void SeqListModify(SeqList* ps,size_t pos,SLDataType x)
{
	assert(ps && pos < ps->_size);
	ps->_array[pos] = x;

}

void SeqListPrint(SeqList* ps)
{
	assert(ps);
	for (size_t i = 0; i < ps->_size; i++)
	{
		printf("%d ", ps->_array[i]);
	}
	printf("\n");
}

void SeqListBubbleSort(SeqList* ps)
{
	assert(ps);
	size_t finish = ps->_size;
	while (finish > 0)
	{
		int exchenge = 1;
		for (size_t i = 0; i <finish; i++)
		{

			if (ps->_array[i]>ps->_array[i + 1])
			{
				SLDataType tmp = ps->_array[i];
				ps->_array[i] = ps->_array[i + 1];
				ps->_array[i + 1] = tmp;
				exchenge = 1;
			}
		}
		--finish;
	}
}

int SeqListBinaryFind(SeqList* ps, SLDataType x)
{
	assert(ps);
	int begin = 0;
	int end = ps->_size - 1;
	while (end >= begin)
	{
		int mid = (begin + end) / 2;
		if (x > ps->_array[mid])
		{
			begin = mid + 1;
		}
		else if (x < ps->_array[mid])
		{
			end = mid - 1;
		}
		else
		{
			return mid;
			printf("找到了%d\n", mid);
		}
	}
	return -1;
}


















