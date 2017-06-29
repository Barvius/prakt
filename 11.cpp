// pr_11.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>

typedef struct Student {
	char LastName[21] = { NULL };
	char FirstName[4] = { NULL };
	char Group[7] = { NULL };
	int score[5] = { NULL };
	float s_score = { NULL };
} Student;

typedef struct Node {
	Student value;
	struct Node *next;
} Node;

// вспомогательные функции для работы со списком

void push(Node **head, Student value) { // создание первого элемента
	Node *tmp = (Node*)malloc(sizeof(Node));
	tmp->value = value;
	tmp->next = (*head);
	(*head) = tmp;
}

Student pop(Node **head) { // удаление первого элемента
	Node* prev = NULL;
	Student val;
	if (head == NULL) {
		exit(-1);
	}
	prev = (*head);
	val = prev->value;
	(*head) = (*head)->next;
	free(prev);
	return val;
}

Node *getLast(Node *head) { // получение последнего элемента
	if (head == NULL) {
		return NULL;
	}
	while (head->next) {
		head = head->next;
	}
	return head;
}

void pushBack(Node **head, Student value) { // запись в конец списка
	Node *last = getLast(*head);
	if (last) {
		Node *tmp = (Node*)malloc(sizeof(Node));
		tmp->value = value;
		tmp->next = NULL;
		last->next = tmp;
	} else {
		push(head, value);
	}
}

Node *getNth(Node* head, int n) { // получение элемента по индексу
	int counter = 0;
	while (counter < n && head) {
		head = head->next;
		counter++;
	}
	return head;
}

Student deleteNth(Node **head, int n) { // удаление элемента по индексу
	if (n == 0) {
		return pop(head);
	} else {
		Node *prev = getNth(*head, n - 1);
		Node *elm = prev->next;
		Student val = elm->value;
		prev->next = elm->next;
		free(elm);
		return val;
	}
}

void deleteList(Node **head) { // удаление всего списка
	Node* prev = NULL;
	while ((*head)->next) {
		prev = (*head);
		(*head) = (*head)->next;
		free(prev);
	}
	free(*head);
}

// вспомогательные функции для работы со списком

void ReadDb(Node **head) { // чтение бд
	FILE *f;
	Student tmp;
	if (!(f = fopen("db.txt", "r"))) {
		printf("Файл не найден....\n");
		system("pause");
		exit(0);
	} else {
		while (fscanf(f, "%s %s %s %d %d %d %d %d\n", tmp.LastName, tmp.FirstName, tmp.Group, &tmp.score[0], &tmp.score[1], &tmp.score[2], &tmp.score[3], &tmp.score[4]) != EOF) {
			tmp.s_score = (tmp.score[0] + tmp.score[1] + tmp.score[2] + tmp.score[3] + tmp.score[4]) / 5.0;
			pushBack(head, tmp);
		}
	}
	fclose(f);
}

void ShowRecords(Node *head) { // печать списка
	system("cls");
	printf("Список студентов\n");
	printf("------------------------\n");
	printf("+----+----------------------+-----+--------+---+---+---+---+---+------+\n");
	printf("| ID | Фамилия              | И.О | Группа |                   |  СБ  |\n");
	int i = 0;
	while (head) {
		printf("+----+----------------------+-----+--------+---+---+---+---+---+------+\n");
		printf("| %-2d | %-20s | %-3s | %-6s | %d | %d | %d | %d | %d | %.2f |\n", i, head->value.LastName, head->value.FirstName, head->value.Group, head->value.score[0], head->value.score[1], head->value.score[2], head->value.score[3], head->value.score[4], head->value.s_score);
		i++;
		head = head->next;
	}
	printf("+----+----------------------+-----+--------+---+---+---+---+---+------+\n");
	printf("\n");
}

void FiltredList(Node *head) { // сортировка по группе
	Node * p = NULL;
	if (head != NULL) {
		while (head->next != NULL) {
			p = head->next;
			do {
				if (strcmp(p->value.Group, head->value.Group) > 0) {
					Student tmp = p->value;
					p->value = head->value;
					head->value = tmp;
				}
				p = p->next;
			} while (p != NULL);
			head = head->next;
		}
	}
}

