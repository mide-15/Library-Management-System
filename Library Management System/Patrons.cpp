#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "Patrons.h"
#include "Books.h"
using namespace std;

extern Books books;

int count = 0;
void Patrons::add(Patron item){ //adds patron
	people.push_back(item);
	count++;
}
void Patrons::remove(string name){ // removes patron
	int size = people.size();
	for(int i = 0; i < people.size(); i++){
		if(people[i].GetName() == name){
			people.erase(people.begin() + i);
			count = count - 1;
		}
	}
	if(people.size() == size){ 
      cout << "Patron not found." << endl << endl;
   }
}
int Patrons::search(string name){ //gets patron id number
	int idnum;
	for(int i = 0; i < people.size(); i++){
		if(people[i].GetName() == name){
			idnum = people[i].GetIDNumber();
		}
	}
	return idnum;
}
void Patrons::PrintEntries(){ // prints all patrons
	cout << "ALL PATRONS IN THE ENTRY: " << endl;
	for(int i = 0;  i < people.size(); i++){
		cout << people[i].GetName() << endl;
	}
	cout << endl;
}
void Patrons::PrintDetails(string name){ // prints details for single patron
	cout << "Details about " << name << ":" << endl;
	for(int i = 0; i < people.size(); i++){
		if(people[i].GetName() == name){
			cout << "ID Number: " << people[i].GetIDNumber() << endl;
			cout << "Fine: $" << people[i].GetFine() << endl;
			cout << "Number of Books checked out: " << people[i].GetNumBooks() << endl;
		}			
	}
}
int Patrons::GetCount(){ //get number of patrons
	return count;
}
void Patrons::AddNumBooks(int idn){ //adds number of books to patron
	for(int i = 0;  i < people.size(); i++){
		if(people[i].GetIDNumber() == idn){
			people[i].SetNumBooks();
		}
	}
}
void Patrons::SubtractNumBooks(int idn){ //deletes number of books to patron
	for(int i = 0;  i < people.size(); i++){
		if(people[i].GetIDNumber() == idn){
			people[i].DelNumBooks();
		}
	}
}
int Patrons::SearchNumBooks(int ian){ // looks for number of books 
	int idnum;
	for(int i = 0; i < people.size(); i++){
		if(people[i].GetIDNumber() == ian){
			idnum = people[i].GetNumBooks();
		}
	}
	return idnum;
}
float Patrons::SearchFine(int ian){ // looks for patron's fine
	float idnum;
	for(int i = 0; i < people.size(); i++){
		if(people[i].GetIDNumber() == ian){
			idnum = people[i].GetFine();
		}
	}
	return idnum;
}
void Patrons::AddFine(int idn){ //adds fine to patron
	for(int i = 0;  i < people.size(); i++){
		if(people[i].GetIDNumber() == idn){
			people[i].SetFine();
		}
	}
}
void Patrons::AddLostFine(int idn, int bok){ //adds fine to patron from the lost book
	for(int i = 0;  i < people.size(); i++){
		if(people[i].GetIDNumber() == idn){
			people[i].SetLostFine(books.LostFine(bok));
		}
	}
}
string Patrons::searchname(int idn){ //looks for patron's name
	string t;
	for(int i = 0; i < people.size(); i++){
		if(people[i].GetIDNumber() == idn){
			t = people[i].GetName();
		}
	}
	return t;
}
void Patrons::PayFine(string name, float fine){ //patron pays fine
	for(int i = 0; i < people.size(); i++){
		if(people[i].GetName() == name){
			people[i].SetPay(fine);
		}
	}
}
void Patrons::StorePatrons(){ //stores all data of patrons
	ofstream fout;
	fout.open("patrondata.dat");
	for(int i = 0; i < people.size(); i++){
		fout << people[i].GetName() << "," << people[i].GetIDNumber() << " " << people[i].GetFine() << " " << people[i].GetNumBooks() << "\n";
	}
	fout.close();
}
void Patrons::LoadPatrons(){ //loads all data of patrons
	string name;
	int idNumber;
	float fine;
	int numBooks;
	ifstream fin;
	Patron newpatron(name);
	int count = 0;
	const char comma = ',';
	fin.open("patrondata.dat");
	while(fin >> ws, getline(fin, name, comma), fin >> idNumber >> fine >> numBooks){
		newpatron.SetName(name);
		newpatron.SetIDNumber(idNumber);
		newpatron.SetFines(fine);
		newpatron.SetNumBookss(numBooks);
		people.push_back(newpatron);
	}
	fin.close();	
}