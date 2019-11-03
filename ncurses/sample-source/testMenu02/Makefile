CC = gcc

SRCS = test.c testing.c

TARGET = testMenu

BUILDDIR = buildDir

SUB_DIRS = ncurses

C_EXTRAINC = testing.h

C_INC = $(patsubst %,-I.%, $(C_EXTRAINC))

LDFLAGS = $(patsubst %,-l%, $(SUB_DIRS))

COBJS = $(addprefix $(BUILDDIR)/, $(SRCS:.c=.o))

all: clean createdirs build

createdirs:
	$(shell mkdir ${BUILDDIR})

build:$(COBJS)
	$(CC) -o $(BUILDDIR)/$(TARGET) $^ $(LDFLAGS)

$(COBJS):$(BUILDDIR)/%.o : %.c
	$(CC) -c $(LDFLAGS) $(C_INC) $< -o $@

clean:
	rm -rf ${BUILDDIR}