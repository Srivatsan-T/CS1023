# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = "C:/Program Files/CMake/bin/cmake.exe"

# The command to remove a file.
RM = "C:/Program Files/CMake/bin/cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:/Users/never/Google Drive/Semester 2/CS1023/CS1023/fmt-7.1.3"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:/Users/never/Google Drive/Semester 2/CS1023/CS1023/build"

# Include any dependencies generated for this target.
include test/CMakeFiles/locale-test.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include test/CMakeFiles/locale-test.dir/compiler_depend.make

# Include the progress variables for this target.
include test/CMakeFiles/locale-test.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/locale-test.dir/flags.make

test/CMakeFiles/locale-test.dir/locale-test.cc.obj: test/CMakeFiles/locale-test.dir/flags.make
test/CMakeFiles/locale-test.dir/locale-test.cc.obj: test/CMakeFiles/locale-test.dir/includes_CXX.rsp
test/CMakeFiles/locale-test.dir/locale-test.cc.obj: C:/Users/never/Google\ Drive/Semester\ 2/CS1023/CS1023/fmt-7.1.3/test/locale-test.cc
test/CMakeFiles/locale-test.dir/locale-test.cc.obj: test/CMakeFiles/locale-test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:/Users/never/Google Drive/Semester 2/CS1023/CS1023/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/CMakeFiles/locale-test.dir/locale-test.cc.obj"
	cd "C:/Users/never/Google Drive/Semester 2/CS1023/CS1023/build/test" && C:/Strawberry/c/bin/x86_64-w64-mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT test/CMakeFiles/locale-test.dir/locale-test.cc.obj -MF CMakeFiles/locale-test.dir/locale-test.cc.obj.d -o CMakeFiles/locale-test.dir/locale-test.cc.obj -c "C:/Users/never/Google Drive/Semester 2/CS1023/CS1023/fmt-7.1.3/test/locale-test.cc"

test/CMakeFiles/locale-test.dir/locale-test.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/locale-test.dir/locale-test.cc.i"
	cd "C:/Users/never/Google Drive/Semester 2/CS1023/CS1023/build/test" && C:/Strawberry/c/bin/x86_64-w64-mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:/Users/never/Google Drive/Semester 2/CS1023/CS1023/fmt-7.1.3/test/locale-test.cc" > CMakeFiles/locale-test.dir/locale-test.cc.i

test/CMakeFiles/locale-test.dir/locale-test.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/locale-test.dir/locale-test.cc.s"
	cd "C:/Users/never/Google Drive/Semester 2/CS1023/CS1023/build/test" && C:/Strawberry/c/bin/x86_64-w64-mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:/Users/never/Google Drive/Semester 2/CS1023/CS1023/fmt-7.1.3/test/locale-test.cc" -o CMakeFiles/locale-test.dir/locale-test.cc.s

# Object files for target locale-test
locale__test_OBJECTS = \
"CMakeFiles/locale-test.dir/locale-test.cc.obj"

# External object files for target locale-test
locale__test_EXTERNAL_OBJECTS =

bin/locale-test.exe: test/CMakeFiles/locale-test.dir/locale-test.cc.obj
bin/locale-test.exe: test/CMakeFiles/locale-test.dir/build.make
bin/locale-test.exe: test/libtest-main.a
bin/locale-test.exe: test/libgmock.a
bin/locale-test.exe: libfmtd.a
bin/locale-test.exe: test/CMakeFiles/locale-test.dir/linklibs.rsp
bin/locale-test.exe: test/CMakeFiles/locale-test.dir/objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:/Users/never/Google Drive/Semester 2/CS1023/CS1023/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../bin/locale-test.exe"
	cd "C:/Users/never/Google Drive/Semester 2/CS1023/CS1023/build/test" && "C:/Program Files/CMake/bin/cmake.exe" -E rm -f CMakeFiles/locale-test.dir/objects.a
	cd "C:/Users/never/Google Drive/Semester 2/CS1023/CS1023/build/test" && C:/Strawberry/c/bin/ar.exe cr CMakeFiles/locale-test.dir/objects.a @CMakeFiles/locale-test.dir/objects1.rsp
	cd "C:/Users/never/Google Drive/Semester 2/CS1023/CS1023/build/test" && C:/Strawberry/c/bin/x86_64-w64-mingw32-g++.exe -g -Wl,--whole-archive CMakeFiles/locale-test.dir/objects.a -Wl,--no-whole-archive -o ../bin/locale-test.exe -Wl,--out-implib,liblocale-test.dll.a -Wl,--major-image-version,0,--minor-image-version,0 @CMakeFiles/locale-test.dir/linklibs.rsp

# Rule to build all files generated by this target.
test/CMakeFiles/locale-test.dir/build: bin/locale-test.exe
.PHONY : test/CMakeFiles/locale-test.dir/build

test/CMakeFiles/locale-test.dir/clean:
	cd "C:/Users/never/Google Drive/Semester 2/CS1023/CS1023/build/test" && $(CMAKE_COMMAND) -P CMakeFiles/locale-test.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/locale-test.dir/clean

test/CMakeFiles/locale-test.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "C:/Users/never/Google Drive/Semester 2/CS1023/CS1023/fmt-7.1.3" "C:/Users/never/Google Drive/Semester 2/CS1023/CS1023/fmt-7.1.3/test" "C:/Users/never/Google Drive/Semester 2/CS1023/CS1023/build" "C:/Users/never/Google Drive/Semester 2/CS1023/CS1023/build/test" "C:/Users/never/Google Drive/Semester 2/CS1023/CS1023/build/test/CMakeFiles/locale-test.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : test/CMakeFiles/locale-test.dir/depend

