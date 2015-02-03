UCCDIR=~/workspace/ucc

run:
	$(UCCDIR)/bin/ucc -a '-Wno-unused-label' -I./include *.c
	$(UCCDIR)/bin/sim a.out

clean:
	rm -f a.out
	rm -f *.s
	rm -rf a.out.dSYM
