#include "Character.hpp"
#include "Config.hpp"

Character::Character(std::string name)
: name(name)
{
   hp = 100;
   is_alive = 1;
   strength = 50;
}

void Character::attack(Character& opponent){
   int damage = strength + (rand() % 50 - 25);
   VSCONFIG_PRINT(name+" deals "+std::to_string(damage)+" damage to "+opponent.name+"!");
   opponent.set_hp(opponent.get_hp() - damage);
}

void Character::set_hp(int hp){
   if (hp <= 0){
      this->hp = 0;
      is_alive = false;
      VSCONFIG_PRINT(name+" has died!");
   }
   else {
      this->hp = hp;
      is_alive = true;
   }
}