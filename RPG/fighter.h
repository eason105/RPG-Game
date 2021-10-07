#pragma once
#ifndef FIGHTER_H
#define FIGHTER_H
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

class CSkill;
class CMap;
class CMonsterData;
class CWeapon;
class CClothes;
class CFood;
class CFighter {
public:
	CFighter(string name, string place, int position, int level, int exp);
	void showstatus();
	void walk(string p, CMap *m);
	string GetPlace();
	int GetPosition();
	int fight(CMonsterData md);
	void levelup();
	CWeapon* wear_weapon(CWeapon *w);
	CClothes* wear_clothes(CClothes *c);
	void use_food(CFood *food);
	bool use_skill_book(CSkill* skill);
	void show_skill_data();
	string get_name() { return name; }
	int get_levl() { return level; }
	int get_exp() { return exp; }
private:
	string name;
	int level;
	int position;
	string race;
	string place;
	int max_hp;
	int hp;
	int attack;
	int defence;
	int max_exp;
	int exp;
	int mp;
	int max_mp;
	int skill_point = 0;
	vector<CSkill*>skill;
	CWeapon* weapon = NULL;
	CClothes *clothes = NULL;
};


#endif