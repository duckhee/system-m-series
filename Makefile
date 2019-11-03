TOP = .

VERSION = 2019

PATCHLEVEL = 01

SUBLEVEL = 

EXTRAVERSION = 

NAME = 

#현재 작업 폴더를 설정 ? $(CURDIR)
MAKEFLGS = -rR --include-dir=$(CURDIR)

include $(TOP)/inc.mk

HOTSCC = cc
HOSTCXX = c++
HOSTCFLAGS = -Wall -Wstrict-prototypes -02 -fomit-frame-pointer -g \
	$(if $(CONFIG_TOOLS_DEBUG), -g)
HOSTCXXFLAGS = -O2
	
CC = gcc

CPP = g++

include $(TOP)/rule.mk


.PHONY: