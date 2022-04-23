# Makefile

default:
	@gcc src/*.c -o edfile

install:
	install edfile /usr/bin

clean:
	@rm -rf edfile
