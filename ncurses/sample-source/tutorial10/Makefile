CC = gcc

SRCS = refreshing.c

TARGET = Refreshing

BUILDDIR = buildDir

SUB_LIBS = ncurses

LDFLAGS = $(patsubst %,-l%, $(SUB_LIBS))

COBJS = $(addprefix $(BUILDDIR)/, $(SRCS:.c=.o))


all: clean createdirs build

createdirs:
	$(shell mkdir ${BUILDDIR})

build: $(COBJS)
	$(CC) -o $(BUILDDIR)/$(TARGET) $^ $(LDFLAGS)

$(COBJS):$(BUILDDIR)/%.o : %.c
	$(CC) -c $(LDFLAGS) $< -o $@

clean:
	rm -rf ${BUILDDIR}