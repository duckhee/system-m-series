CC = gcc

SRCS = test.c

TARGET = Testing

BUILDDIR = buildDir

SUB_DIRS = ncurses

COBJS = $(addprefix $(BUILDDIR)/, $(SRCS:.c=.o))

LDFLAGS = $(patsubst %,-l%, $(SUB_DIRS))

all: clean createdirs build

createdirs:
	$(shell mkdir ${BUILDDIR})

build: $(COBJS)
	$(CC) -o $(BUILDDIR)/$(TARGET) $^ $(LDFLAGS)

$(COBJS):$(BUILDDIR)/%.o : %.c
	$(CC) -c $(LDFLAGS) $< -o $@

clean:
	rm -rf ${BUILDDIR}