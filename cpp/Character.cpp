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
   int damage = get_damage();
   VSCONFIG_PRINT(name+" deals "+std::to_string(damage)+" damage to "+opponent.name+"!");
   opponent.set_hp(opponent.get_hp() - damage);
}

int Character::get_damage(){
   return (strength + (rand() % 50 - 25));
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