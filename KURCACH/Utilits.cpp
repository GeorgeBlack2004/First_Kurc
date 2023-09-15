#include"iostream"
#include"Utilits.h"
#include"Windows.h"
#include"conio.h"
using namespace std;

int protection(int a, int b, int& n)
{
	cin >> n;
	while (true)
	{
		while ((!cin) || (cin.get() != '\n'))
		{
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "Некорректное значение. Повторите ввод!" << endl;
			cin >> n;
		}
		if (n >= a && n <= b) break;
		cout << "Возникла ошибка! Повторите ввод." << endl;
		cin >> n;
	}
	return n;
}

int getConsoleWidth() {
	HANDLE hWndConsole = GetStdHandle(-12);
	CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
	GetConsoleScreenBufferInfo(hWndConsole, &consoleInfo);
	return consoleInfo.srWindow.Right - consoleInfo.srWindow.Left + 1;
}

void accentPrint(string text) 
{
	system("cls");
	cout << " ====== " << text << " ";
	for (int i = 11 + text.size(); i < getConsoleWidth(); i++)
		cout << '=';
	cout << endl;
}

void accent(string text)
{
	cout << " ====== " << text << " ";
	for (int i = 11 + text.size(); i < getConsoleWidth(); i++)
		cout << '=';
	cout << endl;
}

void print() 
{
	for (int i = 0; i < getConsoleWidth(); i++)
		cout << '_';
	cout << endl;
}

string hiddenInput() {
	string result; char ch;
	while (true) {
		ch = _getch();
		if (ch == '\r') break;
		if (ch == '\b') {
			if (result != "") {
				cout << "\b \b";
				result.pop_back();
			}
			continue;
		}
		result += ch;
		cout << '*';
	}
	cout << "\n";
	return result;
}