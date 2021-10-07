#include "stdafx.h"
#include <string>
#include <iostream>
#include "fighter.h"
#include"mosterdata.h"
#include"weapon.h"
#include"clothes.h"
#include"food.h"
#include"skill.h"
#include "map.h"
using namespace std;

CFighter::CFighter(string na, string p, int po, int lev, int e) {
	level = lev;
	place = p;
	position = po;
	exp = e;
	name = na;
	attack = 100 + 20 * lev;
	defence = 80 + 15 * lev;
	max_hp = 500 + 25 * lev;
	max_mp = 500 + 10 * lev;
	hp = max_hp;
	mp = max_mp;
	max_exp = 20 + lev * 20;
	race = "弓箭手";
	skill.push_back(new CSkill("普通攻擊", 0, 0, attack, 0, "ALL", 0));
}

string CFighter::GetPlace() {
	return place;
}
int CFighter::GetPosition() {
	return position;
}

void CFighter::showstatus() {
	cout << "現在狀態  hp：" << hp << "/" << max_hp << " mp：" << mp << "/" << max_mp << " 攻擊力：" << attack << " 防禦：" << defence << " 經驗值：" << exp << "/" << max_exp << endl;
}

void CFighter::levelup() {
	cout << "升級了" << endl;
	attack += 20 * level;
	defence += 15 * level;
	max_exp += level * 200;
	max_hp += 25 * level;
	max_mp += 10 * level;
	hp = max_hp;
	mp = max_mp;
	skill_point += 3;
	skill[0]->levelup();
}
int CFighter::fight(CMonsterData md) {
	system("cls");
	cout << "遇到了" << md.get_name() << endl;
	system("pause");
	system("cls");
	while (hp > 0 && md.get_hp() > 0) {
		cout << md.get_name() << "剩餘血量：" << md.get_hp() << endl;
		cout << "你剩餘血量：" << hp << "剩餘魔力：" << mp << endl;
		for (int i = 0; i < skill.size(); i++) {
			cout << i  << "：" << skill[i]->get_name()<<" ";
		}
		cout << endl;
		int select;
		cin >> select;
		if (select > skill.size()) {
			cout << "無此技能" << endl;
			system("pause");
		}
		//system("cls");
		if (mp < skill[select]->get_mp()) {
			cout << "魔力不足" << endl;
			system("pause");
		}
		else {
			mp -= skill[select]->get_mp();
			int damage;
			damage = skill[select]->get_attack() - md.get_defence();
			if (damage < 0)damage = 1;
			cout << "你對" << md.get_name() << "造成了" << damage << "點傷害" << endl;
			Sleep(500);
			md.attacked(damage);
			if (md.get_hp() < 0) {
				cout << md.get_name() << "倒下了" << endl;
				cout << "你獲得了" << md.get_exp() << "點經驗" << endl;
				exp += md.get_exp();
				if (exp >= max_exp) {
					level++;
					exp -= max_exp;
					levelup();
				}
				return 1;
			}
			damage = md.get_attack() - defence;
			if (damage < 1)
				damage = 1;
			cout << md.get_name() << "對你造成了" << damage << "點傷害" << endl;
			hp -= damage;
			Sleep(500);
			if (hp < 0) {
				cout << "眼前一片漆黑" << endl;
				system("pause");
				return 0;
			}
		}
		system("cls");
	}
}
void CFighter::walk(string p, CMap *m) {
	bool finish = false;
	if (p == "w") {
		if (position > 5)
			position -= 5;
		else {
			for (int i = 0; i < m->GetMap().size(); i++) {
				for (int j = 0; j < m->GetMap()[i].size(); j++) {
					if (m->GetMap()[i][j] == place) {
						if (i != 0 && !finish && m->GetMap()[i - 1][j] != "施工中 ") {
							place = m->GetMap()[i - 1][j];
							position += 20;
							finish = true;
						}
					}
				}
			}
		}
	}
	if (p == "s") {
		if (position < 21)
			position += 5;
		else {
			for (int i = 0; i < m->GetMap().size(); i++) {
				for (int j = 0; j < m->GetMap()[i].size(); j++) {
					if (m->GetMap()[i][j] == place) {
						if (i != 2 && !finish && m->GetMap()[i + 1][j] != "施工中 ") {
							place = m->GetMap()[i + 1][j];
							position -= 20;
							finish = true;
						}
					}
				}
			}
		}
	}
	if (p == "a") {
		if ((position % 5) != 1)
			position -= 1;
		else {
			for (int i = 0; i < m->GetMap().size(); i++) {
				for (int j = 0; j < m->GetMap()[i].size(); j++) {
					if (m->GetMap()[i][j] == place) {
						if (j != 0 && !finish && m->GetMap()[i][j - 1] != "施工中 ") {
							place = m->GetMap()[i][j - 1];
							position += 4;
							finish = true;
						}
					}
				}
			}
		}
	}
	if (p == "d") {
		if ((position % 5) != 0)
			position += 1;
		else {
			for (int i = 0; i < m->GetMap().size(); i++) {
				for (int j = 0; j < m->GetMap()[i].size(); j++) {
					if (m->GetMap()[i][j] == place) {
						if (j != 2 && !finish && m->GetMap()[i][j + 1] != "施工中 ") {
							place = m->GetMap()[i][j + 1];
							position -= 4;
							finish = true;
						}
					}
				}
			}
		}
	}
}

