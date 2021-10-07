#include "stdafx.h"
#include <fstream>
#include <string>
#include <iostream>
#include "clothes.h"
using namespace std;
CClothes::CClothes(string n, int h, int m, int a, int d, string r, string in_drop, int pro) {

	name = n;
	hp = h;
	mp = m;
	race = r;
	attack = a;
	defence = d;
	drop = in_drop;
	probabilistic = pro;

}

void CClothes::showdata() {
	cout << name << " hp：" << hp << " mp：" << mp << " 攻擊：" << attack << " 防禦：" << defence << " 種族：" << race << endl;
	//cout << " " << probabilistic << "%機率於 " << drop << " 掉落" << endl;
}


void CClothesLoad::showdata() {
	for (int i = 0; i < clothesdata.size(); i++) {
		clothesdata[i]->showdata();
	}
}
void CClothesLoad::loading() {
	ifstream fin;
	string name;
	string race;
	string drop;
	int probabilistic;
	int hp;
	int mp;
	int attack;
	int defence;
	fin.open("clothes.txt");
	if (!fin) {
		cout << "clothes.txt cannot be opened" << endl;
		system("pause");
		exit(0);
	}
	while (fin >> name >> hp >> mp >> attack >> defence >> race >> drop >> probabilistic) {
		CClothes *c;
		c = new CClothes(name, hp, mp, attack, defence, race, drop, probabilistic);
		clothesdata.push_back(c);
	}
}