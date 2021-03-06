#include "pch.h"


record* read_base(FILE *f) {
	record* tmp = new record();
	fread((record *)tmp, sizeof(record), 1, f);
	return tmp;
}
queue* init(queue*& toAVL, record* x) {
		struct queue* lst;
		lst = (queue*)malloc(sizeof(queue*));
		lst->data = x;
		lst->next = NULL; // это последний узел списка
		return(lst);
}
queue* add(queue* lst, record* x)
{
	queue* temp, * p;
	temp = (queue*)malloc(sizeof(queue*));
	p = lst->next; // сохранение указателя на следующий узел
	lst->next = temp; // предыдущий узел указывает на создаваемый
	temp->data = x; // сохранение поля данных добавляемого узла
	temp->next = p; // созданный узел указывает на следующий элемент
	return(temp);
}