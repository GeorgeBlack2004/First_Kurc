#include "iostream"
#include "Admin.h"
#include "Utilits.h"
#include "string"
#include "Users.h"
#include "Main.h"
#include "fstream"
#include "vector"

using namespace std;

void Admin::work_with()
{
	int k = -1;
	Main main(pathtoFILE_OF_DATA, pathtoFILE_OF_CLUB);
	accentPrint("� ��� �� ������ ���������� ������: ");
	cout << "\t\t1) � �������� ��������\n"
		"\t\t2) � ������� ����������� ����� ���������\n";
	protection(1, 2, k);
	switch (k)
	{
	case 1:work_with_userlist(); break;
	case 2:work_with_data_of_club(); break;
	}
}

void Admin::work_with_userlist()
{		
	accentPrint("������ � �������� ��������");
	while (command != "5")
	{
			cout << "\t�������� ������ ��� �������\n"
				"\t\t1) - �������� ���� �������������\n"
				"\t\t2) - ���������� ������ ������������\n"
				"\t\t3) - �������������� ������������\n"
				"\t\t4) - �������� ������������\n"
				"\t\t5) - �������� �������� ������ � �������� ��������\n";
			print();
			cout << "\tapp - ������� � ������ � ������� ����������� ����� ���������\n\n";
			cout << "��� �����: ";
			cin >> command;
			if (command == "1")
				watch_userlist();
			else if (command == "2")
				add_user();
			else if (command == "3")
				redact_user();
			else if (command == "4")
				delete_user();
			else if (command == "5")
				accentPrint("����� ����������!!!");
			else if (command == "app")
				work_with_data_of_club();
			else
				accentPrint("����� ������� ����, ���������� ��� ���!");
	}
}

void Admin::work_with_data_of_club()
{
	User user(pathtoFILE_OF_DATA, pathtoFILE_OF_CLUB, login);
	accentPrint("������ � ������� ����������� ����� ���������");
	while (command != "10")
	{
		cout << "\t�������� ������ ��� �������\n"
			"\t\t1) - �������� ������ � ���� ������� �����\n"
			"\t\t2) - ���������� ������ ������ � ������� �����\n"
			"\t\t3) - �������������� ���������� �� ������ � ��� ����������\n"
			"\t\t4) - �������� ������ �� ������� �����\n"
			"\t\t5) - �������� ���-6 ������ ������� � ������� � �������� ����������\n"
			"\t\t6) - ����� ������ ����������\n"
			"\t\t7) - ����������\n"
			"\t\t8) - �������� ��������� �������\n"
			"\t\t9) - ���������� �������\n"
			"\t\t10) - �������� �������� ������ � ������� ����� ���������\n"
			"\t\t11) - ������ � ������� ����������\n";
		print();
		cout << "\tusers - ������� � ������ � ������� �������������\n\n";
		cout << "��� �����: ";
		cin >> command;
		if (command == "1")
			watch_players(0);
		else if (command == "2")
			add_new_player();
		else if (command == "3")
			redact_player();
		else if (command == "4")
			delete_player();
		else if (command == "users")
			work_with_userlist();
		else if (command == "5")
			individualtask();
		else if (command == "6")
			search_player();
		else if (command == "7")
			user.sort();
		else if (command == "8")
			rezult();
		else if (command == "9")
			watch_rezult();
		else if (command == "10")
			accentPrint("����� ����������!!!");
		else if (command == "11")
			yellow();
		else
			accentPrint("����� ������� ����, ���������� ��� ���!");
	}
}

