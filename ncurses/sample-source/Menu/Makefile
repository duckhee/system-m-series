# root file path
TOP = .

CC = gcc

SRCS = menu.c MakeWindow.c

C_EXTRAINC = MakeWindow.h menu.h

C_SUBINC = 

SUB_DIRS = ncurses

SUB_FILES := 
SUB_FILES += os \
chapter \
Board 

# get all include header file
C_ALLINC = $(C_EXTRAINC) $(C_SUBINC)

# add include option
C_INC = $(patsubst %,-I%,$(C_ALLINC))

# make file path add
SUB_FILES := $(addprefix $(TOP)/,$(SUB_FILES))

# add all c file
vpath %.c $(SUB_FILES)

# add sub file Makefile.c
sinclude $(addsuffix /Makefile.inc,$(SUB_FILES))

BUILDDIR = buildDir

TARGET = Menu

# link sub library
LDFLAGS = $(patsubst %,-l%, $(SUB_DIRS))
#LDFLAGS = `pkg-config --cflags --libs ncurses`

# make cobject file
COBJS = $(addprefix $(BUILDDIR)/, $(SRCS:.c=.o))

all: clean createdirs build 

createdirs:
	$(shell mkdir ${BUILDDIR})

build: $(COBJS)
	$(CC) -o $(BUILDDIR)/$(TARGET) $^ $(LDFLAGS)
	@$(shell echo ./$(BUILDDIR)/$(TARGET))
	

$(COBJS):$(BUILDDIR)/%.o : %.c
	$(CC) -c $(LDFLAGS) $(C_INC) $< -o $@

clean:
	rm -rf ${BUILDDIR}


