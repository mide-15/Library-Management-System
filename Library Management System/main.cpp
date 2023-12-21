/*
Ayomide Adedeji
CSCE 1040
Homework 3
*/
#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <ctime>
#include <fstream>
#include "Book.h"
#include "Books.h"
#include "Patron.h"
#include "Patrons.h"
#include "Loan.h"
#include "Loans.h"
using namespace std;

string author;
string title;
string isbn;
int idNumber;
float cost;
Books books;
Patrons patrons;
Book change(author, title, isbn, cost);

int main(){
	string currentStatus;
	char choice;
	string name;
	int pid;
	float fine;
	int numBooks;
	Loans loans; Loan loan(name, title);
	time_t lol = time(NULL);
	tm tell = *localtime(&lol);
	books.LoadBooks();
	patrons.LoadPatrons();
	loans.LoadLoans();
	
	while(choice != 'z' && choice != 'Z'){
		loans.UpdateLoanStatus();
		cout << "A. Add a book" << endl;
		cout << "B. Remove a book" << endl;
		cout << "C. Print a list of all books in the collection" << endl;
		cout << "D. Print the details for a single book" << endl;
		cout << "E. Add a patron" << endl;
		cout << "F. Remove a patron" << endl;
		cout << "G. Print a list of all patrons in the collection" << endl;
		cout << "H. Print the details for a single patron" << endl;
		cout << "I. Check out a book" << endl;
		cout << "J. Check in a book" << endl;
		cout << "K. List all overdue books" << endl;
		cout << "L. List books checked out from a single patron" << endl;
		cout << "M. Recheck a book" << endl;
		cout << "N. Report a lost book" << endl;
		cout << "O. Pay Fines" << endl;
		cout << "Z. Quit" << endl;
		cout << "Choose what action you want to do: "; cin >> choice;
		cout << endl;
		
		switch(tolower(choice)){
			case 'a':
				loans.UpdateLoanStatus();
				cout << "Enter Title: "; cin.ignore(); getline(cin, title);
				cout << "Enter Author: "; getline(cin, author);
				cout << "Enter ISBN Number: "; cin >> isbn;
				cout << "Enter the cost of the book: "; cin >> cost;
				books.add(Book(author, title, isbn, cost)); cout << endl;
				loans.UpdateLoanStatus();
				break;
			case 'b':
				loans.UpdateLoanStatus();
				cout << "Enter the title of the book to remove:" << endl; cin.ignore(); getline(cin, title);
				books.remove(title);
				cout << endl;
				loans.UpdateLoanStatus();
				break;
			case 'c':
				loans.UpdateLoanStatus();
				books.PrintEntries();
				loans.UpdateLoanStatus();
				break;
			case 'd':
				loans.UpdateLoanStatus();
				cout << "Enter the name of the book: "; cin.ignore(); getline(cin, title);
				books.PrintDetails(title); cout << endl;
				loans.UpdateLoanStatus();
				break;
			case 'e':
				loans.UpdateLoanStatus();
				cout << "Enter patron's name: "; cin.ignore(); getline(cin, name);
				patrons.add(Patron(name)); cout << endl;
				loans.UpdateLoanStatus();
				break;
			case 'f':
				loans.UpdateLoanStatus();
				cout << "Enter the name of the patron you want to remove: "; cin.ignore(); getline(cin, name);
				patrons.remove(name); cout << endl;
				loans.UpdateLoanStatus();
				break;
			case 'g':
				loans.UpdateLoanStatus();
				patrons.PrintEntries();
				loans.UpdateLoanStatus();
				break;
			case 'h':
				loans.UpdateLoanStatus();
				cout << "Enter patron's name: "; cin.ignore(); getline(cin, name); cout << endl;
				patrons.PrintDetails(name); cout << endl;
				loans.UpdateLoanStatus();
				break;
			case 'i':
				loans.UpdateLoanStatus();
				cout << "Enter the name of the patron: "; cin.ignore(); getline(cin, name);
				cout << "What book do you want to check out?: "; getline(cin, title);
				loan.SetBookID(title);
				loan.SetPatronID(name);
				loans.CheckOut(Loan(name, title)); cout << endl;
				loans.UpdateLoanStatus();
				break;
			case 'j':
				loans.UpdateLoanStatus();
				cout << "Enter the name of the patron: "; cin.ignore(); getline(cin, name);
				cout << "What book are you checking in: "; getline(cin, title);
				loans.CheckIn(name, title); cout << endl;
				loans.UpdateLoanStatus();
				break;
			case 'k':
				loans.UpdateLoanStatus();
				loans.ListOverdue(); cout << endl;
				loans.UpdateLoanStatus();
				break;
			case 'l':
				loans.UpdateLoanStatus();
				cout << "Enter the name of the patron: "; cin.ignore(); getline(cin, name);
				loans.ListBooksForPatron(name); cout << endl;
				loans.UpdateLoanStatus();
				break;
			case 'm':
				loans.UpdateLoanStatus();
				cout << "Enter the name of the patron: "; cin.ignore(); getline(cin, name);
				cout << "What book do you want to recheck: "; getline(cin, title);
				loans.ReCheck(name, title); cout << endl;
				loans.UpdateLoanStatus();
				break;
			case 'n':
				loans.UpdateLoanStatus();
				cout << "Enter the name of the patron: "; cin.ignore(); getline(cin, name);
				cout << "Enter title of the lost book: "; getline(cin, title);
				loans.ReportLost(name, title); cout << endl;
				loans.UpdateLoanStatus();
				break;
			case 'o':
				loans.UpdateLoanStatus();
				cout << "Enter the name of the patron: "; cin.ignore(); getline(cin, name);
				cout << "How much do you want to pay?: "; cin >> fine;
				patrons.PayFine(name, fine); cout << endl;
				loans.UpdateLoanStatus();
				break;
			case 'p':
				loans.UpdateLoanStatus();
				loans.print(); cout << endl;
				loans.UpdateLoanStatus();
				break;
			case 'z':
				books.StoreBooks();
				patrons.StorePatrons();
				loans.StoreLoans();
				loans.UpdateLoanStatus();
				break;
			default:
				loans.UpdateLoanStatus();
				cout << "Invalid Choice" << endl << endl;
				loans.UpdateLoanStatus();
				break;
		}	
	}
	return 0;
}