void Admin::yellow()
{
	accentPrint("������ � ������� ����������");
	int min = 0, max = -1;
	while (min > max)
	{
		cout << "������� �� ������� ������ �������� ����� ����: ";
		protection(0, 25, min);
		cout << "������� �� ������� ������ �������� ������ ����: ";
		protection(0, 25, max);
		if (max <= min)
			accentPrint("���������� ������ �������!!!");
	}
	amount(11, pathtoFILE_OF_CLUB);
	int g = 0;
	ifstream file(pathtoFILE_OF_CLUB);
	accentPrint("������ � ������� ����������");
	cout << "\t���, �������:" << "\t���� ��������:" << "\t���������� ��������� ������:" << "\t����:" << "\t   �������:" << "\t������ ��������:" << "\t������� ��������:" << "\t�������:" << endl;;
	print();
	for (int i = 0; i < amount_players; i++)
	{
		view_players(file);
		if (yellow_card >= min && yellow_card <= max)
		{
			cout << ++g << ")\t" << name_of_player << " " << last_name_of_player << "\t " << day << "." << month << "." << year << "\t\t   " << amount_of_playing_matches << "\t\t\t " << goles << "\t     " << assists << "\t\t\t" << yellow_card << "\t\t       " << red_card << "\t\t" << position << endl;
			print();
		}
	}
	file.close();
}

void Admin::add_new_player()
{
	accentPrint("���������� ������ ������");
	ofstream file(pathtoFILE_OF_CLUB, ios::app);
	cout << "������� ��� � ������� ������: ";
	cin >> name_of_player >> last_name_of_player;
	cout << "������� ���� �������� ������: ";
	protection(1, 31, day);
	cout << "������� ����� �������� ������: ";
	protection(1, 12, month);
	cout << "������� ��� �������� ������: ";
	protection(1970, 2006, year);
	cout << "������� ���������� ��������� ������, ����� � ��������: ";
	protection(0, 100000, amount_of_playing_matches);
	protection(0, 100000, goles);
	protection(0, 100000, assists);
	cout << "������� ���������� ������ � ������� ��������: ";
	protection(0, 100000, yellow_card);
	protection(0, 100000, red_card);
	cout << "�������� ������� ������:\n"
		"~~~1) Striker\n"
		"~~~2) Midfielder\n"
		"~~~3) Defender\n"
		"~~~4) Goalkeeper\n";
	int n = 0;
	protection(1, 4, n);
	if (n == 1)
		position = "Striker";
	else if (n == 2)
		position = "Midfielder";
	else if (n == 3)
		position = "Defender";
	else
		position = "Goalkeeper";
	file << name_of_player << endl;
	file << last_name_of_player << endl;
	file << day << endl;
	file << month << endl;
	file << year << endl;
	file << amount_of_playing_matches << endl;
	file << goles << endl;
	file << assists << endl;
	file << yellow_card << endl;
	file << red_card << endl;
	file << position << endl;
	file.close();
	accentPrint("����� ������� ��������!!!");
}

void Admin::watch_players(int index)
{
	accentPrint("������ ������� ����� <���������>");
	cout << endl;
	ifstream file(pathtoFILE_OF_CLUB);
	int g = 0;
	amount(11, pathtoFILE_OF_CLUB);
	if (amount_players == 0)
		cout << "������ ����!!!";
	else
	{
		if (index == 0)
		{
			cout << "\t���, �������:" << "\t���� ��������:" << "\t���������� ��������� ������:" << "\t����:" << "\t   �������:" << "\t������ ��������:" << "\t������� ��������:" << "\t�������:" << endl;;
			print();
			for (int i = 0; i < amount_players; i++)
			{
				view_players(file);
				cout << ++g << ")\t" << name_of_player << " " << last_name_of_player << "\t " << day<<"."<<month<<"."<<year << "\t\t   " << amount_of_playing_matches << "\t\t\t " << goles << "\t     " << assists << "\t\t\t" << yellow_card << "\t\t       " << red_card << "\t\t" << position << endl;
				print();
			}
		}
	}
	cout << "\n\n\n" << endl;
	file.close();
}

void Admin::delete_player()
{
	accentPrint("������ ������� ����� < ���������>");
	string login = "default", password = "default";
	watch_players(0);
	amount(11, pathtoFILE_OF_CLUB);
	if (amount_players == 0)
	{
		cout << "\n\n������ ����!!!\n\n" << endl;
	}
	else
	{
		int who = 0;
		cout << "������ ������ �� ������ �������: ";
		protection(1, amount_players, who);
		remove(--who, 11, pathtoFILE_OF_CLUB, login, password);
	}
	accentPrint("����� ������!!!");
}

