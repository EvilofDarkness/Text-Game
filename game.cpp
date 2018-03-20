#include <iostream>
#include <cstdlib>
#include <fstream>
#include <windows.h>
#include <time.h>
#include <conio.h>
using namespace std;
//hp is player healht points, dmg is player damage
//stats with _e and _e_ its enemy stats
int dmg_ch, dmg, dmg_e, dmg_e_max, exp_e_max, exp_e, lvl_exp, gold_e_max, lvl=1, exp=0, hp_e, hp=150, hp_max;
unsigned long long int gold=0, gold_e;
int armor;
string enemy, nickname, location;
void walka();
void get_enemy();
void select_name();
void main_menu();
void save_read();
void adventure();
void tawern()
{
	system("cls");
	int choice;
	cout<<"--------------------------"<<endl;
	cout<<"Welcome into Tawern!"<<endl;
	cout<<"--------------------------"<<endl;
	cout<<"(1) Dring Beer (100g)"<<endl;
	cout<<"(2) Play Bones"<<endl;
	cout<<"(b) Back"<<endl;
	cout<<"--------------------------"<<endl;
	cout<<nickname<<": ";
	choice=getch();
	cout<<endl;
	Sleep(600);
	switch(choice)
	{
		case '1':
		{
			if(gold>=100)
			{
				system("cls");
				cout<<"--------------------------"<<endl;
				cout<<"Drinking Beer!"<<endl;
				cout<<"HP: +50"<<endl;
				cout<<"Gold: -100"<<endl;
				cout<<"--------------------------"<<endl;
				hp+=50;
				gold-=100;
			}
			else
			{
				system("cls");
				cout<<"--------------------------"<<endl;
				cout<<"You not have enough gold!"<<endl;
				cout<<"--------------------------"<<endl;
			}
			break;
		}
		/*case '2':
		{
			bones();
			break;
		}*/
		case 'b':
		{
			main_menu();
			break;
		}
		default:
		{
			tawern();
			break;
		}
	}
	Sleep(600);
	tawern();
}
//HP, Exp and Gold can't be < 0
void hp_exp_balance() 
{
	if(exp<0) 
	{
		exp=0;
	}
	if(hp<0) 
	{
		hp=0;
	}
	if(hp>hp_max) 
	{
		hp=hp_max;
	}
	if(gold<0)
	{
		gold=0;
	}
}
//Calculate Statistics Script
void cal_stats()
{
	lvl_exp=lvl*128;
	hp_max=100+(lvl*50);
	hp_exp_balance();
	dmg_ch=25+(lvl*5);
}
//Level Up Script
void lvl_up() 
{
	if(exp>=lvl_exp) 
	{
		lvl++;
		cal_stats();
		hp=hp_max;
		exp=0;
	}
}
//Test Dmg Script
void damage() 
{
	srand(time(NULL));
	dmg_e=rand()%((dmg_e_max/2)+(dmg_e_max/4))+(dmg_e_max/4);
	dmg=rand()%((dmg_ch/2)+(dmg_ch/4))+(dmg_ch/4);
	exp_e=rand()%((exp_e_max/2)+(exp_e_max/4))+(exp_e_max/4);
	gold_e=rand()%(gold_e_max);
	hp_exp_balance();

}
//Fight Script
void walka() 
{
	get_enemy();
	for(hp, hp_e; hp>0 or hp_e>0; hp-=dmg_e, hp_e-=(dmg-armor)) {
		system("cls");
		damage();
		cout<<nickname<<": "<<hp<<" | "<<enemy<<": "<<hp_e<<endl;
		cout<<"--------------------------"<<endl;
		cout<<enemy<<" deal "<<dmg_e<<" dmg."<<endl;
		cout<<nickname<<" deal "<<dmg<<" dmg."<<endl;
		Sleep(1000);
		if(hp<=0) 
		{
			system("cls");
			cout<<"--------------------------"<<endl;
			cout<<"Your fight with "<<enemy<<" has ended Defeat!"<<endl;
			cout<<"You lose "<<exp_e<<" Exp."<<endl;
			if(gold_e>0)
			{
				cout<<"You lose "<<gold_e<<" gold."<<endl;
			}
			cout<<"--------------------------"<<endl;
			gold-=(gold_e/2);
			exp-=(exp_e/2);
			break;
		}
		if(hp_e<=0) 
		{
			system("cls");
			cout<<"--------------------------"<<endl;
			cout<<"Your fight with "<<enemy<<" has ended Victory!"<<endl;
			cout<<"You gain "<<exp_e<<" Exp."<<endl;
			if(gold_e>0)
			{
				cout<<"You gain "<<gold_e<<" gold."<<endl;
			}
			cout<<"--------------------------"<<endl;
			gold+=gold_e;
			exp+=exp_e;
			break;
		}
	}
	lvl_up();
	Sleep(1000);
	getch();
	main_menu();
}
//Generate Enemy Script
void get_enemy() 
{
	if(location=="Forest") {
		srand(time(NULL));
		int villain=rand()%3+1;
		switch(villain) {
			case 1: {
				hp_e=120;
				dmg_e_max=30;
				exp_e_max=45;
				gold_e_max=12;
				armor=0;
				enemy="Wolf";
				break;
			}
			case 2: {
				hp_e=60;
				dmg_e_max=15;
				exp_e_max=30;
				gold_e_max=6;
				armor=0;
				enemy="Rabbit";
				break;
			}
			case 3: {
				hp_e=180;
				dmg_e_max=55;
				exp_e_max=70;
				gold_e_max=25;
				armor=0;
				enemy="Bear";
				break;
			}
		}
	}
	if(location=="Mountain") {
		srand(time(NULL));
		int villain=rand()%3+1;
		switch(villain) {
			case 1: {
				hp_e=160;
				dmg_e_max=45;
				exp_e_max=60;
				gold_e_max=27;
				armor=0;
				enemy="Mountain Wolf";
				break;
			}
			case 2: {
				hp_e=100;
				dmg_e_max=30;
				exp_e_max=45;
				gold_e_max=18;
				armor=0;
				enemy="Mountain Rabbit";
				break;
			}
			case 3: {
				hp_e=220;
				dmg_e_max=75;
				exp_e_max=90;
				gold_e_max=40;
				armor=0;
				enemy="Mountain Bear";
				break;
			}
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
	if(nickname.length()<3) {
		system("cls");
		cout<<"--------------------------"<<endl;
		cout<<"Your Name Is Too Short."<<endl;
		cout<<"--------------------------"<<endl;
		Sleep(600);
		select_name();
	}
	cal_stats();
	Sleep(200);
	main_menu();
}
//Main Menu Script
void main_menu() 
{
	int choice;
	hp_exp_balance();
	system("cls");
	cout<<"--------------------------"<<endl;
	cout<<nickname<<" Lvl: "<<lvl<<" Gold: "<<gold<<endl;
	cout<<"HP: "<<hp<<"/"<<hp_max;
	cout<<" Exp: "<<exp<<"/"<<lvl_exp<<endl;
	cout<<"--------------------------"<<endl;
	cout<<"(1) Adventure"<<endl;
	cout<<"(2) Tawern"<<endl;
	cout<<"(3) Save"<<endl;
	cout<<"(b) Exit"<<endl;
	cout<<"--------------------------"<<endl;
	cout<<nickname<<": ";
	choice=getch();
	cout<<endl;
	Sleep(600);
	switch(choice) 
	{
		case '1': 
		{
			adventure();
			break;
		}
		case '2':
		{
			tawern();
			break;
		}
		case '3': 
		{
			save_read();
			break;
		}
		case 'b': 
		{
			exit(0);
			break;
		}
		default: 
		{
			main_menu();
			break;
		}
	}
}
//Adventure Menu
void adventure() 
{
	system("cls");
	int choice;
	cout<<"--------------------------"<<endl;
	cout<<"Where you want to go?"<<endl;
	cout<<"--------------------------"<<endl;
	cout<<"(1) Forest"<<endl;
	if(lvl>=5) {
		cout<<"(2) Mountain"<<endl;
	}
	cout<<"(b) Back"<<endl;
	cout<<"--------------------------"<<endl;
	cout<<nickname<<": ";
	choice=getch();
	Sleep(600);
	switch(choice) 
	{
		case '1': 
		{
			location="Forest";
			break;
		}
		case '2': 
		{
			if(lvl>=5) 
			{
				location="Mountain";
			} else 
			{
				adventure();
			}
			break;
		}
		case 'b': 
		{
			main_menu();
			break;
		}
		default: 
		{
			adventure();
			break;
		}
	}
	walka();
}
//Save and Load Game State Script
void save_read() 
{
	int choice;
	cal_stats();
	string txt;
	system("cls");
	cout<<"--------------------------"<<endl;
	cout<<"Do you want save/load game state?"<<endl;
	cout<<"--------------------------"<<endl;
	cout<<"(1) Save"<<endl;
	cout<<"(2) Load"<<endl;
	cout<<"(b) Back"<<endl;
	cout<<"--------------------------"<<endl;
	cout<<nickname<<": ";
	choice=getch();
	Sleep(600);
	switch(choice) {
		case '1': {
			fstream save("saves/save.txt", ios::out);
			if(save.good()) {
				system("cls");
				save<<"Nick: "<<nickname<<endl;
				save<<"HP: "<<hp<<endl;
				save<<"Dmg: "<<dmg_ch<<endl;
				save<<"Exp: "<<exp<<endl;
				save<<"Lvl: "<<lvl<<endl;
				save<<"Gold: "<<gold<<endl;
				cout<<"--------------------------"<<endl;
				cout<<"Game state Saved!"<<endl;
				cout<<"--------------------------"<<endl;
				save.close();
			} else {
				system("cls");
				cout<<"--------------------------"<<endl;
				cout<<"Cannot save game state!"<<endl;
				cout<<"--------------------------"<<endl;
				save.close();
			}
			break;
		}
		case '2': {
			system("cls");
			fstream read("saves/save.txt", ios::in);
			if(read.good()) {
				system("cls");
				read>>txt>>nickname;
				read>>txt>>hp;
				read>>txt>>dmg_ch;
				read>>txt>>exp;
				read>>txt>>lvl;
				read>>txt>>gold;
				cout<<"--------------------------"<<endl;
				cout<<"Game state loaded!"<<endl;
				cout<<"--------------------------"<<endl;
				read.close();
			} else {
				system("cls");
				cout<<"--------------------------"<<endl;
				cout<<"Cannot load game state!"<<endl;
				cout<<"--------------------------"<<endl;
				read.close();
			}
			break;
		}
		case 'b': {
			main_menu();
			break;
		}
		default: {
			save_read();
			break;
		}
	}
	Sleep(1200);
	main_menu();
}
//Game start save load
void start() 
{
	string txt;
	fstream start("saves/save.txt", ios::in);
	if(start.good()) 
	{
		start>>txt>>nickname;
		start>>txt>>hp;
		start>>txt>>dmg_ch;
		start>>txt>>exp;
		start>>txt>>lvl;
		start>>txt>>gold;
		if(nickname.length()<3) 
		{
			select_name();
		}
		cal_stats();
		main_menu();
	} else 
	{
		system("md saves");
		select_name();
	}
}
//Main Function
int main() 
{
	setlocale(LC_ALL, "");
	system("title Gemu");
	start();
	return 0;
}
