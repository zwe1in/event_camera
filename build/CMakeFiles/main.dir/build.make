# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/zw/event_camera

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/zw/event_camera/build

# Include any dependencies generated for this target.
include CMakeFiles/main.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/main.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/main.dir/flags.make

CMakeFiles/main.dir/main.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zw/event_camera/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/main.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/main.cpp.o -c /home/zw/event_camera/main.cpp

CMakeFiles/main.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zw/event_camera/main.cpp > CMakeFiles/main.dir/main.cpp.i

CMakeFiles/main.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zw/event_camera/main.cpp -o CMakeFiles/main.dir/main.cpp.s

CMakeFiles/main.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/main.dir/main.cpp.o.requires

CMakeFiles/main.dir/main.cpp.o.provides: CMakeFiles/main.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/main.dir/main.cpp.o.provides

CMakeFiles/main.dir/main.cpp.o.provides.build: CMakeFiles/main.dir/main.cpp.o


CMakeFiles/main.dir/src/IOUtil.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/src/IOUtil.cpp.o: ../src/IOUtil.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zw/event_camera/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/main.dir/src/IOUtil.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/src/IOUtil.cpp.o -c /home/zw/event_camera/src/IOUtil.cpp

CMakeFiles/main.dir/src/IOUtil.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/src/IOUtil.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zw/event_camera/src/IOUtil.cpp > CMakeFiles/main.dir/src/IOUtil.cpp.i

CMakeFiles/main.dir/src/IOUtil.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/src/IOUtil.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zw/event_camera/src/IOUtil.cpp -o CMakeFiles/main.dir/src/IOUtil.cpp.s

CMakeFiles/main.dir/src/IOUtil.cpp.o.requires:

.PHONY : CMakeFiles/main.dir/src/IOUtil.cpp.o.requires

CMakeFiles/main.dir/src/IOUtil.cpp.o.provides: CMakeFiles/main.dir/src/IOUtil.cpp.o.requires
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/IOUtil.cpp.o.provides.build
.PHONY : CMakeFiles/main.dir/src/IOUtil.cpp.o.provides

CMakeFiles/main.dir/src/IOUtil.cpp.o.provides.build: CMakeFiles/main.dir/src/IOUtil.cpp.o


CMakeFiles/main.dir/src/filter.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/src/filter.cpp.o: ../src/filter.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zw/event_camera/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/main.dir/src/filter.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/src/filter.cpp.o -c /home/zw/event_camera/src/filter.cpp

CMakeFiles/main.dir/src/filter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/src/filter.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zw/event_camera/src/filter.cpp > CMakeFiles/main.dir/src/filter.cpp.i

CMakeFiles/main.dir/src/filter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/src/filter.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zw/event_camera/src/filter.cpp -o CMakeFiles/main.dir/src/filter.cpp.s

CMakeFiles/main.dir/src/filter.cpp.o.requires:

.PHONY : CMakeFiles/main.dir/src/filter.cpp.o.requires

CMakeFiles/main.dir/src/filter.cpp.o.provides: CMakeFiles/main.dir/src/filter.cpp.o.requires
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/filter.cpp.o.provides.build
.PHONY : CMakeFiles/main.dir/src/filter.cpp.o.provides

CMakeFiles/main.dir/src/filter.cpp.o.provides.build: CMakeFiles/main.dir/src/filter.cpp.o


CMakeFiles/main.dir/src/event.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/src/event.cpp.o: ../src/event.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zw/event_camera/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/main.dir/src/event.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/src/event.cpp.o -c /home/zw/event_camera/src/event.cpp

CMakeFiles/main.dir/src/event.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/src/event.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zw/event_camera/src/event.cpp > CMakeFiles/main.dir/src/event.cpp.i

CMakeFiles/main.dir/src/event.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/src/event.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zw/event_camera/src/event.cpp -o CMakeFiles/main.dir/src/event.cpp.s

CMakeFiles/main.dir/src/event.cpp.o.requires:

.PHONY : CMakeFiles/main.dir/src/event.cpp.o.requires

