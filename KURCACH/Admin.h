#pragma once
#include"Main.h"
#include"Users.h"
#include "iostream"
#include "vector"
using namespace std;

const string FILE_OF_REZULT = "Rezult.txt";

class Admin
{
public:
	struct Player {
		string buf_name, buf_lastname, buf_pos;
		int buf_amount, buf_goles, buf_assists, buf_yel, buf_red, buf_day, buf_month, buf_year;
	};
	Admin(string pathtoFILE_OF_DATA, string pathtoFILE_OF_CLUB, string login);
	void work_with();
	void work_with_userlist();
	void watch_userlist();
	void add_user();
	void work_with_data_of_club();
	void add_new_player();
	void watch_players(int);
	void amount(int,string);
	bool remove(size_t, int, string,string&,string&);
	void delete_user();
	void delete_player();
	void search_player();
	void redact_user();
	void individualtask();
	void the_best_players();
	void view_players(ifstream&);
	void redact(int);
	bool redact_user(size_t, int, string&, string&);
	void add_after_redact(string, string, int);
	void redact_player();
	bool redmove_player(size_t, int, string&, string&, string&, string&, string&, string&);
	void redplayer(int);
	void add_redplayer(int, int, string, string, string, string, string, string);
	void sort_pres(int);
	void Quicksort(Player*, int, int, int);
	void rezult();
	void watch_rezult();
	void yellow();
private:
	string name_of_player, last_name_of_player, position, name_of_opponent, name_of_tournament;
	int amount_of_playing_matches, goles, assists, yellow_card, red_card, day, month, year, team_goal, opponent_goal;
	string pathtoFILE_OF_DATA, pathtoFILE_OF_CLUB, login, password, role;
	int i = 0, amount_players = 0;
	string command;
};