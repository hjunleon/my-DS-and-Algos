.SILENT: test tidy
.PHONY: test tidy
SHELL := /bin/bash
FILES=error twilight reverse unique looknsay
CC=clang
LDLIBS=-lm -lcs1010
CFLAGS=@compile_flags.txt

all: tidy
test: $(FILES)
	for question in $(FILES); do ./test.sh $$question; done

tidy: test
	clang-tidy -quiet *.c 2> /dev/null

clean:
	rm $(FILES)
# vim:noexpandtab
