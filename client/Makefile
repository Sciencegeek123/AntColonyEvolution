# Declaration of variables
CC = clang++
CC_FLAGS =-std=c++14 -I../shared/ -I./

# File names
EXEC = ./acs_client.exe
SOURCES = $(shell find ./ -type f -name "*.cpp")
SOURCES += $(shell find ../shared/ -type f -name "*.cpp")
OBJECTS = $(SOURCES:.cpp=.o)

#This is the default target
#It automates part of my workflow.
dev: 
	@echo "Building ACS CLient - DEV MODE"
	@echo " *Dev performs some standard stuff to make my life easier."
	@echo ""
	@echo "************  Cleaning Files ************"
	$(MAKE) clean
	@echo ""
	@echo "************  MAKING ALL IN PARALLEL ************"
	$(MAKE) all -j 12
	@echo ""
	@echo "************  REMOVING OBJECTS ************"
	$(MAKE) rmobj
	@echo ""
	@echo "************  RUNNING EXECUTABLE TEST ************"
	$(EXEC) test1


#This is everything that needs to happen when first starting.
super_dev: 
	@echo "Building ACS CLient - DEV MODE"
	@echo " *Dev performs some standard stuff to make my life easier."
	@echo ""
	@echo "************  Cleaning Files ************"
	$(MAKE) clean
	@echo ""
	@echo "************  Checking out submodules ************"
	/bin/sh -c "git submodule update"
	@echo ""
	@echo "************  Formatting Files ************"
	/bin/sh -c "find ../ -type f -name "*.h" -exec clang-format -style=google -i {} \;"
	/bin/sh -c "find ../ -type f -name "*.cpp" -exec clang-format -style=google -i {} \;"
	@echo ""
	@echo "************  MAKING ALL IN PARALLEL ************"
	$(MAKE) all -j 12
	@echo ""
	@echo "************  REMOVING OBJECTS ************"
	$(MAKE) rmobj
	@echo ""
	@echo "************  RUNNING EXECUTABLE TEST ************"
	$(EXEC) test1

# Exec target
$(EXEC): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(EXEC)
 
# To obtain object files 
%.o: %.cpp
	$(CC) -c $(CC_FLAGS) $< -o $@
 
# To remove generated files
clean:
	rm -f $(EXEC) $(OBJECTS)

rmobj:
	rm -f $(OBJECTS)

.PHONY : all
all : $(EXEC)