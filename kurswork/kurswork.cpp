#include "pch.h"
#include "print.h"
#include "sort.h"
#include "tree_search.h"
#include "coding.h"
#include <fstream> 
#include <stdio.h>
#include <stdlib.h>


record* base[4000];

int *w;
int num_h = 0, num_t = 0;

int main()
{
	record* sbase[4000];
	queue* toAVL;
	int search = 0;
	setlocale(LC_ALL, "Russian");
	//SetConsoleCP(866);
	int g = 0;
	int sum = 0;
	FILE *Base3;
	errno_t err; 
	err = fopen_s(&Base3, "testBase3.dat", "rb");
	if (err != 0)
	{
		cout << "Ошибка: невозможно открыть файл" << endl;
		exit(1);
	}
	for (int i = 0; i < 4000; i++) {
		base[i] = read_base(Base3);
	}
	FILE* Base2;
	errno_t err0;
	err0 = fopen_s(&Base2, "testBase3.dat", "rb");
	for (int i = 0; i < 4000; i++) {
		sbase[i] = read_base(Base2);
	}
	_fcloseall();
	///sort///
	//sbase = copy_base(base);
	heapSort(sbase, 4000);
	///tree///
	vertex *root = NULL;
	///code//
	SetConsoleCP(1251);
	readfile((char*)"testBase3.dat");
	///-menu-///
	int enter = 0;
	while (true) {
		system("CLS");
		enter = 0;
		SetConsoleCP(866);
		cout << "\t------------------------------МЕНЮ------------------------" << endl;
		cout << "\t1. Посмотреть базу данных (Enter - вперед, Backspace - назад, esc - выйти)" << endl;
		cout << "\t2. Просмотр отсортированной базы данных (Heap sort)" << endl;
		cout << "\t3. Поиск в массиве и добавление в дерево" << endl;
		cout << "\t4. Поиск в дереве (AVL)" << endl;
		cout << "\t5. Кодирование статистика" << endl;
		cout << "\tEsc. Выход " << endl;
		cout << "\t----------------------------------------------------------" << endl;
		while ((enter != 27) && (enter != 49) && (enter != 50) && (enter != 51) && (enter != 52) && (enter != 53)) {
			if (_kbhit()) {
				enter = _getch();
			}
		}
		switch (enter) {
		case 27: return 0;
		case 49:
			print_base(base);
			break;
		case 50:
			print_base(sbase);
			break;
		case 51:
			toAVL=(queue*)malloc(sizeof(queue*));
			toAVL->next = NULL;
			printf("Введите сумму\n");
			scanf_s("%d", &sum);
			SetConsoleCP(866);
			search = BSearch2(sbase, sum);
			if (search == -1) {
				printf("Нет такой записи\n");
				_getch();
				break;
			}
			toAVL = init(toAVL, sbase[search]);
			search++;
			while (true) {
				if (sbase[search]->sum == sum) {
					//print_record(sbase[search]);
					add(toAVL, sbase[search]);
					search++;
				}
				else
					break;
			}
			addAVL(toAVL, root);
			_getch();
			break;
		case 52:
			int x;
			cout << "Посмотреть дерево (1/0) ";
			scanf_s("%d", &x);
			if (x == 1) {
				LR(root);
			}
			while (true) {
				SetConsoleCP(866);
				cout << "Введите сумму (ext = 1)" << endl;
				scanf_s("%d", &x);
				tree_search(root, x);
				if (x == 1) break;
			}
			break;
		case 53:
			encodeHuffman();
			break;
		}
	}
	return 0;
}