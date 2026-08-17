/*
Вам требуется написать на C++ функцию со следующим заголовком:
"std::pair<size_t, size_t> MatrixArgMax(const std::vector<std::vector<int>>& matrix);".
Функция должна вернуть пару из индексов максимального элемента в матрице.
Если максимальных элементов несколько, то нужно вернуть наименьшую такую пару.

Формат ввода:
В первой строке двумя числами "n" и "k" задан размер матрицы.
В последующих "n" строках вводится числовая матрица в "k" столбцов.

Формат вывода:
Индекс строки и столбца максимального элемента в матрице.

Примечание:
Считайте, что матрица задана корректно: все строки одинаковой длины, пустых строк нет.
В матрице всегда есть хотя бы один элемент.
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

pair<size_t, size_t> MatrixArgMax(const vector<vector<int>>& matrix) {
	pair<size_t, size_t> index = { 0, 0 };
	int max = matrix[0][0];
    for (size_t i = 0; i != matrix.size(); ++i) {
        for (size_t j = 0; j != matrix[i].size(); ++j) {
            if (matrix[i][j] > max) {
                max = matrix[i][j];
                index = { i, j };
            }
        }
    }
	return index;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> matrix(n, vector<int>(k));

    for (size_t i = 0; i != n; ++i) {
        for (size_t j = 0; j != k; ++j) {
            cin >> matrix[i][j];
        }
    }

    pair<size_t, size_t> res = MatrixArgMax(matrix);
    cout << res.first << " " << res.second;
}