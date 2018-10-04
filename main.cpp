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
   Character potato("Potato");

   yumi.attack(potato);
   yumi.attack(potato);

   VSCONFIG_PRINT(potato.get_hp());
}