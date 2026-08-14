/*
Пароль от некоторого сервиса должен удовлетворять таким ограничениям:
- состоять из символов таблицы ASCII с кодами от 33 до 126;
- быть не короче 8 символов и не длиннее 14;
- из 4 классов символов - большие буквы, маленькие буквы, цифры, прочие символы - в пароле должны присутствовать не менее трёх любых.

Напишите программу, которая проверит, что введённый пароль подходит под эти ограничения.

Формат ввода:
На входе дана одна строка с паролем.

Формат вывода:
Выведите "YES", если пароль удовлетворяет требованиям, и "NO" в противном случае.

Примечание:
Вы можете воспользоваться функциями из заголовочного файла "cctype" или реализовать самостоятельно их аналоги.
*/

#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;

int main() {
	string password;
	cin >> password;
	if (password.size() >= 8 && password.size() <= 14) {
		vector<bool> rules(4, false);
		bool result = true;
		for (char el : password) {
			if (!(static_cast<int>(el) >= 33 && static_cast<int>(el) <= 126)) {
				result = false;
				break;
			}
			if (isalpha(el)) {
				if (isupper(el))
					rules[0] = true;
				else
					rules[1] = true;
			}
			else if (isdigit(el))
				rules[2] = true;
			else if (isgraph(el))
				rules[3] = true;
		}
		if (result) {
			int count = 0;
			for (size_t i = 0; i != rules.size(); ++i) {
				if (rules[i])
					++count;
			}
			if (count >= 3)
				cout << "YES";
			else
				cout << "NO";
		}
	}
	else
		cout << "NO";
}