#pragma once
#ifndef MAP_H
#define MAP_H
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <windows.h>
using namespace std;

class CFighter;
class CBag;
class CMap {
public:
	CMap();
	bool move(CFighter *f, vector<int>mp,CBag *bag);
	void showmap(CFighter *f);
	void showposition(CFighter *f, vector<int>mp);
	vector<vector<string>> GetMap();
private:
	vector<vector<string>>map;
	vector<vector<int>>postion;
};
#endif