CXX=g++
CXXFLAGS=-std=c++17 -Wall -Werror -Wextra
TEST_FGLAGS=-lgtest
GCOV_FLAGS=-fprofile-arcs -ftest-coverage
TEST_SRC=calctest/main.cc calctest/testcalc.cc
LIB_SRC=model/calcmodel.cc
OPEN_CMD=open

all: clean gcov_report

test:
	@echo "\033[0;33m Preparing tests......\033[0m"
	$(CXX) $(CXXFLAGS) $(TEST_SRC) $(LIB_SRC) $(TEST_FGLAGS)
	./a.out


gcov_report:
	@echo "\033[0;33m Preparing tests...\033[0m"
	$(CXX) $(CXXFLAGS) $(TEST_SRC) $(LIB_SRC) $(TEST_FGLAGS) $(GCOV_FLAGS)
	@./a.out
	@echo "\033[0;33m Preparing report...\033[0m"
	@lcov --no-external -capture --directory . --output-file main_coverage.info
	@genhtml *.info -o ./gcov_report
	@rm -rf *.gcda *.gcno
	@$(OPEN_CMD) gcov_report/index.html


install:
	@cmake -B build && make -C build 
	@mv build/ SCIENTIFICCALC/
	@rm -rf SCIENTIFICCALC/build/
	@$(OPEN_CMD) SCIENTIFICCALC/smartcalccpp.app 


uninstall:
	@rm -rf SCIENTIFICCALC

clean:
	@rm -rf a.out *.gcno *.a *.gcda gcov_report *.pdf *.dvi *.info