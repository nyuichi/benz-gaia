UCCDIR=~/workspace/ucc

gaia:
	$(UCCDIR)/bin/ucc -a '-Wno-unused-label' -I./include *.c
	$(UCCDIR)/bin/sim -stat a.out

clean:
	rm -f a.out
	rm -f *.s
	rm -rf a.out.dSYM
