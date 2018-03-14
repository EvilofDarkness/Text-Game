#include <iostream>
#include <cstdlib>
#include <fstream>
#include <windows.h>
#include <time.h>
#include <conio.h>
using namespace std;
//hp is player healht points, dmg is player damage
//hp_e is enemy health, dmg_e is enemy damege
int hp=1000, dmg, hp_e, dmg_e;
string enemy, nickname;
//Fight Script
void walka()
{
	void get_enemy();
	void main_menu();
	get_enemy();
	for(hp, hp_e;hp>=0 or hp_e>=0;hp-=dmg_e, hp_e-=dmg)
	{
		system("cls");
		cout<<nickname<<": "<<hp<<" | "<<enemy<<": "<<hp_e<<endl;
		cout<<"--------------------------"<<endl;
		cout<<enemy<<" gets "<<dmg<<" dmg"<<endl;
		cout<<nickname<<" gets "<<dmg_e<<" dmg"<<endl;
		if(hp<=0)
		{
			system("cls");
			cout<<"--------------------------"<<endl;
			cout<<"Your fight with "<<enemy<<" has ended Defeat!"<<endl;
			cout<<"--------------------------"<<endl;
			getch();
			main_menu();
			break;
		}
		if(hp_e<=0)
		{
			system("cls");
			cout<<"--------------------------"<<endl;
			cout<<"Your fight with "<<enemy<<" has ended Victory!"<<endl;
			cout<<"--------------------------"<<endl;
			getch();
			main_menu();
			break;
		}
		Sleep(600);
	}
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
				dmg_e=30;
				enemy="Wolf";
				break;
			}
		case 2:
			{
				hp_e=120;
				dmg_e=15;
				enemy="Rabbit";
				break;
			}
		case 3:
			{
				hp_e=600;
				dmg_e=55;
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
	cout<<"(2) Exit"<<endl;
	cout<<"--------------------------"<<endl;
	cout<<nickname<<": ";
	choice=getch();
	cout<<endl;
	Sleep(700);
	switch(choice)
	{
		case '1':
			{
				walka();
				break;
			}
		case '2':
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
//Main Function
int main()
{
	setlocale(LC_ALL, "");
	select_name();
	dmg=25;
	main_menu();
	return 0;
}
