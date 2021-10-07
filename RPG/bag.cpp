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
	cout << "1�G�Z�� 2�G���� 3�G���ӫ~ 4�G�ޯ�� 5�G�I�]�� money�G" << money << "��" << endl;
	cin >> choose;
	system("cls");
	int select;
	switch (choose)
	{
	case 1:
		while (1) {
			for (int i = 0; i < weapon.size(); i++) {
				cout << i << "�G";
				weapon[i]->showdata();
			}
			if (weapon.size() <= 0)
				cout << "���֥h����" << endl;
			cin >> select;
			if (select < 0)
				break;
			if (select >= weapon.size())
				cout << "�L�����" << endl;
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
				cout << i << "�G";
				clothes[i]->showdata();
			}
			if (clothes.size() <= 0)
				cout << "���֥h����" << endl;
			cin >> select;
			if (select < 0)
				break;
			if (select >= clothes.size())
				cout << "�L�����" << endl;
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
				cout << i << "�G";
				food[i]->showdata();
			}
			if (food.size() <= 0)
				cout << "���֥h����" << endl;
			cin >> select;
			if (select < 0)
				break;
			if (select >= food.size())
				cout << "�L�����" << endl;
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
				cout << i << "�G";
				skill[i]->showdata();
			}
			if (skill.size() <= 0)
				cout << "���֥h����" << endl;
			cin >> select;
			if (select < 0)
				break;
			if (select >= skill.size())
				cout << "�L�����" << endl;
			else {
				if (f->use_skill_book(skill[select]))
					skill.erase(skill.begin() + select);
			}
			system("pause");
			system("cls");
		}
		break;
	case 5:
		cout << "1�G�p�I�] 2�G���I�] 3�G�j�I�]" << endl;
		int select;
		cin >> select;
		if (select == 1) {
			size = "�p�I�]";
			max_volume = 5;
			if (max_volume < volume)
				del();
		}
		if (select == 2) {
			size = "���I�]";
			max_volume = 10;
			if (max_volume < volume)
				del();
		}
		if (select == 3) {
			size = "�j�I�]";
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
	cout << "�O�_�R��I�]" << endl;
	cout << "1�G�O" << endl;
	int choose;
	int ob;
	int ww;//�R�Z��
	int cc;
	cin >> choose;
	switch (choose)
	{
	case 1:
		while (max_volume < volume) {
			cout << "��ܭn�R��������:1.�Z�� 2.���� 3.���ӫ~ 4.�ޯ��" << endl;
			cin >> ob;
			if (ob == 1) {
				for (int i = 0; i<weapon.size(); i++) {
					cout << i << "�G";
					weapon[i]->showdata();
				}
				cin >> ww;
				weapon.erase(weapon.begin() + ww);
			}
			if (ob == 2) {
				for (int i = 0; i< clothes.size(); i++) {
					cout << i << "�G";
					clothes[i]->showdata();
				}
				cin >> cc;
				clothes.erase(clothes.begin() + cc);
			}
			if (ob == 3) {
				for (int i = 0; i< food.size(); i++) {
					cout << i << "�G";
					food[i]->showdata();
				}
				cin >> cc;
				food.erase(food.begin() + cc);
			}
			if (ob == 4) {
				for (int i = 0; i< skill.size(); i++) {
					cout << i << "�G";
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