
TARGET ?= 3DViewer

CC=gcc 
CFLAGS=-std=c11 -Wall -Werror -Wextra

GCOV=--coverage
SRC_DIRS ?=./c_part

SCR_ALL ?= ./

SRCS := $(shell find $(SRC_DIRS) -name '*.c' )
SRCSH := $(shell find $(SRC_DIRS) -name '*.h' )

ALL_SRCS := $(shell find $(SCR_ALL) -name '*.cpp' )
ALL_SRCSH := $(shell find $(SCR_ALL) -name '*.h' )


OBJS := $(addsuffix .o,$(basename $(SRCS)))

README = README.html

TEST = unit_test

all: $(TARGET).a

$(TARGET).a: $(OBJS)
	@ar rc $@ $(OBJS)


tests : clean $(TARGET).a $(OBJS)
	$(CC) $(CFLAGS) $(OBJS)  -l check -L. $(TARGET).a -o test
	./test

install:
	qmake -o Executables/Makefile $(TARGET)/$(TARGET).pro
	cd Executables && make
	
start: install
	cd Executables/$(TARGET).app/Contents/MacOS && ./$(TARGET)

dist: install 
	cd .. && tar -czf $(TARGET).tgz src


uninstall:
	cd Executables && make clean
	cd Executables && rm -rf Makefile qmake_qmake_qm_files.qrc $(TARGET).app .qm .qmake.stash

dvi: 
	open $(README)

gcov_report: install_lcov g$(TARGET).a
	$(CC) -o gcov g$(TARGET).a -lcheck $(SRCS) $(GCOV)
	chmod +x gcov
	./gcov
	lcov -t "gcovReport" -o gcov.info -c -d .
	genhtml -o report gcov.info
	open report/index.html


g$(TARGET).a: $(OBJS)
	$(CFLAGS)+=$(GCOV)
	@ar rc  $@ $(OBJS)


leaks:
	chmod 777 Executables/$(TARGET).app/Contents/MacOS/$(TARGET)
	cd Executables/$(TARGET).app/Contents/MacOS && CK_FORK=no leaks --atExit -- ./$(TARGET)

install_lcov:
	brew install lcov

clean_import:
	rm -rf Import
	mkdir Import

clean:
	$(RM) a.out $(TARGET).a $(OBJS) $(TARGET).o test
	$(RM) gcov  *.info *.gcda *.gcno Tests/*.gcda Tests/*.gcno g$(TARGET).a
	rm -rf report


push: 
	git add .
	git commit -m'$m'
	git push 

        # eval "$(/opt/goinfre/pickling/homebrew/bin/brew shellenv)"
        # chmod -R go-w "$(brew --prefix)/share/zsh"

style: 
	cp ../materials/linters/.clang-format .clang-format 
	clang-format -n $(ALL_SRCS)
	clang-format -n $(ALL_SRCSH)
	rm -rf .clang-format

style_done: 
	cp ../materials/linters/.clang-format .clang-format 
	clang-format -i $(ALL_SRCS)
	clang-format -i $(ALL_SRCSH)
	rm -rf .clang-format


# docker:
# 	rm -rf ~/Library/Containers/com.docker.docker
# 	mkdir -p ~/goinfre/Docker/Data
# 	ln -s ~/goinfre/Docker ~/Library/Containers/com.docker.docker

# val: docker
# 	cd Valgrind && sh run.sh

# valgrind: start
# 	CK_FORK=no valgrind --trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all --verbose --log-file=RESULT.txt ./$(TARGET)
# 	cat RESULT.txt