CC = gcc

SRCS = tseter.c

TARGET = Testing

SUB_DIRS = ncurses

LDFLAGS = $(patsubst %,-l%, $(SUB_DIRS))

BUILDDIR = buildDir

COBJS = $(addprefix $(BUILDDIR)/, $(SRCS:.c=.o))

all: clean createdirs build

createdirs:
	$(shell mkdir ${BUILDDIR})

build:$(COBJS)
	$(CC) -o $(BUILDDIR)/$(TARGET) $^ $(LDFLAGS)

$(COBJS):$(BUILDDIR)/%.o : %.c
	$(CC) -c $(LDFLAGS) $< -o $@

clean:
	rm -rf ${BUILDDIR}


