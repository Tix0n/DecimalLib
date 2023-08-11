CC = gcc -g
PLATFORM = $(shell uname)
CFLAGS = -Wall -Wextra -std=c11 -g
SRC = s21_arithmetic_functions.c s21_arithmetic_help_functions.c s21_comparison_functions.c s21_conversion_functions.c s21_helpers_functions.c s21_rounding_functions.c
OBJ = *.o
TESTS_SRC = s21_decimal_test.c
INC_CHECK = $(shell pkg-config --cflags --libs check)
LFLAGS = -fprofile-arcs -ftest-coverage
GCOV_FLAGS  = -fprofile-arcs -ftest-coverage -lgcov --coverage -lcheck -lm -lpthread

ifeq ($(PLATFORM), Linux)
OPEN = xdg-open 
else
OPEN = open
endif

all: clean s21_decimal.a test gcov_report


s21_decimal.a: $(OBJ) s21_decimal.h
	$(CC) $(CFLAGS) -c $(SRC)
	ar rcs $@ $(OBJ)
	ranlib $@

s21_decimal_test.a: s21_arithmetic_functions.c s21_arithmetic_help_functions.c s21_comparison_functions.c s21_conversion_functions.c s21_helpers_functions.c s21_rounding_functions.c
	$(CC) -c $(CFLAGS) --coverage $?
	ar -rcs $@ *.o
	ranlib $@
	rm -f *.o

test: s21_decimal_test.a tests/s21_decimal_test.c
	$(CC) tests/s21_decimal_test.c $(INC_CHECK) $(CFLAGS) $(LFLAGS) -lcheck s21_decimal_test.a -o $@
	./$@

gcov_report: test
	gcovr -r . --html --html-details -o coverage_report.html
	rm -f tests_s21_string.gcda tests_s21_string.gcno
	$(OPEN) coverage_report.html

lcov_report:
	$(CC) -o test *.c *.h tests/s21_decimal_test.c $(GCOV_FLAGS) 
	./test
	~/homebrew/bin/lcov -t "gcov_report" -o test.info -c -d .
	~/homebrew/bin/genhtml -o gcov_report test.info
	rm -rf *.gcno *.gcda *.gcov *.info *.o test

linter:
	cppcheck *.c *.h tests/*.c
	clang-format -i --style=Google *.c *.h
	clang-format -n --style=Google *.c *.h


clean:
	rm -rf *.dSYM unit_tests *.o *.out *.a html_report *.css *.html mid_html_res *.gcda *.gcno success fail test_results report test test.c *.exe *.info *.gcov gcov_report/

rebuild: clean all
