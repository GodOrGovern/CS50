CFLAGS = -g -Wall -Wextra -std=c99
INCS = -I../extra
LIBS = -L../extra
LIBFLAG = -lfunc -lm
DEPS = ../extra/*.a ../extra/*.o
LIBDEPS = ../extra/*.h ../extra/*.c

cash: $(DEPS)
	gcc $(CFLAGS) $(INCS) $(LIBS) cash.c $(LIBFLAG) -o cash

credit: $(DEPS)
	gcc $(CFLAGS) $(INCS) $(LIBS) credit.c $(LIBFLAG) -o credit

hello: $(DEPS)
	gcc $(CFLAGS) $(INCS) $(LIBS) hello.c $(LIBFLAG) -o hello

mario: $(DEPS)
	gcc $(CFLAGS) $(INCS) $(LIBS) mario.c $(LIBFLAG) -o mario

update: $(LIBDEPS)
	cc -Wall -c ../extra/*.c
	ar -cvq ../extra/lib$(name).a *.o