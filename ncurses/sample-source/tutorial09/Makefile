CC = g++

SRCS = basic_topdownplayer.cpp

TARGET = BasicTopDownPlayer

BUILDDIR = buildDir

SUB_DIRS = ncurses 

LDFLAGS = $(patsubst %,-l%, $(SUB_DIRS))

COBJS = $(addprefix $(BUILDDIR)/, $(SRCS:.cpp=.o))

all: clean createdirs build

createdirs:
	$(shell mkdir ${BUILDDIR})

build: $(COBJS)
	$(CC) -o $(BUILDDIR)/$(TARGET) $^ $(LDFLAGS)


$(COBJS): $(BUILDDIR)/%.o : %.cpp
	$(CC) -c $(LDFLAGS) $< -o $@

clean:
	rm -rf ${BUILDDIR}
