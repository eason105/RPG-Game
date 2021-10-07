#pragma once
#ifndef SKILL_H
#define SKILL_H

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <windows.h>
using namespace std;

class CSkill {
public:
	CSkill(string name, int hp, int mp, int attack, int defence, string race,int price);
	void showdata();
	int get_hp() { return hp; }
	int get_mp() { return mp; }
	int get_attack() { return attack; }
	int get_defence() { return defence; }
	int get_price() { return price; }
	int get_level() { return level; }
	string get_name() { return name; }
	string get_race() { return race; }
	void levelup();
private:
	string name;
	int hp;
	int attack;
	int defence;
	int mp;
	string race;
	int price;
	int level;
};
class CSkillLoad {
public:
	void loading();
	void showdata();
	vector<CSkill *>skilldata;

};
#endif