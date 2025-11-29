add_library(MathFunctions MathFunctions.cxx)

target_include_directories(MathFunctions
  INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:include>
)

option(USE_MYMATH "Use tutorial provided math implementation" ON)

if(USE_MYMATH)
  target_compile_definitions(MathFunctions PRIVATE "USE_MYMATH")

  add_executable(MakeTable MakeTable.cxx)

  add_custom_command(
    OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/Table.h
    COMMAND MakeTable ${CMAKE_CURRENT_BINARY_DIR}/Table.h
    DEPENDS MakeTable
  )

  add_library(SqrtLibrary STATIC
    mysqrt.cxx
    ${CMAKE_CURRENT_BINARY_DIR}/Table.h
  )

  target_include_directories(SqrtLibrary PRIVATE
    ${CMAKE_CURRENT_BINARY_DIR}
  )

  set_target_properties(SqrtLibrary PROPERTIES
    POSITION_INDEPENDENT_CODE ${BUILD_SHARED_LIBS}
  )

  target_link_libraries(MathFunctions PRIVATE SqrtLibrary)
endif()

target_compile_definitions(MathFunctions PRIVATE "EXPORTING_MYMATH")

set(installable_libs MathFunctions tutorial_compiler_flags)
if(TARGET SqrtLibrary)
  list(APPEND installable_libs SqrtLibrary)
endif()

install(TARGETS ${installable_libs}
  DESTINATION lib
  EXPORT MathFunctionsTargets
)

install(FILES MathFunctions.h DESTINATION include)

install(EXPORT MathFunctionsTargets
  FILE MathFunctionsTargets.cmake
  DESTINATION lib/cmake/MathFunctions
)
