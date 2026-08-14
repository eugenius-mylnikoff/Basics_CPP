/*
Известный алгоритм Soundex определяет, похожи ли два английских слова по звучанию.
На вход он принимает слово и заменяет его на некоторый четырёхсимвольный код.
Если коды двух слов совпадают, то слова, как правило, звучат похоже.

Вам требуется реализовать этот алгоритм:
- Первая буква слова сохраняется.
- В остальной части слова буквы "a", "e", "h", "i", "o", "u", "w" и "y" удаляются;
- Оставшиеся буквы заменяются на цифры от 1 до 6, причём похожим по звучанию буквам соответствуют одинаковые цифры:
"b", "f", "p", "v": 1
"c", "g", "j", "k", "q", "s", "x", "z": 2
"d", "t": 3
"l": 4
"m", "n": 5
"r": 6
- Любая последовательность идущих подряд одинаковых цифр сокращается до одной такой цифры.
- Итоговая строка обрезается до первых четырёх символов.
- Если длина строки получилась меньше четырёх символов, в конце добавляются нули.

Формат ввода:
На вход подаётся одно непустое слово из строчных латинских букв.
Длина слова не превосходит 20 символов.

Формат вывода:
Напечатайте четырёхбуквенный код, соответствующий слову.
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	string word;
	string result;
	cin >> word;
	result += word[0];
	word = word.substr(1);
	for (char c : {'a', 'e', 'h', 'i', 'o', 'u', 'w', 'y'}) {
		word.erase(remove(word.begin(), word.end(), c), word.end());
	}
	string num;
	for (char c : word) {
		char el;
		switch (c) {
			case 'b':
			case 'f':
			case 'p':
			case 'v':
				el = '1';
				break;
			case 'c':
			case 'g':
			case 'j':
			case 'k':
			case 'q':
			case 's':
			case 'x':
			case 'z':
				el = '2';
				break;
			case 'd':
			case 't':
				el = '3';
				break;
			case 'l':
				el = '4';
				break;
			case 'm':
			case 'n':
				el = '5';
				break;
			case 'r':
				el = '6';
				break;
		}
		if (num.size() > 0) {
			if (num[num.size() - 1] == el) {
				continue;
			}
		}
		num += el;
	}
	result += num;
	result = result.substr(0, 4);
	while (result.size() < 4) {
		result += "0";
	}
	cout << result;
}