void Admin::watch_userlist()
{
	accentPrint("������ �������������");
	Main main(pathtoFILE_OF_DATA, pathtoFILE_OF_CLUB);
	main.watch();
}

void Admin::add_user()
{
	accentPrint("������ ���������������� �������������");
	string login = "default", password = "default", whois;
	Main main(pathtoFILE_OF_DATA, pathtoFILE_OF_CLUB);
	int f = 0, n = 0;
	main.unusers(2, f);
	amount(3, pathtoFILE_OF_DATA);
	int who = 0;
	if (f == 0)
	{
		cout << "\n\n������ ����!!!\n\n" << endl;
	}
	else
	{
		do
		{
			cout << "������� ������������, �������� ������ ������������: ";
			cin >> whois;
		} while (!cin);
		ifstream file1(pathtoFILE_OF_DATA);
		for (int i = 0; i < amount_players; i++)
		{
			file1 >> this->login;
			file1 >> this->password;
			file1 >> role;
			if (this->login == whois)
			{
				who = i;
				n++;
				break;
			}
		}
		file1.close();
		if (n == 0)
		{
			accentPrint("������ ������������ ���� � ����!!!");
		}
		else
		{
			remove(who, 3, pathtoFILE_OF_DATA, login, password);
			ofstream file(pathtoFILE_OF_DATA, ios::app);
			file << login << endl;
			file << password << endl;
			file << "0" << endl;
			file.close();
			accentPrint("������������ ��������!!!");
		}
	}
}

void Admin::redact_user()
{
	accentPrint("������ �������������");
	Main main(pathtoFILE_OF_DATA, pathtoFILE_OF_CLUB);
	main.watch();
	amount(3, pathtoFILE_OF_DATA);
	int who = 0;
	cout << "������� ������������, �������� ������ ��������: ";
	protection(1, amount_players, who);
	redact(--who);
}

void Admin::redact_player()
{
	watch_players(0);
	amount(11, pathtoFILE_OF_CLUB);
	if (amount_players == 0)
	{
		cout << "\n\n������ ����!!!\n\n" << endl;
	}
	else
	{
		int who = 0;
		cout << "������� ����� ������ �������� ������ ���������������: ";
		protection(1, amount_players, who);
		redplayer(--who);
	}
}

void Admin::redplayer(int who)
{
	accentPrint("��� �� ������ ��������?");
	string info1 = "default", info2 = "default", info3 = "default", info4 = "default", info5 = "default", info6 = "default", info7 = "default", info8 = "default";
	cout << "\t\t1 - ���, �������, ���� �������� ������ � ������� ������\n"
		"\t\t2 - ���������� ������\n";
	cout << "\t��� �����: ";
	do
	{
		cin >> command;
		if (command == "1")
		{
			redmove_player(who, 0, info1, info2, info3, info4, info5, info6);
			add_redplayer(who, 0, info1, info2, info3, info4, info5, info6);
		}
		else if (command == "2")
		{
			redmove_player(who, 1, info1, info2, info3, info4, info5, info6);
			add_redplayer(who, 1, info1, info2, info3, info4, info5, info6);
		}
		else
		{
			cout << "\t������������ ����!!! ���������� ��� ���: ";
		}
	} while (command != "1" && command != "2");
}

