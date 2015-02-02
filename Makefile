UCCDIR=~/workspace/ucc

gaia:
	$(UCCDIR)/bin/ucc -I./include *.c
	$(UCCDIR)/bin/sim -msize 64 -stat a.out

clean:
	rm -f a.out
	rm -f *.s
	rm -rf a.out.dSYM
