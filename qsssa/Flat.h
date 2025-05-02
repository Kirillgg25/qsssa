#pragma once
#ifndef FLAT_H
#define FLAT_H

class Flat {
private:
    double area;
    double price;

public:
    Flat(double a = 0.0, double p = 0.0);

    bool operator==(const Flat& other) const;
    Flat& operator=(const Flat& other);
    bool operator>(const Flat& other) const;

    void print() const;
};

#endif // FLAT_H
