// RPG.cpp: 定義主控台應用程式的進入點。
//
#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include"map.h"
#include"fighter.h"
#include "mosterdata.h"
#include"weapon.h"
#include"clothes.h"
#include"bag.h"
#include"skill.h"
#include"food.h"
#include <windows.h>
#include "string"
using namespace std;
CMonsterLoad ml;
CFoodLoad fl;
CSkillLoad sl;
CWeaponLoad wl;
CClothesLoad cl;
CBag *bag;

string enter() {
	string account, code, code1;
	ifstream fin;
	cout << "輸入帳號: ";
	cin >> account;
	account = account + ".txt";
	cout << endl;
	cout << "輸入密碼: ";
	cin >> code;
	cout << endl;
	fin.open(account);
	if (!fin) {
		cout << "帳號或密碼錯誤" << endl;
		return "0";
	}
	fin >> code1;
	if (code1 != code) {
		cout << "帳號或密碼錯誤" << endl;
		return "0";
	}
	return account;
}
void creat() {
	string account, code, code2;
	cout << "輸入帳號: ";
	cin >> account;
	cout << endl;
	cout << "輸入密碼: ";
	cin >> code;
	cout << endl;
	cout << "確認密碼: ";
	cin >> code2;
	cout << endl;
	while (code != code2) {
		system("cls");
		cout << "密碼錯誤" << endl;
		cout << "輸入帳號: ";
		cin >> account;
		cout << endl;
		cout << "輸入密碼: ";
		cin >> code;
		cout << endl;
		cout << "確認密碼: ";
		cin >> code2;
		cout << endl;
	}
	account = account + ".txt";
	ofstream fout(account);
	fout << code << endl;
}

CFighter* creatC() {
	string name;
	cout << "創建角色" << endl;
	cout << "輸入名稱:";
	cin >> name;
	cout << name << "歡迎" << endl;
	return new CFighter(name, "你的家 ", 13, 1, 0);
}
void victory(string place) {
	//cout << "fuck" << endl;
	for (int i = 0; i < wl.weapondata.size(); i++) {
		if (wl.weapondata[i]->get_drop() == place) {
			int x = rand() % 100;
			//cout << x << endl;
			if (x < wl.weapondata[i]->get_probabilistic()) {
				cout << "掉落了" << wl.weapondata[i]->get_name() << endl;
				if (bag->volume >= bag->max_volume)
					cout << "包包已滿" << endl;
				else {
					bag->weapon.push_back(wl.weapondata[i]);
					bag->volume++;
				}
			}
		}
	}
	for (int i = 0; i < cl.clothesdata.size(); i++) {
		if (cl.clothesdata[i]->get_drop() == place) {
			int x = rand() % 100;
			//cout << x << endl;
			if (x < cl.clothesdata[i]->get_probabilistic()) {
				cout << "掉落了" << cl.clothesdata[i]->get_name() << endl;
				if (bag->volume >= bag->max_volume)
					cout << "包包已滿" << endl;
				else {
					bag->clothes.push_back(cl.clothesdata[i]);
					bag->volume++;
				}
			}
		}
	} 

	int money = (rand() % 15) + 10;
	bag->money += money;
	cout << "獲得了" << money << "元" << endl;
}
int main()
{
	vector<CFighter*>account_f;
	string account;
	string code;
	vector<int>monster;
	ifstream fin;
	CFighter *f;
	CMap *m;
	int a, opf;
	int cnt = 0;
	for (int i = 0; i < 3; i++) {
		account_f.push_back(NULL);
	}
	while (1)
	{
		cout << "歡迎進入世界" << endl;
		cout << "1:登入帳號  2:創建帳號" << endl;
		cin >> a;
		if (a == 1) {
			account = enter();
			while (account == "0") {
				account = enter();
			}
			break;
		}
		if (a == 2)
			creat();
		system("pause");
	}
	fin.open(account);
	string name;
	string place;
	int pos,lev,exp;
	fin >> code;
	while (fin >> name >> place >> pos >> lev >> exp ) {
		account_f[cnt] = new CFighter(name, place, pos, lev, exp);
		cnt = cnt + 1;
	}
	while (1) {
		for (int i = 0; i < 3; i++) {
			if (account_f[i] == NULL)
				cout << i << ":尚無角色" << endl;
			else
				cout << i << ":" << account_f[i]->get_name() << endl;
		}
		cin >> opf;
		if (account_f[opf] == NULL) {
			f = creatC();
			account_f[opf] = f;
		}
		else {
			int zzz;
			cout << "1:登入遊戲 2:刪除腳色" << endl;
			cin >> zzz;
			if (zzz == 1) {
				f = account_f[opf];
				break;
			}
			if (zzz == 2)
				account_f[opf] = NULL;
		}
	}
	system("pause");
	system("cls");
	//f = new CFighter("你的家 ", 13, 1, 0);
	m = new CMap;
	sl.loading();
	fl.loading();
	ml.loading();
	wl.loading();
	cl.loading();
	srand((unsigned int)time(NULL));
	bool alive = true;
	bag = new CBag;
	while (alive) {
		while (monster.size() <= 2) {
			int p;
			while (monster.size() < 4) {
				p = (rand() % 25) + 1;
				while (p == f->GetPosition()) {
					p = (rand() % 25) + 1;
				}
				monster.push_back(p);
			}
		}
		if (f->GetPlace() == "你的家 ")monster.clear();
		/*wl.showdata();
		cl.showdata();*/
		/*sl.showdata();
		fl.showdata();*/
		ml.showdata();
		f->showstatus();
		if (!m->move(f, monster, bag))
			break;
		for (int i = 0; i < monster.size(); i++) {
			if (f->GetPosition() == monster[i]) {
				for (int j = 0; j < ml.monsterdata.size(); j++) {
					if (f->GetPlace() == ml.monsterdata[j]->get_place()) {
						if (f->fight(*ml.monsterdata[j])) {
							monster.erase(monster.begin() + i);
							victory(ml.monsterdata[j]->get_name());
							system("pause");
						}
						else alive = false;
					}
				}
			}
		}
		system("cls");
	}
	ofstream fout(account);
	fout << code << endl;
	for (int i = 0; i < 3; i++) {
		if (account_f[i] != NULL) {
			fout << account_f[i]->get_name() << " " << account_f[i]->GetPlace() << " " << account_f[i]->GetPosition() << " " << account_f[i]->get_levl() << " " << account_f[i]->get_exp() << endl;
		}
	}
	system("pause");
    return 0;
}

