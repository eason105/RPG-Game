#include "stdafx.h"
#include <string>
#include <iostream>
#include "map.h"
#include"bag.h"
#include "fighter.h"
#include"shop.h"
using namespace std;

CMap::CMap() {
	vector<string>m;
	vector<int>p;
	m.push_back("施工中 ");
	m.push_back("2號道路");
	m.push_back("施工中 ");
	map.push_back(m);
	m.clear();
	m.push_back("4號道路");
	m.push_back("你的家 ");
	m.push_back("6號道路");
	map.push_back(m);
	m.clear();
	m.push_back("7號道路");
	m.push_back("8號道路");
	m.push_back("施工中 ");
	map.push_back(m);
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			p.push_back(0);
		}
		postion.push_back(p);
		p.clear();
	}
}

vector<vector<string>> CMap::GetMap() {
	return map;
}
void CMap::showmap(CFighter *f) {
	for (int i = 0; i < map.size(); i++) {
		for (int j = 0; j < map[i].size(); j++) {
			if (f->GetPlace() == map[i][j]) {
				cout << ">" << map[i][j] << " ";
			}
			else
				cout << " " << map[i][j] << " ";
		}
		cout << endl;
	}
}
void CMap::showposition(CFighter *f, vector<int>mp) {
	bool fa = false;
	for (int i = 0; i < postion.size(); i++) {
		for (int j = 0; j < postion[i].size(); j++) {
			for (int k = 0; k < mp.size(); k++) {
				if ((i * 5 + j + 1) == mp[k] && !fa) {
					cout << " " << "M" << " ";
					fa = true;
				}
			}
			if (!fa) {
				if ((i * 5 + j + 1) == f->GetPosition()) {
					cout << " " << "1" << " ";
				}
				else
					cout << " " << postion[i][j] << " ";
			}
			fa = false;
		}
		cout << endl;
	}
}
bool CMap::move(CFighter *f, vector<int>mp, CBag *bag) {
	showmap(f);
	showposition(f, mp);
	cout << "上：w 左：a 下：s 右：d 商店：p 背包：b 技能：k 登出：y" << endl;
	string move;
	cin >> move;
	if (move == "b") {
		bag->showdata(f);
		system("pause");
	}
	if (move == "p") {
		CShop shop;
		system("cls");
		shop.showdata(bag);
		system("pause");
	}
	if (move == "k") {
		f->show_skill_data();
	}
	if (move == "y") {
		return false;
	}
	else
		f->walk(move, this);
	return true;
}