void ShowGodStudents(Node *head) { // студенты с средним баллом > 4
	system("cls");
	printf("Студенты с средним баллом > 4\n");
	printf("-----------------------------\n");
	int i = 0;
	printf("+----+----------------------+--------+\n");
	printf("| ИД | Фамилия              | Группа |\n");
	while (head) {
		if (head->value.s_score >= 4.0) {
			printf("+----+----------------------+--------+\n");
			printf("| %-2d | %-20s | %-6s |\n", i, head->value.LastName, head->value.Group);
			i++;
		}
		head = head->next;
	}
	printf("+----+----------------------+--------+\n");
	if (!i) {
		system("cls");
		printf("Студенты с средним баллом > 4\n");
		printf("-----------------------------\n");
		printf("Увы и ах...\nСтуденты данного учебного заведения,\nпредпочитают проводить пары в столовой.\n");
	}
}

void AddRecords(Node **head) { // добавление новой записи
	system("cls");
	Student NewStudent;
	printf("Добавление новой записи\n");
	printf("-----------------------\n");
	printf("Фамилия:  ");
	scanf("%s20", NewStudent.LastName);
	printf("\nИнициалы:  ");
	scanf("%s3", NewStudent.FirstName);
	printf("\nГруппа:  ");
	scanf("%s6", NewStudent.Group);
	printf("\nПервая оценка:  ");
	scanf("%d", &NewStudent.score[0]);
	printf("\nВторая оценка:  ");
	scanf("%d", &NewStudent.score[1]);
	printf("\nТретья оценка:  ");
	scanf("%d", &NewStudent.score[2]);
	printf("\nЧетвертая оценка:  ");
	scanf("%d", &NewStudent.score[3]);
	printf("\nПятая оценка:  ");
	scanf("%d", &NewStudent.score[4]);
	NewStudent.s_score = (NewStudent.score[0] + NewStudent.score[1] + NewStudent.score[2] + NewStudent.score[3] + NewStudent.score[4]) / 5.0;
	pushBack(head, NewStudent);
}

void DelRecords(Node **head) { // удаление записи
	system("cls");
	printf("Удаление записи\n");
	printf("---------------\n");
	int rm_row;
	ShowRecords(*head);
	printf("Введите ID удаляемой записи\n");
	scanf("%d", &rm_row);
	deleteNth(head, rm_row);
	printf("Запись с ID %d устпешно удалена\n", rm_row);
}

void preexit(Node *head) { // вопрос о сохранении измененного списка в файл
	system("cls"); 
	printf("Сохранить изменение в файле? y/n\n");
	FILE *f;
	switch (_getch()) {
	case 'y':
		f = fopen("db.txt", "w");
		while (head) {
			fprintf(f, "%s %s %s %d %d %d %d %d\n", head->value.LastName, head->value.FirstName, head->value.Group, head->value.score[0], head->value.score[1], head->value.score[2], head->value.score[3], head->value.score[4]);
			head = head->next;
		}
		fclose(f);
		break;
	default:
		break;
	}
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	system("color F0");
	Node* head = NULL;
	ReadDb(&head);
	while (true) {
		system("cls");
		printf("Выберите действие:\n");
		printf("------------------\n");
		printf("l - Отобразить все записи\n");
		printf("a - Добавить запись\n");
		printf("d - Удалить запись\n");
		printf("s - Показать товарищей с средним баллом > 4\n");
		printf("f - Сортировка по названию группы\n");
		printf("q - Выход\n");
		printf("\n");
		switch (_getch()) {
		case 'l':
			ShowRecords(head);
			break;
		case 'a':
			AddRecords(&head);
			break;
		case 'd':
			DelRecords(&head);
			break;
		case 's':
			ShowGodStudents(head);
			break;
		case 'f':
			FiltredList(head);
			ShowRecords(head);
			break;
		case 'q':
			preexit(head);
			exit(0);
			break;
		}
		printf("-------------------------------------\n");
		printf("Для возврата в главное меню нажмите m\n");
		printf("Для выхода нажмите q\n");
		bool w = true;
		while (w) {
			switch (_getch()) {
			case 'm':
				w = false;
				break;
			case 'q':
				preexit(head);
				exit(0);
				break;
			}
		}
	}
	deleteList(&head);
	return 0;
}

