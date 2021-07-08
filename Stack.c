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

// 스택이 비어 있다면 1을 반환. 스택에 데이터가 있다면 0 반환
int StkEmpty(const Stack* stack) {
	return stack && stack->darr && stack->top == -1;
}

// 스택에 e 추가
int StkPush(Stack* stack, Element e) {
	if (stack && stack->darr) {
		DAAdd(stack->darr, e);
		stack->top++;
		return 1;
	}
	return 0;
}

// 스택의 가장 윗부분에 있는 데이터를 pe로 저장해서 반환
// 스택의 가장 윗부분에 있는 데이터는 제거
int StkPop(Stack* stack, Element* pe) {
	if (stack && stack->darr) {
		DAGet(stack->darr, stack->top, pe);
		stack->top--;
		return 1;
	}
	return 0;
}

// 스택의 가장 윗부분에 있는 데이터를 pe로 저장해서 반환
// 스택의 가장 윗부분에 있는 데이터는 제거 안함
int StkTop(const Stack* stack, Element* pe){
	if (stack && stack->darr) {
		DAGet(stack->darr, stack->top, pe);
		return 1;
	}
	return 0;
}
// 스택의 가장 윗부분에 있는 데이터부터 순서대로 화면에 출력

//틀림 다시봐라 
void StkPrint(const Stack* stack, PrintFunc func) {
	if (stack && stack->darr) {
		int getNum = 0;
		for (int i = stack->top; i >= 0; i--) {
			DAGet(stack->darr, i, &getNum);
			func(getNum);
		}
	}
}

// 스택 제거
void StkDestroy(Stack* stack) {
	if (stack) {
		free(stack->darr);
		free(stack);
	}
}