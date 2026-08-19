/*
Дана прямоугольная матрица "A" из "m" строк и "n" столбцов.
Транспонированной матрицей "A^T" называется матрица из "n" строк и "m" столбцов,
в которой строки и столбцы поменялись ролями: элемент "A_ij^T" равен элементу "A_ji".

Напишите функцию, которая возвращает транспонированную матрицу:
"std::vector<std::vector<int>> Transpose(const std::vector<std::vector<int>>& matrix);".

Примечание:
Гарантируется, что вектор "matrix" непуст и все его элементы имеют равную ненулевую длину.
*/

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> Transpose(const vector<vector<int>>& matrix) {
    size_t m = matrix.size();
    size_t n = matrix[0].size();

    vector<vector<int>> result(n);
    for (size_t i = 0; i != n; ++i) {
        result[i].resize(m);
        for (size_t j = 0; j != m; ++j) {
            result[i][j] = matrix[j][i];
        }
    }
    return result;
}

int main() {
    vector<vector<int>> matrix = {{1, 2, 3},{4, 5, 6}};
    vector<vector<int>> transposed = Transpose(matrix);

    cout << "Original matrix:\n";
    for (const auto& row : matrix) {
        for (int value : row) {
            cout << value << ' ';
        }
        cout << '\n';
    }

    cout << "\nTransposed matrix:\n";
    for (const auto& row : transposed) {
        for (int value : row) {
            cout << value << ' ';
        }
        cout << '\n';
    }
}