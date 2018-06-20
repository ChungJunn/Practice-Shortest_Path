#ifndef __list_h__
#define __list_h__

#define TRUE 1
#define FALSE 0

typedef int LData;

typedef struct _node{
	LData data;
	struct _node * next;
}Node;

typedef struct _list{
	struct _node * head;
	struct _node * cur;
	struct _node * prev;
	int (*comp)(LData d1, LData d2);
}List;

void ListInit(List * plist);

void SetSortRule(List * plist, int (*comp)(LData d1, LData d2));

void SInsert(List * plist, LData data);

void FInsert(List * plist, LData data);

void LInsert(List * plist, LData data);

int LFirst(List * plist, LData * pdata);

int LNext(List * plist, LData * pdata);

LData LRemove(List * plist);

#endif
