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

constexpr bu::quantity<bu::si::velocity> avg_speed(bu::quantity<bu::si::length> d, bu::quantity<bu::si::time> t)
{
  return d / t;
  // return d * t;
}

template<typename T>
void km_per_h(const T& v)
{
  const bu::quantity<kilometer_per_hour> kmph(v);

  std::cout << "v = " << v << '\n';       // prints "v = 30.5556 m s^-1"
  std::cout << "kmph = " << kmph << '\n'; // prints "kmph = 110 k(m h^-1)"

  assert(v.value() != 110);                                                 // <=== !!!!
  assert(v == bu::quantity<bu::si::velocity>(110 * kilometers_per_hour));
  assert(bu::quantity<kilometer_per_hour>(v) != 110 * kilometers_per_hour); // <=== !!!!
  assert(kmph.value() != 110);                                              // <=== !!!!
  assert(kmph != 110 * kilometers_per_hour);                                // <=== !!!!
}

void km_per_h()
{
  constexpr auto v = avg_speed(bu::quantity<bu::si::length>(220 * bu::si::kilo * bu::si::meters), bu::quantity<bu::si::time>(2 * hours));
  km_per_h(v);
}

void km_per_h(double a, double b)
{
  const auto v = avg_speed(bu::quantity<bu::si::length>(a * bu::si::kilo * bu::si::meters), bu::quantity<bu::si::time>(b * hours));
  km_per_h(v);
}

template<typename T>
void mi_per_h(const T& v)
{
  const bu::quantity<mile_per_hour> miph(v);

  std::cout << "v = " << v << '\n';       // prints "v = 31.2928 m s^-1"
  std::cout << "miph = " << miph << '\n'; // prints "miph = 70 mi h^-1"

  assert(v.value() != 70);                                          // <=== !!!!
  assert(v == bu::quantity<bu::si::velocity>(70 * miles_per_hour));
  assert(bu::quantity<mile_per_hour>(v) != 70 * miles_per_hour);    // <=== !!!!
  assert(miph.value() != 70);                                       // <=== !!!!
  assert(miph != 70 * miles_per_hour);                              // <=== !!!!
}

void mi_per_h()
{
  const auto v2 = avg_speed(bu::quantity<bu::si::length>(140 * miles), bu::quantity<bu::si::time>(2 * hours));
  mi_per_h(v2);
}

void mi_per_h(double a, double b)
{
  const auto v2 = avg_speed(bu::quantity<bu::si::length>(a * miles), bu::quantity<bu::si::time>(b * hours));
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
