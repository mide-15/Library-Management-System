#include <iostream>
#include <vector>
#include "Patron.h"
using namespace std;

Patron::Patron(string person){ //sets up patron
	name = person; idNumber = nextID; fine = 0.0; numBooks = 0; nextID++;
}
void Patron::SetName(string person){ //'set' are mutators and 'get' are accessors
	name = person;
}
void Patron::SetIDNumber(int id){
	idNumber = id;
}
void Patron::SetPay(float pay){
	fine = fine - pay;
}
void Patron::SetFine(){
	fine = fine + 0.25;
}
void Patron::SetLostFine(float pay){
	fine = fine + pay;
}
void Patron::SetNumBooks(){ //adds 1 to number of books
	numBooks++;
}
void Patron::DelNumBooks(){ // deletes 1 to number of books
	numBooks--;
}
string Patron::GetName(){
	return name;
}
int Patron::GetIDNumber(){
	return idNumber;
}
float Patron::GetFine(){
	return fine;
}
int Patron::GetNumBooks(){
	return numBooks;
}
int Patron::nextID = 100000; //sets up patron id.
void Patron::SetNumBookss(int boo){
	numBooks = boo;
}
void Patron::SetFines(float fines){
	fine = fines;
}