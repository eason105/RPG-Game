#pragma once
#ifndef BAG_H
#define BAG_H

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <windows.h>

class CFood;
class CSkill;
class CClothes;
class CWeapon;
class CFighter;
using namespace std;

class CBag {
public:
	void showdata(CFighter *f);
	void del();
	vector<CFood*>food;
	vector<CSkill*>skill;
	vector<CClothes*>clothes;
	vector<CWeapon*>weapon;
	int money = 0;
	string size = "¤p­I¥]";
	int volume = 0;
	int max_volume = 5;
};
#endif