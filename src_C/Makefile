CC=gcc
STDFLAGS=-Wall -Werror -Wextra -std=c11
GCOV_FLAGS=-fprofile-arcs -ftest-coverage
TEST_SRC=$(wildcard tests/*.c)
SRC=$(wildcard core/*.c)
OBJ=$(patsubst %.c,%.o, ${SRC})
TARGET=s21_smartcalc.a
OPEN_CMD=open
CHECK_FLAGS=-lcheck

OS := $(shell uname -s)
ifeq ($(OS),Linux)
	OPEN_CMD=xdg-open
	CHECK_FLAGS=-lcheck -lsubunit -lrt -lpthread -lm
endif
ifeq ($(OS),Darwin)
	OPEN_CMD=open
	CHECK_FLAGS=-lcheck -lm -lpthread
endif

all: $(TARGET)

$(TARGET): ${OBJ} 
	$(CC) -c $(STDFLAGS) $(SRC)
	ar rc $@ $(OBJ)
	ranlib $@
	cp $@ lib$@
	rm -rf *.o

	scientific_calc

install:
	cmake -B build  && make -C build && mv build/ SCIENTIFICCALC && rm -rf SCIENTIFICCALC/build/
	
uninstall:
	rm -rf SCIENTIFICCALC

test: $(TARGET)
	${CC} $(STDFLAGS) ${TEST_SRC} $< -o test_exe $(CHECK_FLAGS)
	./test_exe

gcov_report:
	$(CC) $(STDFLAGS) $(GCOV_FLAGS) $(STDFLAGS) ${TEST_SRC} $(SRC) -o test_exe  $(CHECK_FLAGS)
	./test_exe
	lcov -capture --directory . --output-file main_coverage.info
	genhtml *.info -o ./gcov_report
	rm -rf *.gcda *.gcno *.info test_exe
	${OPEN_CMD} gcov_report/index.html

clean:
	rm -rf test_exe *.gcno *.a *.gcda gcov_report *.pdf core/*.o