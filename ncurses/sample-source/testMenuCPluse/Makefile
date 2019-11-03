CC = g++

SRCS = menu.cpp #move.c

SUB_DIRS = ncurses 

LDFLAGS = $(patsubst %,-l%, $(SUB_DIRS))

BUILDDIR = buildDir

TARGET = menu

COBJS = $(addprefix $(BUILDDIR)/, $(SRCS:.cpp=.o))

C_INC = move.h

C_EXTRAINC = -I$(C_INC)

all: clean createdirs build

createdirs:
	$(shell mkdir ${BUILDDIR})

build: $(COBJS)
	$(CC) -o $(BUILDDIR)/$(TARGET) $^ $(LDFLAGS)


$(COBJS): $(BUILDDIR)/%.o : %.cpp
	$(CC) -c $(LDFLAGS) $(C_EXTRAINC) $< -o $@


clean:
	rm -rf ${BUILDDIR}


