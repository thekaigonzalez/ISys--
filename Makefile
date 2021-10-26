USEREADLINE=no
STACK=no

EXT_FLAGS=

ifeq ($(USEREADLINE), yes)
	EXT_FLAGS += -DUSE_READLINE -lreadline
endif

ifneq ($(OS), Windows_NT)
	# UNAME_S := $(shell uname -s)
	# ifeq ($)
	EXT_FLAGS += -DUSE_READLINE -lreadline
endif

ifeq ($(STACK), yes)
	EXT_FLAGS += -DUSE_STACK -ldl
endif
all:
	gcc isys/tinyexpr.c -c
	g++ isys.cpp tinyexpr.o $(EXT_FLAGS) -g -o isyspp
	# g++ isys/isyspapi.cpp -c

preinstall:
	mkdir /usr/local/include/isys

install:
	cp ./isyspp /usr/local/bin/isyspp
	# cp isys/*.h /usr/local/include/isys/
