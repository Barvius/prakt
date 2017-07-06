// dvs.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <stdlib.h>

typedef struct Order {
	//struct Check_acc payer;
	//struct Check_acc recivier;
	float sum;
}Order;

typedef struct _Node {
	Order val;
	struct _Node *next;
	struct _Node *prev;
} Node;

typedef struct _List {
	size_t size;
	Node *head;
	Node *tail;
} List;

List* createLinkedList() { // создает список
	List *tmp = new List;
	tmp->size = 0;
	tmp->head = tmp->tail = NULL;
	return tmp;
}

void deleteLinkedList(List **list) { // удаляет список
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

void push(List *list, Order data) { // добавляет/создает элемент
	Node *tmp = new Node;
	tmp->val = data;
	if (!list->size) { // если список пустой то создаем первый элемент
		tmp->next = list->head;
		tmp->prev = NULL;
		if (list->head) {
			list->head->prev = tmp;
		}
		list->head = tmp;
		if (list->tail == NULL) {
			list->tail = tmp;
		}
	} else { // если не пустой, то докидываем в конец записи
		tmp->next = NULL;
		tmp->prev = list->tail;
		if (list->tail) {
			list->tail->next = tmp;
		}
		list->tail = tmp;
		if (list->head == NULL) {
			list->head = tmp;
		}
	}
	list->size++;
}

Node* getNth(List *list, size_t index) { // получает значение элемента по индексу, нужно для удаления
	Node *tmp = list->head;
	size_t i = 0;
	while (tmp && i < index) {
		tmp = tmp->next;
		i++;
	}
	return tmp;
}

Order deleteNth(List *list, size_t index) { //удаляет элемент по индексу
	Node *elm = NULL;
	Order tmp;
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
	tmp = elm->val;
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
	DblLinkedList *list = createLinkedList();// создание списка
	//push(list, Order); - добавление
	//deleteNth(list, n) - удаление;
	//deleteLinkedList(&list); - удаление всего списка
	system("pause");
}

