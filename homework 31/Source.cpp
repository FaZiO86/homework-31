#include <iostream>					//стандартная библиотека
#include <stdlib.h>					//библиотека для рандомайзера
#include <time.h>					//библиотека для рандомайзера
#include <algorithm>				//заголовочный файл в стандартной библиотеке языка программирования C++, включающий набор функций для выполнения алгоритмических операций над контейнерами и над другими последовательностями. Все функции библиотеки расположены в пространстве имён std
#include <string>					//Библеоткеа для строк

using namespace std;

int random(int n, int m);

int wordLength(string str);

int main() {
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	int n, m;
	string str;
	//Задача 1
	try {
		cout << "Задача 1\nВведите диапазон чисел: ";
		cin >> n >> m;
		cout << "Случайное число, введённого вами диапазона = " << random(n, m) << endl << endl;
	}
	catch (const invalid_argument& ex) {
		cout << "Ошибка: " << ex.what() << endl << endl;
	}
	cin.ignore();

	//Задача 2
	try {
		cout << "Задача 2\nВведите слово и его длинну в одном сообщении: ";
		getline(cin, str);
		cout << "Результат: " << wordLength(str) << endl << endl;
	}
	catch(const runtime_error &ex) {
		cout << "Runtime error: " << ex.what() << endl << endl;
	}

	return 0;
}

int wordLength(string str) {
	int count = 0;
	if (str == " ")
		throw runtime_error("Нельзя ставить пробел первый!");
	if (str[0] == 0)
		throw runtime_error("Вы ничего не ввели!");
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == ' ')
			count++;
		if (count > 1)
			throw runtime_error("Слишком много пробелов!");
	}
	if (count < 1)
		throw runtime_error("Вы не поставили ни одного пробела!");
	
	size_t first = str.find_first_of("0123456789");
	size_t last = str.find_last_of("0123456789");
	//if(first && last)																//не могу найти решение, если пользователь вводит допустим слово, пробел и ничего больше
	//	throw runtime_error("Не найдено значение длинны слова");					//(срабатывает необработанное исключение...)
	string num = str.substr(first, (last - first) + 1);
	int str_size = str.find(" ");
	int newNum = stoi(num);
	if (newNum == str_size)
		return true;
	return false;
}

int random(int n, int m) {
	if (n == m)
		throw invalid_argument("Диапазон чисел не должен равняться!");
	if (n > m)
		throw invalid_argument("Начало диапазона не может быть больше, чем конец диапазона!");
	return rand() % (m - n) + n;

}







	
	