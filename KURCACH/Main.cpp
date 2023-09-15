#include "iostream"
#include "iomanip"
#include "Users.h"
#include "Main.h"
#include "Utilits.h"
#include "Admin.h"
#include "fstream"
#include "Windows.h"
#include "string"
#include "vector"
using namespace std;

void Main::firstrun()
{
	accentPrint("Добро пожаловать!!!");
	cout << "Это первый запуск программы\n"
		"Сейчас пройдет регистрация администратора\n"
		"Введите логин: ";
	string login; cin >> login;
	cout << "Введите пароль: ";
	string password; password = hiddenInput();
	ofstream file(pathtoFILE_OF_DATA);
	this->login = login;
	this->password = password;
	this->role = 1;
	file << login << endl;
	file << password << endl;
	file << role << endl;
	file.close();
	system("cls");
}

void Main::welcome()
{
	accentPrint("Добро пожаловать!!!");
	int k = -1;
	bool byadmin = false;
	while (k != 0)
	{	
		cout << "1) Вход\n"
			"2) Зарегистрироваться\n";
		print();
		cout << "\t\tНажмите 0, если хотите выйти из приложения\n";
		protection(0, 2, k);
		switch (k)
		{
		case 1:entrance(); break;
		case 2:registration(); break;
		}
	}
}

void Main::entrance()
{
	string name_of_player, last_name_of_player, date_of_birth;
	int  amount_of_playing_matches = 0, goles = 0, assists = 0, yellow_card = 0, red_card = 0;
	ifstream file(pathtoFILE_OF_DATA);
	int role = -1;
	string login, password, data;
	bool acsess = false;
	if (!file.is_open())
		firstrun();
	else
	{
		accentPrint("ВХОД");
		do
		{
			cout << "Введите логин: ";
			cin >> login;
			cout << "Введите пароль: ";
			password = hiddenInput();
			data = login + "\n" + password;
			proof(data, acsess);
			if (acsess == false)
			{
				accentPrint("Неверный логин или пароль!!! Повторите попытку");
			}
		} while (acsess==false);
		Admin admin(pathtoFILE_OF_DATA, pathtoFILE_OF_CLUB, login);
		User user(pathtoFILE_OF_DATA, pathtoFILE_OF_CLUB, login);
		trueadmin(data, role);
		if (role == 1)
			admin.work_with();
		else if (role == 0)
			user.user_menu();
		else
			accentPrint("Ждите когда админ вас авторизует!!!");
	}
	file.close();
}

void Main::registration()
{
	accentPrint("Регистрация");
	ofstream file(pathtoFILE_OF_DATA, ios::app);
	string login, password1, password2;
	int role = 2;
	bool acsess = true;
	do
	{
		cout << "Введите логин: ";
		cin >> login;
		truelogin(login, acsess);
		if (login.length() < 5 || login.length() > 15)
		{
			acsess = true;
			cout << "Логин должен состоять минимум из 5 символов и максимум из 15!!!" << endl;
		}
	} while (acsess == true);
	do
	{
		cout << "Введите новый пароль: ";
		password1 = hiddenInput();
		cout << "Повторите пароль: ";
		password2 = hiddenInput();
		if (password1 != password2)
			cout << "Неверный пароль, повторите попытку!!!" << endl;
		if (password1.length() < 5 || password1.length() > 15)
			cout << "Пароль должен быть не менее 5 символов и не более 15!!!" << endl;
	} while (password1 != password2|| password1.length() < 5 || password1.length() > 15);
	this->login = login;
	this->password = password1;
	file << login << endl;
	file << password << endl;
	file << role << endl;
	file.close();
	system("cls");
	accentPrint("Как только администратор одобрит вашу заявку, вы сможете войти!!!");
}

void Main:: start()
{
	welcome();
}

Main::Main(string pathtoFILE_OF_DATA,string pathtoFILE_OF_CLUB)
{
	this->pathtoFILE_OF_DATA = pathtoFILE_OF_DATA;
	this->pathtoFILE_OF_CLUB = pathtoFILE_OF_CLUB;
}

void Main::proof(string& data,bool& acsess)
{
	ifstream file(pathtoFILE_OF_DATA);
	amount_users();
	for (int i = 0; i < amountusers; i++)
	{
		view_users(file);
		if (data == login + "\n" + password)
		{
			acsess = true;
		}
	}
	file.close();
}

void Main::truelogin(string truelogin,bool&acsess)
{
	ifstream file(pathtoFILE_OF_DATA);
	amount_users();
	for (int i = 0; i < amountusers; i++)
	{
		view_users(file);
		if (truelogin == login)
		{
			cout << "Такой логин уже существует, попробуйте другой!!!" << endl;
			acsess = true;
			break;
		}
		else 
			acsess = false;
	}
	file.close();
}

void Main::trueadmin(string data, int& role1)
{
	ifstream file(pathtoFILE_OF_DATA);
	amount_users();
	cout << amountusers << endl;
	for (int i = 0; i < amountusers; i++)
	{
		view_users(file);
		if (data == login + "\n" + password)
		{
			if (role == 1)
				role1 = 1;
			else if (role == 0)
				role1 = 0;
			else if (role == 2)
				role1 = 2;
		}
	}
	file.close();
}

void Main::amount_users()
{
	ifstream file(pathtoFILE_OF_DATA);
	i = 0;
	while (getline(file,login))
	{
		i++;
	}
	amountusers = i / 3;
}

void Main::view_users(ifstream& file)
{
	file >> login;
	file >> password;
	file >> role;
}

void Main::watch()
{
	ifstream file(pathtoFILE_OF_DATA);
	amount_users();
	int g = 0;
	string role1;
	cout << setw(9) << "Логин:" << setw(5) << "\u00A6" << setw(15) << "Авторизация:" << endl;
	print();
	for (int i = 0; i < amountusers; i++)
	{
		view_users(file);
		if (role == 1)
			role1 = "Администратор";
		else if (role == 0)
			role1 = "Пользователь(Авторизован)";
		else
			role1 = "Пользователь(Не авторизован)";
		cout << ++g << ") " << login <<right<< setw(6) << "\u00A6" << setw(10) << role1 << endl;
		print();
	}
	file.close();
}

void Main::unusers(int step,int& f)
{
	ifstream file(pathtoFILE_OF_DATA);
	amount_users();
	int g = 0;
	for (int i = 0; i < amountusers; i++)
	{
		view_users(file);
		if (step == 0)
		{
			if (role == 0 || role == 2)
			{
				cout <<++g<<") "<< login << endl;
			}
		}
		else if (step == 2)
		{
			if (role == 2)
			{
				cout << "---- " << login << endl;
				f++;
			}
		}
	}
	file.close();
}