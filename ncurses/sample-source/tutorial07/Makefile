CC = gcc

SRCS = userInput.c

TARGET = UserInput

BUILDDIR = buildDir

COBJS = $(addprefix $(BUILDDIR)/, $(SRCS:.c=.o))

SUB_LIBS = ncurses

LDFLAGS = $(patsubst %,-l%, $(SUB_LIBS))

all: clean createdirs build

createdirs:
	$(shell mkdir ${BUILDDIR})

build: $(COBJS)
	$(CC) -o $(BUILDDIR)/$(TARGET) $^ $(LDFLAGS)

$(COBJS): $(BUILDDIR)/%.o : %.c
	$(CC) -c $(LDFLAGS) $< -o $@

clean:
	rm -rf ${BUILDDIR}

