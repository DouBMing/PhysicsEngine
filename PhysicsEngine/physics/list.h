#ifndef _stack_h
#define _stack_h

#include "boolean.h"

typedef struct node
{
	void* data;
	struct node* next;
}Node;

/// <summary>
/// ֧�������������ݵ��������ݱ�����ָ��
/// </summary>
typedef struct list
{
	Node* head;
	Node* tail;
	int dataSize;
	int length;
}List;

/// <summary>
/// �½�������
/// </summary>
/// <param name="dataSize">�������ݵĴ�С</param>
/// <returns></returns>
List* CreateList(int dataSize);

/*�������*/
/// <summary>
/// ͷ������
/// </summary>
void InsertFromHead(List* list, void* data);
/// <summary>
/// β������
/// </summary>
void InsertFromTail(List* list, void* data);
void InsertByIndex(List* list, void* data, int index);

/*�Ƴ�����*/
bool RemoveFromHead(List* list);
bool RemoveFromTail(List* list);
bool RemoveByIndex(List* list, int index);
/// <summary>
/// �������
/// </summary>
void ClearList(List* list);

void* GetData(List* list, int index);
bool IsContain(List* list, void* data);
bool IsEmpty(List* list);

#endif