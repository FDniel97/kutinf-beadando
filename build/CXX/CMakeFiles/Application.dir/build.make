# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\Daniel\Downloads\kutinf beadando"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\Daniel\Downloads\kutinf beadando\build"

# Include any dependencies generated for this target.
include CXX/CMakeFiles/Application.dir/depend.make

# Include the progress variables for this target.
include CXX/CMakeFiles/Application.dir/progress.make

# Include the compile flags for this target's objects.
include CXX/CMakeFiles/Application.dir/flags.make

CXX/CMakeFiles/Application.dir/main.cpp.obj: CXX/CMakeFiles/Application.dir/flags.make
CXX/CMakeFiles/Application.dir/main.cpp.obj: ../CXX/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Daniel\Downloads\kutinf beadando\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CXX/CMakeFiles/Application.dir/main.cpp.obj"
	cd /d C:\Users\Daniel\DOWNLO~1\KUTINF~1\build\CXX && C:\PROGRA~2\CODEBL~1\MinGW\bin\MINGW3~2.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Application.dir\main.cpp.obj -c "C:\Users\Daniel\Downloads\kutinf beadando\CXX\main.cpp"

CXX/CMakeFiles/Application.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Application.dir/main.cpp.i"
	cd /d C:\Users\Daniel\DOWNLO~1\KUTINF~1\build\CXX && C:\PROGRA~2\CODEBL~1\MinGW\bin\MINGW3~2.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Daniel\Downloads\kutinf beadando\CXX\main.cpp" > CMakeFiles\Application.dir\main.cpp.i

CXX/CMakeFiles/Application.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Application.dir/main.cpp.s"
	cd /d C:\Users\Daniel\DOWNLO~1\KUTINF~1\build\CXX && C:\PROGRA~2\CODEBL~1\MinGW\bin\MINGW3~2.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\Daniel\Downloads\kutinf beadando\CXX\main.cpp" -o CMakeFiles\Application.dir\main.cpp.s

# Object files for target Application
Application_OBJECTS = \
"CMakeFiles/Application.dir/main.cpp.obj"

# External object files for target Application
Application_EXTERNAL_OBJECTS =

CXX/Application.exe: CXX/CMakeFiles/Application.dir/main.cpp.obj
CXX/Application.exe: CXX/CMakeFiles/Application.dir/build.make
CXX/Application.exe: CXX/CMakeFiles/Application.dir/linklibs.rsp
CXX/Application.exe: CXX/CMakeFiles/Application.dir/objects1.rsp
CXX/Application.exe: CXX/CMakeFiles/Application.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\Daniel\Downloads\kutinf beadando\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Application.exe"
	cd /d C:\Users\Daniel\DOWNLO~1\KUTINF~1\build\CXX && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Application.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CXX/CMakeFiles/Application.dir/build: CXX/Application.exe

.PHONY : CXX/CMakeFiles/Application.dir/build

CXX/CMakeFiles/Application.dir/clean:
	cd /d C:\Users\Daniel\DOWNLO~1\KUTINF~1\build\CXX && $(CMAKE_COMMAND) -P CMakeFiles\Application.dir\cmake_clean.cmake
.PHONY : CXX/CMakeFiles/Application.dir/clean

CXX/CMakeFiles/Application.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\Daniel\Downloads\kutinf beadando" "C:\Users\Daniel\Downloads\kutinf beadando\CXX" "C:\Users\Daniel\Downloads\kutinf beadando\build" "C:\Users\Daniel\Downloads\kutinf beadando\build\CXX" "C:\Users\Daniel\Downloads\kutinf beadando\build\CXX\CMakeFiles\Application.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CXX/CMakeFiles/Application.dir/depend
