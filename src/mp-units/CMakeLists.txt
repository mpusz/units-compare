find_package(mp-units CONFIG REQUIRED)

add_executable(mp_units_avg_speed_si_coherent_units avg_speed_si_coherent_units.cpp)
target_compile_features(mp_units_avg_speed_si_coherent_units PRIVATE cxx_std_20)
target_link_libraries(mp_units_avg_speed_si_coherent_units PRIVATE mp-units::mp-units)

add_executable(mp_units_avg_speed_concepts avg_speed_concepts.cpp)
target_compile_features(mp_units_avg_speed_concepts PRIVATE cxx_std_20)
target_link_libraries(mp_units_avg_speed_concepts PRIVATE mp-units::mp-units)
