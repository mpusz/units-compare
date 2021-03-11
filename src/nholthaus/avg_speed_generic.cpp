#include <units.h>
#include <cassert>
#include <iostream>

namespace {

template<typename Length, typename Time,
         typename = std::enable_if_t<units::traits::is_length_unit<Length>::value &&
                                     units::traits::is_time_unit<Time>::value>>
constexpr auto avg_speed(Length d, Time t)
{
  const auto v = d / t;
  static_assert(units::traits::is_velocity_unit<decltype(v)>::value);
  return v;
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
