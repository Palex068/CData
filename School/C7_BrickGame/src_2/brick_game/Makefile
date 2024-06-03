#---== COMPILER ==---#
CC = gcc
DEBUG = -g
CFLAGS = -Wall -Werror -Wextra -std=c11 -I.. -I./$(target_dir) -pedantic
LDFLAGS = -lcheck -lsubunit -lpthread

#---== STATIC_VARIABLES ==---#
project_name = tetris
target_dir = 
bin_dir	= $(target_dir)/bin
bin_sub_dir = release
build_dir = $(target_dir)/build
func_dir = $(target_dir)/functions
test_dir = $(target_dir)/tests

#---= DYNAMIC_VARIABLES =---#
find_command = find $(1) -iname "*.c"
depenc_command = $(addprefix $(build_dir)/, $(subst tetris/,,$(filter $(1)/%.o, $(obj_list))))
find_command_gcov = find $(1) -iname "*.gcda" -o -iname '*.gcno'

lib_name := $(addsuffix .a, $(project_name))
test_lib_name := $(addsuffix _test.a, $(project_name))
import = $(test_lib_name) $(lib_name)

func_source := $(shell $(call find_command, $(func_dir)))
test_source := $(shell $(call find_command, $(test_dir)))
obj_list := $(patsubst %.c, %.o, $(func_source) $(test_source))
gcov_list := $(shell $(call find_command_gcov, $(func_dir)))
dir_list := $(addprefix $(build_dir)/, $(subst tetris/,,$(sort $(dir $(func_source) $(test_source)))))

#---== COMPILE_RULES ==---#
.PHONY: test 
all: $(lib_name)

test: $(import)

$(lib_name): build $(call depenc_command, $(func_dir))
$(test_lib_name): build $(call depenc_command, $(test_dir))

%.a:
	ar crs $@ $(filter %.o, $?)

$(build_dir)/functions/%.o: $(func_dir)/%.c
	$(CC) $(CFLAGS) $(if $(filter $(func_dir)/%.c, $^), $(GCOVFLAGS)) $(DEBUG) -c $^ -o $@

$(build_dir)/tests/%.o: $(test_dir)/%.c
	$(CC) $(CFLAGS) $(DEBUG) -c $^ -o $@

build:
	@$(shell [ ! -w "$(build_dir)" ] && mkdir $(build_dir) )
	@$(shell [ ! -w "$(dir_list)" ] && mkdir -p $(dir_list) )

bin:
	@$(shell [ ! -w $(bin_dir) ] && mkdir $(bin_dir) )
	@$(shell [ ! -w $(bin_dir)/$(bin_sub_dir) ] && mkdir $(bin_dir)/$(bin_sub_dir) )

#-----=== CHECK_RULES ===------#
.PHONY: clang-n clang-i
clang-n:
	find . -iname '*.h' -o -iname '*.c' | xargs clang-format -n -style=file:../../materials/linters/.clang-format

clang-i:
	find . -iname '*.h' -o -iname '*.c' | xargs clang-format -i -style=file:../../materials/linters/.clang-format

#---== REPORT ==---#
gcov_report: GCOVFLAGS = -fprofile-arcs -ftest-coverage
gcov_report: LDFLAGS += -lgcov
gcov_report: clean_gcov test

#---== CLEAN ==---#
.PHONY: clean clean_gcov clean_obj clean_doc
clean: clean_doc
	@rm -rf $(obj_list) $(gcov_list)
	@rm -rf $(lib_name) $(test_lib_name)
	@rm -rf $(build_dir) $(bin_dir)

clean_obj:
	@rm -rf $(addprefix $(build_dir)/, $(filter $(func_dir)/%.o, $(obj_list)))

clean_gcov: clean_obj
	@rm -rf $(gcov_list)

clean_doc:
	@rm -rf doc/html doc/latex