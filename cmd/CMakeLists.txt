include_directories(
    ${CMAKE_CURRENT_BINARY_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}
)

set(cutelyst_cmd_SRCS
    uwsgiprocess.cpp
    main.cpp
)

add_executable(cutelyst-skell ${cutelyst_cmd_SRCS})
target_compile_features(cutelyst-skell
  PUBLIC
    cxx_generalized_initializers
)
target_link_libraries(cutelyst-skell
    Qt5::Core
    Qt5::Network
)

set_target_properties(cutelyst-skell PROPERTIES OUTPUT_NAME cutelyst)
install(TARGETS cutelyst-skell DESTINATION ${CMAKE_INSTALL_PREFIX}/bin/)
