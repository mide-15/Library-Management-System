#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <fstream>
#include "Loans.h"
#include "Patrons.h"
#include "Patron.h"
#include "Books.h"
using namespace std;

extern Patrons patrons;
extern Books books;

void Loans::CheckOut(Loan item){ // check's out book
	if(patrons.SearchNumBooks(item.GetPatronID()) < 6 && patrons.SearchFine(item.GetPatronID()) <= 0){
		borrow.push_back(item);
		patrons.AddNumBooks(borrow.back().GetPatronID());
		books.edit(borrow.back().GetBookID());
		cout << "Book is due 10 days from today" << endl;
	}
	else{
		cout << "Patron either has too many books out or owes a fine" << endl;
	}
}
void Loans::CheckIn(string name, string title){ //check in a book
	for(int i = 0; i < borrow.size(); i++){
		if(borrow[i].GetPatronID() == patrons.search(name)){
			for(int j = 0; j < borrow.size(); j++){
				if(borrow[j].GetBookID() == books.search(title)){
					books.in(borrow[j].GetBookID());
					patrons.SubtractNumBooks(borrow[i].GetPatronID());
					borrow.erase(borrow.begin() + i);
					cout << "Book checked in" << endl;
					if(patrons.SearchFine(borrow[i].GetPatronID()) > 0){
						cout << "You owe $" << patrons.SearchFine(borrow[i].GetPatronID()) << endl;
					}
				}
			}
		}
	}
}
void Loans::ListOverdue(){ //list all overdue books
	time_t now = time(NULL); tm nowlocal = *localtime(&now);
	for(int i = 0; i < borrow.size(); i++){
		 if(borrow[i].GetDueDate() < now){
			 cout << books.SearchBookName(borrow[i].GetBookID()) << " (Checked out by " << patrons.searchname(borrow[i].GetPatronID()) << ")" << endl;
		 }
	}
}
void Loans::ListBooksForPatron(string name){ //list books patron has checked out
	cout << "All books checked out by " << name << endl;
	for(int i = 0; i < borrow.size(); i++){
		if(borrow[i].GetPatronID() == patrons.search(name)){
			cout << books.SearchBookName(borrow[i].GetBookID()) << endl;
		}
	}
}
void Loans::print(){ //testing stuff
	for(int i = 0; i < borrow.size(); i++){
		time_t now = time(NULL);
		cout << now << endl;
		cout << borrow[i].GetDueDate() << endl;
	}
}
void Loans::UpdateLoanStatus(){ //checks if books are overdue
	time_t now = time(NULL);
	for(int i = 0; i < borrow.size(); i++){
		if(borrow[i].GetDueDate() < now){
			borrow[i].SetStatus();
			patrons.AddFine(borrow[i].GetPatronID());
			borrow[i].SetDueDate();
		}
	}
}
void Loans::ReCheck(string name, string title){ //rechecks a loaned book
	for(int i = 0; i < borrow.size(); i++){
		if(borrow[i].GetPatronID() == patrons.search(name)){
			for(int j = 0; j < borrow.size(); j++){
				if(borrow[j].GetBookID() == books.search(title)){
					for(int k = 0; k < borrow.size(); k++){
						if(borrow[k].GetPatronID() == borrow[i].GetPatronID() && borrow[k].GetBookID() == borrow[j].GetBookID()){
							if(borrow[k].GetRe() == 0){
								borrow[k].SetReDate(); borrow[k].SetRe();
								cout << "10 days have been added to your loan" << endl;
							}
							else{
								cout << "You already rechecked this book" << endl;
							}
						}
					}
				}
			}
		}
	}
}
void Loans::ReportLost(string name, string title){ //sets book as lost and adds fine to patron
	for(int i = 0; i < borrow.size(); i++){
		if(borrow[i].GetPatronID() == patrons.search(name)){
			for(int j = 0; j < borrow.size(); j++){
				if(borrow[j].GetBookID() == books.search(title)){
					for(int k = 0; k < borrow.size(); k++){
						if(borrow[k].GetPatronID() == borrow[i].GetPatronID() && borrow[k].GetBookID() == borrow[j].GetBookID()){
							books.lost(borrow[k].GetBookID());
							patrons.SubtractNumBooks(borrow[k].GetPatronID());
							patrons.AddLostFine(borrow[k].GetPatronID(), borrow[k].GetBookID());
							borrow.erase(borrow.begin() + k);
							cout << "Fines have been added" << endl;
						}
					}
				}
			}
		}
	}
}
void Loans::StoreLoans(){ //stores all data of loans
	ofstream fout;
	fout.open("data.dat");
	for(int i = 0; i < borrow.size(); i++){
		fout << borrow[i].GetLoanID() << " " << borrow[i].GetBookID() << " " << borrow[i].GetPatronID() << " " << borrow[i].GetDueDate() << " " << borrow[i].GetStatus() << " " << borrow[i].GetRe() << endl;
	}
	fout.close();
}
void Loans::LoadLoans(){ //loads all data of loans
	int loanID;
	int bookID;
	int patronID;
	long int dueDate;
	string currentStatus;
	string name; string title;
	int re;
	ifstream fin;
	int count = 0;
	fin.open("data.dat");
	Loan newloan(name, title);
	//fin >> count;
	while(fin >> ws, fin >> loanID >> bookID >> patronID >> dueDate >> currentStatus >> re){
		newloan.SetLoanID(loanID);
		newloan.SetBookIDs(bookID);
		newloan.SetPatronIDs(patronID);
		newloan.SetDueDates(dueDate);
		newloan.SetStatuses(currentStatus);
		newloan.SetRee(re);
		borrow.push_back(newloan);
	}
	fin.close();
	
}
