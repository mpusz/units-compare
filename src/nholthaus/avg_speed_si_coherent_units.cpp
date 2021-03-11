#include <units.h>
#include <cassert>
#include <iostream>

namespace {

constexpr units::velocity::meters_per_second_t avg_speed(units::length::meter_t d, units::time::second_t t)
{
  return d / t;
}

template<typename T>
void km_per_h(const T& v)
{
  const units::velocity::kilometers_per_hour_t kmph = v;

  std::cout << "v = " << v << '\n';        // prints "v = 30.5556 m s^-1"
  std::cout << "kmph = " << kmph << '\n';  // prints "kmph = 30.5556 m s^-1"

  using namespace units::literals;
  assert(v.value() != 110);  // <=== !!!!
  assert(v == 110_kph);
  assert(kmph.value() == 110);
  assert(kmph == 110_kph);
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
  const units::velocity::miles_per_hour_t miph = v;

  std::cout << "v = " << v << '\n';        // prints "v = 31.2928 m s^-1"
  std::cout << "miph = " << miph << '\n';  // prints "miph = 30.5556 m s^-1"

  using namespace units::literals;
  assert(v.value() != 70);  // <=== !!!!
  assert(v == 70_mph);
  assert(miph.value() == 70);
  assert(miph == 70_mph);
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
