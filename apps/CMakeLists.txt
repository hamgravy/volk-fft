#
# Copyright 2011-2013 Free Software Foundation, Inc.
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.
#

########################################################################
# Setup profiler
########################################################################
if(Boost_FOUND)

if(MSVC)
    include_directories(${CMAKE_SOURCE_DIR}/cmake/msvc)
endif(MSVC)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_BINARY_DIR}
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_BINARY_DIR}/include
    ${CMAKE_SOURCE_DIR}/lib
    ${CMAKE_BINARY_DIR}/lib
    ${Boost_INCLUDE_DIRS}
)

# MAKE volk_fft_profile
add_executable(volk_fft_profile
    ${CMAKE_CURRENT_SOURCE_DIR}/volk_fft_profile.cc
    ${CMAKE_SOURCE_DIR}/lib/qa_utils.cc
)

target_link_libraries(volk_fft_profile volk_fft ${Boost_LIBRARIES})

install(
    TARGETS volk_fft_profile
    DESTINATION bin
    COMPONENT "volk_fft"
)

# MAKE volk_fft-config-info
add_executable(volk_fft-config-info volk_fft-config-info.cc)
target_link_libraries(volk_fft-config-info volk_fft ${Boost_LIBRARIES})

install(
    TARGETS volk_fft-config-info
    DESTINATION bin
    COMPONENT "volk_fft"
)

endif(Boost_FOUND)
