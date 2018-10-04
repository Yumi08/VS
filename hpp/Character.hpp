#pragma once
#include <string>

// note: prefix all properties with prop_* and never access them directly

class Character{
   public:
   Character(std::string name);

   std::string name;
   bool is_alive;
   int strength;
   int base_defense;

   void attack(Character& opponent);
   int get_damage();
   void take_damage(int dmg);

   // props
   int get_hp() {return prop_hp;}
   void set_hp(int hp);

   private:
   // props
   int prop_hp;
};