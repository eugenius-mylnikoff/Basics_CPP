/*
Вам требуется написать функцию со следующим заголовком:
"vector<string> Split(const string& str, char delimiter);".

Функция должна вернуть вектор строк, полученный разбиением строки "str" на части по указанному символу-разделителю "delimiter".
Если разделитель встретился в начале или в конце строки "str", то в начале (соответственно, в конце) вектора с результатом должна быть пустая строка.
Если два разделителя встретились рядом, то пустая строка между ними тоже должна попасть в ответ.
Для пустой строки надо вернуть вектор, содержащий одну пустую строку.
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> Split(const string& str, char delimiter) {
	vector<string> result;
	string nakoplenie;
	for (const char& s : str) {
		if (s == delimiter) {
			result.push_back(nakoplenie);
			nakoplenie = "";
		}
		else {
			nakoplenie += s;
		}
	}
	result.push_back(nakoplenie);
	return result;
}

int main() {
	vector<string> test1 = Split("_What_is_your_name?_", '_');
	vector<string> test2 = Split("13-24--08-11-2014", '-');

	for (const string& el : test1) {
		cout << el << "\n";
	}
	cout << "\n";
	for (const string& el : test2) {
		cout << el << "\n";
	}
}