IDIR = ../include
CXX = g++ -std=gnu++11
CXXFLAGS = -I$(IDIR) -g -pedantic -W -Wall -ftest-coverage -fprofile-arcs 

ODIR=obj
LDIR = ../lib

LIBS = -lm

_DEPS = arvore.hpp catch.hpp 
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = testa_arvore.o arvore.o 
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.c $(DEPS)
	$(CXX) -c -o $@ $< $(CXXFLAGS)

testa_arvore: $(OBJ)
	g++ -std=gnu++11 -o $@ $^ $(CXXFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~

