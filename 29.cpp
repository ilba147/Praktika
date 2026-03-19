#include <iostream>
#include  <cmath>

using namespace std;

void add() {
	double a, b;
	cout << "Введите 2 числа: ";
	cin >> a >> b;
	cout << "+ Результат:" << a + b << endl;
}
void substract() {
	double a, b;
	cout << "Введите 2 числа: ";
	cin >> a >> b;
	cout << "- Результат:" << a - b << endl;
}
void multiply() {
	double a, b;
	cout << "Введите 2 числа: ";
	cin >> a >> b;
	cout << "* Результат:" << a * b << endl;
}
void divide() {
	double a, b;
	cout << "Введите 2 числа: ";
	cin >> a >> b;
	if (b == 0) {
		cout << "Делить на 0 нельзя!" << endl;
	}
	else {
		cout << "/ Результат:" << a / b << endl;
	}
}
void remainder() {
	int a, b;
	cout << "Введите 2 числа: ";
	cin >> a >> b;
	if (b == 0) {
		cout << "Делить на 0 нельзя!" << endl;
	}
	else {
		cout << "% Остаток:" << a % b << endl;
	}
}
void power() {
	double a, b;
	cout << "Введите 2 числа: ";
	cin >> a >> b;
	cout << "^2 Результат:" << pow(a, b) << endl;
}
void squareRoot() {
	double a;
	cout << "Введите число: ";
	cin >> a;
	if (a < 0) {
		cout << " Корень из отрицательного числа!" << endl;
	}
	cout << "sqrt Результат:" << sqrt(a) << endl;
}
void cube() {
	double a;
	cout << "Введите число: ";
	cin >> a;
	cout << "^3 Результат:" << pow(a, 3) << endl;
}
void sine() {
	double a;
	cout << "Введите угол в радианах: ";
	cin >> a;
	cout << "sin Результат:" << sin(a) << endl;
}
void cosine() {
	double a;
	cout << "Введите угол в радианах: ";
	cin >> a;
	cout << "cos Результат:" << cos(a) << endl;
}
int main() {
	setlocale(0, "");

	int choice;

	while (true) {
		cout << "\nКАЛЬКУЛЯТОР" << endl;
		cout << "1. Сложить" << endl;
		cout << "2. Вычесть" << endl;
		cout << "3. Умножить" << endl;
		cout << "4. Делить" << endl;   
		cout << "5. Остаток" << endl;
		cout << "6. Степень" << endl;
		cout << "7. Корень" << endl;
		cout << "8. Куб" << endl;
		cout << "9. Синус" << endl;
		cout << "10. Косинус" << endl;
		cout << "0. Выход" << endl;
		cout << "Выберите операцию: ";
		cin >> choice;

		if (choice == 0) break;

		switch (choice) {
		case 1: add(); break;
		case 2: substract(); break;
		case 3: multiply(); break;
		case 4: divide(); break;
		case 5: remainder(); break;
		case 6: power(); break;
		case 7: squareRoot(); break;
		case 8: cube(); break;
		case 9: sine(); break;
		case 10: cosine(); break;
		default: cout << "Неверный выбор!" << endl;
		}
	}
	cout << "Программа завершена" << endl;
	return 0;
}
