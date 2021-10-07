#include "stdafx.h"
#include <string>
#include <iostream>
#include"shop.h"
#include"food.h"
#include"bag.h"
#include"skill.h"

using namespace std;


void CShop::showdata(CBag *bag) {
	CSkillLoad sl;
	CFoodLoad fl;
	sl.loading();
	fl.loading();
	int select;
	int choose;
	while (1) {
		cout << "1：消耗品 2：技能書" << endl;
		cin >> select;
		system("cls");
		if (select <= 0)
			break;
		switch (select)
		{
		case 1:
			while (1) {
				cout << "現在金額：" << bag->money << endl;
				fl.showdata();
				cin >> choose;
				if (choose < 0)
					break;
				if (choose >= fl.fooddata.size())
					cout << "查無此產品" << endl;
				else {
					if (bag->money >= fl.fooddata[choose]->get_price()) {
						bag->food.push_back(fl.fooddata[choose]);
						bag->money -= fl.fooddata[choose]->get_price();
						cout << "已購買" << fl.fooddata[choose]->get_name() << endl;
					}
					else
						cout << "去賺錢啦白癡" << endl;
				}
				system("pause");
				system("cls");
			}
			system("pause");
			break;
		case 2:
			while (1) {
				cout << "現在金額：" << bag->money << endl;
				sl.showdata();
				cin >> choose;
				if (choose < 0)
					break;
				if (choose >= sl.skilldata.size())
					cout << "查無此產品" << endl;
				else {
					if (bag->money >= sl.skilldata[choose]->get_price()) {
						bag->skill.push_back(sl.skilldata[choose]);
						bag->money -= sl.skilldata[choose]->get_price();
						cout << "已購買" << sl.skilldata[choose]->get_name() << endl;
					}
					else
						cout << "去賺錢啦白癡" << endl;
				}
				system("pause");
				system("cls");
			}
			system("pause");
			break;
		default:
			break;
		}
		system("cls");
	}
}