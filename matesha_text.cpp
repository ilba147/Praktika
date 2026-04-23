ee971cba37ffffebfe11f6eb03533a9dcd7374617469632e766b2e636f6d
#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <algorithm>
#include <Windows.h>

using namespace std;

struct PlayerScore {
    string name;
    int score;
};

bool compareScores(const PlayerScore& a, const PlayerScore& b) {
    return a.score > b.score;
}

enum OpType { ADD, SUB, MUL, DIV, MIX };

struct GameSettings {
    OpType op = ADD;
    int difficulty = 1;

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

void saveScore(string name, int score) {
    ofstream file("leaderboard.txt", ios::app);
    if (file.is_open()) {
        file << name << " " << score << endl;
        file.close();
    }
}

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
        int a, b;
        
        if (settings.difficulty == 1) {
            a = rand() % 9 + 1;
            b = rand() % 9 + 1;
        } else if (settings.difficulty == 2) {
            a = rand() % 90 + 10;
            b = rand() % 90 + 10;
        } else {
            a = rand() % 900 + 100;
            b = rand() % 900 + 100;
        }

        OpType currentOp = (settings.op == MIX) ? static_cast<OpType>(rand() % 4) : settings.op;

        int correctAnswer;
        char opChar;

        switch (currentOp) {
        case ADD: 
            correctAnswer = a + b; 
            opChar = '+'; 
            break;
        case SUB: 
            if (a < b) swap(a, b); 
            correctAnswer = a - b; 
            opChar = '-'; 
            break;
        case MUL: 
            if (settings.difficulty == 2) b = rand() % 9 + 1;
            if (settings.difficulty == 3) b = rand() % 90 + 10;
            correctAnswer = a * b; 
            opChar = '*'; 
            break;
        case DIV: 
        {
            int multiplier;
            if (settings.difficulty == 1) multiplier = rand() % 9 + 1;
            else if (settings.difficulty == 2) multiplier = rand() % 20 + 1;
            else multiplier = rand() % 50 + 1;

            a = b * multiplier;
            correctAnswer = a / b;
            opChar = '/'; 
            break;
        }
        }

        cout << a << " " << opChar << " " << b << " = ";
        int userAnswer;
        if (!(cin >> userAnswer)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Пожалуйста, введите число!\n";
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

void showOpSettings(GameSettings& settings) {
    cout << "\n--- Настройки операции ---" << endl;
    cout << "1. Сложение\n2. Вычитание\n3. Умножение\n4. Деление\n5. Микс\nВыбор: ";
    int choice;
    if (cin >> choice && choice >= 1 && choice <= 5) {
        settings.op = static_cast<OpType>(choice - 1);
    } else {
        cin.clear(); cin.ignore(10000, '\n');
    }
}

void showDifficultySettings(GameSettings& settings) {
    cout << "\n--- Выбор сложности ---" << endl;
    cout << "1. Легкая (1-9)\n2. Средняя (10-99)\n3. Сложная (100-999)\nВыбор: ";
    int choice;
    if (cin >> choice && choice >= 1 && choice <= 3) {
        settings.difficulty = choice;
    } else {
        cin.clear(); cin.ignore(10000, '\n');
    }
}

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    srand(time(0));
    GameSettings settings;
    int choice;

    while (true) {
        cout << "\n=== ГЛАВНОЕ МЕНЮ ===" << endl;
        cout << "1. Начать игру\n";
        cout << "2. Тип примеров (" << settings.getOpName() << ")\n";
        cout << "3. Уровень сложности (Уровень " << settings.difficulty << ")\n";
        cout << "4. Таблица лидеров\n";
        cout << "5. Выход\n>>> ";
        
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        switch (choice) {
        case 1: startGame(settings); break;
        case 2: showOpSettings(settings); break;
        case 3: showDifficultySettings(settings); break;
        case 4: showLeaderboard(); break;
        case 5: return 0;
        default: cout << "Неверный ввод!\n"; break;
        }
    }
    return 0;
}
