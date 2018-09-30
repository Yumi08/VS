#include "Character.hpp"

Character::Character(std::string name)
: name(name)
{
   hp = 100;
   is_alive = 1;
}

void Character::set_hp(int hp){
   if (hp <= 0){
      this->hp = 0;
      is_alive = false;
   }
   else {
      this->hp = hp;
      is_alive = true;
   }
}