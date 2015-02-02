gaia:
	rm -f a.out
	rm -f *.s
	rm -rf a.out.dSYM
	~/workspace/ucc/bin/ucc -I./include *.c
	~/workspace/ucc/bin/sim -msize 64 -stat a.out

native:
	rm -f a.out
	rm -f *.s
	rm -rf a.out.dSYM
	clang -O0 -g -I./include *.c
	./a.out
