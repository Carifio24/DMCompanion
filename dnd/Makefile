# The directory in which to place headers
INCLUDE_DIR = /usr/local/include

# The directory in which to place libraries
LIB_DIR = /usr/local/lib

##############################################

# Build directory
BUILD_DIR = ./build

# Default target
.DEFAULT_TARGET := all

# Compiler options
CXX = g++
CXXFLAGS = -fPIC -std=c++17

# Static library build options
AR = ar

# Sources, headers, etc.
SOURCES = converters.cpp creature.cpp creature_builder.cpp dice_set.cpp die_helpers.cpp distance.cpp duration.cpp enummaps.cpp fraction.cpp helpers.cpp length_unit.cpp monster_builder.cpp spell_builder.cpp spell.cpp string_helpers.cpp test.cpp time_unit.cpp
TEMPLATES = named_enum.hpp quantity.hpp string_helpers.tpp sfinae.hpp vector_helpers.hpp
HEADERS = $(SOURCES:.cpp=.h)  action.h alignment.h caster_class.h condition.h damage_info.h distance_type.h duration.h duration_type.h enumerations.h keys.h language.h ref_wrap_comp.h school.h sense.h sense_type.h size.h skill.h sourcebook.h special_ability.h speed.h speed_type.h subclass.h unit.h
OBJECTS = $(SOURCES:%.cpp=$(BUILD_DIR)/%.o)
DEPENDENCIES = $(OBJ:.o=.d)

.PHONY: all install uninstall clean

all: libdnd.a libdnd.o

install:
	mkdir -p $(INCLUDE_DIR)/DnD
	cp *.h* $(INCLUDE_DIR)/DnD/
	cp *.tpp $(INCLUDE_DIR)/DnD/
	cp $(BUILD_DIR)/libdnd.* $(LIB_DIR)/
	ldconfig

uninstall:
	rm -rf $(INCLUDE_DIR)/DnD
	rm -f $(LIB_DIR)/libdnd.*
	ldconfig

clean:
	rm -f $(OBJECTS)

# Static library
libdnd.a: $(OBJECTS)
	$(AR) rcs $(BUILD_DIR)/libdnd.a $(OBJECTS)

# Shared library
libdnd.o: $(OBJECTS)
	$(CXX) -shared -fPIC -o $(BUILD_DIR)/libdnd.o $(OBJECTS)	

#### Object dependencies ####
-include $(DEPENDENCIES)

# Build target for every object file
# The -MMD flags additionally creates a .d file with
# the same name as the .o file.
$(BUILD_DIR)/%.o : %.cpp
	mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -MMD -c $< -o $@
