#include "iostream"
#include "Admin.h"
#include "Utilits.h"
#include "string"
#include "Users.h"
#include "Main.h"
#include "fstream"
#include "vector"
using namespace std;

void User::user_menu()
{
	accentPrint("����� ���������� � �������������� ���������� �� ���������");
	Admin admin(pathtoFILE_OF_DATA, pathtoFILE_OF_CLUB, login);
	while (step != "6")
	{
		cout << "\t�������� ������ ��� �������\n"
			"\t\t1) - �������� ������ � ���� ������� �����\n"
			"\t\t2) - �������� ���-6 ������ ������� � ������� � �������� ����������\n"
			"\t\t3) - ����� ������ ����������\n"
			"\t\t4) - ����������\n"
			"\t\t5) - ���������� �������\n"
			"\t\t6) - �������� �������� ������ � ������� ����� ���������\n";
		cout << "��� �����: ";
		cin >> step;
		if (step == "1")
			admin.watch_players(0);
		else if (step == "2")
			admin.individualtask();
		else if (step == "3")
			admin.search_player();
		else if (step == "4")
			sort();
		else if (step == "5")
			admin.watch_rezult();
		else if (step == "6")
			accentPrint("����� ����������!!!");
		else
			accentPrint("����� ������� ����, ���������� ��� ���!");
	}
}

void User::sort()
{
	Admin admin(pathtoFILE_OF_DATA, pathtoFILE_OF_CLUB, login);
	accentPrint("�� ��� �� ������ ������������� �������");
	cout << "\t\t1) - �� �������\n"
		"\t\t2) - �� ���������� ��������� ������\n"
		"\t\t3) - �� ���+���\n"
		"\t\t4) - �� ���������� ������ ��������\n"
		"\t\t5) - �� ���������� ������� ��������\n"
		"\t\t0) - �����\n";
	cout << "\t��� �����: ";
	protection(0, 5, var);
	if (var == 1)
	{
		admin.sort_pres(1);
		accentPrint("���������� ���������");
	}
	else if (var == 2)
	{
		admin.sort_pres(2);
		accentPrint("���������� ���������");
	}
	else if (var == 3)
	{
		admin.sort_pres(3);
		accentPrint("���������� ���������");
	}
	else if (var == 4)
	{
		admin.sort_pres(4);
		accentPrint("���������� ���������");
	}
	else if (var == 5)
	{
		admin.sort_pres(5);
		accentPrint("���������� ���������");
	}
	else if (var == 0)
		accentPrint("����� ���������� � �������������� ���������� �� ���������");
}

User::User(string pathtoFILE_OF_DATA, string pathtoFILE_OF_CLUB, string login)
{
	this->pathtoFILE_OF_DATA = pathtoFILE_OF_DATA;
	this->pathtoFILE_OF_CLUB = pathtoFILE_OF_CLUB;
	this->login = login;
}