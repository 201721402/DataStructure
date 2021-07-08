#include <stdio.h>
#include <stdlib.h>

#include "Stack.h"

Stack* StkCreate() {
	Stack* stack = (Stack*)malloc(sizeof(Stack));
	if (!stack) {
		free(stack);
		return NULL;
	}
	else {
		stack->darr = DACreate();
		if (!stack->darr) {
			DADestroy(stack->darr);
			return NULL;
		}
		stack->top = -1;
		return stack;
	}
	return NULL;
}

// ������ ��� �ִٸ� 1�� ��ȯ. ���ÿ� �����Ͱ� �ִٸ� 0 ��ȯ
int StkEmpty(const Stack* stack) {
	return stack && stack->darr && stack->top == -1;
}

// ���ÿ� e �߰�
int StkPush(Stack* stack, Element e) {
	if (stack && stack->darr) {
		DAAdd(stack->darr, e);
		stack->top++;
		return 1;
	}
	return 0;
}

// ������ ���� ���κп� �ִ� �����͸� pe�� �����ؼ� ��ȯ
// ������ ���� ���κп� �ִ� �����ʹ� ����
int StkPop(Stack* stack, Element* pe) {
	if (stack && stack->darr) {
		DAGet(stack->darr, stack->top, pe);
		stack->top--;
		return 1;
	}
	return 0;
}

// ������ ���� ���κп� �ִ� �����͸� pe�� �����ؼ� ��ȯ
// ������ ���� ���κп� �ִ� �����ʹ� ���� ����
int StkTop(const Stack* stack, Element* pe){
	if (stack && stack->darr) {
		DAGet(stack->darr, stack->top, pe);
		return 1;
	}
	return 0;
}
// ������ ���� ���κп� �ִ� �����ͺ��� ������� ȭ�鿡 ���

//Ʋ�� �ٽú��� 
void StkPrint(const Stack* stack, PrintFunc func) {
	if (stack && stack->darr) {
		int getNum = 0;
		for (int i = stack->top; i >= 0; i--) {
			DAGet(stack->darr, i, &getNum);
			func(getNum);
		}
	}
}

// ���� ����
void StkDestroy(Stack* stack) {
	if (stack) {
		free(stack->darr);
		free(stack);
	}
}