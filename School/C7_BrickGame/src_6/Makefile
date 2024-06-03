CC :=gcc
CFLAGS =-Wall -Werror -Wextra -std=c11 -O2 
GCOV_FLAGS :=--coverage #--fprofile-arcs --ftest-coverage // Тоже самое что и --coverage
GCOV_FLAGS_TEMP :=

ifeq ($(shell uname -s), Linux) # Linux
	ADD_LIB =-lrt -pthread -lsubunit -lm -lncurses
else
	ADD_LIB =-lm -lncurses
endif


CONTROLLER_SOURCE = src/brick_game/tetris/tetris_main.c
BUILD_DIR = build
DIST_DIR = s21_tetris
EXECUTABLE_NAME = tetris_game.exe


LOGIC_SOURCE_DIR = src/brick_game/tetris/functions
LOGIC_SOURCE =$(foreach current_dir, $(LOGIC_SOURCE_DIR), $(wildcard $(current_dir)/*.c)) 
LOGIC_OBJECTS =$(patsubst %.c,%.o, $(LOGIC_SOURCE))
LOGIC_LIB_NAME =s21_tetris.a

VIEW_SOURCE_DIR = src/gui/cli
VIEW_SOURCE =$(foreach current_dir, $(VIEW_SOURCE_DIR), $(wildcard $(current_dir)/*.c)) 
VIEW_OBJECTS =$(patsubst %.c,%.o, $(VIEW_SOURCE))
VIEW_LIB_NAME =s21_cli.a


TEST_SOURCE_DIR = tests tests/* tests/*/*
TEST_SOURCE =$(foreach current_dir, $(TEST_SOURCE_DIR), $(wildcard $(current_dir)/*.c))
TEST_OBJECTS =$(patsubst %.c,%.o, ${TEST_SOURCE})
TEST_EXECUTABLE_NAME = TTRS_tetris_test
ADD_TEST_LIB =-lcheck

GCOV_REPORT_NAME =$(TEST_EXECUTABLE_NAME)_gcov_report
REPORT_LIB =gcov_report


all: clean test

install: clean_exe create_build_dir $(LOGIC_LIB_NAME) $(VIEW_LIB_NAME)
	$(CC) $(CFLAGS) $(CONTROLLER_SOURCE) $(BUILD_DIR)/$(LOGIC_LIB_NAME) $(BUILD_DIR)/$(VIEW_LIB_NAME) -o $(BUILD_DIR)/$(EXECUTABLE_NAME) ${ADD_LIB}
	./$(BUILD_DIR)/$(EXECUTABLE_NAME)

uninstall: 
	rm $(BUILD_DIR)/$(EXECUTABLE_NAME)

dvi: clean_dvi create_build_dir
	doxygen Doxyfile
	open materials/docs/html/index.html


dist: clean_dist create_build_dir
	mkdir -p $(BUILD_DIR)/${DIST_DIR}
	cp -rf src/brick_game $(BUILD_DIR)/${DIST_DIR}/brick_game
	cp -rf src/gui $(BUILD_DIR)/${DIST_DIR}/gui
	cp -rf Makefile $(BUILD_DIR)/${DIST_DIR}/
	cp -rf Doxyfile $(BUILD_DIR)/${DIST_DIR}/
	tar -czf $(BUILD_DIR)/${DIST_DIR}.tar.gz $(BUILD_DIR)/${DIST_DIR}
	rm -rf $(BUILD_DIR)/${DIST_DIR}

$(LOGIC_LIB_NAME): clean_obj create_build_dir ${LOGIC_OBJECTS}
	ar rc $(BUILD_DIR)/$@ ${LOGIC_OBJECTS}
# 	Обновляет объектные файлы в статической библиотеки: Но зачем это нужно хз
#	ranlib $@ 
#	флаг -s подавляет вывод
	@make -s clean_obj

$(VIEW_LIB_NAME): clean_obj create_build_dir ${VIEW_OBJECTS}
	ar rc $(BUILD_DIR)/$@ ${VIEW_OBJECTS}
	@make -s clean_obj

.c.o: 
	$(CC) $(CFLAGS) $(GCOV_FLAGS_TEMP) -c $(patsubst %.o,%.c, $@) -o $@ ${ADD_LIB}

# Компиляция тестов
$(TEST_EXECUTABLE_NAME): clean_test_exe create_build_dir $(LOGIC_OBJECTS) ${TEST_OBJECTS}
	${CC} ${CFLAGS} $(LOGIC_OBJECTS) ${TEST_OBJECTS} -o $(BUILD_DIR)/$@ ${ADD_TEST_LIB} ${ADD_LIB} 
	@make -s clean_obj

${TEST_OBJECTS}:
	$(CC) $(CFLAGS) -c $(patsubst %.o,%.c, $@) -o $@ ${ADD_TEST_LIB} ${ADD_LIB}

# Запуск тестов
test: $(TEST_EXECUTABLE_NAME)
	./$(BUILD_DIR)/$(TEST_EXECUTABLE_NAME)

# запуск тестов и создание gcov_report'a
gcov_report: clean_test_exe clean_gcov_test create_build_dir gcov_compile ${LOGIC_OBJECTS} ${TEST_OBJECTS} 
#	${CC} -c ${CFLAGS} ${GCOV_FLAGS} ${SOURCE} -o test_${EXECUTABLE_NAME} ${ADD_LIB}
	${CC} ${CFLAGS} ${GCOV_FLAGS} ${LOGIC_OBJECTS} ${TEST_OBJECTS} -o $(BUILD_DIR)/${GCOV_REPORT_NAME} ${ADD_TEST_LIB} ${ADD_LIB}
	@make -s clean_obj
	./$(BUILD_DIR)/${GCOV_REPORT_NAME}
#  	| --capture \ -c | --test-name \ -t |  --output-file \ -o | --directory \ -d | --directory .
	lcov --capture  --test-name "${GCOV_REPORT_NAME}" --output-file $(BUILD_DIR)/${GCOV_REPORT_NAME}.info --directory .
#	| --output-directory \ -o |
	genhtml --output-directory $(BUILD_DIR)/$(REPORT_LIB)/html_info $(BUILD_DIR)/${GCOV_REPORT_NAME}.info
	@make -s clean_gcov_test
# открывем файл
	open $(BUILD_DIR)/$(REPORT_LIB)/html_info/index.html


##-##-## Clean
clean_obj:
	rm -f *.o */*.o */*/*.o */*/*/*.o */*/*/*/*.o

clean_libs: 
	rm -f $(BUILD_DIR)/$(LOGIC_LIB_NAME) $(BUILD_DIR)/$(VIEW_LIB_NAME)

clean_exe: 
	rm -f $(BUILD_DIR)/$(EXECUTABLE_NAME)

clean_test_exe: 
	rm -f $(BUILD_DIR)/$(TEST_EXECUTABLE_NAME)
	rm -f $(BUILD_DIR)/${GCOV_REPORT_NAME}

clean_gcov_test_exe:
	rm -rf $(BUILD_DIR)/$(REPORT_LIB)

clean_gcov_test:
	rm -f *.gcno */*.gcno */*/*.gcno */*/*/*.gcno */*/*/*/*.gcno
	rm -f *.gcov */*.gcov */*/*.gcov */*/*/*.gcov */*/*/*/*.gcov
	rm -f *.info */*.info */*/*.info */*/*/*.info */*/*/*/*.info
	rm -f *.gcda */*.gcda */*/*.gcda */*/*/*.gcda */*/*/*/*.gcda
#	lcov -z -d . выдаёт ошибку если нечего удалять 

clean_dvi:
	rm -rf materials/docs/

clean_dist:
	rm -rf $(BUILD_DIR)/${DIST_DIR}.*

clean: clean_obj clean_libs clean_exe clean_test_exe clean_gcov_test_exe clean_gcov_test clean_dvi clean_dist
##-##-##

create_build_dir:
	mkdir -p $(BUILD_DIR)

gcov_compile: $($(eval gcov_report: GCOV_FLAGS_TEMP += $(GCOV_FLAGS)))

clang:
	clang-format -i -style=google $(LOGIC_SOURCE) ${TEST_SOURCE}

clang_check:
	clang-format -n -style=google $(LOGIC_SOURCE) ${TEST_SOURCE}

# Нужна для того чтобы обозначить имеющиеся цели.
.PHONY: all install uninstall dvi dist create_build_dir $(TEST_EXECUTABLE_NAME) $(LOGIC_LIB_NAME) $(VIEW_LIB_NAME) all test gcov_report clean_obj clean_gcov_test clean_exe clean_test_exe clean_gcov_test_exe clean_libs clean_dvi clean, clang, clang_check
