#include "stdafx.h"
#include <fstream>
#include <string>
#include <iostream>
#include "food.h"
using namespace std;
CFood::CFood(string n, int h, int m,int p) {

	name = n;
	hp = h;
	mp = m;
	price = p;

}

void CFood::showdata() {
	cout << name << " hp¡G" << hp << " mp¡G" << mp << " »ù¿ú¡G" << price << endl;
}


void CFoodLoad::showdata() {
	for (int i = 0; i < fooddata.size(); i++) {
		cout << i << "¡G";
		fooddata[i]->showdata();
	}
}
void CFoodLoad::loading() {
	ifstream fin;
	string name;
	string race;
	int hp;
	int mp;
	int attack;
	int defence;
	int price;
	fin.open("food.txt");
	if (!fin) {
		cout << "food.txt cannot be opened" << endl;
		system("pause");
		exit(0);
	}
	while (fin >> name >> hp >> mp >> price) {
		CFood *f;
		f = new CFood(name, hp, mp, price);
		fooddata.push_back(f);
	}
}