void Admin::add_redplayer(int who, int rezult, string info1, string info2, string info3, string info4, string info5, string info6)
{
	accentPrint("��������������");
	ofstream file(pathtoFILE_OF_CLUB, ios::app);
	string name, last_name, matches, goles, assists, yelcard, redcard, position;
	int day, month, year;
	if (rezult == 0)
	{
		cout << "������� ��� � �������: ";
		cin >> name >> last_name;
		cout << "������� ���� �������� ������: ";
		protection(1, 31, day);
		cout << "������� ����� �������� ������: ";
		protection(1, 12, month);
		cout << "������� ��� �������� ������: ";
		protection(1970, 2015, year);
		cout << "�������� ������� ������:\n"
			"~~~1) Striker\n"
			"~~~2) Midfielder\n"
			"~~~3) Defender\n"
			"~~~4) Goalkeeper\n";
		int n = 0;
		protection(1, 4, n);
		if (n == 1)
			position = "Striker";
		else if (n == 2)
			position = "Midfielder";
		else if (n == 3)
			position = "Defender";
		else
			position = "Goalkeeper";
		file << name << endl;
		file << last_name << endl;
		file << day << endl;
		file << month << endl;
		file << year << endl;
		file << info1 << endl;
		file << info2 << endl;
		file << info3 << endl;
		file << info4 << endl;
		file << info5 << endl;
		file << position << endl;
	}
	else if (rezult == 1)
	{
		cout << "������� ���������� ������, �����, ��������, ������ � ������� ��������: ";
		cin >> matches >> goles >> assists >> yelcard >> redcard;
		file << info1 << endl;
		file << info2 << endl;
		file << info3 << endl;
		file << info4 << endl;
		file << info5 << endl;
		file << matches << endl;
		file << goles << endl;
		file << assists << endl;
		file << yelcard << endl;
		file << redcard << endl;
		file << info6 << endl;
	}
	file.close();
	accentPrint("������ ��������!!!");
}

bool Admin::redmove_player(size_t index, int rezult, string& info1, string& info2, string& info3, string& info4, string& info5, string& info6)
{
	int c = 0;
	vector<string> users;
	ifstream file(pathtoFILE_OF_CLUB);
	if (file.is_open())
	{
		string player;
		while (getline(file, player))
		{
			if (rezult == 0)
			{
				if (c == index * 11 + 5)
					info1 = player;
				if (c == index * 11 + 6)
					info2 = player;
				if (c == index * 11 + 7)
					info3 = player;
				if (c == index * 11 + 8)
					info4 = player;
				if (c == index * 11 + 9)
					info5 = player;
			}
			else if (rezult == 1)
			{
				if (c == index * 11)
					info1 = player;
				if (c == index * 11 + 1)
					info2 = player;
				if (c == index * 11 + 2)
					info3 = player;
				if (c == index * 11 + 3)
					info4 = player;
				if (c == index * 11 + 4)
					info5 = player;
				if (c == index * 11 + 10)
					info6 = player;
			}
			users.push_back(player);
			c++;
		}
		file.close();
		if (users.size() / 11 < index)
			return false;
		for (int i = 1; i < 12; i++)
		{
			users.erase(users.begin() + index * 11);
			ofstream outfile(pathtoFILE_OF_CLUB);
			if (outfile.is_open())
			{
				copy(users.begin(), users.end(),
					ostream_iterator<string>(outfile, "\n"));
				outfile.close();
			}
		}
		return true;
	}
	return false;
}

void Admin::redact(int who)
{
	accentPrint("��� �� ������ ��������?");
	string info1 = "default", info2 = "default";
	cout << "\t\t1) - ����� ������������\n"
		"\t\t2) - ������ ������������\n";
	cout << "\t��� �����: ";
	do
	{
		cin >> command;
		if (command == "1")
		{
			redact_user(who, 0, info1, info2);
			add_after_redact(info1, info2, 0);
		}
		else if (command == "2")
		{
			redact_user(who, 1, info1, info2);
			add_after_redact(info1, info2, 1);
		}
		else
		{
			cout << "\t������������ ����!!! ���������� ��� ���: ";
		}
	} while (command != "1" && command != "2");

}

void Admin::add_after_redact(string info1, string info2, int rezult)
{
	string login, password;
	ofstream file(pathtoFILE_OF_DATA, ios::app);
	if (rezult == 0)
	{
		cout << "������� ����� �����: ";
		cin >> login;
		file << login << endl;
		file << info1 << endl;
		file << info2 << endl;
	}
	else if (rezult == 1)
	{
		cout << "������� ����� ������: ";
		password = hiddenInput();
		file << info1 << endl;
		file << password << endl;
		file << info2 << endl;
	}
	file.close();
	accentPrint("������ ��������!!!");
}

