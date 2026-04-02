#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <algorithm>
#include <Windows.h>

using namespace std;

// Структура для игрока в таблице лидеров
struct PlayerScore {
    string name;
    int score;
};

// Сортировка: сначала самые высокие баллы
bool compareScores(const PlayerScore& a, const PlayerScore& b) {
    return a.score > b.score;
}

enum OpType { ADD, SUB, MUL, DIV, MIX };

struct GameSettings {
    OpType op = ADD;
    string getOpName() {
        switch (op) {
        case ADD: return "Сложение (+)";
        case SUB: return "Вычитание (-)";
        case MUL: return "Умножение (*)";
        case DIV: return "Деление (/)";
        case MIX: return "Микс (+, -, *, /)";
        default: return "";
        }
    }
};

// Функция сохранения в файл
void saveScore(string name, int score) {
    ofstream file("leaderboard.txt", ios::app);
    if (file.is_open()) {
        file << name << " " << score << endl;
        file.close();
    }
}

// Функция отображения таблицы
void showLeaderboard() {
    ifstream file("leaderboard.txt");
    vector<PlayerScore> scores;
    string name;
    int score;

    cout << "\n=== ТАБЛИЦА ЛИДЕРОВ ===" << endl;

    if (!file) {
        cout << "Таблица пока пуста. Будь первым!" << endl;
        return;
    }

    while (file >> name >> score) {
        scores.push_back({ name, score });
    }
    file.close();

    sort(scores.begin(), scores.end(), compareScores);

    for (size_t i = 0; i < scores.size() && i < 10; ++i) {
        cout << i + 1 << ". " << scores[i].name << " — " << scores[i].score << " очк." << endl;
    }
}

void startGame(GameSettings& settings) {
    int correct = 0;
    int errors = 0;
    const int MAX_ERRORS = 5;

    cout << "\n--- ИГРА НАЧАЛАСЬ! ---" << endl;

    while (errors < MAX_ERRORS) {
        int a = rand() % 100 + 1;
        int b = rand() % 100 + 1;
        OpType currentOp = (settings.op == MIX) ? static_cast<OpType>(rand() % 4) : settings.op;

        int correctAnswer;
        char opChar;

        switch (currentOp) {
        case ADD: correctAnswer = a + b; opChar = '+'; break;
        case SUB: if (a < b) swap(a, b); correctAnswer = a - b; opChar = '-'; break;
        case MUL: a = rand() % 12 + 1; b = rand() % 12 + 1; correctAnswer = a * b; opChar = '*'; break;
        case DIV: b = rand() % 10 + 1; a = b * (rand() % 10 + 1); correctAnswer = a / b; opChar = '/'; break;
        }

        cout << a << " " << opChar << " " << b << " = ";
        int userAnswer;
        if (!(cin >> userAnswer)) { // Защита от ввода букв
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        if (userAnswer == correctAnswer) {
            cout << "Верно!" << endl;
            correct++;
        }
        else {
            errors++;
            cout << "Ошибка! [" << errors << "/" << MAX_ERRORS << "]. Ответ: " << correctAnswer << endl;
        }
    }

    cout << "\nИгра окончена! Ваш результат: " << correct << endl;
    cout << "Введите ваше имя для таблицы: ";
    string name;
    cin >> name;
    saveScore(name, correct);
}

void showSettings(GameSettings& settings) {
    cout << "\n--- Настройки ---" << endl;
    cout << "1. Сложение\n2. Вычитание\n3. Умножение\n4. Деление\n5. Микс\nВыбор: ";
    int choice;
    cin >> choice;
    if (choice >= 1 && choice <= 5) settings.op = static_cast<OpType>(choice - 1);
}

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    srand(time(0));
    GameSettings settings;
    int choice;

    while (true) {
        cout << "\n1. Начать игру\n2. Настройки (" << settings.getOpName() << ")\n3. Таблица лидеров\n4. Выход\n>>> ";
        if (!(cin >> choice)) break;

        switch (choice) {
        case 1: startGame(settings); break;
        case 2: showSettings(settings); break;
        case 3: showLeaderboard(); break;
        case 4: return 0;
        }
    }
    return 0;
}
