#ifndef BOOKS_H
#define BOOKS_H
#include "Book.h"
#include <vector>
using namespace std;

class Books{
	public:
		void add(Book item);
		void edit(int idn);
		void in(int idn);
		void lost(int idn);
		void remove(string title);
		int search(string title);
		void PrintEntries();
		void PrintDetails(string title);
		string SearchBookName(int idn);
		float LostFine(int idn);
		void StoreBooks();
		void LoadBooks();
	private:
		vector<Book> bookCount;
};

#endif