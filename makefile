CFLAGS = -g -Wall -Wextra  
INCS = -Iextra
LIBS = -Lextra
LIBFLAG = -lfunc -lm
DEPS = extra/*.a extra/*.o
LIBDEPS = extra/*.h extra/*.c

$(file): $(DEPS)
	gcc $(CFLAGS) $(INCS) $(LIBS) */$(file).c $(LIBFLAG) -o $(file)

update: $(LIBDEPS)
	cc -Wall -c extra/*.c
	ar -cvq extra/lib$(name).a *.o