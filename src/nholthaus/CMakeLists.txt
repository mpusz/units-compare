find_package(units CONFIG REQUIRED)

add_executable(nholthaus_avg_speed_si_coherent_units avg_speed_si_coherent_units.cpp)
target_link_libraries(nholthaus_avg_speed_si_coherent_units PRIVATE units::units)

add_executable(nholthaus_avg_speed_generic avg_speed_generic.cpp)
target_compile_features(nholthaus_avg_speed_generic PRIVATE cxx_std_17)
target_link_libraries(nholthaus_avg_speed_generic PRIVATE units::units)

add_executable(nholthaus_avg_speed_concepts avg_speed_concepts.cpp)
target_compile_features(nholthaus_avg_speed_concepts PRIVATE cxx_std_20)
target_link_libraries(nholthaus_avg_speed_concepts PRIVATE units::units)
