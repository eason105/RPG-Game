#include "stdafx.h"
#include <fstream>
#include <string>
#include <iostream>
#include "skill.h"
using namespace std;
CSkill::CSkill(string n, int h, int m, int a, int d, string r,int pr) {

	name = n;
	hp = h;
	mp = m;
	race = r;
	attack = a;
	defence = d;
	price = pr;
	level = 1;

}

void CSkill::showdata() {
	cout << name << " hp¡G" << hp << " mp¡G" << mp << " §ðÀ»¡G" << attack << " ¨¾¿m¡G" << defence << " ºØ±Ú¡G" << race << " »ù¿ú¡G" << price << endl;
}

void CSkill::levelup() {
	hp *=  1.25;
	mp *=  1.25;
	attack *= 1.25;
	defence *= 1.25;
	level++;
}
void CSkillLoad::showdata() {
	for (int i = 0; i < skilldata.size(); i++) {
		cout << i << "¡G";
		skilldata[i]->showdata();
	}
}
void CSkillLoad::loading() {
	ifstream fin;
	string name;
	string race;
	int hp;
	int mp;
	int attack;
	int defence;
	int price;
	fin.open("skill.txt");
	if (!fin) {
		cout << "skill.txt cannot be opened" << endl;
		system("pause");
		exit(0);
	}
	while (fin >> name >> hp >> mp >> attack >> defence >> race >> price) {
		CSkill *s;
		s = new CSkill(name, hp, mp, attack, defence, race, price);
		skilldata.push_back(s);
	}
}