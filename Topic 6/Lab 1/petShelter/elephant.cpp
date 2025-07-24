#include "elephant.h"

Elephant::Elephant(const std::string &id, const std::string &name) : Pet(id, name, Species::Elephant) {}

Elephant::Elephant(const std::string &name) : Elephant("", name) {}

std::string Elephant::speak() const { return "Grunt?"; }