
void Admin::create_start_squad()
{
	accentPrint("����������� ���������� �������");
	ifstream file(pathtoFILE_OF_CLUB);
	amount(9, pathtoFILE_OF_CLUB);
	if (amount_players == 0)
	{
		cout << "\n\n������ ����!!!\n\n" << endl;
	}
	else
	{
		int am_striker = 0, am_midf = 0, am_defe = 0, am_goal = 0;
		do
		{
			for (int i = 0; i < amount_players; i++)
			{
				view_players(file);
				if (position == "Striker")
					am_striker++;
				else if (position == "Midfielder")
					am_midf++;
				else if (position == "Defender")
					am_defe++;
				else
					am_goal++;
			}
			if (am_goal == 0)
			{
				cout << "\n\n� ����� ������� ���� �������, �������� ���!!!\n\n" << endl; system("pause");
				add_new_player();
			}
		} while (am_goal == 0);
		accentPrint("����������� ���������� �������");
		cout << "\n\n��� ����� ������� �����:\n"
			"\t1) 4 - 3 - 3\n"
			"\t2) 3 - 4 - 3\n"
			"\t3) 4 - 4 - 2\n"
			"\t4) 3 - 5 - 2\n"
			"\t5) 4 - 2 - 4\n";
		cout << "��� �����: ";
		int n = 0, g = 0;
		protection(1, 5, n);
		switch (n)
		{
		case 1:
		{
			check(4, am_defe, "����������");
			check(3, am_midf, "��������������");
			check(3, am_striker, "����������");
			start_squad(4, 3, 3);
		}; break;
		case 2:
		{
			check(3, am_defe, "����������");
			check(4, am_midf, "��������������");
			check(3, am_striker, "����������");
		}; break;
		case 3:
		{
			check(4, am_defe, "����������");
			check(4, am_midf, "��������������");
			check(2, am_striker, "����������");
		}break;
		case 4:
		{
			check(3, am_defe, "����������");
			check(5, am_midf, "��������������");
			check(2, am_striker, "����������");
		}break;
		case 5:
		{
			check(4, am_defe, "����������");
			check(2, am_midf, "��������������");
			check(4, am_striker, "����������");
		}break;
		}
	}
	file.close();
}

void Admin::start_squad(int def, int mid, int forw)
{
	accentPrint("����������� ���������� �������");
	ifstream file(pathtoFILE_OF_CLUB);
	amount(9, pathtoFILE_OF_CLUB);
	int mas_def[4], mas_mid[3], mas_forw[4];
	int g = 0;
	cout << "\t���, �������:" << "\t���� ��������:" << "\t���������� ��������� ������:" << "\t����:" << "\t   �������:" << "\t������ ��������:" << "\t������� ��������:" << endl;
	print();
	for (int i = 0; i < amount_players; i++)
	{
		view_players(file);
		if (position == "Defender")
		{
			cout << ++g << ")\t" << name_of_player << " " << last_name_of_player << "\t " << date_of_birth << "\t\t   " << amount_of_playing_matches << "\t\t\t " << goles << "\t     " << assists << "\t\t" << yellow_card << "\t\t       " << red_card << endl;
			print();
		}
	}
	cout << "�������� ����������:" << endl;
	for (int i = 0; i < def; i++)
	{
		cin >> mas_def[i];
	}
	file.close();
}

void Admin::check(int index, int am_, string who)
{
	do
	{
		if (index - am_ > 0)
		{
			cout << "\n� ��� �� ������� " << index - am_ << " " << who << ", �������� ��!!!" << endl; system("pause");
			add_for_squad(index, am_);
			am_++;
		}
	} while (index - am_ > 0);
}

void Admin::add_for_squad(int index, int am_)
{
	for (int i = 0; i < index - am_; i++)
	{
		add_new_player();
	}
}