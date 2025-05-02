#pragma once
#ifndef OVERCOAT_H
#define OVERCOAT_H

#include <string>

class Overcoat {
private:
    std::string type;
    double price;

public:
    Overcoat(std::string t = "", double p = 0.0);

    bool operator==(const Overcoat& other) const;
    Overcoat& operator=(const Overcoat& other);
    bool operator>(const Overcoat& other) const;

    void print() const;
};

#endif // OVERCOAT_H
