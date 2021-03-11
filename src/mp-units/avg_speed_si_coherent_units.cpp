#include <units/physical/si/derived/speed.h>
#include <units/physical/si/international/derived/speed.h>
#include <units/quantity_io.h>
#include <cassert>
#include <iostream>

namespace {

using namespace units::physical;

constexpr si::speed<si::metre_per_second> avg_speed(si::length<si::metre> d, si::time<si::second> t)
{
  return d / t;
}

template<typename T>
void km_per_h(const T& v)
{
  const si::speed<si::kilometre_per_hour> kmph = v;

  std::cout << "v = " << v << '\n';        // prints "v = 30.5556 m/s"
  std::cout << "kmph = " << kmph << '\n';  // prints "kmph = 110 km/h"

  using namespace si::unit_constants;
  assert(v.count() != 110);     // <=== !!!!
  assert(v == 110 * km / h);
  assert(kmph.count() != 110);  // <=== !!!!
  assert(kmph != 110 * km / h); // <=== !!!!
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
  const si::speed<si::international::mile_per_hour> miph = v;

  std::cout << "v = " << v << '\n';        // prints "v = 31.2928 m/s"
  std::cout << "miph = " << miph << '\n';  // prints "miph = 70 mi/h"

  using namespace si::unit_constants;
  using namespace si::international::unit_constants;
  assert(v.count() != 70);  // <=== !!!!
  assert(v == 70 * mi / h);
  assert(miph.count() == 70);
  assert(miph == 70 * mi / h);
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
