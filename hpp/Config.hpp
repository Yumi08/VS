#pragma once
#include <string>

struct Config{
   inline static void (*write)(std::string output) = 0;
};