#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

bool checkRNG(int chance);

struct Player
{
	string nazwa = "Wojownik";
	int currentHp = 100;
	int maxHp = 100;
	int lvl = 1;
	int skillPoints = 0;
	int currentEXP = 0;
	int maxEXP = 100;
	int strength = 0;
	int vitality = 0;
	int agility = 0;
	int dodge = 0;
	int damage = 10;
	int hitChance = 50;
	int morals = 0;
	int hit() {
		if (checkRNG(hitChance)) return damage + strength;
		else return 0;
	}
	void lvlUP() {
		do {
			currentEXP -= maxEXP;
			lvl++;
			skillPoints += 2;
		} while (currentEXP >= maxEXP);
		while (skillPoints > 0) {
			system("cls");
			cout << "Masz " << skillPoints << " punkty do rozdania!" << endl;
			cout << "Twoje staty:" << endl;
			cout << "1.Sila: " << strength << endl;
			cout << "2.Witalnosc: " << vitality << endl;
			cout << "3.Zrecznosc: " << agility << endl;
			cout << "Co dodac?(1,2,3)";
			int choice = 0;
			cin >> choice;
			switch (choice) {
				case 1:
					strength++;
					break;
				case 2:
					vitality++;
					maxHp += 10;
					currentHp = maxHp;
					break;
				case 3:
					agility++;
					dodge++;
					hitChance++;
					break;
				}
			skillPoints--;
		}	
	}
};
struct Enemy
{
	string nazwa = "Chrzaszcz";
	int hp = 50;
	int lvl = 1;
	int strength = 0;
	int vitality = 0;
	int agility = 0;
	int dodge = 0;
	int damage = 5;
	int hitChance = 50;
	int morals = 0;
	int hit(bool isDodged) {
		if (checkRNG(hitChance) && !isDodged) return damage + strength;
		else return 0;
	}
};
void start();
void fill_stats();
bool fight(Player player, Enemy enemy);
Player gracz;
Enemy potwor;

int main()
{
	srand(time(NULL));
	start();
	system("pause");
	return 0;
}

void start() {
	cout << "Wybrales wojownika." << endl;
	fill_stats();
	cout << fight(gracz, potwor);

}

void fill_stats() {
	gracz.strength = 1;
}

bool fight(Player player, Enemy enemy) {
	bool whoStart = checkRNG(50);
	if(!whoStart) player.currentHp -= enemy.hit(checkRNG(player.dodge));
	while (player.currentHp > 0 && enemy.hp > 0) {
		int action = 0;
		if (player.currentHp <= 0) return false;
		cout << "hp: " << player.currentHp << endl;
		cout << "hp wroga: " << enemy.hp << endl;
		cout << "co robisz?\n1. Atakuj \n2. Blok\n" << endl;
		cin >> action;
		if (action == 1) enemy.hp -= player.hit();
		if (action == 2) {
			player.currentHp += 10;
			if (player.currentHp > 100) player.currentHp = 100;
		}
		player.currentHp -= enemy.hit(checkRNG(player.dodge));
	}
	if (player.currentHp > 0) { 
		player.currentEXP += 1000;
		player.lvlUP();
		return true; 
	}
	else return false;
}

bool checkRNG(int chance) {
	int RNG = (rand() % 100) + 1;
	if (RNG <= chance) return true;
	else return false;
}
