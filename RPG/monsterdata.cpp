#include "stdafx.h"
#include <fstream>
#include <string>
#include <iostream>
#include "mosterdata.h"
using namespace std;
CMonsterData::CMonsterData(string n,string p,int hp,int a,int d,int e) {

	name = n;
	place = p;
	MAX_HP = hp;
	attack = a;
	defence = d;
	exp = e;

}

void CMonsterData::showdata() {
		cout << name << "出現於：" << place << " 血量：" << MAX_HP << " 攻擊力：" << attack << " 防禦：" << defence << endl;
}


void CMonsterLoad::showdata() {
	for (int i = 0; i < monsterdata.size(); i++) {
		monsterdata[i]->showdata();
	}
}
void CMonsterLoad::loading() {
	ifstream fin;
	string place;
	string name;
	int MAX_HP;
	int attack;
	int defence;
	int exp;
	fin.open("monster.txt");
	if (!fin) {
		cout << "monster.txt cannot be opened" << endl;
		system("pause");
		exit(0);
	}
	while (fin >> name >> place >> MAX_HP >> attack >> defence >> exp) {
		CMonsterData *m;
		m = new CMonsterData(name, place, MAX_HP, attack, defence, exp);
		monsterdata.push_back(m);
	}
}