bool Admin::redact_user(size_t index, int rezult, string& info1, string& info2)
{
	int c = 0;
	vector<string> users;
	ifstream file(pathtoFILE_OF_DATA);
	if (file.is_open())
	{
		string user;
		while (getline(file, user))
		{
			if (rezult == 0)
			{
				if (c == index * 3 + 1)
				{
					info1 = user;
				}
				if (c == index * 3 + 2)
				{
					info2 = user;
				}
			}
			else if (rezult == 1)
			{
				if (c == index * 3)
				{
					info1 = user;
				}
				if (c == index * 3 + 2)
				{
					info2 = user;
				}
			}
			users.push_back(user);
			c++;
		}
		file.close();
		if (users.size() / 3 < index)
			return false;
		for (int i = 1; i < 4; i++)
		{
			users.erase(users.begin() + index * 3);
			ofstream outfile(pathtoFILE_OF_DATA);
			if (outfile.is_open())
			{
				copy(users.begin(), users.end(),
					ostream_iterator<string>(outfile, "\n"));
				outfile.close();
			}
		}
		return true;
	}
	return false;
}

bool Admin::remove(size_t index, int amount, string pathto, string& login, string& password)
{
	vector<string> vector_user;
	int c = 0;
	ifstream file(pathto);
	if (file.is_open())
	{
		string user;
		while (getline(file, user))
		{
			if (c == index * 3)
			{
				login = user;
			}
			else if (c == index * 3 + 1)
			{
				password = user;
			}
			vector_user.push_back(user);
			c++;
		}
		file.close();
		if (vector_user.size() / amount < index)
			return false;
		for (int i = 1; i < amount + 1; i++)
		{		
			vector_user.erase(vector_user.begin() + index * amount);
			ofstream outfile(pathto);
			if (outfile.is_open())
			{
				copy(vector_user.begin(), vector_user.end(),
					ostream_iterator<string>(outfile, "\n"));
				outfile.close();
			}
		}
		return true;
	}
	return false;
}

void Admin::delete_user()
{
	accentPrint("������ �������������");
	string login = "default", password = "default";
	Main main(pathtoFILE_OF_DATA, pathtoFILE_OF_CLUB);
	int f = 0;
	main.unusers(0, f);
	amount(3, pathtoFILE_OF_CLUB);
	if (amount_players < 2)
	{
		cout << "\n\n������ ����!!!\n\n" << endl;
	}
	else
	{
		int who = 0;
		cout << "������ ������������ �� ������ �������: ";
		protection(1, amount_players, who);
		remove(who, 3, pathtoFILE_OF_DATA, login, password);
	}
}

Admin::Admin(string pathtoFILE_OF_DATA, string pathtoFILE_OF_CLUB, string login)
{
	this->pathtoFILE_OF_DATA = pathtoFILE_OF_DATA;
	this->pathtoFILE_OF_CLUB = pathtoFILE_OF_CLUB;
	this->login = login;
}

void Admin::amount(int amount,string pathto)
{
	string str;
	ifstream file(pathto);
	i = 0;
	while (getline(file,str))
	{
		i++;
	}
	amount_players = i / amount;
	file.close();
}

