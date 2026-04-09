#include <iostream>
#include <Windows.h>
using namespace std;
int main() {
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);
	int a = 1;
	int swap = 0;
	int top10[10] = { 5, 3, 10, 50, -3, -50, 100, 10, 9, 0 };
	while (a > 0) {
		a = 0;
		for (int i = 0; i < 9; i++) {
			if (top10[i] < top10[i + 1]) {
				swap = top10[i];
				top10[i] = top10[i + 1];
				top10[i + 1] = swap;
				a++;
			}
		}
	}
	cout << "Массив: ";
	for (int i = 0; i < 10; i++) {
		cout << top10[i] << " ";
	}
	cout << endl;

	return 0;
}
