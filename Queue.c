#include "Queue.h"

Queue* QueCreate() {
	Queue* qu = (Queue*)malloc(sizeof(Queue));
	if (qu) {
		qu->darr = DACreate();
		if (!qu->darr) {
			free(qu);
			return NULL;
;		}
		qu->front = -1;
		qu->rear = -1;
		return qu;
	}
	return NULL;
}

int QueEmpty(const Queue* queue) {
	return queue && queue->darr && queue -> front == queue -> rear;
}
//왜 인큐에서 e가 없으면 표시를 하면 오류가남?? 맨앞에e가 0이라서 
int QueEnqueue(Queue* queue, Element e) {
	if (queue && queue->darr) {
		if (DAAdd(queue->darr, e)) {
			queue->rear++;
			return 1;
		}
		return 0;
	}
	return 0;
}
//디큐부분 다시해야함.
int QueDequeue(Queue* queue, Element* pe) {
	if (queue && queue->darr && QueEmpty(queue) == 0 && queue->front == -1) {
		int num = 0;
		DAGet(queue->darr, queue->front + 1, pe);
		for (int i = 0; i <= queue->rear; i++) {
			DAGet(queue->darr, queue->front + i+2, &num);
			DAPut(queue->darr, queue->front + i+1, num);
	
		}
		queue->rear--;
		return 1;
	}
	return 0;
}
int QueFront(const Queue* queue, Element* pe) {
	if (queue && queue->darr && pe) {
		if (DAGet(queue->darr,queue->front+1,pe)) {
			return 1;
		}
		return 0;
	}
	return 0;
}
void QuePrint(const Queue* queue, PrintFunc func) {
	if (queue && queue->darr) {
		int num = DAGetCount(queue->darr);
		for (int i = 0; i < num; i++) {
			func(i);
		}
	}

}

void QueDestroy(Queue* queue) {
	if (queue && DADestroy(queue->darr)) {
		free(queue);
	}
}