void Admin::search_player()
{
	accentPrint("����� ������");
	ifstream file(pathtoFILE_OF_CLUB);
	amount(11, pathtoFILE_OF_CLUB);
	if (amount_players == 0)
	{
		cout << "\n\n������ ����!!!\n\n" << endl;
	}
	else
	{
		cout << "\n�������� �����:\n"
			"\t1) �� �������\n"
			"\t2) �� �������\n"
			"\t3) �� ��������� ������\n";
		int n = 0, g = 0;
		protection(1, 3, n);
		switch (n)
		{
		case 1:
		{
			accentPrint("����� ������");
			string lastname;
			do
			{
				cout << "������� ������� ������, �������� ������ �����: ";
				cin >> lastname;
			} while (!cin);
			system("cls");
			cout << "\t���, �������:" << "\t���� ��������:" << "\t���������� ��������� ������:" << "\t����:" << "\t   �������:" << "\t������ ��������:" << "\t������� ��������:" << "\t�������:" << endl;;
			print();
			for (int i = 0; i < amount_players; i++)
			{
				view_players(file);
				if (lastname == last_name_of_player)
				{
					cout << ++g << ")\t" << name_of_player << " " << last_name_of_player << "\t " << day << "." << month << "." << year << "\t\t   " << amount_of_playing_matches << "\t\t\t " << goles << "\t     " << assists << "\t\t\t" << yellow_card << "\t\t       " << red_card << "\t\t" << position << endl;
					print();
				}
			}
			cout << "\n\n\n" << endl;
		}; break;
		case 2:
		{
			accentPrint("����� ������");
			string buf_position;
			cout << "������ ����� ������� �� ������ �����:\n"
				"\t1) Striker\n"
				"\t2) Midfielder\n"
				"\t3) Defender\n"
				"\t4) Goalkeeper\n";
			protection(1, 5, n);
			if (n == 1)
				buf_position = "Striker";
			else if (n == 2)
				buf_position = "Midfielder";
			else if (n == 3)
				buf_position = "Defender";
			else
				buf_position = "Goalkeeper";
			system("cls");
			cout << "\t���, �������:" << "\t���� ��������:" << "\t���������� ��������� ������:" << "\t����:" << "\t   �������:" << "\t������ ��������:" << "\t������� ��������:" << "\t�������:" << endl;;
			print();
			for (int i = 0; i < amount_players; i++)
			{
				view_players(file);
				if (buf_position == position)
				{
					cout << ++g << ")\t" << name_of_player << " " << last_name_of_player << "\t " << day << "." << month << "." << year << "\t\t   " << amount_of_playing_matches << "\t\t\t " << goles << "\t     " << assists << "\t\t\t" << yellow_card << "\t\t       " << red_card << "\t\t" << position << endl;
					print();
				}
			}
			cout << "\n\n\n" << endl;
		}; break;
		case 3:
		{
			accentPrint("����� ������");
			int pos_1 = 0, pos_2 = -1;
			cout << "������� ���������� ������, � �������� ����� �������� �����:\n";
			cout << "��: ";
			protection(0, 10000, pos_1);
			do
			{
				cout << "��: ";
				protection(0, 10000, pos_2);
				if (pos_2 < pos_1)
					cout << "������ �������� ������ ���� ������ �����������!!!" << endl;
			} while (pos_2 < pos_1);
			system("cls");
			cout << "\t���, �������:" << "\t���� ��������:" << "\t���������� ��������� ������:" << "\t����:" << "\t   �������:" << "\t������ ��������:" << "\t������� ��������:" << "\t�������:" << endl;;
			print();
			for (int i = 0; i < amount_players; i++)
			{
				view_players(file);
				if (pos_1 < amount_of_playing_matches && amount_of_playing_matches < pos_2)
				{
					cout << ++g << ")\t" << name_of_player << " " << last_name_of_player << "\t " << day << "." << month << "." << year << "\t\t   " << amount_of_playing_matches << "\t\t\t " << goles << "\t     " << assists << "\t\t\t" << yellow_card << "\t\t       " << red_card << "\t\t" << position << endl;
					print();
				}
			}
			cout << "\n\n\n" << endl;
		}; break;
		}
		if (g == 0)
			accentPrint("������ ������ ���� � ����� ����!!!");
	}
	file.close();
}

