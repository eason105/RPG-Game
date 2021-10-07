#pragma once
#ifndef WEAPON_H
#define WEAPON_H

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <windows.h>
using namespace std;

class CWeapon {
public:
	CWeapon(string name, int hp, int mp, int attack, int defence, string race, string drop, int probabilistic);
	void showdata();
	int get_hp() { return hp; }
	int get_mp() { return mp; }
	int get_attack() { return attack; }
	int get_defence() { return defence; }
	string get_name() { return name; }
	string get_race() { return race; }
	string get_drop() { return drop; }
	int get_probabilistic() { return probabilistic; }
private:
	string name;
	int hp;
	int mp;
	int attack;
	int defence;
	string race;
	string drop;
	int probabilistic;

};
class CWeaponLoad {
public:
	void loading();
	void showdata();
	vector<CWeapon *>weapondata;

};
#endif