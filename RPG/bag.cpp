#include "stdafx.h"
#include <fstream>
#include <string>
#include <iostream>
#include "bag.h"
#include"weapon.h"
#include"clothes.h"
#include"fighter.h"
#include"food.h"
#include"skill.h"
using namespace std;

void CBag::showdata(CFighter *f) {
	system("cls");
	int choose;
	cout << size << " " << volume << "/" << max_volume << endl;
	cout << "1：武器 2：防具 3：消耗品 4：技能書 5：背包更換 money：" << money << "元" << endl;
	cin >> choose;
	system("cls");
	int select;
	switch (choose)
	{
	case 1:
		while (1) {
			for (int i = 0; i < weapon.size(); i++) {
				cout << i << "：";
				weapon[i]->showdata();
			}
			if (weapon.size() <= 0)
				cout << "趕快去打裝" << endl;
			cin >> select;
			if (select < 0)
				break;
			if (select >= weapon.size())
				cout << "無此選擇" << endl;
			else {
				CWeapon *w = f->wear_weapon(weapon[select]);
				if (w != NULL) {
					weapon[select] = w;
				}
				else
					weapon.erase(weapon.begin() + select);
			}
			system("cls");
		}
		break;
	case 2:
		while (1) {
			for (int i = 0; i < clothes.size(); i++) {
				cout << i << "：";
				clothes[i]->showdata();
			}
			if (clothes.size() <= 0)
				cout << "趕快去打裝" << endl;
			cin >> select;
			if (select < 0)
				break;
			if (select >= clothes.size())
				cout << "無此選擇" << endl;
			else {
				CClothes *c = f->wear_clothes(clothes[select]);
				if (c != NULL) {
					clothes[select] = c;
				}
				else
					clothes.erase(clothes.begin() + select);
			}
			system("cls");
		}
		break;
	case 3:
		while (1) {
			for (int i = 0; i < food.size(); i++) {
				cout << i << "：";
				food[i]->showdata();
			}
			if (food.size() <= 0)
				cout << "趕快去打裝" << endl;
			cin >> select;
			if (select < 0)
				break;
			if (select >= food.size())
				cout << "無此選擇" << endl;
			else {
				f->use_food(food[select]);
				food.erase(food.begin() + select);
			}
			system("cls");
		}
		break;
	case 4:
		while (1) {
			for (int i = 0; i < skill.size(); i++) {
				cout << i << "：";
				skill[i]->showdata();
			}
			if (skill.size() <= 0)
				cout << "趕快去打裝" << endl;
			cin >> select;
			if (select < 0)
				break;
			if (select >= skill.size())
				cout << "無此選擇" << endl;
			else {
				if (f->use_skill_book(skill[select]))
					skill.erase(skill.begin() + select);
			}
			system("pause");
			system("cls");
		}
		break;
	case 5:
		cout << "1：小背包 2：中背包 3：大背包" << endl;
		int select;
		cin >> select;
		if (select == 1) {
			size = "小背包";
			max_volume = 5;
			if (max_volume < volume)
				del();
		}
		if (select == 2) {
			size = "中背包";
			max_volume = 10;
			if (max_volume < volume)
				del();
		}
		if (select == 3) {
			size = "大背包";
			max_volume = 15;
			if (max_volume < volume)
				del();
		}
		break;
	default:
		break;
	}
}

void CBag::del() {
	cout << "是否刪減背包" << endl;
	cout << "1：是" << endl;
	int choose;
	int ob;
	int ww;//刪武器
	int cc;
	cin >> choose;
	switch (choose)
	{
	case 1:
		while (max_volume < volume) {
			cout << "選擇要刪除的種類:1.武器 2.防具 3.消耗品 4.技能書" << endl;
			cin >> ob;
			if (ob == 1) {
				for (int i = 0; i<weapon.size(); i++) {
					cout << i << "：";
					weapon[i]->showdata();
				}
				cin >> ww;
				weapon.erase(weapon.begin() + ww);
			}
			if (ob == 2) {
				for (int i = 0; i< clothes.size(); i++) {
					cout << i << "：";
					clothes[i]->showdata();
				}
				cin >> cc;
				clothes.erase(clothes.begin() + cc);
			}
			if (ob == 3) {
				for (int i = 0; i< food.size(); i++) {
					cout << i << "：";
					food[i]->showdata();
				}
				cin >> cc;
				food.erase(food.begin() + cc);
			}
			if (ob == 4) {
				for (int i = 0; i< skill.size(); i++) {
					cout << i << "：";
					skill[i]->showdata();
				}
				cin >> cc;
				skill.erase(skill.begin() + cc);
			}
			volume = volume - 1;
		}
		break;
	default:
		break;
	}
}