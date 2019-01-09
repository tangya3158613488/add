#include<stdio.h>
#include<assert.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>

typedef int HPDataType;
typedef struct Heap
{
	HPDataType* _array;
	size_t _size;
	size_t _capacity;
}Heap;

Heap hp;
void HeapInit(Heap* hp, HPDataType* a, size_t n);
void HeapDestroy(Heap* hp);
void HeapPrint(Heap* hp);
void HeapPush(Heap* hp, HPDataType x);
void HeapPop(Heap* hp);
void HeapSort(HPDataType*a,size_t n);//∂—≈≈–Ú
void TopK();
void TestHeap();