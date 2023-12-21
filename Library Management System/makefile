Library: Book.o Patron.o Loan.o Books.o Patrons.o Loans.o main.o
	g++ Book.o Patron.o Loan.o Books.o Patrons.o Loans.o main.o -o Library
	
Book.o: Book.cpp Book.h
	g++ -c Book.cpp
	
Books.o: Books.cpp Books.h
	g++ -c Books.cpp
	
Patron.o: Patron.cpp Patron.h
	g++ -c Patron.cpp
	
Patrons.o: Patrons.cpp Patrons.h
	g++ -c Patrons.cpp
	
Loan.o: Loan.cpp Loan.h Patrons.h Patron.h Books.h Book.h
	g++ -c Loan.cpp
	
Loans.o: Loans.cpp Loans.h Patrons.h Patron.h Books.h
	g++ -c Loans.cpp
	
main.o: main.cpp Book.h Books.h Patron.h Patrons.h Loan.h Loans.h
	g++ -c main.cpp