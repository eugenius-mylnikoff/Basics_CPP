/*
Вам даны координаты точек на плоскости. Выведите эти точки в порядке возрастания расстояний до начала координат.

Формат ввода:
Сначала задано количество точек "n".
Затем идет последовательность из "n" строк, каждая из которых содержит два целых числа - координаты точки.
Величина "n" не превосходит 100. Координаты точек по модулю не превосходят 1000.

Формат вывода:
Выведите через пробел координаты точек в порядке возрастания расстояний до начала координат.
После каждой пары координат печатайте перевод строки.
*/

#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

struct Point {
	int x;
	int y;
};

int main() {
	size_t n;
	cin >> n;

	vector<Point> points(n);
	for (size_t i = 0; i != n; ++i) {
		cin >> points[i].x >> points[i].y;
	}

	sort(
		points.begin(),
		points.end(),
		[](const Point& p1, const Point& p2) {
			return pow(p1.x, 2) + pow(p1.y, 2) < pow(p2.x, 2) + pow(p2.y, 2);
		}
	);

	for (const auto& point : points) {
		cout << point.x << " " << point.y << "\n";
	}
}
