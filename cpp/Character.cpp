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
   int damage = get_damage_dealable();
   VSCONFIG_PRINT(name+" deals "+std::to_string(calculate_taken_damage(damage))+" damage to "+opponent.name+"!");
   opponent.take_damage(damage);
}

int Character::calculate_taken_damage(int dmg){
   return dmg*(100/(100+(float)base_defense));
}

void Character::take_damage(int dmg){
   int damage = calculate_taken_damage(dmg);
   set_hp(get_hp() - damage);

   #if HEAVYDEBUG
      VSCONFIG_PRINT("dmg: "+std::to_string(dmg));
      VSCONFIG_PRINT("taken: "+std::to_string(damage));
   #endif
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