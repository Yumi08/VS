#include "Character.hpp"
#include <iostream>
#include "Config.hpp"
#include <random>

void setup(){
   srand(time(0));
}

int main(){
   setup();

   Character yumi("Yumi");
   Character bob("Bob");

   bob.take_damage(10);

   VSCONFIG_PRINT(bob.get_hp());
}