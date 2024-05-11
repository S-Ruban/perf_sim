# Compiler
CXX := g++
CC := gcc
# Compiler flags
CXXFLAGS := -g
CFLAGS := -g
# Source directories
SRC_DIRS := . ./fdt ./fesvr ./insns ./softfloat
# Source files
CPP_SRC := $(foreach dir,$(SRC_DIRS),$(wildcard $(dir)/*.cpp))
CC_SRC := $(foreach dir,$(SRC_DIRS),$(wildcard $(dir)/*.cc))
C_SRC := $(foreach dir,$(SRC_DIRS),$(wildcard $(dir)/*.c))
# Object files
CPP_OBJ := $(CPP_SRC:.cpp=.o)
C_OBJ := $(C_SRC:.c=.o)
CC_OBJ := $(CC_SRC:.cc=.o)
# Object file directories
OBJ_DIRS := $(addsuffix /obj,$(SRC_DIRS))
# Executable name
EXEC := perf_sim.exe

# Default rule
all: $(EXEC)

# Rule to create object file directories
# $(OBJ_DIRS):
# 	mkdir -p $@

# Rule to compile C++ source files
%.o: %.cpp | $(SRC_DIRS)
	$(CXX) $(CXXFLAGS) -c $<

%.o: %.cc | $(SRC_DIRS)
	$(CXX) $(CXXFLAGS) -c $<

# Rule to compile C source files
%.o: %.c | $(SRC_DIRS)
	$(CC) $(CFLAGS) -c $<

# Rule to link the executable
$(EXEC): $(CPP_OBJ) $(C_OBJ) $(CC_OBJ)
	$(CXX) $(CXXFLAGS) $(addprefix $(dir $@)/,$(notdir $(CPP_OBJ))) \
        $(addprefix $(dir $@)/,$(notdir $(C_OBJ))) \
		$(addprefix $(dir $@)/,$(notdir $(CC_OBJ))) -o $@

# Clean rule
clean:
	# rm -rf $(SRC_DIRS) $(EXEC)
	rm *.o
