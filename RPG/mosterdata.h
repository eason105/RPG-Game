#pragma once
#ifndef MONSTERDATA_H
#define MONSTERDATA_H

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <windows.h>
using namespace std;

class CMonsterData {
public:
	CMonsterData(string name,string place,int MAX_HP,int attack,int defence,int exp);
	void showdata();
	void attacked(int dmg) { MAX_HP -= dmg; }
	int get_hp() { return MAX_HP; }
	int get_attack() { return attack; }
	int get_defence() { return defence; }
	int get_exp() { return exp; }
	string get_name() { return name; }
	string get_place() { return place; }
private:
	string place;
	string name;
	int MAX_HP;
	int attack;
	int defence;
	int exp;
};
class CMonsterLoad {
public:
	void loading();
	void showdata();
	vector<CMonsterData *>monsterdata;

};
#endif