#include "print.h"
#include "pch.h"

void print_record(record *t) {
	SetConsoleCP(1251);
	for (int j = 0; j < 30; j++)
		cout << t->username[j];
	cout << "|";
		cout << t->sum;
	cout << "|";
	for (int j = 0; j < 10; j++)
		cout << t->date[j];
	cout << "|";
	for (int j = 0; j < 22; j++)
		cout << t->lawer[j];
	cout << "| " << endl;
}

void print_base(record* l[4000]) {
	int M = 20;
	int i = 0, num = 0;
	int c = 0;
	bool toNext = true;
	while (num >= 0 && num < 4000) {
		system("cls");
		cout << "+-----+------------+--------------------------------+----------------+------+-----+" << endl;
		while ((i < M) && (num <= N)) {
			num++;
			cout << "|";
			cout << setw(4) << num << ")|";
			print_record(l[i]);
			cout << "+-----+------------+--------------------------------+----------------+------+-----+" << endl;

			i++;
		}
		SetConsoleCP(866);
		c = 0;
		while (true) {
			if (_kbhit()) {
				c = _getch();
				if (c == 13) {
					M += 20;
					break;
				}
				if (c == 8) {
					M -= 20;
					i -= 40;
					num -= 40;
					break;
				}
				if (c == 27) {
					return;
				}
			}
		}
	}
	return;
}