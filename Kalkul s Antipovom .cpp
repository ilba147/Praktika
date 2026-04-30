#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    srand(time(0));

    const int SIZE = 5;
    double arr[SIZE];

 
    cout << "--- Инициализация массива ---" << endl;
    cout << "Введите " << SIZE << " чисел для заполнения массива:\n";
    for (int i = 0; i < SIZE; i++) {
        cout << "Элемент " << i + 1 << ": ";
        cin >> arr[i];
    }
    cout << "\n";

  
    for (int i = 0; i < SIZE; i++) {
        double num = arr[i];

        
        cout << " | Таблица: " << i + 1 << "\n";
        cout << " -----------------------------------------------------\n";
        cout << " |     Число     |       Пример        |  Результат  |\n";
        cout << " -----------------------------------------------------\n";

      
        for (int j = 0; j < 4; j++) {
            double result = 0;
            char op = '+';

         
            if (j == 0) {
                result = num + num;
                op = '+';
            }
            else if (j == 1) {
                result = num - num;
                op = '-';
            }
            else if (j == 2) {
                if (num != 0) {
                    result = num / num;
                }
                else {
                    result = 0; 
                }
                op = '/';
            }
            else if (j == 3) {
                result = num * num;
                op = '*';
            }

            
            cout << " | " << setw(7) << num << "       | "
                << setw(6) << num << " " << op << " " << left << setw(7) << num << right
                << " | " << setw(5) << result << "       |\n";

            cout << " -----------------------------------------------------\n";
        }
        cout << "\n";
    }

    return 0;
}
