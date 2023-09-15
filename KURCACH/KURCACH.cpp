#include "iostream"
#include"Main.h";
#include "Windows.h"
using namespace std;

const string FILE_OF_DATA = "Data of accounts.txt";
const string FILE_OF_CLUB = "Data of club.txt";

int main()
{
	setlocale(LC_ALL, "RUS");
	HWND hWnd = GetForegroundWindow();
	ShowWindow(hWnd, SW_MAXIMIZE);
	Main app(FILE_OF_DATA,FILE_OF_CLUB);
	app.start();
	system("pause");
}