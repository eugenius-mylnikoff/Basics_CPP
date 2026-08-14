/*
Вам даны строки текстового файла. Отсортируйте набор этих строк по убыванию.

Формат ввода:
Количество строк не превосходит 1000. Каждая строка состоит из символов ASCII с кодами от 32 до 126.
Длина строки не превосходит 100.

Формат вывода:
Напечатайте строки в отсортированном по убыванию порядке.
Для сравнения строк друг с другом достаточно использовать стандартные операторы сравнения, определённые для "std::string".

Примечание:
Компилятор не поддерживает "std::ranges".
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	vector<string> data;
	string line;
	while (getline(cin, line)) {
		data.push_back(line);
	}
	sort(data.rbegin(), data.rend());
	for (string el : data)
		cout << el << "\n";
}