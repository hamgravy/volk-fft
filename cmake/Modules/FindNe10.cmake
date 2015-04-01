include(FindPkgConfig)
pkg_check_modules(NE10 ne10)


find_path(NE10_INCLUDE_DIR
  NAMES
    ne10/NE10.h
  PATHS
	include
)

find_library(NE10_LIBRARY
  NAMES
    NE10
  PATHS
	lib
)

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(NE10 DEFAULT_MSG NE10_INCLUDE_DIR NE10_LIBRARY)
mark_as_advanced(NE10_INCLUDE_DIR NE10_LIBRARY)
