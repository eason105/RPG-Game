#pragma once
#ifndef FOOD_H
#define FOOD_H

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <windows.h>
using namespace std;

class CFood {
public:
	CFood(string name, int hp, int mp,int price);
	void showdata();
	int get_hp() { return hp; }
	int get_mp() { return mp; }
	int get_price() { return price; }
	string get_name() { return name; }
private:
	string name;
	int hp;
	int mp;
	int price;
};
class CFoodLoad {
public:
	void loading();
	void showdata();
	vector<CFood *>fooddata;

};
#endif