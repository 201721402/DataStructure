#include <stdlib.h>
#include "List.h"

// List를 생성한 후 반환. 동적 할당이 제대로 안되면 NULL반환
List* LstCreate() {
	List* list = (List*)malloc(sizeof(List));
	if (list) {
		list->head = NULL;
		list->tail = NULL;
		return list;
	}
	return NULL;
}

// 리스트에 요소가 있으면 0, 없으면 1을 반환
int LstEmpty(const List* list) {
	return list && list->head == 0 && list->tail == 0;
}

// list의 마지막 요소로 e를 삽입. ListNode를 새로 동적 할당함
// 추가에 성공하면 1 반환. 아니면 0 반환
int LstAddToEnd(List* list, Element e) {
	if (list) {
		ListNode* listnode = (ListNode*)malloc(sizeof(ListNode));
		listnode->element = e;
		if (list->head == 0) {
			listnode->next = NULL;
			list->tail = listnode;
			list->head = listnode;
			return 1;
		}
		listnode->next = NULL;
		list->tail->next = listnode;
		list->tail = listnode;
		return 1;
	}
	return 0;
}

// list의 첫 번째 요소로 e를 삽입. ListNode를 새로 동적 할당함
// 추가에 성공하면 1 반환. 아니면 0 반환
int LstAddToFront(List* list, Element e) {
	if (list) {
		ListNode* listnode = (ListNode*)malloc(sizeof(ListNode));
		listnode->element = e;
		if (list->head == 0) {
			listnode->next = NULL;
			list->tail = listnode;
			list->head = listnode;
			return 1;
		}
		listnode->next = list->head;
		list->head = listnode;
		return 1;
	}
	return 0;
}

// list에 next노드가 있다면, next 앞에 e를 삽입. 성공하면 1, 실패하면 0을 반환
// list에 next가 없으면 0 반환
//다시
int LstInsertBefore(List* list, ListNode* next, Element e) {
	if (list && next) {
		ListNode* listnode = (ListNode*)malloc(sizeof(ListNode));
		ListNode* pre = (ListNode*)malloc(sizeof(ListNode));
		listnode->element = e;
		if (next == list->head) {
			listnode->next = list->head;
			list->head = listnode;
			return 1;
		}
		for (ListNode* i = list->head; i != NULL; i = i->next) {
			if (i->next = next) {
				listnode->next = i->next;
				i->next = listnode;
			}
		}
		return 1;
	}
	return 0;
}

// list에 next노드가 있다면, previous 뒤에 e를 삽입. 성공하면 1, 실패하면 0을 반환
// list에 previous가 없으면 0 반환
int LstInsertAfter(List* list, ListNode* previous, Element e) {
	if (list && previous) {
		ListNode* listnode = (ListNode*)malloc(sizeof(ListNode));
		listnode->element = e;
		if (previous == list->tail) {
			list->tail = listnode;
		}
		listnode->next = previous->next;
		previous->next = listnode;
		return 1;

	}
	return 0;
}

// func를 이용해서 list의 모든 요소를 출력
//다시
void LstPrint(List* list, PrintFunc func) {
	if (list) {
		for (ListNode* p = list->head; p != NULL; p = p->next) {
			func(p->element);
		}
	}
}

// list에서 node를 삭제. 성공하면 1을 반환. 실패하면 0을 반환
int LstDelete(List* list, ListNode* node) {
	if (list && node) {
		ListNode* del = NULL;
		if (list->head == node) {
			del = list->head;
			list->head = list->head->next;
			free(del);
			return 1;
		}
		for (ListNode* i = list->head; i != NULL; i = i->next) {
			if (i->next == node) {
				if (i->next == list->tail) {
					list->tail = i;
				}
				del = node;
				i->next = node->next;
				free(del);
			}
		}
		return 1;
	}
	return 0;
}

// list에서 e를 검색해서 있으면 e를 해당 노드를 반환. Element를 비교하는 것은 CompareFunc를 이용
// 만약 해당 노드가 없으면 NULL 반환
ListNode* LstFindNode(List* list, Element e, CompareFunc func) {
	for (ListNode* a = list->head; a != NULL; a = a->next) {
		if (func(&(a->element), &e)) {
			return a;
		}
	}
	return NULL;
}

// IteratorFunc를 list의 각 요소에 적용. func()함수에 p를 인자로 전달
void LstIterate(List* list, IterateFunc func, void* p) {
	for (ListNode* a = list->head; a != NULL; a = a->next) {
		func(&(a->element), p);
	}
}

// list에 있는 모든 요소를 삭제하고 동적 할당된 메모리 해제
void LstDestroy(List* list) {
	ListNode* a = (ListNode*)malloc(sizeof(ListNode));
	if (list) {
		while (list->head) {
			a = list->head;
			list->head = a->next;
			free(a);
		}

		free(list);
	}
}
