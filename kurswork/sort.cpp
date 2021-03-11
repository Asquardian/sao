#include "sort.h"
#include "pch.h"

/*void copy_base(record* arr[], record* &sarr[]) {
	for (int c = 0; c <= 3999; c++) {
		sarr[c] = arr[c];
	}
}
*/

void heapify(record* sbase[], int m, int i)
{
	int largest = i;
	char year[2] = "";
	char year1[2] = "";
	// �������������� ���������� ������� ��� ������
	int l = 2 * i + 1; // ����� = 2*i + 1
	int r = 2 * i + 2; // ������ = 2*i + 2
 // ���� ����� �������� ������� ������ �����
	if (l < m) {
			if (sbase[l]->sum > sbase[largest]->sum) {
				largest = l;
			}
			if (sbase[l]->sum == sbase[largest]->sum) {
				char years = sbase[l]->date[6];
				year[0] = years;
				years = sbase[l]->date[7];
				year[1] = years;
				int y = atoi(year);
				char years1 = sbase[largest]->date[6];
				year1[0] = years1;
				years1 = sbase[largest]->date[7];
				year1[1] = years1;
				int y1 = atoi(year1);
				if (y > y1) {
					largest = l;
				}
				if (y == y1) {
					char years = sbase[l]->date[3];
					year[0] = years;
					years = sbase[l]->date[4];
					year[1] = years;
					int y = atoi(year);
					char years1 = sbase[largest]->date[3];
					year1[0] = years1;
					years1 = sbase[largest]->date[4];
					year1[1] = years1;
					int y1 = atoi(year1);
					if (y > y1) {
						largest = l;
					}
					if (y == y1) {
						char years = sbase[l]->date[0];
						year[0] = years;
						years = sbase[l]->date[1];
						year[1] = years;
						int y = atoi(year);
						char years1 = sbase[largest]->date[0];
						year1[0] = years1;
						years1 = sbase[largest]->date[1];
						year1[1] = years1;
						int y1 = atoi(year1);
						if (y > y1) {
							largest = l;
						}
					}
				}
			}
		}
	if (r < m) {
			if (sbase[r]->sum > sbase[largest]->sum) {
				largest = r;
			}
				if (sbase[r]->sum == sbase[largest]->sum) {
					char years = sbase[r]->date[6];
					year[0] = years;
					years = sbase[r]->date[7];
					year[1] = years;
					int y = atoi(year);
					char years1 = sbase[largest]->date[6];
					year1[0] = years1;
					years1 = sbase[largest]->date[7];
					year1[1] = years1;
					int y1 = atoi(year1);
					if (y > y1) {
						largest = r;
					}
					if (y == y1) {
						char years = sbase[r]->date[3];
						year[0] = years;
						years = sbase[r]->date[4];
						year[1] = years;
						int y = atoi(year);
						char years1 = sbase[largest]->date[3];
						year1[0] = years1;
						years1 = sbase[largest]->date[4];
						year1[1] = years1;
						int y1 = atoi(year1);
						if (y > y1) {
							largest = r;
						}
						if (y == y1) {
							char years = sbase[r]->date[0];
							year[0] = years;
							years = sbase[r]->date[1];
							year[1] = years;
							int y = atoi(year);
							char years1 = sbase[largest]->date[0];
							year1[0] = years1;
							years1 = sbase[largest]->date[1];
							year1[1] = years1;
							int y1 = atoi(year1);
							if (y > y1) {
								largest = r;
							}
						}
					}
				}
		}
	

		// ���� ����� ������� ������� �� ������
		if (largest != i)
		{
			swap(sbase[i], sbase[largest]);

			// ���������� ����������� � �������� ���� ���������� ���������
			heapify(sbase, m, largest);
		}

}

// �������� �������, ����������� ������������� ����������
void heapSort(record* sbase[], int m)
{
	// ���������� ���� (�������������� ������)
	for (int i = m/2 - 1; i > 0; i--)
		heapify(sbase, m, i);
	// ���� �� ������ ��������� �������� �� ����
	for (int i = m - 1; i > 0; i--)
	{
		// ���������� ������� ������ � �����
		swap(sbase[0], sbase[i]);

		// �������� ��������� heapify �� ����������� ����
		heapify(sbase, i, 0);
	}
}