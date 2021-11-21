#include "tuple.h"
#include "math.h"

Tuple::Tuple(){
  tuple_ = std::array<double,4> {0.0, 0.0, 0.0, 0.0};
}

Tuple::Tuple(std::array<double, 4> tuple){
  tuple_ = tuple;
}

Tuple::Tuple(double x, double y, double z, double w) {
  tuple_ = std::array<double,4> {x,y,z,w};
};

bool Tuple::IsPoint() const{
  return epsilon_eq(tuple_[3], 1.0);
}

bool Tuple::IsVector() const{
  return epsilon_eq(tuple_[3], 0.0);
}

Tuple Tuple::add(const Tuple rhs) const{
  std::array<double, 4> r;
  std::transform(tuple_.begin(), tuple_.end(), rhs.tuple_.begin(), r.begin(), std::plus<double>());
  return std::move(Tuple(r));
}

Tuple Tuple::subtract(const Tuple rhs) const{
  std::array<double, 4> r;
  std::transform(tuple_.begin(), tuple_.end(), rhs.tuple_.begin(), r.begin(), std::minus<double>());
  return std::move(Tuple(r));
}

Tuple Tuple::negate() const{
  std::array<double, 4> r;
  std::transform(tuple_.begin(), tuple_.end(), r.begin(), std::negate<double>());
  return std::move(Tuple(r));
}

Tuple Tuple::multiply(double x) const{
  std::array<double, 4> r;
  std::transform(tuple_.begin(), tuple_.end(), r.begin(), [&x](double c){return c*x;});
  return std::move(Tuple(r));
}

Tuple Tuple::divide(double x) const{
  std::array<double, 4> r;
  std::transform(tuple_.begin(), tuple_.end(), r.begin(), [&x](double c){return c/x;});
  return std::move(Tuple(r));
}

double Tuple::magnitude() const{
  auto acc = std::accumulate(tuple_.begin(), tuple_.end(), 0, [](double acc, double c){return acc + std::pow(c,2);});
  return sqrt(acc);
}

bool operator==(const Tuple lhs, const Tuple rhs) {
  return epsilon_eq(lhs.x(), rhs.x()) &&
    epsilon_eq(lhs.y(), rhs.y()) &&
    epsilon_eq(lhs.z(), rhs.z()) &&
    epsilon_eq(lhs.w(), rhs.w());
}

Tuple operator+(const Tuple lhs, const Tuple rhs) {
  auto r = lhs.add(rhs);
  return std::move(r);
}

Tuple operator-(const Tuple lhs, const Tuple rhs) {
  auto r = lhs.subtract(rhs);
  return std::move(r);
}

Tuple operator-(const Tuple x){
  auto r = x.negate();
  return std::move(r);
}

Tuple operator*(double x, const Tuple t){
  auto r = t.multiply(x);
  return std::move(r);
}

Tuple operator*(const Tuple t, double x){
  auto r = t.multiply(x);
  return std::move(r);
}

Tuple operator/(const Tuple t, double x){
  auto r = t.divide(x);
  return std::move(r);
}

Tuple Point(double x, double y, double z) {
  return Tuple(x, y, z, 1.0);
}

Tuple Vector(double x, double y, double z) {
  return Tuple(x, y, z, 0.0);
}