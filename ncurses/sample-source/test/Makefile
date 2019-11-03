CC = gcc

SRCS = blank.c

TARGET = test

BUILDDIR = buildDir

COBJS = $(addprefix $(BUILDDIR)/, $(SRCS:.c=.o))

EXTRA_LIBS = ncurses

CFLAGS = $(patsubst %,-l%, $(EXTRA_LIBS))

all: clean createdirs build

createdirs:
	$(shell mkdir ${BUILDDIR})

build:$(COBJS)
	$(CC) -o $(BUILDDIR)/$(TARGET) $^ $(CFLAGS)

$(COBJS):$(BUILDDIR)/%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -rf ${BUILDDIR}