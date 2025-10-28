#include <iostream>
using namespace std;

class Weapon{
  public:
    string Name;
    float Damage;
    int Range;
 // public:
    void showStats(){
        cout<<"Weapon Name ###"<<Name<<endl;
        cout<<"Damage done by "<<Name<<" ###"<<Damage<<endl;
        cout<<"Range of "<<Name<<" ###"<<Range<<endl;
    }
    Weapon()
    {
        Name = "Kalashankov";
        Damage = 60.53;
        Range = 5 ;
        cout << "Weapon " << Name << " created!" << endl;
    }
    Weapon(string name, float damage, int range)
    : Name(name), Damage(damage), Range(range) 
    {
         cout << "Weapon " << Name << " created!" << endl;
    }
    
    ~Weapon() {
    cout << "Weapon " << Name << " destroyed!" << endl;
}


 
};
class Player{
  public:
    string playerName;
    int health;
    Weapon weapon;
 // This is composition relationship.
    void attack()
    {
        cout<<playerName<<" is attacking with "<<weapon.Name<<endl;
    }
    Player()
    {
        playerName = "Ali" ;
        health = 100 ;
    }
    Player(string n, int h, string wName, float wDamage, int wRange)
    : playerName(n), health(h), weapon(wName, wDamage, wRange)
    {
        cout << "Player " << playerName << " joined the game!" << endl;
    }
    void showPlayerInfo()
    {
        cout<<playerName<<" has "<<weapon.Name<<" as the weapon with the range of "<<weapon.Range<<"m and damage of "<<weapon.Damage<<endl;
        cout<<playerName<<" has health of "<<health<<" %"<<endl;
    }
    ~Player()
    {
        cout<<playerName<<" account and "<<weapon.Name<<" deleted! Game OVer.."<<endl;
    }
};


int main()
{
    Weapon weapon("Long Sword" , 60.50, 10);
    weapon.showStats(); 
    cout<<endl;
    Player player1;
    player1.attack();
    player1.showPlayerInfo();
    
    Player p2("Imran", 100, "Bow", 40.0, 15);
    Player p3("Noor", 80, "Gun", 75.0, 30);
    cout << "\n=== Player Info ===" << endl;
   
    p2.showPlayerInfo();
    p3.showPlayerInfo();

    cout << "\n=== Attack Simulation ===" << endl;
   
    p2.attack();
    p3.attack();

}
