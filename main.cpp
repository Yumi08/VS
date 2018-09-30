#include "Character.hpp"
#include <iostream>
#include "Config.hpp"

void setup(){
   Config::write = [](std::string output){
      std::cout << output << std::endl;
   };
}

int main(){
   setup();

   Config::write("test");
}