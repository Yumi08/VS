#include "Character.hpp"
#include <iostream>

#define PRINT(x) std::cout << x << std::endl

int main(){
   Character yumi("Yumi");
   
   PRINT(yumi.get_hp());
   PRINT(yumi.is_alive);

   yumi.set_hp(0);

   PRINT(yumi.get_hp());
   PRINT(yumi.is_alive);

   yumi.set_hp(50);

   PRINT(yumi.get_hp());
   PRINT(yumi.is_alive);
}