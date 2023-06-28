tokenizer: tokenizer.o uimain.o history.o
	cc -o tokenizer tokenizer.o uimain.o history.o
clean:
	rm -f *.o

tokenizer.o: tokenizer.h tokenizer.c uimain.c history.c

uimain.o: uimain.c tokenizer.c history.c

history.o: history.h history.c tokenizer.h
