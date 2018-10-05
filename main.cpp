#include "Character.hpp"
#include <iostream>
#include "Config.hpp"
#include <random>
#include <nlohmann/json.hpp>
#include <fstream>
#include "Game_Objects.hpp"
#include "Globals.hpp"

Game_Objects import_objects(){
   Game_Objects objects;

   // Read from file
   std::ifstream objects_file("Game_Objects.json", std::ios::in | std::ios::ate);
   std::string file_text;

   objects_file.seekg(0, std::ios::end);
   file_text.reserve(objects_file.tellg());
   objects_file.seekg(0, std::ios::beg);

   file_text.assign(std::istreambuf_iterator<char>(objects_file),
   std::istreambuf_iterator<char>());
   
   // Convert to json
   using json = nlohmann::json;

   auto objects_json = json::parse(file_text);

   // Create weapons
   for (auto i = objects_json.at("Weapons").begin(); i != objects_json.at("Weapons").end(); ++i){
      Weapon weapon;
      weapon.name = i->at("Name");
      // weapon.type = // Use unordered_map instead of enum and convert.
      weapon.damage = i->at("Damage");
      objects.weapons.push_back(weapon);
   }

   return objects;
};

void setup(){
   srand(time(0));
   Globals::game_objects = import_objects();
}

int main(){
   setup();

   VSCONFIG_PRINT(Globals::game_objects.weapons[0].name);
}