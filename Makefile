CC=g++
CFLAGS=-Wall -std=c++17
BINDIR=bin
OBJDIR=obj
SRCDIR=src

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

$(BINDIR)/tester: $(OBJDIR)/test.o $(OBJDIR)/Expression.o
	$(CC) -o $@ $^
	
$(BINDIR)/evaluator: $(OBJDIR)/main.o $(OBJDIR)/Expression.o
	$(CC) -o $@ $^

test: $(BINDIR)/tester
	$(BINDIR)/tester

build: $(BINDIR)/evaluator
	# $(BINDIR)/evaluator

clean:
	rm -rf $(OBJDIR)/*
	rm -rf $(BINDIR)/*