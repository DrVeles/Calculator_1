CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11
G_CFLAGS = -Wall -Werror -Wextra -std=c11 -fprofile-arcs -ftest-coverage

OS := $(shell uname -s)
ifeq ($(OS),Linux)
	LIBS =  -lcheck -lm -lrt -lpthread -lsubunit
	LEAKS = CK_FORK=no valgrind --vgdb=no --leak-check=full --show-leak-kinds=all --track-origins=yes --read-var-info=yes 
	OPEN_COMAND	= xdg-open 
else ifeq ($(OS),Darwin)
	LIBS = -lcheck -lm -lpthread
	LEAKS = leaks -atExit -- 
	OPEN_COMAND = open 
endif

.PHONY: test rt test_converter test_calculations

all: install

install: uninstall
	@cmake -B build "front/Calculator_1" 
	@make -C build Calculator_1
	@cp -R build/Calculator_1.app ../
	@rm -rf ./build/
	@echo "======================================"
	@echo "==> INSTALLED ../Calculator_1.app  <=="
	@echo "======================================"

uninstall: clean
	-@rm -rf build/ ../Calculator_1.app/
	@echo "======================================"
	@echo "===========> UNINSATLLED <============"
	@echo "======================================"

dvi:
	$(OPEN_COMAND) ../README.md

dist: clean 
	@mkdir SmartCalc_v1.0
	@mkdir SmartCalc_v1.0/src
	@cp -r front functions tests Makefile s21_calc_controller.* SmartCalc_v1.0/src/
	@cp ../README.md SmartCalc_v1.0/
	@tar -cf SmartCalc_v1.0.tar SmartCalc_v1.0 
	@rm -rf SmartCalc_v1.0/

test_converter:
	-@$(CC) $(CFLAGS) functions/s21_stack.c functions/s21_converter.c tests/s21_converter_tests.c -o test_converter $(LIBS)
	-@./test_converter

test_calculations:
	-@$(CC) $(CFLAGS) functions/s21_stack.c functions/s21_converter.c functions/s21_calculations.c tests/s21_calculations_tests.c -o test_calculations $(LIBS)
	-@./test_calculations

test: clean test_converter test_calculations

rt: format test

gcov_report: clean 
	@$(CC) $(G_CFLAGS) functions/s21_stack.c functions/s21_converter.c tests/s21_converter_tests.c -o test_converter $(LIBS)
	@$(CC) $(G_CFLAGS) functions/s21_stack.c functions/s21_converter.c functions/s21_calculations.c tests/s21_calculations_tests.c -o test_calculations $(LIBS)
	@./test_converter
	@lcov -t "test" -o test_converter.info --no-external -c -d .
	@./test_calculations
	@lcov -t "test" -o test_calculations.info --no-external -c -d .
	@lcov --add-tracefile test_converter.info --add-tracefile test_calculations.info -o final.info
	@lcov --remove final.info "*s21_converter_tests.c*" -o final.info 
	@lcov --remove final.info "*s21_calculations_tests.c*" -o final.info
	@genhtml -o report/ final.info
	$(OPEN_COMAND) ./report/index.html
	@make clean_without_report

format:
	@clang-format -style=Google -i *.c *.h */*.c */*.h */*/*.cpp */*/*.h
	@echo "======================================"
	@echo "============> FORMATTED <============="
	@echo "======================================"

leaks: test
	-$(LEAKS) ./test_converter
	-$(LEAKS) ./test_calculations

clean_without_report: 
	@rm -f *.o *.gcno *.gcov *.gcda *.info *.a a.out test_converter test_calculations  

clean: clean_without_report
	@rm -rf report gcov_unit_test *.dSYM/ *.tar
	clear