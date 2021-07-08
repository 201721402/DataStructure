#include <stdlib.h>
#include "List.h"

// List�� ������ �� ��ȯ. ���� �Ҵ��� ����� �ȵǸ� NULL��ȯ
List* LstCreate() {
	List* list = (List*)malloc(sizeof(List));
	if (list) {
		list->head = NULL;
		list->tail = NULL;
		return list;
	}
	return NULL;
}

// ����Ʈ�� ��Ұ� ������ 0, ������ 1�� ��ȯ
int LstEmpty(const List* list) {
	return list && list->head == 0 && list->tail == 0;
}

// list�� ������ ��ҷ� e�� ����. ListNode�� ���� ���� �Ҵ���
// �߰��� �����ϸ� 1 ��ȯ. �ƴϸ� 0 ��ȯ
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

// list�� ù ��° ��ҷ� e�� ����. ListNode�� ���� ���� �Ҵ���
// �߰��� �����ϸ� 1 ��ȯ. �ƴϸ� 0 ��ȯ
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

// list�� next��尡 �ִٸ�, next �տ� e�� ����. �����ϸ� 1, �����ϸ� 0�� ��ȯ
// list�� next�� ������ 0 ��ȯ
//�ٽ�
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

// list�� next��尡 �ִٸ�, previous �ڿ� e�� ����. �����ϸ� 1, �����ϸ� 0�� ��ȯ
// list�� previous�� ������ 0 ��ȯ
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

// func�� �̿��ؼ� list�� ��� ��Ҹ� ���
//�ٽ�
void LstPrint(List* list, PrintFunc func) {
	if (list) {
		for (ListNode* p = list->head; p != NULL; p = p->next) {
			func(p->element);
		}
	}
}

// list���� node�� ����. �����ϸ� 1�� ��ȯ. �����ϸ� 0�� ��ȯ
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

// list���� e�� �˻��ؼ� ������ e�� �ش� ��带 ��ȯ. Element�� ���ϴ� ���� CompareFunc�� �̿�
// ���� �ش� ��尡 ������ NULL ��ȯ
ListNode* LstFindNode(List* list, Element e, CompareFunc func) {
	for (ListNode* a = list->head; a != NULL; a = a->next) {
		if (func(&(a->element), &e)) {
			return a;
		}
	}
	return NULL;
}

// IteratorFunc�� list�� �� ��ҿ� ����. func()�Լ��� p�� ���ڷ� ����
void LstIterate(List* list, IterateFunc func, void* p) {
	for (ListNode* a = list->head; a != NULL; a = a->next) {
		func(&(a->element), p);
	}
}

// list�� �ִ� ��� ��Ҹ� �����ϰ� ���� �Ҵ�� �޸� ����
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
