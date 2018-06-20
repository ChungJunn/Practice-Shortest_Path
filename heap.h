#ifndef __heap_h__
#define __heap_h__

#include "graph.h"

#define HEAP_LEN 512

typedef int HData;
typedef int Priority;
typedef Vertex * HandleToApp;

typedef struct _heapNode{
	HData data;
	Priority pr;
	HandleToApp handle;
}HeapNode;

typedef struct _heap{
	HeapNode heapArr[HEAP_LEN];
	int numOfData;
}Heap;

void showHeap(Heap * ph);

int parent(int idx);

int leftChild(int idx);

int rightChild(int idx);

int GetPriChildIdx(Heap * ph, int idx);

void HeapInit(Heap * ph);

void HInsert(Heap * ph, HData data, Priority pr, HandleToApp handle);

HData HDelete(Heap * ph);

int HisEmpty(Heap * ph);

void HPriorityDecrease(Heap * ph, HandleToHeap handle, Priority newPr);

#endif

