#include "Character.hpp"
#include "Config.hpp"

Character::Character(std::string name)
: name(name)
{
   prop_hp = 100;
   is_alive = 1;
   strength = 50;
   base_defense = 50;
}

void Character::attack(Character& opponent){
   int damage = get_damage();
   VSCONFIG_PRINT(name+" deals "+std::to_string(damage)+" damage to "+opponent.name+"!");
   opponent.take_damage(damage);
}

int Character::get_damage(){
   return (strength + (rand() % 50 - 25));
}

void Character::take_damage(int dmg){
   set_hp(get_hp() - (dmg*(100/(100+(float)base_defense))));
}

void Character::set_hp(int hp){
   if (hp <= 0){
      prop_hp = hp;
      is_alive = false;
      VSCONFIG_PRINT(name+" has died!");
   }
   else {
      prop_hp = hp;
      is_alive = true;
   }
}