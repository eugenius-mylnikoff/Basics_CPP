/*
Дана строка из строчных латинских букв и пробелов. Проверьте, является ли она палиндромом без учета пробелов.

Формат ввода:
На вход подается одна строка. В строке могут быть пробелы.
Подряд может идти произвольное число пробелов. Длина строки не превосходит 100.

Формат вывода:
Представьте, что из строки удалили все пробелы.
Необходимо вывести "YES", если полученная строка - палиндром, и "NO" в противном случае.

Примечание:
Пустая строка считается палиндромом.
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	string line;
	getline(cin, line);
	line.erase(remove(line.begin(), line.end(), ' '), line.end());
	string reverse;
	for (int i = line.size() - 1; i != -1; --i) {
		reverse += line[i];
	}
	if (line == reverse)
		cout << "YES";
	else
		cout << "NO";
}