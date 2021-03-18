#include <units/isq/si/speed.h>
#include <units/isq/si/international/speed.h>
#include <units/quantity_io.h>
#include <cassert>
#include <iostream>

namespace {

using namespace units::isq;

constexpr Speed auto avg_speed(Length auto d, Time auto t)
{
  return d / t;
}

template<typename T>
void km_per_h(const T& v)
{
  std::cout << "v = " << v << '\n';        // prints "v = 110 km/h"

  using namespace si::unit_constants;
  assert(v.count() == 110);
  assert(v == 110 * km / h);
}

void km_per_h()
{
  using namespace si::literals;
  constexpr auto v1 = avg_speed(220_q_km, 2_q_h);
  km_per_h(v1);

  using namespace si::unit_constants;
  constexpr auto v2 = avg_speed(220 * km, 2 * h);
  km_per_h(v2);
}

void km_per_h(double a, double b)
{
  const auto v1 = avg_speed(si::length<si::kilometre>(a), si::time<si::hour>(b));
  km_per_h(v1);

  using namespace si::unit_constants;
  const auto v2 = avg_speed(a * km, b * h);
  km_per_h(v2);
}

template<typename T>
void mi_per_h(const T& v)
{
  std::cout << "v = " << v << '\n';        // prints "v = 70 mi/h"

  using namespace si::unit_constants;
  using namespace si::international::unit_constants;
  assert(v.count() == 70);
  assert(v == 70 * mi / h);
}

void mi_per_h()
{
  using namespace si::literals;
  using namespace si::international::literals;
  constexpr auto v1 = avg_speed(140_q_mi, 2_q_h);
  mi_per_h(v1);

  using namespace si::unit_constants;
  using namespace si::international::unit_constants;
  constexpr auto v2 = avg_speed(140 * mi, 2 * h);
  mi_per_h(v2);
}

void mi_per_h(double a, double b)
{
  const auto v1 = avg_speed(si::length<si::international::mile>(a), si::time<si::hour>(b));
  mi_per_h(v1);

  using namespace si::unit_constants;
  using namespace si::international::unit_constants;
  const auto v2 = avg_speed(a * mi, b * h);
  mi_per_h(v2);
}

}  // namespace

int main()
{
  km_per_h();
  km_per_h(220, 2);
  mi_per_h();
  mi_per_h(140, 2);
}