CWeapon* CFighter::wear_weapon(CWeapon *w) {
	if (race != w->get_race()) {
		cout << "職業不符" << endl;
		system("pause");
		return w;
	}
	cout << "hp + " << w->get_hp() << " mp + " << w->get_mp() << " attack + " << w->get_attack() << " defence + " << w->get_defence() << endl;
	max_hp += w->get_hp();
	max_mp += w->get_mp();
	attack += w->get_attack();
	defence += w->get_defence();
	system("pause");
	if (weapon != NULL) {
		CWeapon *ww;
		ww = weapon;
		weapon = w;
		max_hp -= ww->get_hp();
		max_mp -= ww->get_mp();
		attack -= ww->get_attack();
		defence -= ww->get_defence();
		return ww;
	}
	else {
		weapon = w;
		return NULL;
	}
}

CClothes* CFighter::wear_clothes(CClothes *c) {
	if (race != c->get_race()) {
		cout << "職業不符" << endl;
		system("pause");
		return c;
	}
	cout << "hp + " << c->get_hp() << " mp + " << c->get_mp() << " attack + " << c->get_attack() << " defence + " << c->get_defence() << endl;
	max_hp += c->get_hp();
	max_mp += c->get_mp();
	attack += c->get_attack();
	defence += c->get_defence();
	system("pause");
	if (clothes != NULL) {
		CClothes *cc;
		cc = clothes;
		clothes = c;
		max_hp -= cc->get_hp();
		max_mp -= cc->get_mp();
		attack -= cc->get_attack();
		defence -= cc->get_defence();
		return cc;
	}
	else {
		clothes = c;
		return NULL;
	}
}
void CFighter::use_food(CFood *food){
	if (food->get_hp() != 0) {
		cout << "使用了" << food->get_name() << "回復了" << food->get_hp() << "點血量" << endl;
		hp += food->get_hp();
		if (hp > max_hp)
			hp = max_hp;
	}
	if (food->get_mp() != 0) {
		cout << "使用了" << food->get_name() << "回復了" << food->get_mp() << "點魔力" << endl;
		mp += food->get_mp();
		if (mp > max_mp)
			mp = max_mp;
	}
	system("pause");

}
bool CFighter::use_skill_book(CSkill *sk) {
	bool get = false;
	for (int i = 0; i < skill.size(); i++) {
		if (skill[i]->get_name() == sk->get_name()) {
			cout << "已學會此技能" << endl;
			get = true;
		}
	}
	if (!get) {
		if (race != sk->get_race()) {
			cout << "職業不符" << endl;
			return false;
		}
		else {
			cout << "已學會" << sk->get_name() << endl;
			skill.push_back(sk);
			return true;
		}
	}
	return false;
}

void CFighter::show_skill_data() {
	while (1) {
		system("cls");
		cout << "技能點數：" << skill_point << endl;
		for (int i = 1; i < skill.size(); i++) {
			cout << i << "：" << skill[i]->get_name() << " " << "level：" << skill[i]->get_level() << endl;
		}
		int select;
		cin >> select;
		if (select < 0)
			break;
		if (select >= skill.size()) {
			cout << "無此技能" << endl;
			system("pause");
			continue;
		}
		if (skill_point <= 0) {
			cout << "技能點數不足" << endl;
			system("pause");
			continue;
		}
		cout << skill[select]->get_name() << "升級了" << endl;
		skill[select]->levelup();
		skill_point--;
		system("pause");

	}
}