#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <ctime>
#include "Loan.h"
#include "Book.h"
#include "Books.h"
#include "Patron.h"
#include "Patrons.h"
using namespace std;

extern Books books;
extern Patrons patrons;
Loan::Loan(string name, string title){ //sets up loan
	time_t now = time(NULL); tm nowlocal = *localtime(&now);
	loanID = l; bookID = books.search(title); patronID = patrons.search(name); dueDate = now + 864000; currentStatus = "normal"; re = 0;
	l++;
}
void Loan::SetLoanID(int lid){  //'set' are mutators and 'get' are accessors
	loanID = lid;
}
void Loan::SetBookID(string title){
	bookID = books.search(title);
}
void Loan::SetPatronID(string name){
	patronID = patrons.search(name);
}
void Loan::SetDueDate(){
	dueDate = dueDate + 86400;
}
void Loan::SetReDate(){
	dueDate = dueDate + 864000;
}
void Loan::SetStatus(){
	currentStatus = "overdue";
}
void Loan::SetNormal(){
	currentStatus = "normal";
}
int Loan::GetLoanID(){
	return loanID;
}
int Loan::GetBookID(){
	return bookID;
}
int Loan::GetPatronID(){
	return patronID;
}
long int Loan::GetDueDate(){
	return dueDate;
}
string Loan::GetStatus(){
	return currentStatus;
}
void Loan::SetRe(){
	re++;
}
int Loan::GetRe(){
	return re;
}
void Loan::SetDueDates(int due){
	dueDate = due;
}
void Loan::SetStatuses(string cur){
	currentStatus = cur;
}
void Loan::SetRee(int ree){
	re = ree;
}
int Loan::l = 1000000000; //set up loan id
void Loan::SetBookIDs(int bid){
	bookID = bid;
}
void Loan::SetPatronIDs(int patronid){
	patronID = patronid;
}