CMakeFiles/main.dir/src/event.cpp.o.provides: CMakeFiles/main.dir/src/event.cpp.o.requires
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/event.cpp.o.provides.build
.PHONY : CMakeFiles/main.dir/src/event.cpp.o.provides

CMakeFiles/main.dir/src/event.cpp.o.provides.build: CMakeFiles/main.dir/src/event.cpp.o


CMakeFiles/main.dir/src/region.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/src/region.cpp.o: ../src/region.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zw/event_camera/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/main.dir/src/region.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/src/region.cpp.o -c /home/zw/event_camera/src/region.cpp

CMakeFiles/main.dir/src/region.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/src/region.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zw/event_camera/src/region.cpp > CMakeFiles/main.dir/src/region.cpp.i

CMakeFiles/main.dir/src/region.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/src/region.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zw/event_camera/src/region.cpp -o CMakeFiles/main.dir/src/region.cpp.s

CMakeFiles/main.dir/src/region.cpp.o.requires:

.PHONY : CMakeFiles/main.dir/src/region.cpp.o.requires

CMakeFiles/main.dir/src/region.cpp.o.provides: CMakeFiles/main.dir/src/region.cpp.o.requires
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/region.cpp.o.provides.build
.PHONY : CMakeFiles/main.dir/src/region.cpp.o.provides

CMakeFiles/main.dir/src/region.cpp.o.provides.build: CMakeFiles/main.dir/src/region.cpp.o


# Object files for target main
main_OBJECTS = \
"CMakeFiles/main.dir/main.cpp.o" \
"CMakeFiles/main.dir/src/IOUtil.cpp.o" \
"CMakeFiles/main.dir/src/filter.cpp.o" \
"CMakeFiles/main.dir/src/event.cpp.o" \
"CMakeFiles/main.dir/src/region.cpp.o"

# External object files for target main
main_EXTERNAL_OBJECTS =

