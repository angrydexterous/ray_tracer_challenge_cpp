#ifndef TUPLES_H
#define TUPLES_H

#include <array>
#include <algorithm> 
#include <functional>
#include <numeric>
#include <cmath>

class Tuple {
  public:
    Tuple();
    Tuple(std::array<double, 4> tuple);
    Tuple(double x, double y, double z, double w);

    double x() const { return tuple_[0]; }
    double y() const { return tuple_[1]; }
    double z() const { return tuple_[2]; }
    double w() const { return tuple_[3]; }
    bool IsPoint() const;
    bool IsVector() const;
    Tuple add(const Tuple rhs) const;
    Tuple subtract(const Tuple rhs) const;
    Tuple negate() const;
    Tuple multiply(double x) const;
    Tuple divide(double x) const;
    double magnitude() const;

  protected: 
    std::array<double, 4> tuple_;
};

bool operator==(const Tuple lhs, const Tuple rhs);
Tuple operator+(const Tuple lhs, const Tuple rhs);
Tuple operator-(const Tuple lhs, const Tuple rhs);
Tuple operator-(const Tuple x);
Tuple operator*(double x, const Tuple t);
Tuple operator*(const Tuple t, double x);
Tuple operator/(const Tuple t, double x);


Tuple Point(double x, double y, double z);
Tuple Vector(double x, double y, double z);
#endif //TUPLES_H