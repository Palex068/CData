.PHONY: all install uninstall clean dvi dist test gcov_report generate_make
# =========================================== VAR ==================================================
CC := gcc
GCOVFLAGS := -fprofile-arcs -ftest-coverage
HEADER := backend/3d_viewer.h
TESTS := test
UNAME := $(shell uname -s)

GCOV_DIR = report
QT_PROJECT_NAME = 3DViewer_v1
QT_PROJECT_FOLDER = .
QT_PRO = $(QT_PROJECT_NAME).pro
QT_MAKEFILE = $(QT_PROJECT_NAME)_Makefile
QT_BUILD_FOLDER = ../build
QT_APP_FOLDER = ../app
TAR_SOURCE = ../tar/
TAR_DIR = $(TAR_SOURCE)$(QT_PROJECT_NAME)_Archive

# =========================================== OS ===================================================

ifeq ($(UNAME),Linux)
	LDFLAGS = -pthread -lcheck_pic -pthread -lrt -lm -lsubunit
	OPEN_CM = xdg-open
endif
ifeq ($(UNAME),Darwin)
	LDFLAGS = -lcheck
	OPEN_CM = open
endif

# ========================================= TARGETS ================================================

all: clean install gcov_report

generate_make:
	@qmake $(QT_PROJECT_FOLDER)/$(QT_PRO) -o ./$(QT_BUILD_FOLDER)/$(QT_MAKEFILE)

install: generate_make
	@echo "Building application..."
	@cd ./$(QT_BUILD_FOLDER) && make -sf $(QT_MAKEFILE)
	@echo "Application builded."
	@echo -n "Moving application to folder \"$(QT_APP_FOLDER)\"..."
	@mkdir ./$(QT_APP_FOLDER)
ifeq ($(UNAME), Darwin)
	@mv ./$(QT_BUILD_FOLDER)/$(QT_PROJECT_NAME).app ./$(QT_APP_FOLDER)/$(QT_PROJECT_NAME).app
else
	@mv ./$(QT_BUILD_FOLDER)/$(QT_PROJECT_NAME) ./$(QT_APP_FOLDER)/$(QT_PROJECT_NAME)
endif
	@echo "\nDone."
	@echo -n "Deleting build folder..."
	@rm -rf $(QT_BUILD_FOLDER)
	@echo "\nDone."
	@echo "Installation complete!"
#	@mkdir build
#	@cd build/ && qmake ../3DViewer_v1.pro && make
	@open $(QT_APP_FOLDER)/$(QT_PROJECT_NAME)*

open_app:
	@open $(QT_APP_FOLDER)/$(QT_PROJECT_NAME)*


uninstall: $(QT_APP_FOLDER)
	@echo -n "Uninstalling application..."
	@rm -rf $(QT_APP_FOLDER)
	@echo "\nDone."

dist: clean
	@mkdir ./../tar
	@mkdir $(TAR_DIR)
	@mkdir $(TAR_DIR)/src
	@cp -r ./* $(TAR_DIR)/src
	@tar cvzf $(TAR_DIR).tgz $(TAR_DIR)
	@mv $(TAR_DIR).tgz ./..
	@rm -rf ./../tar

dvi:
	@doxygen conf && mv html documentation
	@open documentation/index.html

clean:
	-rm -f *.gcda *.gcov *.o *.gcno *.tgz test main_test.c ../$(QT_PROJECT_NAME)_Archive.tgz
	-rm -rf $(QT_BUILD_FOLDER) $(GCOV_DIR) html $(TAR_SOURCE) build
	-rm -rf *.html *.info documentation/ html/ *.stash *.gz *.gcda

check: test_C_functions.check
	@checkmk clean_mode=1 test_C_functions.check > main_test.c

test: check
	@$(CC) backend/*ing/*.c main_test.c $(LDFLAGS) -o $(TESTS)
	@./$(TESTS)

gcov_report: check
	@$(CC) $(GCOVFLAGS) backend/*ing/*.c main_test.c $(LDFLAGS) -o report.out
	@./report.out
	@lcov -t "gcov_report" -o Coverage_Report.info -c -d ./
	@-lcov -r Coverage_Report.info 'backend/*ing/*.c' -o Coverage_Report.info
	@genhtml -o ./$(GCOV_DIR) Coverage_Report.info
	@rm -rf *.o *.gcno *.gcda *.info *.out *.gcov s21_matrix/*.o
	@-$(OPEN_CM) ./report/index-sort-f.html

rebuild: clean all

# ========================================== STYLE =================================================

style:
	@clang-format -style=google -n *.cpp *.h backend/*ing/*.c backend/*.h

correction_style:
	@clang-format -style=google -i *.cpp *.h backend/*ing/*.c backend/*.h
