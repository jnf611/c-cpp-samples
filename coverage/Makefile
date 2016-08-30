CC=gcc
# --coverage replaces the previous flags -fprofile-arcs -ftest-coverage from
# previous versions of gcc
CFLAGS=-Wall --coverage
TARGET=test
LCOV_FILE=coverage.info
LCOV_DIR=out

all: main.o
	$(CC) $(CFLAGS) -o $(TARGET) main.o

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

coverage: $(TARGET)
	# the executables should be run to generate the statistics
	./$(TARGET)
	# generate the coverage report from the statistics
	lcov --capture -d . -o $(LCOV_FILE)
	# convert it into an html report
	genhtml $(LCOV_FILE) --output-directory $(LCOV_DIR)
	@echo "you can browse the coverage report with:"
	@echo "firefox ./$(LCOV_DIR)/index.html"

clean:
	rm -f $(TARGET)
	rm -f *.o
	rm -f *.gcda
	rm -f *.gcno
	rm -f coverage.info
	rm -rf $(LCOV_DIR)
