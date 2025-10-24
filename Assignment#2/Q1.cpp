#include <iostream>
using namespace std;

class Weapon{
  public:
    string Name;
    float Damage;
    int Range;
 // public:
    void showStats(){
        cout<<"Weapon Name ### "<<Name<<endl;
        cout<<"Damage done by "<<Name<<" ### "<<Damage<<endl;
        cout<<"Range of "<<Name<<" ### "<<Range<<endl;
    }
    Weapon()
    {
        Name = "Talwar";
        Damage = 60.53;
        Range = 5 ;
    }
    Weapon(string name, float damage, int range)
    : Name(name), Damage(damage), Range(range) {}

 
};
class Player{
  public:
    string playerName;
    int health;
    Weapon weapon;
 // public:
    void attack()
    {
        cout<<playerName<<" is attacking with "<<weapon.Name<<endl;
    }
    Player()
    {
        playerName = "Ali" ;
        health = 100 ;
    }
    Player(string n, int h) : playerName(n) , health(h) {}
    void showPlayerInfo()
    {
        cout<<playerName<<" has "<<weapon.Name<<" as the weapon with the range of "<<weapon.Range<<"m and damage of "<<weapon.Damage<<endl;
        cout<<playerName<<" has health of "<<health<<" %"<<endl;
    }
    ~Player()
    {
        cout<<playerName<<" account deleted! Game OVer.."<<endl;
    }
};


int main()
{
    Weapon("Long Sword" , 60.50, 10);
    Player player1;
    player1.attack();
    player1.showPlayerInfo();
}
