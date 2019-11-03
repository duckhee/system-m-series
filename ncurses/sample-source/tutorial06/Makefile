CC = gcc

SRCS = getInfo.c

TARGET = GetInfo

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