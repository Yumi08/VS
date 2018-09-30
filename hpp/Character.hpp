#pragma once
#include <string>

class Character{
   public:
   Character(std::string name);

   std::string name;
   bool is_alive;

   // props
   int get_hp() {return hp;}
   void set_hp(int hp);
   private:

   // props
   int hp;
};