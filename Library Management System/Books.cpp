#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "Books.h"
using namespace std;

void Books::add(Book item){ //adds books
	bookCount.push_back(item);
}
void Books::edit(int idn){ //sets status to out
	for(int i = 0; i < bookCount.size(); i++){
		if(bookCount[i].GetIDNumber() == idn){
			bookCount[i].SetOutStatus();
		}
	}
}
void Books::in(int idn){ //sets status to in
	for(int i = 0; i < bookCount.size(); i++){
		if(bookCount[i].GetIDNumber() == idn){
			bookCount[i].SetInStatus();
		}
	}
}
void Books::lost(int idn){ //sets status to lost
	for(int i = 0; i < bookCount.size(); i++){
		if(bookCount[i].GetIDNumber() == idn){
			bookCount[i].SetLostStatus();
		}
	}
}
void Books::remove(string title){ // removes book
	int size = bookCount.size();
	for(int i = 0; i < bookCount.size(); i++){
		if(bookCount[i].GetTitle() == title){
			bookCount.erase(bookCount.begin() + i);
		}
	}
	if(bookCount.size() == size){
      cout << "Book not found." << endl << endl;
   }
}
int Books::search(string title){ //looks for book id
	int idnum = 4;
	for(int i = 0; i < bookCount.size(); i++){
		if(bookCount[i].GetTitle() == title){
			idnum = bookCount[i].GetIDNumber();
			return idnum;
		}
	}
	return -1;
}
void Books::PrintEntries(){ //prints all books
	cout << "ALL BOOKS IN THE ENTRY: " << endl;
	for(int i = 0;  i < bookCount.size(); i++){
		cout << bookCount[i].GetTitle() << endl;
	}
	cout << endl;
}
void Books::PrintDetails(string title){ //prints details for single book
	cout << "Details about " << title << ":" << endl;
	for(int i = 0; i < bookCount.size(); i++){
		if(bookCount[i].GetTitle() == title){
			cout << "Author: " << bookCount[i].GetAuthor() << endl;
			cout << "ISBN Number: " << bookCount[i].GetISBN() << endl;
			cout << "ID Number: " << bookCount[i].GetIDNumber() << endl;
			cout << "Price: $" << bookCount[i].GetCost() << endl;
			cout << "Status: " << bookCount[i].GetStatus() << endl;
		}			
	}
}
string Books::SearchBookName(int idn){ // looks for book name
	string t;
	for(int i = 0; i < bookCount.size(); i++){
		if(bookCount[i].GetIDNumber() == idn){
			t = bookCount[i].GetTitle();
		}
	}
	return t;
}
float Books::LostFine(int idn){ //looks for book cost
	float t;
	for(int i = 0; i < bookCount.size(); i++){
		if(bookCount[i].GetIDNumber() == idn){
			t = bookCount[i].GetCost();
		}
	}
	return t;
}
void Books::StoreBooks(){ //stores all books
	ofstream fout;
	fout.open("bookdata.dat");
	for(int i = 0; i < bookCount.size(); i++){
		fout << bookCount[i].GetAuthor() << "," << bookCount[i].GetTitle() << ", " << bookCount[i].GetISBN() << " " << bookCount[i].GetIDNumber() << " " << bookCount[i].GetCost() << " " << bookCount[i].GetStatus() << endl;
	}
	fout.close();
}
void Books::LoadBooks(){  //loads all books
    string author;
	string title;
	string isbn;
	int idNumber;
	float cost;
	string currentStatus;
	Book newbook(author, title, isbn, cost);
	ifstream fin;
	int count = 0;
	const char comma = ',';
	fin.open("bookdata.dat");
	while(fin >> ws, getline(fin, author, comma), getline(fin, title, comma), fin >> isbn >> idNumber >> cost >> currentStatus){
		newbook.SetAuthor(author);
		newbook.SetTitle(title);
		newbook.SetISBN(isbn);
		newbook.SetIDNumber(idNumber);
		newbook.SetCost(cost);
		newbook.SetStatus(currentStatus);
		bookCount.push_back(newbook);
	}
	fin.close();
	
}