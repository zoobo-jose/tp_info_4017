tp1:
		g++ -c tp1.cpp
		g++ -c main.cpp
		g++ -c utilities.cpp
		g++ -o main main.o tp1.o utilities.o
		./main