#include <iostream>
using namespace std;

int main() {
    setlocale(0, "");
    int choice;
    int type;
    int size;
    int shir;
    char texture;

    cout << "Программа - \"Геометрические фигуры\"\n\n";
    cout << "1) Линия\n";
    cout << "2) Квадрат\n\n";
    cout << "Выберите фигуру: ";
    cin >> choice;

    if (choice == 1) {
        cout << "\n\nФигура: \"Линия\"\n\n";
        cout << "\nРазмер: ";
        cin >> size;
        cout << "Текстура: ";
        cin >> texture;


        for (int i = 0; i < size; i++) {
            cout << texture << " ";
        }
        cout << "\n";
    }




    else if (choice == 2) {
        cout << "\n\nФигура: \"Квадрат\"\n\n";
        cout << "1) Заполненный\n";
        cout << "2) Пустой\n\n";
        cout << "Выберите тип: ";
        cin >> type;

        cout << "\nРазмер: ";
        cin >> size;
        cout << "Текстура: ";
        cin >> texture;

        cout << "\n\nРезультат:\n\n";

        if (type == 1) {

            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    cout << texture << " ";
                }
                cout << "\n";
            }
        }
        else if (type == 2) {

            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    if (i == 0 || i == size - 1 || j == 0 || j == size - 1) {
                        cout << texture << " ";
                    }
                    else {
                        cout << "  ";
                    }
                }
                cout << "\n";
            }
        }
    }
    else if (choice == 3) {
        cout << "\n\nФигура: \"Прямогуольник\"\n\n";
        cout << "1) Заполненный\n";
        cout << "2) Пустой\n\n";
        cout << "Выберите тип: ";
        cin >> type;

        cout << "\nВысота: ";
        cin >> size;
        cout << "\nШирина: ";
        cin >> shir;
        cout << "\nТекстура: ";
        cin >> texture;

        cout << "\n\nРезультат:\n\n";

        if (type == 1) {

            for (int i = 0; i < size; i++) {
                for (int j = 0; j < shir; j++) {
                    cout << texture << " ";
                }
                cout << "\n";
            }
        }
    else if (type == 2) {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < shir; j++) {
                if (i == 0 || i == size - 1 || j == 0 || j == shir - 1) {
                    cout << texture << " ";
                    }
                    else {
                        cout << "  ";
                    }
                }
                cout << "\n";
            }
        }
    }

    return 0;
}
        
