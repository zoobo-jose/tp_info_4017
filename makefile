tp:
		g++ -c tp1.cpp
		g++ -c pgcb.cpp
		g++ -c exo8.cpp
		g++ -c exo9.cpp
		g++ -c main.cpp
		g++ -c utilities.cpp
		g++ -o main main.o tp1.o pgcb.o exo8.o exo9.o utilities.o
		./main