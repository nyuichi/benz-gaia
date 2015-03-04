UCCDIR=~/workspace/ucc

run:
	$(UCCDIR)/bin/ucc -Wa=-Wno-unused-label -I./include *.c
	$(UCCDIR)/bin/sim -simple a.out

clean:
	rm -f a.out
	rm -f *.s
	rm -rf a.out.dSYM
