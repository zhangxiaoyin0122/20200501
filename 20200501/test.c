#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef int Type;

typedef struct Node {
	Type _value;
	struct Node* _next;
}Node;

typedef struct SingleList {
	Node* _head;
}SingleList;

void SingleListInit(SingleList* sl) {
	sl->_head = NULL;
}
Node* creatNode(Type data) {
	Node* node = (Node*)malloc(sizeof(Type));
	node->_next = NULL;
	node->_value = data;
	return node;
}
//尾插
void SingleListPushBack(SingleList* sl, Type data) {
	Node* node = creatNode(data);
	if (sl->_head == NULL) {
		sl->_head = node;
	}
	else {
		Node* last = sl->_head;
		while (last->_next) {
			last = last->_next;
		}
		last->_next = node;
	}
}
//尾删
void SingleListPopBack(SingleList* sl) {
	if (sl->_head) {
		Node* prev = NULL;
		Node* tail = sl->_head;
		while (tail->_next) {
			prev = tail;
			tail = tail->_next;
		}
		if (tail == sl->_head) {
			sl->_head = NULL;
		}
		else {
			prev->_next = NULL;
		}
		free(tail);
	}
}
//头插
void SingleListPushFront(SingleList* sl, Type data) {
	Node* node = creatNode(data);
	if (sl->_head == NULL) {
		sl->_head = node;
	}
	else {
		node->_next = sl->_head;
		sl->_head = node;
	}
}
//头删
void SingleListPopFront(SingleList* sl) {
	if (sl->_head) {
		Node* start = sl->_head;
		sl->_head = start->_next;
		free(start);
	}
}
//任意位置后面插入
void SingleListInsert(Node* pos, Type data) {
	Node* node = creatNode(data);
	if (pos == NULL)
		return;
	node->_next = pos->_next;
	pos->_next = pos;
}
//任意位置后面删除
void SingleListEnsert(Node* pos) {
	if (pos == NULL)
		return;
	Node* next = pos->_next;
		if (next) {  //判断next是否存在
			pos->_next = next->_next;
			free(next);
		}
}
Node* SingleListFind(SingleList* sl,Type data) {
	Node* cur = sl->_head;
	while (cur->_next) {
		if (cur->_value == data) {
			return cur;
			break;
		}
		cur = cur->_next;
	}
	return NULL;
}
void SingleListPrint(SingleList* sl) {
	Node* cur = sl->_head;
	while (cur->_next) {
		printf("%d ", cur->_value);
	}
	printf("\n");
}
//判空
int SingleEmpty(SingleList* sl) {
	if (sl->_head == NULL)
		return 1;
	return 0;
}
//链表的销毁
void SingleListDestory(SingleList* sl) {
	Node* cur = sl->_head;
	while (cur) {
		Node* next = cur->_next;
		free(cur);
		cur = next;
	}
}
