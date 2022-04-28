#include <iostream>					//����������� ����������
#include <stdlib.h>					//���������� ��� ������������
#include <time.h>					//���������� ��� ������������
#include <algorithm>				//������������ ���� � ����������� ���������� ����� ���������������� C++, ���������� ����� ������� ��� ���������� ��������������� �������� ��� ������������ � ��� ������� ��������������������. ��� ������� ���������� ����������� � ������������ ��� std
#include <string>					//���������� ��� �����

using namespace std;

int random(int n, int m);

int wordLength(string str);

int main() {
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	int n, m;
	string str;
	//������ 1
	try {
		cout << "������ 1\n������� �������� �����: ";
		cin >> n >> m;
		cout << "��������� �����, ��������� ���� ��������� = " << random(n, m) << endl << endl;
	}
	catch (const invalid_argument& ex) {
		cout << "������: " << ex.what() << endl << endl;
	}
	cin.ignore();

	//������ 2
	try {
		cout << "������ 2\n������� ����� � ��� ������ � ����� ���������: ";
		getline(cin, str);
		cout << "���������: " << wordLength(str) << endl << endl;
	}
	catch(const runtime_error &ex) {
		cout << "Runtime error: " << ex.what() << endl << endl;
	}

	return 0;
}

int wordLength(string str) {
	int count = 0;
	if (str == " ")
		throw runtime_error("������ ������� ������ ������!");
	if (str[0] == 0)
		throw runtime_error("�� ������ �� �����!");
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == ' ')
			count++;
		if (count > 1)
			throw runtime_error("������� ����� ��������!");
	}
	if (count < 1)
		throw runtime_error("�� �� ��������� �� ������ �������!");
	
	size_t first = str.find_first_of("0123456789");
	size_t last = str.find_last_of("0123456789");
	//if(first && last)																//�� ���� ����� �������, ���� ������������ ������ �������� �����, ������ � ������ ������
	//	throw runtime_error("�� ������� �������� ������ �����");					//(����������� �������������� ����������...)
	string num = str.substr(first, (last - first) + 1);
	int str_size = str.find(" ");
	int newNum = stoi(num);
	if (newNum == str_size)
		return true;
	return false;
}

int random(int n, int m) {
	if (n == m)
		throw invalid_argument("�������� ����� �� ������ ���������!");
	if (n > m)
		throw invalid_argument("������ ��������� �� ����� ���� ������, ��� ����� ���������!");
	return rand() % (m - n) + n;

}







	
	