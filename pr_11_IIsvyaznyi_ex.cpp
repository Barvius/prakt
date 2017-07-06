// dvs.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <stdlib.h>

typedef struct Car{
	char mark[20] = { NULL };
	char number[10] = { NULL };
	char surname[20] = { NULL };
} Car;

typedef struct _Node {
	Car value;
	struct _Node *next;
	struct _Node *prev;
} Node;


typedef struct _DblLinkedList {
	size_t size;
	Node *head;
	Node *tail;
} DblLinkedList;


DblLinkedList* createDblLinkedList() {
	DblLinkedList *tmp = new DblLinkedList;
	tmp->size = 0;
	tmp->head = tmp->tail = NULL;
	return tmp;
}

void deleteDblLinkedList(DblLinkedList **list) {
	Node *tmp = (*list)->head;
	Node *next = NULL;
	while (tmp) {
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
	free(*list);
	(*list) = NULL;
}

void pushFront(DblLinkedList *list, Car data) {
	Node *tmp = new Node;
	if (tmp == NULL) {
		exit(1);
	}
	tmp->value = data;
	tmp->next = list->head;
	tmp->prev = NULL;
	if (list->head) {
		list->head->prev = tmp;
	}
	list->head = tmp;
	if (list->tail == NULL) {
		list->tail = tmp;
	}
	list->size++;
}

Car popFront(DblLinkedList *list) {
	Node *prev;
	Car tmp;
	if (list->head == NULL) {
		exit(2);
	}

	prev = list->head;
	list->head = list->head->next;
	if (list->head) {
		list->head->prev = NULL;
	}
	if (prev == list->tail) {
		list->tail = NULL;
	}
	tmp = prev->value;
	free(prev);

	list->size--;
	return tmp;
}

void pushBack(DblLinkedList *list, Car value) {
	Node *tmp = new Node;
	if (tmp == NULL) {
		exit(3);
	}
	tmp->value = value;
	tmp->next = NULL;
	tmp->prev = list->tail;
	if (list->tail) {
		list->tail->next = tmp;
	}
	list->tail = tmp;
	if (list->head == NULL) {
		list->head = tmp;
	}
	list->size++;
}

Car popBack(DblLinkedList *list) {
	Node *next;
	Car tmp;
	if (list->tail == NULL) {
		exit(4);
	}
	next = list->tail;
	list->tail = list->tail->prev;
	if (list->tail) {
		list->tail->next = NULL;
	}
	if (next == list->head) {
		list->head = NULL;
	}
	tmp = next->value;
	free(next);
	list->size--;
	return tmp;
}

Node* getNth(DblLinkedList *list, size_t index) {
	Node *tmp = list->head;
	size_t i = 0;
	while (tmp && i < index) {
		tmp = tmp->next;
		i++;
	}
	return tmp;
}

Node* getNthq(DblLinkedList *list, size_t index) {
	Node *tmp = NULL;
	size_t i;
	if (index < list->size / 2) {
		i = 0;
		tmp = list->head;
		while (tmp && i < index) {
			tmp = tmp->next;
			i++;
		}
	}
	else {
		i = list->size - 1;
		tmp = list->tail;
		while (tmp && i > index) {
			tmp = tmp->prev;
			i--;
		}
	}
	return tmp;
}


void printDblLinkedList(DblLinkedList *list) {
	Node *tmp = list->head;
	int i = 0;
	while (tmp) {
		printf("  %d) %-15s %-15s %-15s \n", i + 1, tmp->value.mark, tmp->value.number, tmp->value.surname);
		i++;
		tmp = tmp->next;
	}
	printf("\n");
}
/*
DblLinkedList* fromArray(void *arr, size_t n, size_t size) {
	DblLinkedList *tmp = NULL;
	size_t i = 0;
	if (arr == NULL) {
		exit(7);
	}

	tmp = createDblLinkedList();
	while (i < n) {
		pushBack(tmp, ((char*)arr + i*size));
		i++;
	}

	return tmp;
}
*/

void insert(DblLinkedList *list, size_t index, Car value) {
	Node *elm = NULL;
	Node *ins = NULL;
	elm = getNth(list, index);
	if (elm == NULL) {
		exit(5);
	}
	ins = (Node*)malloc(sizeof(Node));
	ins->value = value;
	ins->prev = elm;
	ins->next = elm->next;
	if (elm->next) {
		elm->next->prev = ins;
	}
	elm->next = ins;

	if (!elm->prev) {
		list->head = elm;
	}
	if (!elm->next) {
		list->tail = elm;
	}

	list->size++;
}

Car deleteNth(DblLinkedList *list, size_t index) {
	Node *elm = NULL;
	Car tmp;
	elm = getNth(list, index);
	if (elm == NULL) {
		exit(5);
	}
	if (elm->prev) {
		elm->prev->next = elm->next;
	}
	if (elm->next) {
		elm->next->prev = elm->prev;
	}
	tmp = elm->value;

	if (!elm->prev) {
		list->head = elm->next;
	}
	if (!elm->next) {
		list->tail = elm->prev;
	}

	free(elm);

	list->size--;

	return tmp;
}

void main(){
	DblLinkedList *list = createDblLinkedList();
	Car car, car2, car3;
	sprintf(car.mark,"bmw");
	sprintf(car.number, "123");
	sprintf(car.surname, "bgbv");
	sprintf(car2.mark, "audi");
	sprintf(car2.number, "123");
	sprintf(car2.surname, "bcxv");
	sprintf(car3.mark, "xuy");
	sprintf(car3.number, "456");
	sprintf(car3.surname, "abc");
	pushFront(list, car);
	pushBack(list, car2);
	insert(list, 1, car3);
	printDblLinkedList(list);
	deleteNth(list, 0);
	printDblLinkedList(list);
	/*
	printf("length %d\n", list->size);
	printf("nth 2 %d\n", *((int*)(getNthq(list, 2))->value));
	printf("nth 5 %d\n", *((int*)(getNthq(list, 5))->value));
	printf("popFront %d\n", *((int*)popFront(list)));
	printf("popFront %d\n", *((int*)popFront(list)));
	printf("head %d\n", *((int*)(list->head->value)));
	printf("tail %d\n", *((int*)(list->tail->value)));
	printf("popBack %d\n", *((int*)popBack(list)));
	printf("popBack %d\n", *((int*)popBack(list)));
	printf("length %d\n", list->size);
	printDblLinkedList(list, printInt);
	insert(list, 1, &g);
	printDblLinkedList(list, printInt);
	deleteNth(list, 0);
	printDblLinkedList(list, printInt);
	*/
	deleteDblLinkedList(&list);

	system("pause");
}

