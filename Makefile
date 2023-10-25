CC = gcc
CFLAGS = -Wall -Wextra
INCLUDES = -I /usr/include/SDL2/
LIBS = -lSDL2

SRCDIR = src
OBJDIR = output

SRCFILES = window.c main.c 
OBJFILES = $(SRCFILES:.c=.o)

SRCS = $(addprefix $(SRCDIR)/, $(SRCFILES))
OBJS = $(addprefix $(OBJDIR)/, $(OBJFILES)) 
MAIN = app




$(MAIN): $(OBJS) 
	$(CC) $(CFLAGS) $(INCLUDES) -o $(MAIN) $(OBJS) $(LIBS)


$(OBJDIR)/window.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRCDIR)/window.c -o $@

$(OBJDIR)/main.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRCDIR)/main.c -o $@

clean:
	$(RM) $(OBJS) $(MAIN)

