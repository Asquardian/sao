#include "pch.h"
#include "tree_search.h"
#include "print.h"
#include <time.h>

extern int num_h, num_t;

bool up;

int compare(int a, int b) {
	if (a < b) return 1;
		else
			if (a > b) return -1;
	return 0;
}

int BSearch2(record* sbase[4000], int sum) {
	int L = 0, R = 3999, m;
	while (L < R) {
		m = (L + R) / 2;
		if (sbase[m]->sum < sum)	
			L = m + 1;
		else R = m;
	}
	if (sbase[R]->sum == sum) { return R; }
	else { return -1; }
}


void ll(vertex*& point)
{
	vertex* current = point->left;
	point->bal = 0;
	current->bal = 0;
	point->left = current->right;
	current->right = point;
	point = current;
}

void rr(vertex*& point)
{
	vertex* current = point->right;

	point->bal = 0;
	current->bal = 0;
	point->right = current->left;
	current->left = point;
	point = current;
}

void lr(vertex*& point)
{
	vertex* current = point->left;
	vertex* reva = current->right;

	if (reva->bal < 0) {
		point->bal = 1;
	}
	else {
		point->bal = 0;
	}

	if (reva->bal > 0) {
		current->bal = -1;
	}
	else {
		current->bal = 0;
	}
	reva->bal = 0;
	current->right = reva->left;
	point->left = reva->right;
	reva->left = current;
	reva->right = point;
	point = reva;
}

void rl(vertex*& point)
{
	vertex* current = point->right;
	vertex* reva = current->left;

	if (reva->bal < 0) {
		point->bal = 1;
	}
	else {
		point->bal = 0;
	}

	if (reva->bal > 0) {
		current->bal = -1;
	}
	else {
		current->bal = 0;
	}
	reva->bal = 0;
	current->left = reva->right;
	point->right = reva->left;
	reva->right = current;
	reva->left = point;
	point = reva;
}

void printList(queue* l) {
		queue* p;
		p = l;
		do {
			print_record(p->data);
			p = p->next; // переход к следующему узлу
		} while (p != NULL);
}

void tree_search(vertex* p, int x) {
	vertex* tmp = p;
	while (tmp != NULL) {
		if (tmp->data->data->sum == x) {
			printList(tmp->data);
			return;
		}
		else {
			if (tmp->data->data->sum > x)
				tmp = tmp->left;
			else
				if (tmp->data->data->sum < x)
					tmp = tmp->right;
		}
	}
	cout << "Сумма не найдена" << endl;
}

void LR(vertex* tree)
{
	if (NULL == tree)    return;    //Если дерева нет, выходим

	printList(tree->data);
	LR(tree->left); //Обошли левое поддерево   
	LR(tree->right); //Обошли правое поддерево   
}

void addAVL(queue* data, vertex*& point)
{
	printList(data);
	if (point == NULL) {
		point = new vertex;
		point->data = data;
		point->bal = 0;
		point->left = NULL;
		point->right = NULL;
		up = true;
	}
	else
		if (point->data->data->sum > data->data->sum) { // править  
			addAVL(data, point->left);
			if (up == true) {
				if (point->bal > 0) {
					point->bal = 0;
					up = false;
				}
				else
					if (point->bal == 0) {
						point->bal = -1;
						up = true;
					}
					else
						if (point->left->bal < 0) {
							ll(point);
							up = false;
						}
						else {
							lr(point);
							up = false;
						}
			}
		}
		else {
			if (point->data->data->sum < data->data->sum) {
				addAVL(data, point->right);
				if (up == false) {
					if (point->bal < 0) {
						point->bal = 0;
						up = false;
					}
					else {
						if (point->bal == 0) {
							point->bal = 1;
							up = true;
						}
						else {
							if (point->right->bal > 0) {
								rr(point);
								up = false;
							}
							else {
								rl(point);
								up = false;
							}
						}
					}
				}
			}
			else {
				return;
			}
		}
}
