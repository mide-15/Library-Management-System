#include <iostream>
#include <vector>
#include <string>
#include "Book.h"
using namespace std;

Book::Book(string person, string bookTitle, string isbnNumber, float pay){ //sets up books
	author = person;
	title = bookTitle;
	isbn = isbnNumber;
	idNumber = num;
	cost = pay;
	currentStatus = "In";
	num++;
}
void Book::SetAuthor(string person){      //'set' are mutators and 'get' are accessors
	author = person;
}
void Book::SetTitle(string bookTitle){
	title = bookTitle;
}
void Book::SetISBN(string isbnNumber){
	isbn = isbnNumber;
}
void Book::SetIDNumber(int id){
	idNumber = id;
}
void Book::SetCost(float pay){
	cost = pay;
}
void Book::SetOutStatus(){
	currentStatus = "Out";
}
void Book::SetInStatus(){
	currentStatus  = "In";
}
void Book::SetLostStatus(){
	currentStatus  = "Lost";
}
string Book::GetAuthor(){
	return author;
}
string Book::GetTitle(){
	return title;
}
string Book::GetISBN(){
	return isbn;
}
int Book::GetIDNumber(){
	return idNumber;
}
float Book::GetCost(){
	return cost;
}
string Book::GetStatus(){
	return currentStatus;
}
int Book::num = 1000000000; //sets up book id
void Book::SetStatus(string stat){
	currentStatus = stat;
}