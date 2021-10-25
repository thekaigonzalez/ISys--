USEREADLINE=no
STACK=no

EXT_FLAGS=-O

ifeq ($(USEREADLINE), yes)
	EXT_FLAGS += -DUSE_READLINE -lreadline
endif

ifeq ($(STACK), yes)
	EXT_FLAGS += -DUSE_STACK -ldl
endif
all:
	gcc isys/tinyexpr.c -c
	g++ isys.cpp tinyexpr.o $(EXT_FLAGS) -g -o isyspp

preinstall:
	mkdir /usr/local/include/isys

install:
	cp ./isyspp /usr/local/bin/isyspp
	cp isys/*.h /usr/local/include/isys/
