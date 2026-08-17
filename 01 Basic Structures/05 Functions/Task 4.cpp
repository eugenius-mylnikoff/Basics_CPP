/*
Вам требуется написать функцию Join со следующим заголовком:
"std::string Join(const std::vector<std::string>& tokens, char delimiter);".

Функция должна вернуть строку, полученную склейкой элементов вектора через указанный разделитель.

Примечание:
Если вектор "tokens" пустой, то функция должна вернуть пустую строку.
Если в векторе "tokens" ровно один элемент, то он и должен вернуться в ответе.
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

string Join(const vector<string>& tokens, char delimiter) {
	string result;
	for (size_t i = 0; i != tokens.size(); ++i) {
		result += tokens[i];
		if (i + 1 != tokens.size())
			result += delimiter;
	}
	return result;
}

int main() {
	cout << Join({ "What", "is", "your", "name?" }, '_') << "\n"
		<< Join({ "Hello" }, '!') << "\n"
		<< Join({ }, '-') << "\n";
}