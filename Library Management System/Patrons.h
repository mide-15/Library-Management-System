#ifndef PATRONS_H
#define PATRONS_H
#include "Patron.h"
#include <vector>
//using namespace std;

class Patrons{
	public:
		void add(Patron item);
		void edit(Patron item);
		void remove(string name);
		int search(string name);
		void PrintEntries();
		void PrintDetails(string name);
		int GetCount();
		void AddNumBooks(int idn);
		int SearchNumBooks(int ian);
		float SearchFine(int ian);
		void AddFine(int idn);
		void AddLostFine(int idn, int bok);
		void SubtractNumBooks(int idn);
		string searchname(int idn);
		void PayFine(string name, float fine);
		void StorePatrons();
		void LoadPatrons();
	private:
		vector<Patron> people;
};

#endif