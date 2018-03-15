#include <iostream>
#include <cstdlib>
#include <fstream>
#include <windows.h>
#include <time.h>
#include <conio.h>
using namespace std;
//hp is player healht points, dmg is player damage
//hp_e is enemy health, dmg_e is enemy damege
int hp=1000, dmg_ch, dmg, hp_e, dmg_e, dmg_e_max;
string enemy, nickname;
void walka();
void get_enemy();
void select_name();
void main_menu();
void save_read();
//Test Dmg Script
void damage()
{
	srand(time(NULL));
	dmg_e=rand()%((dmg_e_max/2)+(dmg_e_max/4))+(dmg_e_max/4);
	dmg=rand()%((dmg_ch/2)+(dmg_ch/4))+(dmg_ch/4);
}
//Fight Script
void walka()
{
	get_enemy();
	for(hp, hp_e;hp>=0 or hp_e>=0;hp-=dmg_e, hp_e-=dmg)
	{
		system("cls");
		damage();
		cout<<nickname<<": "<<hp<<" | "<<enemy<<": "<<hp_e<<endl;
		cout<<"--------------------------"<<endl;
		cout<<enemy<<" deal "<<dmg_e<<" dmg"<<endl;
		cout<<nickname<<" deal "<<dmg<<" dmg"<<endl;
		Sleep(1000);
		if(hp<=0)
		{
			system("cls");
			cout<<"--------------------------"<<endl;
			cout<<"Your fight with "<<enemy<<" has ended Defeat!"<<endl;
			cout<<"--------------------------"<<endl;
			break;
		}
		if(hp_e<=0)
		{
			system("cls");
			cout<<"--------------------------"<<endl;
			cout<<"Your fight with "<<enemy<<" has ended Victory!"<<endl;
			cout<<"--------------------------"<<endl;
			break;
		}
	}
	Sleep(1000);
	getch();
	main_menu();
}
//Generate Enemy Script
void get_enemy()
{
	srand(time(NULL));
	int villain=rand()%3+1;
	switch(villain)
	{
		case 1:
		{
			hp_e=230;
			dmg_e_max=30;
			enemy="Wolf";
			break;
		}
		case 2:
		{
			hp_e=120;
			dmg_e_max=15;
			enemy="Rabbit";
			break;
		}
		case 3:
		{
			hp_e=600;
			dmg_e_max=55;
			enemy="Mountain Bear";
			break;
		}
	}
}
//Name Select Script
void select_name()
{
	system("cls");
	cout<<"--------------------------"<<endl;
	cout<<"Enter Your Name."<<endl;
	cout<<"--------------------------"<<endl;
	getline(cin, nickname);
	Sleep(200);
	main_menu();
}
//Main Menu Script
void main_menu()
{
	int choice;
	system("cls");
	cout<<"--------------------------"<<endl;
	cout<<"Welcome "<<nickname<<endl;
	cout<<"What you want to do?"<<endl;
	cout<<"(1) Fight"<<endl;
	cout<<"(2) Save"<<endl;
	cout<<"(3) Exit"<<endl;
	cout<<"--------------------------"<<endl;
	cout<<nickname<<": ";
	choice=getch();
	cout<<endl;
	Sleep(600);
	switch(choice)
	{
		case '1':
		{
			walka();
			break;
		}
		case '2':
		{
			save_read();
			break;
		}			
		case '3':
		{
			system("pause");
			break;
		}
		default:
		{
			main_menu();
		}
	}
}
//Save and Load Game State Script
void save_read()
{
	int choice;
	system("cls");
	cout<<"--------------------------"<<endl;
	cout<<"Do you want save/load game state?"<<endl;
	cout<<"(1) Save"<<endl;
	cout<<"(2) Load"<<endl;
	cout<<"(3) Back"<<endl;
	cout<<"--------------------------"<<endl;
	cout<<nickname<<": ";
	choice=getch();
	Sleep(600);
	switch(choice)
	{
		case '1':
		{
			fstream save("saves/save.txt", ios::out);
			if(save.good())
			{
				system("cls");
				save<<nickname<<endl;
				save<<hp<<endl;
				save<<dmg_ch<<endl;
				cout<<"--------------------------"<<endl;
				cout<<"Game state Saved!"<<endl;
				cout<<"--------------------------"<<endl;
				save.close();
			}
			else
			{
				system("cls");
				system("md saves");
				cout<<"--------------------------"<<endl;
				cout<<"Cannot save game state!"<<endl;
				cout<<"--------------------------"<<endl;
				save.close();
			}
			break;
		}
		case '2':
		{
			system("cls");
			fstream read("saves/save.txt", ios::in);
			if(read.good())
			{
				system("cls");
				read>>nickname>>hp>>dmg_ch;
				cout<<"--------------------------"<<endl;
				cout<<"Game state loaded!"<<endl;
				cout<<"--------------------------"<<endl;
				read.close();
			}
			else
			{
				system("cls");
				cout<<"--------------------------"<<endl;
				cout<<"Cannot load game state!"<<endl;
				cout<<"--------------------------"<<endl;
				read.close();
			}
			break;
		}
		case '3':
		{
			main_menu();
			break;
		}
		default:
		{
			save_read();
		}
	}
	Sleep(1200);
	save_read();
}
//Game start save load
void start()
{
	fstream start("saves/save.txt", ios::in);
	if(start.good())
	{
		start>>nickname>>hp>>dmg_ch;
		main_menu();
	}
	else
	{
		select_name();
	}
}
//Main Function
int main()
{
	setlocale(LC_ALL, "");
	dmg_ch=25;
	start();
	return 0;
}
