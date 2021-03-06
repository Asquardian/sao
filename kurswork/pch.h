#ifndef PCH_H
#define PCH_H

#include <iostream> ///Для работы с клавиатурой
#include <conio.h>///для getch
#include <Windows.h>///Для русских букв
#include <iomanip>/// для установки кол-ва символов при выводе
#include <cstdio> ///Например для fread()
#include <cstring> ///Для работы со строками
#include <cstdlib>

using namespace std;

const int N = 4000;

struct record
{
	char username[30];
	unsigned short int sum;
	char date[10];
	char lawer[22];
};

struct queue {
	record* data;
	queue* next;
};

struct vertex {
	queue* data;
	int bal;
	vertex *left;
	vertex *right;
};


extern int *w;
extern int num_h, num_t;

record* read_base(FILE* f);
queue* init(queue*& toAVL, record* x);
queue* add(queue* lst, record* x);

#endif //PCH_H