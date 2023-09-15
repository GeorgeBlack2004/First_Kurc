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
	accentPrint("ДОБРО ПОЖАЛОВАТЬ В СТАТИСТИЧЕСКОЕ ПРИЛОЖЕНИЕ ФК БАРСЕЛОНА");
	Admin admin(pathtoFILE_OF_DATA, pathtoFILE_OF_CLUB, login);
	while (step != "6")
	{
		cout << "\tВыберете нужную вам функцию\n"
			"\t\t1) - просмотр данных о всех игроках клуба\n"
			"\t\t2) - показать топ-6 лучших игроков и игроков с красными карточками\n"
			"\t\t3) - поиск нужной информации\n"
			"\t\t4) - сортировки\n"
			"\t\t5) - результаты команды\n"
			"\t\t6) - покинуть страницу работы с данными клуба Барселона\n";
		cout << "Ваш выбор: ";
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
			accentPrint("Добро пожаловать!!!");
		else
			accentPrint("Такой команды нету, попробуйте еще раз!");
	}
}

void User::sort()
{
	Admin admin(pathtoFILE_OF_DATA, pathtoFILE_OF_CLUB, login);
	accentPrint("По чем вы хотите отсортировать игроков");
	cout << "\t\t1) - по фамилии\n"
		"\t\t2) - по количеству сыгранных матчей\n"
		"\t\t3) - по гол+пас\n"
		"\t\t4) - по количеству желтых карточек\n"
		"\t\t5) - по количеству красных карточек\n"
		"\t\t0) - выйти\n";
	cout << "\tВаш выбор: ";
	protection(0, 5, var);
	if (var == 1)
	{
		admin.sort_pres(1);
		accentPrint("СОРТИРОВКА ЗАВЕРШЕНА");
	}
	else if (var == 2)
	{
		admin.sort_pres(2);
		accentPrint("СОРТИРОВКА ЗАВЕРШЕНА");
	}
	else if (var == 3)
	{
		admin.sort_pres(3);
		accentPrint("СОРТИРОВКА ЗАВЕРШЕНА");
	}
	else if (var == 4)
	{
		admin.sort_pres(4);
		accentPrint("СОРТИРОВКА ЗАВЕРШЕНА");
	}
	else if (var == 5)
	{
		admin.sort_pres(5);
		accentPrint("СОРТИРОВКА ЗАВЕРШЕНА");
	}
	else if (var == 0)
		accentPrint("ДОБРО ПОЖАЛОВАТЬ В СТАТИСТИЧЕСКОЕ ПРИЛОЖЕНИЕ ФК БАРСЕЛОНА");
}

User::User(string pathtoFILE_OF_DATA, string pathtoFILE_OF_CLUB, string login)
{
	this->pathtoFILE_OF_DATA = pathtoFILE_OF_DATA;
	this->pathtoFILE_OF_CLUB = pathtoFILE_OF_CLUB;
	this->login = login;
}