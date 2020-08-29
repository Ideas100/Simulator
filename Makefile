OBJS = src/main.o src/gpio.o src/view.o
LIBS = -lncurses
CPPFLAGS = -I ./include
EXPR = '50,$$d'

all: test-env
	@echo 'File = $(FILEPATH)'
	sed -i $(EXPR) src/main.cpp
	cat $(FILEPATH) >> src/main.cpp
	@echo "Done...!"

test-env:
ifndef FILEPATH
	$(error FILEPATH env is undefined, Type 'make help')
endif


help:
	@echo 'Usage:'
	@echo '   $ export FILEPATH=<filename>'
	@echo '   $ make'
	@echo '   $ make compile'


compile: out 
	cp src/out run

out: $(OBJS) 
	g++ $(OBJS) $(LIBS) -o src/out

%.o: %.c 
	g++ $(CPPFLAGS) -c $^ -o $@



.PHONY: clean distclean

clean:
	sed -i $(EXPR) src/main.cpp
	rm src/*.o
	rm src/out
	rm run

distclean:
	find . -name code.c~ -delete
	find src/ -name *~ -delete
	find include/ -name *~ -delete
	find test/ -name *~ -delete
