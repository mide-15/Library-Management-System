#ifndef BOOK_H
#define BOOK_H
#include <string>
using namespace std;

class Book{
   public:
      Book(string person, string bookTitle, string isbnNumber, float pay);
	  void SetAuthor(string person);
	  void SetTitle(string bookTitle);
	  void SetISBN(string isbnNumber);
	  void SetIDNumber(int id);
	  void SetCost(float pay);
	  void SetOutStatus();
	  void SetInStatus();
	  void SetLostStatus();
	  void SetStatus(string stat);
	  string GetAuthor();
	  string GetTitle();
	  string GetISBN();
	  int GetIDNumber();
	  float GetCost();
	  string GetStatus();
      static int num;
   private:
      string author;
	  string title;
	  string isbn;
	  int idNumber;
	  float cost;
	  string currentStatus;
};

#endif