void Admin::individualtask()
{
	ifstream file(pathtoFILE_OF_CLUB);
	amount(11, pathtoFILE_OF_CLUB);
	if (amount_players == 0)
	{
		cout << "\n\n������ ����!!!\n\n" << endl;
	}
	else
	{
		the_best_players();
		accentPrint("������ � �������� ����������");
		cout << endl;
		int g = 0;
		cout << "\t���, �������:" << "\t���� ��������:" << "\t���������� ��������� ������:" << "\t����:" << "\t   �������:" << "\t������ ��������:" << "\t������� ��������:" << "\t�������:" << endl;;
		print();
		for (int i = 0; i < amount_players; i++)
		{
			view_players(file);
			if (red_card > 0)
			{
				cout << ++g << ")\t" << name_of_player << " " << last_name_of_player << "\t " << day << "." << month << "." << year << "\t\t   " << amount_of_playing_matches << "\t\t\t " << goles << "\t     " << assists << "\t\t\t" << yellow_card << "\t\t       " << red_card << "\t\t" << position << endl;
				print();
			}
		}
		cout << "\n\n\n" << endl;
	}
	file.close();
}

void Admin::the_best_players()
{
	ifstream file(pathtoFILE_OF_CLUB);
	accentPrint("���-6 ������ �������");
	amount(11, pathtoFILE_OF_CLUB);
	cout << endl;
	int g = 0;
	cout << "\t���, �������:" << "\t���� ��������:" << "\t���������� ��������� ������:" << "\t����:" << "\t   �������:" << "\t������ ��������:" << "\t������� ��������:" << "\t�������:" << endl;;
	print();
	sort_pres(3);
	for (int i = 0; i < 6; i++)
	{
		view_players(file);
		cout << ++g << ")\t" << name_of_player << " " << last_name_of_player << "\t " << day << "." << month << "." << year << "\t\t   " << amount_of_playing_matches << "\t\t\t " << goles << "\t     " << assists << "\t\t\t" << yellow_card << "\t\t       " << red_card << "\t\t" << position << endl;
		print();
	}
	system("pause");
	file.close();
}

void Admin::view_players(ifstream& file)
{
	file >> name_of_player;
	file >> last_name_of_player;
	file >> day;
	file >> month;
	file >> year;
	file >> amount_of_playing_matches;
	file >> goles;
	file >> assists;
	file >> yellow_card;
	file >> red_card;
	file >> position;
}

void Admin::sort_pres(int index)
{
	ifstream file(pathtoFILE_OF_CLUB);
	amount(11, pathtoFILE_OF_CLUB);
	if (amount_players == 0)
		cout << "������ ����!!!";
	else
	{
		Player* play = new Player[amount_players];
		for (int i = 0; i < amount_players; i++)
		{
			view_players(file);
			play[i].buf_name = name_of_player;
			play[i].buf_lastname = last_name_of_player;
			play[i].buf_day = day;
			play[i].buf_month = month;
			play[i].buf_year = year;
			play[i].buf_amount = amount_of_playing_matches;
			play[i].buf_goles = goles;
			play[i].buf_assists = assists;
			play[i].buf_yel = yellow_card;
			play[i].buf_red = red_card;
			play[i].buf_pos = position;
		}
		Quicksort(play, index, 0, amount_players - 1);
		delete[]play;
	}
	file.close();
}

void Admin::Quicksort(Player* play, int index, int left, int right)
{
	if (left >= right)
		return;
	int pivot = (left + right) / 2;
	int i = left, j = right;
	while (i <= j)
	{
		if (index == 1)
		{
			while (play[i].buf_lastname < play[pivot].buf_lastname)i++;
			while (play[j].buf_lastname > play[pivot].buf_lastname)j--;
		}
		else if (index == 2)
		{
			while (play[i].buf_amount > play[pivot].buf_amount)i++;
			while (play[j].buf_amount < play[pivot].buf_amount)j--;
		}
		else if (index == 3)
		{
			while ((play[i].buf_goles + play[i].buf_assists) > (play[pivot].buf_goles + play[pivot].buf_assists))i++;
			while ((play[j].buf_goles + play[j].buf_assists) < (play[pivot].buf_goles + play[pivot].buf_assists))j--;
		}
		else if (index == 4)
		{
			while (play[i].buf_yel > play[pivot].buf_yel)i++;
			while (play[j].buf_yel < play[pivot].buf_yel)j--;
		}
		else if (index == 5)
		{
			while (play[i].buf_red > play[pivot].buf_red)i++;
			while (play[j].buf_red < play[pivot].buf_red)j--;
		}
		if (i <= j)
		{
			swap(play[i], play[j]);
			i++;
			j--;
		}
		Quicksort(play, index, left, j);
		Quicksort(play, index, i, right);
	}
	amount(11, pathtoFILE_OF_CLUB);
	ofstream file(pathtoFILE_OF_CLUB, ios::out);
	for (int i = 0; i < amount_players; i++)
	{
		file << play[i].buf_name << endl;
		file << play[i].buf_lastname << endl;
		file << play[i].buf_day << endl;
		file << play[i].buf_month << endl;
		file << play[i].buf_year << endl;
		file << play[i].buf_amount << endl;
		file << play[i].buf_goles << endl;
		file << play[i].buf_assists << endl;
		file << play[i].buf_yel << endl;
		file << play[i].buf_red << endl;
		file << play[i].buf_pos << endl;
	}
	file.close();
}

