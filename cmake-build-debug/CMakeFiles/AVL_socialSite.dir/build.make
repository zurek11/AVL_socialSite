# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.7

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2016.3.4\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2016.3.4\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "D:\Moje Projekty\AVL_socialSite"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "D:\Moje Projekty\AVL_socialSite\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/AVL_socialSite.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/AVL_socialSite.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/AVL_socialSite.dir/flags.make

CMakeFiles/AVL_socialSite.dir/main.c.obj: CMakeFiles/AVL_socialSite.dir/flags.make
CMakeFiles/AVL_socialSite.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\Moje Projekty\AVL_socialSite\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/AVL_socialSite.dir/main.c.obj"
	C:\MinGW\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\AVL_socialSite.dir\main.c.obj   -c "D:\Moje Projekty\AVL_socialSite\main.c"

CMakeFiles/AVL_socialSite.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/AVL_socialSite.dir/main.c.i"
	C:\MinGW\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "D:\Moje Projekty\AVL_socialSite\main.c" > CMakeFiles\AVL_socialSite.dir\main.c.i

CMakeFiles/AVL_socialSite.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/AVL_socialSite.dir/main.c.s"
	C:\MinGW\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "D:\Moje Projekty\AVL_socialSite\main.c" -o CMakeFiles\AVL_socialSite.dir\main.c.s

CMakeFiles/AVL_socialSite.dir/main.c.obj.requires:

.PHONY : CMakeFiles/AVL_socialSite.dir/main.c.obj.requires

CMakeFiles/AVL_socialSite.dir/main.c.obj.provides: CMakeFiles/AVL_socialSite.dir/main.c.obj.requires
	$(MAKE) -f CMakeFiles\AVL_socialSite.dir\build.make CMakeFiles/AVL_socialSite.dir/main.c.obj.provides.build
.PHONY : CMakeFiles/AVL_socialSite.dir/main.c.obj.provides

CMakeFiles/AVL_socialSite.dir/main.c.obj.provides.build: CMakeFiles/AVL_socialSite.dir/main.c.obj


# Object files for target AVL_socialSite
AVL_socialSite_OBJECTS = \
"CMakeFiles/AVL_socialSite.dir/main.c.obj"

# External object files for target AVL_socialSite
AVL_socialSite_EXTERNAL_OBJECTS =

AVL_socialSite.exe: CMakeFiles/AVL_socialSite.dir/main.c.obj
AVL_socialSite.exe: CMakeFiles/AVL_socialSite.dir/build.make
AVL_socialSite.exe: CMakeFiles/AVL_socialSite.dir/linklibs.rsp
AVL_socialSite.exe: CMakeFiles/AVL_socialSite.dir/objects1.rsp
AVL_socialSite.exe: CMakeFiles/AVL_socialSite.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="D:\Moje Projekty\AVL_socialSite\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable AVL_socialSite.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\AVL_socialSite.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/AVL_socialSite.dir/build: AVL_socialSite.exe

.PHONY : CMakeFiles/AVL_socialSite.dir/build

CMakeFiles/AVL_socialSite.dir/requires: CMakeFiles/AVL_socialSite.dir/main.c.obj.requires

.PHONY : CMakeFiles/AVL_socialSite.dir/requires

CMakeFiles/AVL_socialSite.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\AVL_socialSite.dir\cmake_clean.cmake
.PHONY : CMakeFiles/AVL_socialSite.dir/clean

CMakeFiles/AVL_socialSite.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "D:\Moje Projekty\AVL_socialSite" "D:\Moje Projekty\AVL_socialSite" "D:\Moje Projekty\AVL_socialSite\cmake-build-debug" "D:\Moje Projekty\AVL_socialSite\cmake-build-debug" "D:\Moje Projekty\AVL_socialSite\cmake-build-debug\CMakeFiles\AVL_socialSite.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/AVL_socialSite.dir/depend

