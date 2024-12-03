cmake_minimum_required(VERSION 3.16.3)
project(IOMeshMZ3Examples)

set(ExampleSpecificComponents
  IOMeshMZ3
  )

if(NOT ITK_SOURCE_DIR)
  find_package(ITK REQUIRED COMPONENTS ITKMeshIO ${ExampleSpecificComponents})
else()
  # When being built as part of ITK, ITKMeshIO
  # lists of modules are not yet ready, causing a configure error
  find_package(ITK REQUIRED COMPONENTS ${ExampleSpecificComponents})
endif()
include(${ITK_USE_FILE})

add_executable(ReadWriteMZ3Mesh ReadWriteMZ3Mesh.cxx)
target_link_libraries(ReadWriteMZ3Mesh ${ITK_LIBRARIES})

enable_testing()
add_test(NAME ReadWriteMZ3MeshTest
  COMMAND ReadWriteMZ3Mesh
    ${CMAKE_CURRENT_SOURCE_DIR}/cortex_5124.mz3
    ${CMAKE_CURRENT_BINARY_DIR}/cortex_5124_itk.mz3
    1
  )