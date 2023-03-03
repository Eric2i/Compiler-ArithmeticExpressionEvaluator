CC=g++
CFLAGS=-Wall -std=c++17
BINDIR=bin
OBJDIR=obj
SRCDIR=src

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

$(BINDIR)/run: $(OBJDIR)/test.o $(OBJDIR)/Expression.o
	$(CC) -o $@ $^

test: $(BINDIR)/run
	$(BINDIR)/run

clean:
	rm -rf $(OBJDIR)/*
	rm -rf $(BINDIR)/*