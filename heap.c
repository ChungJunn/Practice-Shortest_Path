#include "heap.h"
#include <stdio.h>

void HeapInit(Heap * ph){
	ph->numOfData = 0;
}

int parent(int idx){
//returns parent idx
	return idx/2;
}

int leftChild(int idx){
	return idx*2;
}

int rightChild(int idx){
	return idx*2+1;
}

void showHeap(Heap * ph){
	int i=0;
	for(i=1;i<=ph->numOfData;i++){
		printf("%d data:%d pr:%d\n",i, ph->heapArr[i].data, ph->heapArr[i].pr);
	}
}

void HInsert(Heap * ph, HData data, Priority pr, HandleToApp handle){	
	int data_idx;
	int parent_idx;
	HeapNode node = {data, pr, handle};
	//HeapNode node;
	if(ph->numOfData>=HEAP_LEN){
		printf("heap is full\n");
		return;
	}
	
	//create new HeapNode
	data_idx = ph->numOfData+1;


	//find right place
	while(parent(data_idx)>0){
		parent_idx = parent(data_idx);
		if(pr >= ph->heapArr[parent_idx].pr){
			break;
		}
		
		ph->heapArr[data_idx] = ph->heapArr[parent_idx];
		//access corresponding app object and update handle
		ph->heapArr[data_idx].handle->handle = data_idx;
		//move up
		data_idx = parent(data_idx);
	}
	//add to the last place
	ph->heapArr[data_idx]=node;
	//access corresponding app object and update handle
	ph->heapArr[data_idx].handle->handle = data_idx;
	//increase number of data
	ph->numOfData++;
	return;
}

int GetHiPriChildIdx(Heap * ph, int parent){
	if(leftChild(parent) > ph->numOfData){
		return 0;
	}
	else if(rightChild(parent) > ph->numOfData){
		return leftChild(parent);
	}
	else{ 	
		if(ph->heapArr[leftChild(parent)].pr >  ph->heapArr[rightChild(parent)].pr) return rightChild(parent);
		else return leftChild(parent);
	}
}


HData HDelete(Heap * ph){
	//get data to return
	HData data = ph->heapArr[1].data;
	//get the node in the last place
	HeapNode node = ph->heapArr[ph->numOfData];
	ph->numOfData--;

	//define idx vars
	int data_idx=1;
	int child_idx;

	//heap reorder
	while((child_idx=GetHiPriChildIdx(ph, data_idx))){
		if(node.pr > ph->heapArr[child_idx].pr){
			ph->heapArr[data_idx] = ph->heapArr[child_idx];
			//access corresponding app object and update handle
			ph->heapArr[data_idx].handle->handle = data_idx;

			data_idx=child_idx;
		}
		else break;
	}
	//insert node the place
	ph->heapArr[data_idx] = node;
	//access corresponding app object and update handle
	ph->heapArr[data_idx].handle->handle = data_idx;

	return data;
}

int HisEmpty(Heap * ph){
	if(ph->numOfData <= 0) return 1;
	else return 0;
}

void HPriorityDecrease(Heap * ph, HandleToHeap handle, Priority newPr){
	//get idx from handle and save the node in new var
	int data_idx = handle;
	int parent_idx;
	HeapNode node = ph->heapArr[data_idx];

	//compare newPr with old pr
	if(newPr >= ph->heapArr[data_idx].pr){
		printf("new priority must be less than old priority\n");
		return;
	}
	
	//reorder heap according to newly given pr	
	while(parent(data_idx)>0){
		parent_idx = parent(data_idx);
		if(newPr >= ph->heapArr[parent_idx].pr){
			break;
		}
		
		ph->heapArr[data_idx] = ph->heapArr[parent_idx];
		//access corresponding app object and update handle
		ph->heapArr[data_idx].handle->handle = data_idx;
		data_idx = parent_idx;
	}
	
	ph->heapArr[data_idx]=node;
	//access corresponding app object and update handle
	ph->heapArr[data_idx].handle->handle = data_idx;
	ph->heapArr[data_idx].pr = newPr;

	return;
}
