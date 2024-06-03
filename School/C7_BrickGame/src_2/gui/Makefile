#---== COMPILER ==---#
CC = gcc
DEBUG = -g
CFLAGS = -Wall -Werror -Wextra -std=c11 -I./$(include_dir) -I.. -pedantic
LDFLAGS = -lm -lncurses

#---== STATIC_VARIABLES ==---#
project_name = gui
target_dir = 
build_dir = $(target_dir)/build
func_dir = $(target_dir)/functions
include_dir = $(target_dir)/include
lib_name := $(project_name).a

#---= DYNAMIC_VARIABLES =---#
func_source := $(shell find $(func_dir) -iname "*.c")
obj_list := $(addprefix $(build_dir)/, $(patsubst %.c, %.o, $(func_source)))
dir_list := $(addprefix $(build_dir)/, $(sort $(dir $(func_source))))

#---== COMPILE_RULES ==---#
# SUPPORT #
.PHONY: test 
all: $(lib_name)

build:
	@mkdir -p $(build_dir) $(dir_list)

# MAIN #
$(lib_name): build $(obj_list)
	ar crs $@ $(filter %.o, $?)

$(build_dir)/%.o: %.c
	$(CC) $(CFLAGS) $(if $(filter $(func_dir)/%.c, $^), $(GCOVFLAGS)) $(DEBUG) -c $^ -o $@

#---== CLEAN ==---#
.PHONY: clean clean_gcov clean_obj clean_doc
clean: clean_doc
	@rm -rf $(obj_list) 
	@rm -rf $(lib_name)
	@rm -rf $(build_dir)

clean_doc:
	@rm -rf doc/html doc/latex