CC = gcc
CFLAGS = -g -Wall -Wextra  
INCS = -Iextra
LIBS = -Lextra
LIBFLAG = -lfunc -lm
DEPS = extra/*.a extra/*.o

$(file): $(DEPS)
	$(CC) $(CFLAGS) $(INCS) $(LIBS) */$(file).c $(LIBFLAG) -o $(file)