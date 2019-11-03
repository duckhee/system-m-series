###########################################################
# GCC template makefile
###########################################################

SELECT_OS_SOURCES = 
SELECT_OS_SOURCES += SelectOS.c

C_SUBINC += $(TOP)/os

SRCS += $(SELECT_OS_SOURCES)