void Admin::rezult()
{
	accentPrint("������ ����������");
	string name_my_team = "FC_Barcelona", tour1;
	int n = 0, tour = 0;
	while (n < 1 || n>5)
	{
		cout << "\t���������� ������ ������� �� ������ ��������:\n"
			"\t\t1) ���� ���������\n"
			"\t\t2) ��������� �������\n"
			"\t\t3) ���� ������\n"
			"\t\t4) ����� �������\n"
			"\t\t5) ���������� �������\n";
		protection(1, 5, n);
		if (n == 1)
			name_of_tournament = "Champions_League";
		else if (n == 2)
			name_of_tournament = "LaLiga";
		else if (n == 3)
			name_of_tournament = "Europe_League";
		else if (n == 4)
			name_of_tournament = "Cup_Espania";
		else if (n == 5)
			name_of_tournament = "Supercup_Espania";
		else
			accentPrint("������ �������� ����!!!");
	}
	cout << "��������� ������ ���� �� ������ ��������: ";
	if (name_of_tournament == "LaLiga")
		protection(1, 38, tour);
	else 
		cin >> tour1;
	cout << endl;
	cout << "������ ���� ����� " << name_my_team << "(������ �������� ������� ����� _ , ���� � ��� ������ ������ �����) : " << endl;
	cin >> name_of_opponent;
	cout << endl;
	cout << "������� ����� " << name_my_team << ": " << endl;
	protection(0, 15, team_goal);
	cout << endl;
	cout << "������� ����� " << name_of_opponent << ": " << endl;
	protection(0, 15, opponent_goal);
	ofstream file(FILE_OF_REZULT,ios::app);
	file << name_of_tournament << endl;
	if (tour == 0)
		file << tour1 << endl;
	else
		file << tour << endl;
	file << name_of_opponent << endl;
	file << team_goal << endl;
	file << opponent_goal << endl;
	file.close();
	accentPrint("������ � ������� ����������� ����� ���������");
}

void Admin::watch_rezult()
{
	accentPrint("����������");
	ifstream file(FILE_OF_REZULT);
	string tournament, tour;
	cout << endl;
	amount(5, FILE_OF_REZULT);
	for (int i = 0; i < amount_players; i++)
	{
		file >> name_of_tournament;
		file >> tour;
		file >> name_of_opponent;
		file >> team_goal;
		file >> opponent_goal;
		if (name_of_tournament == "Champions_League")
			tournament = "���� ���������";
		else if (name_of_tournament == "LaLiga")
			tournament = "��������� �������";
		else if (name_of_tournament == "Europe_League")
			tournament = "���� ������";
		else if (name_of_tournament == "Cup_Espania")
			tournament = "����� �������";
		else
			tournament = "���������� �������";
		accent(tournament);
		if (name_of_tournament == "LaLiga")
			cout << "\t     ��� " << tour << "\n" << endl;
		else
			cout << "\t     " << tour << "\n" << endl;
		cout << "FC_Barcelona " << team_goal << " - " << opponent_goal << " " << name_of_opponent << endl;
		print();
	}
	file.close();
	system("pause");
	accentPrint("������ � ������� ����������� ����� ���������");
}