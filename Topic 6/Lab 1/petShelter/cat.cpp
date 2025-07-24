#include "cat.h"

Cat::Cat(const std::string &id, const std::string &name) : Pet(id, name, Species::Cat) {}

Cat::Cat(const std::string &name) : Cat("", name) {}

std::string Cat::speak() const { return "Meow."; }