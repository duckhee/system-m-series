###########################################################
# GCC template makefile
###########################################################


SELECT_BOARD_SOURCES = 
SELECT_BOARD_SOURCES += SelectBoard.c

C_SUBINC += $(TOP)/Board

SRCS += $(SELECT_BOARD_SOURCES)