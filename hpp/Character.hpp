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

   // Amount of damage to take.
   int calculate_taken_damage(int dmg);
   void take_damage(int dmg);

   // Props
   int get_hp() {return prop_hp;}
   void set_hp(int hp);

   // Amount of damage to do.
   int get_damage_dealable(){return (strength + (rand() % 50 - 25));};

   private:
   // Props
   int prop_hp;
};