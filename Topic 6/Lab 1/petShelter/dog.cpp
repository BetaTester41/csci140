#include "dog.h"

Dog::Dog(const std::string &id, const std::string &name) : Pet(id, name, Species::Dog) {}

Dog::Dog(const std::string &name) : Dog("", name) {}

std::string Dog::speak() const { return "Woof!"; }