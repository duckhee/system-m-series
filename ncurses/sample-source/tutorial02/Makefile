CC = gcc

SRC = movingCurses.c

TARGET = movingCurses

BUILDDIR = buildDir

SUB_LIBS = ncurses

LDFLAGS = $(patsubst %,-l%, $(SUB_LIBS))

COBJS = $(addprefix $(BUILDDIR)/, $(SRC:.c=.o))


all: clean createdirs build

createdirs:
	$(shell mkdir ${BUILDDIR})

build: $(COBJS)
	$(CC) -o $(BUILDDIR)/$(TARGET) $^ $(LDFLAGS)

$(COBJS): $(BUILDDIR)/%.o : %.c
	$(CC) $(LDFLAGS) -o $@ -c $<

clean:
	rm -rf ${BUILDDIR}