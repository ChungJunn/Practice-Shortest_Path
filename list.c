#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void ListInit(List * plist){
	plist->head = (Node*)malloc(sizeof(Node));
	plist->head->next=0x0;
	plist->comp=0x0;
}

void LInsert(List * plist, LData data){
	if(plist->comp == 0x0){
		FInsert(plist, data);
	}else{
		SInsert(plist, data);
	}
}

void FInsert(List * plist, LData data){
	Node * pNode = (Node*)malloc(sizeof(Node));
	pNode->data = data;
	
	pNode->next = plist->head->next;
	plist->head->next=pNode;
	return;
}

void SInsert(List * plist, LData data){
	Node * pNode = (Node*)malloc(sizeof(Node));
	Node * prev = plist->head;
	pNode->data = data;

	while(prev->next!=0x0 && plist->comp(pNode->data, prev->next->data)){
		prev = prev->next;
	}
	pNode->next = prev->next;
	prev->next = pNode;
}

int LFirst(List * plist, LData * pdata){
	if(plist->head->next == 0x0){
		return FALSE;
}

	plist->cur = plist->head->next;
	plist->prev = plist->head;

	*pdata = plist->cur->data;
	return TRUE;
}
int LNext(List * plist, LData * pdata){
	if(plist->cur->next == 0x0){
		return FALSE;
	}

	plist->prev = plist->cur;
	plist->cur = plist->cur->next;
	*pdata = plist->cur->data;
	return TRUE;
}

LData LRemove(List * plist){
	Node * pNode = plist->cur;
	LData ret = pNode->data;

	plist->prev->next = pNode->next;
	plist->cur = plist->prev;
	
	free(pNode);

	return ret;
}

void SetSortRule(List * plist, int (*comp)(LData d1, LData d2))
{
	plist->comp = comp;
}







