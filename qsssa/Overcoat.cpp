#include "Overcoat.h"
#include <iostream>

Overcoat::Overcoat(std::string t, double p) : type(t), price(p) {}

bool Overcoat::operator==(const Overcoat& other) const {
    return type == other.type;
}

Overcoat& Overcoat::operator=(const Overcoat& other) {
    if (this != &other) {
        type = other.type;
        price = other.price;
    }
    return *this;
}

bool Overcoat::operator>(const Overcoat& other) const {
    if (*this == other) {
        return price > other.price;
    }
    return false;
}

void Overcoat::print() const {
    std::cout << "“ип: " << type << ", ÷ена: " << price << std::endl;
}
