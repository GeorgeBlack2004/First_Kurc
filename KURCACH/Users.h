#pragma once

#include "fstream"
#include "Windows.h"
#include "string"
#include "vector"
using namespace std;

class User
{
public:
	User(string pathtoFILE_OF_DATA, string pathtoFILE_OF_CLUB, string login);
	void user_menu();
	void sort();
private:
	string pathtoFILE_OF_DATA, pathtoFILE_OF_CLUB, login;
	string step;
	int var;
};