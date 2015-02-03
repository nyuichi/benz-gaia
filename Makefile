UCCDIR=~/workspace/ucc

gaia:
	$(UCCDIR)/bin/ucc -I./include *.c
	$(UCCDIR)/bin/sim -stat a.out

clean:
	rm -f a.out
	rm -f *.s
	rm -rf a.out.dSYM
