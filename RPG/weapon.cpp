#include "stdafx.h"
#include <fstream>
#include <string>
#include <iostream>
#include "weapon.h"
using namespace std;
CWeapon::CWeapon(string n, int h, int m, int a, int d, string r, string in_drop, int pro) {

	name = n;
	hp = h;
	mp = m;
	race = r;
	attack = a;
	defence = d;
	drop = in_drop;
	probabilistic = pro;

}

void CWeapon::showdata() {
	cout << name << " hp：" << hp << " mp：" << mp << " 攻擊：" << attack << " 防禦：" << defence << " 種族：" << race << endl;
	//cout << " " << probabilistic << "%機率於 " << drop << " 掉落" << endl;
}


void CWeaponLoad::showdata() {
	for (int i = 0; i < weapondata.size(); i++) {
		weapondata[i]->showdata();
	}
}
void CWeaponLoad::loading() {
	ifstream fin;
	string name;
	string race;
	string drop;
	int probabilistic;
	int hp;
	int mp;
	int attack;
	int defence;
	fin.open("weapon.txt");
	if (!fin) {
		cout << "weapon.txt cannot be opened" << endl;
		system("pause");
		exit(0);
	}
	while (fin >> name >> hp >> mp >> attack >> defence >> race >> drop >> probabilistic) {
		CWeapon *w;
		w = new CWeapon(name, hp, mp, attack, defence, race, drop, probabilistic);
		weapondata.push_back(w);
	}
}