main: CMakeFiles/main.dir/main.cpp.o
main: CMakeFiles/main.dir/src/IOUtil.cpp.o
main: CMakeFiles/main.dir/src/filter.cpp.o
main: CMakeFiles/main.dir/src/event.cpp.o
main: CMakeFiles/main.dir/src/region.cpp.o
main: CMakeFiles/main.dir/build.make
main: /usr/local/lib/libopencv_gapi.so.4.5.0
main: /usr/local/lib/libopencv_stitching.so.4.5.0
main: /usr/local/lib/libopencv_alphamat.so.4.5.0
main: /usr/local/lib/libopencv_aruco.so.4.5.0
main: /usr/local/lib/libopencv_bgsegm.so.4.5.0
main: /usr/local/lib/libopencv_bioinspired.so.4.5.0
main: /usr/local/lib/libopencv_ccalib.so.4.5.0
main: /usr/local/lib/libopencv_cudabgsegm.so.4.5.0
main: /usr/local/lib/libopencv_cudafeatures2d.so.4.5.0
main: /usr/local/lib/libopencv_cudaobjdetect.so.4.5.0
main: /usr/local/lib/libopencv_cudastereo.so.4.5.0
main: /usr/local/lib/libopencv_dnn_objdetect.so.4.5.0
main: /usr/local/lib/libopencv_dnn_superres.so.4.5.0
main: /usr/local/lib/libopencv_dpm.so.4.5.0
main: /usr/local/lib/libopencv_face.so.4.5.0
main: /usr/local/lib/libopencv_freetype.so.4.5.0
main: /usr/local/lib/libopencv_fuzzy.so.4.5.0
main: /usr/local/lib/libopencv_hdf.so.4.5.0
main: /usr/local/lib/libopencv_hfs.so.4.5.0
main: /usr/local/lib/libopencv_img_hash.so.4.5.0
main: /usr/local/lib/libopencv_intensity_transform.so.4.5.0
main: /usr/local/lib/libopencv_line_descriptor.so.4.5.0
main: /usr/local/lib/libopencv_mcc.so.4.5.0
main: /usr/local/lib/libopencv_quality.so.4.5.0
main: /usr/local/lib/libopencv_rapid.so.4.5.0
main: /usr/local/lib/libopencv_reg.so.4.5.0
main: /usr/local/lib/libopencv_rgbd.so.4.5.0
main: /usr/local/lib/libopencv_saliency.so.4.5.0
main: /usr/local/lib/libopencv_stereo.so.4.5.0
main: /usr/local/lib/libopencv_structured_light.so.4.5.0
main: /usr/local/lib/libopencv_superres.so.4.5.0
main: /usr/local/lib/libopencv_surface_matching.so.4.5.0
main: /usr/local/lib/libopencv_tracking.so.4.5.0
main: /usr/local/lib/libopencv_videostab.so.4.5.0
main: /usr/local/lib/libopencv_viz.so.4.5.0
main: /usr/local/lib/libopencv_xfeatures2d.so.4.5.0
main: /usr/local/lib/libopencv_xobjdetect.so.4.5.0
main: /usr/local/lib/libopencv_xphoto.so.4.5.0
main: libparameterize.a
main: /usr/local/lib/libopencv_shape.so.4.5.0
main: /usr/local/lib/libopencv_highgui.so.4.5.0
main: /usr/local/lib/libopencv_datasets.so.4.5.0
main: /usr/local/lib/libopencv_plot.so.4.5.0
main: /usr/local/lib/libopencv_text.so.4.5.0
main: /usr/local/lib/libopencv_dnn.so.4.5.0
main: /usr/local/lib/libopencv_ml.so.4.5.0
main: /usr/local/lib/libopencv_phase_unwrapping.so.4.5.0
main: /usr/local/lib/libopencv_cudacodec.so.4.5.0
main: /usr/local/lib/libopencv_videoio.so.4.5.0
main: /usr/local/lib/libopencv_cudaoptflow.so.4.5.0
main: /usr/local/lib/libopencv_cudalegacy.so.4.5.0
main: /usr/local/lib/libopencv_cudawarping.so.4.5.0
main: /usr/local/lib/libopencv_optflow.so.4.5.0
main: /usr/local/lib/libopencv_ximgproc.so.4.5.0
main: /usr/local/lib/libopencv_video.so.4.5.0
main: /usr/local/lib/libopencv_imgcodecs.so.4.5.0
main: /usr/local/lib/libopencv_objdetect.so.4.5.0
main: /usr/local/lib/libopencv_calib3d.so.4.5.0
main: /usr/local/lib/libopencv_features2d.so.4.5.0
main: /usr/local/lib/libopencv_flann.so.4.5.0
main: /usr/local/lib/libopencv_photo.so.4.5.0
main: /usr/local/lib/libopencv_cudaimgproc.so.4.5.0
main: /usr/local/lib/libopencv_cudafilters.so.4.5.0
main: /usr/local/lib/libopencv_imgproc.so.4.5.0
main: /usr/local/lib/libopencv_cudaarithm.so.4.5.0
main: /usr/local/lib/libopencv_core.so.4.5.0
main: /usr/local/lib/libopencv_cudev.so.4.5.0
main: /usr/local/cuda-11.2/lib64/libcudart_static.a
main: /usr/lib/x86_64-linux-gnu/librt.so
main: CMakeFiles/main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/zw/event_camera/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable main"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/main.dir/build: main

.PHONY : CMakeFiles/main.dir/build

CMakeFiles/main.dir/requires: CMakeFiles/main.dir/main.cpp.o.requires
CMakeFiles/main.dir/requires: CMakeFiles/main.dir/src/IOUtil.cpp.o.requires
CMakeFiles/main.dir/requires: CMakeFiles/main.dir/src/filter.cpp.o.requires
CMakeFiles/main.dir/requires: CMakeFiles/main.dir/src/event.cpp.o.requires
CMakeFiles/main.dir/requires: CMakeFiles/main.dir/src/region.cpp.o.requires

.PHONY : CMakeFiles/main.dir/requires

CMakeFiles/main.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/main.dir/cmake_clean.cmake
.PHONY : CMakeFiles/main.dir/clean

CMakeFiles/main.dir/depend:
	cd /home/zw/event_camera/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/zw/event_camera /home/zw/event_camera /home/zw/event_camera/build /home/zw/event_camera/build /home/zw/event_camera/build/CMakeFiles/main.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/main.dir/depend

