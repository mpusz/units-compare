#include <units.h>
#include <cassert>
#include <iostream>

namespace {

template<typename T>
concept Length = units::traits::is_length_unit<T>::value;

template<typename T>
concept Time = units::traits::is_time_unit<T>::value;

template<typename T>
concept Velocity = units::traits::is_velocity_unit<T>::value;

constexpr Velocity auto avg_speed(Length auto d, Time auto t)
{
  return d / t;
}

template<typename T>
void km_per_h(const T& v)
{
  std::cout << "v = " << v << '\n'; // prints "v = 30.5556 m s^-1"

  using namespace units::literals;
  assert(v.value() == 110);
  assert(v == 110_kph);
}

void km_per_h()
{
  using namespace units::literals;
  constexpr auto v = avg_speed(220_km, 2_hr);
  km_per_h(v);
}

void km_per_h(double a, double b)
{
  const auto v = avg_speed(units::length::kilometer_t(a), units::time::hour_t(b));
  km_per_h(v);
}

template<typename T>
void mi_per_h(const T& v)
{
  std::cout << "v = " << v << '\n'; // prints "v = 31.2928 m s^-1"

  using namespace units::literals;
  assert(v.value() == 70);
  assert(v == 70_mph);
}

void mi_per_h()
{
  using namespace units::literals;
  const auto v = avg_speed(140_mi, 2_hr);
  mi_per_h(v);
}

void mi_per_h(double a, double b)
{
  const auto v = avg_speed(units::length::mile_t(a), units::time::hour_t(b));
  mi_per_h(v);
}

}  // namespace

int main()
{
  km_per_h();
  km_per_h(220, 2);
  mi_per_h();
  mi_per_h(140, 2);
}
