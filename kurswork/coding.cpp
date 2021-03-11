#include "pch.h"
#include <algorithm>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#include <conio.h>

std::vector<double> probabilitiesTmp;
std::vector<char> m_data;
std::vector<double> m_probabilities;
std::vector<std::vector<int>> m_matrix;
std::vector<int> length;
std::vector<double> probSum;


void clearMatrix() {
	m_matrix.clear();
	m_matrix.resize(m_probabilities.size());
	probSum.clear();
	length.clear();
}

void print() {
	double averageLen = 0;
	double entropy = 0;
	for (int i = 0; i < m_matrix.size(); ++i) {
		averageLen += m_matrix[i].size() * m_probabilities[i];
		entropy -= m_probabilities[i] * log2(m_probabilities[i]);
		std::cout << " " << m_data[i] << "    ";
		std::cout << std::setw(5) << std::to_string(m_probabilities[i]) << "    ";
		std::cout << m_matrix[i].size() << "    ";
		for (auto& j : m_matrix[i]) {
			std::cout << j;
		}
		std::cout << std::endl;
	}
	std::cout << "—редн€€ длина: " << averageLen << std::endl;
	std::cout << "Ёнтропи€: " << entropy << std::endl;
	std::cout << entropy + 1 << ">" << averageLen << std::endl;
	_getch();
};


int up(int n, double q) {
	int j;
	for (int i = n - 1; i >= 0; i--) {
		if (i > 0 && probabilitiesTmp[i - 1] < q) {
			probabilitiesTmp[i] = probabilitiesTmp[i - 1];
			j = i;
		}
		else {
			j = i;
			break;
		}
	}
	probabilitiesTmp[j] = q;
	return j;
}
void down(int n, int j) {
	std::vector<int> s(m_matrix[j].size());
	s = m_matrix[j];
	for (int i = j; i < n - 1; i++) {
		m_matrix[i] = m_matrix[i + 1];
	}
	m_matrix[n - 1] = s;
	m_matrix[n] = s;
	m_matrix[n - 1].push_back(0);
	m_matrix[n].push_back(1);
}

void readfile(char* path) {
	std::ifstream file("testBase3.dat");
	if (file.is_open()) {
		m_data.clear();
		m_probabilities.clear();
		char symbol;
		while (file.get(symbol)) {
			bool isExist = false;
			for (size_t i = 0; i < m_data.size(); i++) {
				if (symbol == m_data[i]) {
					m_probabilities[i]++;
					isExist = true;
					break;
				}
			}
			if (!isExist) {
				m_data.push_back(symbol);
				m_probabilities.push_back(1);
			}
		}
		int sumOfProbabilities = 0;
		for (auto& probability : m_probabilities) {
			sumOfProbabilities += probability;
		}
		for (auto& probability : m_probabilities) {
			probability /= sumOfProbabilities;
		}
		clearMatrix();
		return;
	}
	std::cout << "ќшибка " << std::endl;
	_getch();
	exit(-1);
}
void huffmanCode(int n) {
	double q;
	int j;
	if (n == 1) {
		m_matrix[0].push_back(0);
		m_matrix[1].push_back(1);
	}
	else {
		q = probabilitiesTmp[n - 1] + probabilitiesTmp[n];
		j = up(n, q);
		huffmanCode(n - 1);
		down(n, j);
	}
}

void encodeHuffman() {
	for (auto& i : m_probabilities) {
		probabilitiesTmp.push_back(i);
	}
	huffmanCode((int)m_probabilities.size() - 1);
	print();
}