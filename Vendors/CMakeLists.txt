set(ASH_ENABLE_USAGE_OF_EXTERNAL_VENDORS ON)
set(ASH_ENABLE_LOGGER ON)

add_subdirectory("Ash")
add_subdirectory("fmt")
add_subdirectory("glfw")

include("pcg.cmake")
include("imgui.cmake")
