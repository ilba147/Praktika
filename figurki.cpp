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
    cout << "2) Квадрат\n";
    cout << "3) Прямоугольник\n";
    cout << "4) Крест\n";
    cout << "5) Плюс\n";
    cout << "6) Квадрат 1/4\n";
    cout << "7) Квадрат цветной 4/4\n\n";
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
        cout << "\n\nФигура: \"Прямоугольник\"\n\n";
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

    else if (choice == 4) {
        cout << "\n\nФигура: \"Крест\"\n\n";
        cout << "Размер (нечетное число): ";
        cin >> size;
        cout << "Текстура: ";
        cin >> texture;

        cout << "\n\nРезультат:\n\n";

        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if ((i == j) || ((size - 1 - i) == j)) {
                    cout << texture << " ";
                }
                else {
                    cout << "  ";
                }
            }
            cout << "\n";
        }

    }
    else if (choice == 5) {
        cout << "\n\nФигура: \"Плюс\"\n\n";
        cout << "Размер (нечётное число): ";
        cin >> size;
        cout << "Текстура: ";
        cin >> texture;

        cout << "\n\nРезультат:\n\n";

        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                if (j == size / 2 || i == size / 2)
                    cout << texture << " ";
                else
                    cout << "  ";
            }
            cout << endl;
        }
    }
    else if (choice == 6) {
        cout << "1) Заполненный\n";
        cout << "2) Пустой\n\n";
        cout << "Выберите тип: ";
        cin >> type;
        cout << "\nРазмер: ";
        cin >> size;
        cout << "Текстура:";
        cin >> texture;       
        if (type == 1) {
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    if (i == 0 || i == size - 1 || j == 0 || j == size - 1) {
                        cout << texture << " ";
                    }
                    else if (j == size / 2 || i == size / 2)
                        cout << texture << " ";
                    else if (i >= size / 2 && j >= size / 2) {
                        cout << texture << " ";
                    }
                    else {
                        cout << "  ";
                    }

                }
                cout << "\n";
            }
        }
        if (type == 2) {
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    if (i == size - 1 && j >= size / 2) {
                        cout << texture << " ";
                    }
                    else if (j == size - 1 && i >= size / 2) {
                        cout << texture << " ";
                    }
                    else if (i >= size / 2 && j >= size / 2) {
                        if (i == size / 2 || j == size - 1 || j == size / 2 || j == size - 1) {
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
        else if (choice == 7) {
            cout << "\nРазмер: ";
            cin >> size;
            cout << "Текстура стен:";
            cin >> texture;
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    if (i == 0 || i == size - 1 || j == 0 || j == size - 1) {
                        cout << texture << " ";
                    }
                    else if (j == size / 2 || i == size / 2)
                        cout << texture << " ";
                    else if (i >= size / 2 && j >= size / 2) {
                        cout << "\x1b[91m#\x1b[0m" << " ";
                    }
                    else if (i <= size / 2 && j <= size / 2) {
                        cout << "\x1b[92m#\x1b[0m" << " ";
                    }
                    else if (i <= size / 2 && j >= size / 2) {
                        cout << "\x1b[93m#\x1b[0m" << " ";
                    }
                    else if (i >= size / 2 && j <= size / 2) {
                        cout << "\x1b[94m#\x1b[0m" << " ";
                    }

                    else {
                        cout << "  ";
                    }

                }
                cout << "\n";
            }
        }


        return 0;
    }
}
