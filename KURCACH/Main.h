#pragma once

#include "fstream"
#include "Windows.h"
#include "string"
#include "vector"
using namespace std;

class Main
{
public:
	Main(string pathtoFILE_OF_DATA, string pathtoFILE_OF_CLUB);
	void start();
	void entrance();
	void firstrun();
	void registration();
	void welcome();
	void proof(string&, bool&);
	void trueadmin(string,int&);
	void amount_users();
	void truelogin(string,bool&);
	void view_users(ifstream&);
	void watch();
	void unusers(int, int&);
private:
	int i, amountusers = 0;
	string pathtoFILE_OF_DATA, pathtoFILE_OF_CLUB;
	string login, password;
	int role;
};