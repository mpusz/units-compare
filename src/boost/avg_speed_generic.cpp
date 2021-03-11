#include <boost/units/base_units/metric/hour.hpp>
#include <boost/units/base_units/us/mile.hpp>
#include <boost/units/io.hpp>
#include <boost/units/make_scaled_unit.hpp>
#include <boost/units/quantity.hpp>
#include <boost/units/systems/si/length.hpp>
#include <boost/units/systems/si/prefixes.hpp>
#include <boost/units/systems/si/time.hpp>
#include <boost/units/systems/si/velocity.hpp>
#include <cassert>
#include <iostream>

namespace {

namespace bu = boost::units;

// h
using hour = bu::metric::hour_base_unit::unit_type;
BOOST_UNITS_STATIC_CONSTANT(hours, hour);

// km
using kilometer = bu::make_scaled_unit<bu::si::length, bu::scale<10, bu::static_rational<3>>>::type;

// km/h
using kilometer_per_hour = bu::divide_typeof_helper<kilometer, hour>::type;
BOOST_UNITS_STATIC_CONSTANT(kilometers_per_hour, kilometer_per_hour);

// mi
using mile = bu::us::mile_base_unit::unit_type;
BOOST_UNITS_STATIC_CONSTANT(miles, mile);

// mi/h
using mile_per_hour = bu::divide_typeof_helper<mile, hour>::type;
BOOST_UNITS_STATIC_CONSTANT(miles_per_hour, mile_per_hour);

template<typename LengthSystem, typename Rep1, typename TimeSystem, typename Rep2>
constexpr auto avg_speed(bu::quantity<bu::unit<bu::length_dimension, LengthSystem>, Rep1> d,
                         bu::quantity<bu::unit<bu::time_dimension, TimeSystem>, Rep2> t)
{
  return d / t;
}

template<typename T>
void km_per_h(const T& v)
{
  std::cout << "v = " << v << '\n'; // prints "v = 110 k(m h^-1)"

  using namespace bu::si;
  assert(v.value() == 110);
  assert(v == 110 * kilometers_per_hour);
}

void km_per_h()
{
  using namespace bu::si;
  constexpr auto v = avg_speed(220 * kilo * meters, 2 * hours);
  km_per_h(v);
}

void km_per_h(double a, double b)
{
  using namespace bu::si;
  const auto v = avg_speed(a * kilo * meters, b * hours);
  km_per_h(v);
}

template<typename T>
void mi_per_h(const T& v)
{
  std::cout << "v = " << v << '\n'; // prints "v = 70 mi h^-1"

  using namespace bu::si;
  assert(v.value() == 70);
  assert(v == 70 * miles_per_hour);
}

void mi_per_h()
{
  using namespace bu::si;

  const auto v = avg_speed(140 * miles, 2 * hours);
  mi_per_h(v);
}

void mi_per_h(double a, double b)
{
  using namespace bu::si;

  const auto v = avg_speed(a * miles, b * hours);
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
