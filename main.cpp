#include <iostream>

using namespace std;

struct Player
{
    string nazwa = "Wojownik";
    int hp = 100;
    int lvl = 1;
    int strength = 0;
    int vitality = 0;
    int agility = 0;
    int morals = 0;
    int hit() {
       return 10;
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
    int morals = 0;
    int hit() {
       return 5;
    }
};
void start();
void fill_stats();
bool fight(Player player, Enemy enemy);
Player gracz;
Enemy potwor;

int main()
{
    start();
    return 0;
}

void start() {
    cout << "Wybrales wojownika." << endl;
    fill_stats();
    cout << fight(gracz, potwor);

}

void fill_stats() {
    gracz.strength=1;
}

bool fight(Player player, Enemy enemy){
    while(player.hp > 0 && enemy.hp > 0) {
        int action = 0;
        player.hp -= enemy.hit();
        if (player.hp <= 0) return false;
        cout << "hp: " << player.hp << endl;
        cout << "hp wroga: " << enemy.hp << endl;
        cout << "co robisz?\n1. Atakuj \n2. Blok\n" << endl;
        cin >> action;
        if(action == 1) enemy.hp -= player.hit();
        if(action == 2) {
            player.hp += 10;
            if (player.hp > 100) player.hp = 100;
        }
    }
    if (player.hp > 0) return true;
    else return false;
}
