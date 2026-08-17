/*
Напишите функцию для вычисления наибольшего общего префикса строк, переданных в векторе "words":
"std::string CommonPrefix(const std::vector<std::string>& words);".

Например, для пустого вектора функция должна вернуть пустую строку, а для вектора из строк
"apple", "apricot" и "application" - строку "ap".
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

string CommonPrefix(const vector<string>& words) {
	if (words.empty())
		return "";

	for (size_t i = 1; i != words[0].size() + 1; ++i) {
		string prefix = words[0].substr(0, i);
		bool ok = true;
		for (const string& word : words) {
			if (!word.starts_with(prefix)) {
				ok = false;
				break;
			}
		}
		if (!ok) {
			prefix.pop_back();
			return prefix;
		}
	}
	return words[0];
}

int main() {
	vector<string> test1 = { "apple", "apricot", "application" };
	vector<string> test2 = { "abcd", "abcdef", "abcdefghi" };
	vector<string> test3;
	vector<string> test4 = { "987654321", "9876543", "9876", "98" };
	vector<string> test5 = { "abc", "def", "ghk" };
	cout << CommonPrefix(test1) << "\n"
		<< CommonPrefix(test2) << "\n"
		<< CommonPrefix(test3) << "\n"
		<< CommonPrefix(test4) << "\n"
		<< CommonPrefix(test5);
}