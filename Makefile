USEREADLINE=no

EXT_FLAGS=-O

ifeq ($(USEREADLINE), yes)
	EXT_FLAGS += -DUSE_READLINE -lreadline
endif
all:
	gcc isys/tinyexpr.c -c
	g++ isys.cpp tinyexpr.o $(EXT_FLAGS) -g -o isyspp