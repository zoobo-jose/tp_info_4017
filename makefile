tp:
		g++ -c tp1.cpp
		g++ -c pgcb.cpp
		g++ -c main.cpp
		g++ -c utilities.cpp
		g++ -o main main.o tp1.o pgcb.o utilities.o
		./main