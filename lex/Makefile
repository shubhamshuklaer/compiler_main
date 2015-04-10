.PHONY: all clean

all: parser

clean: 
	rm parser.cpp scanner.cpp parser out.png

parser.cpp : parser.y
	bison --verbose -d -o $@ parser.y

scanner.cpp : scanner.l parser.hpp
	lex -o $@ scanner.l

parser : parser.cpp scanner.cpp sym_table.h
	g++ -std=c++11 -g -o $@ parser.cpp scanner.cpp -ll -lcgraph -lcdt

out.png : syntax_graph.gv
	dot -Tpng $^ > $@

