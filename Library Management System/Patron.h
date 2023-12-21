#ifndef PATRON_H
#define PATRON_H
using namespace std;

class Patron{
	public:
		Patron(string person);
		void SetName(string person);
		void SetIDNumber(int id);
		void SetFine();
		void SetFines(float fines);
		void SetNumBooks();
		void SetNumBookss(int boo);
		void DelNumBooks();
		string GetName();
		int GetIDNumber();
		float GetFine();
		void SetLostFine(float pay);
		int GetNumBooks();
		void SetPay(float pay);
		static int nextID;
	private:
		string name;
		int idNumber;
		float fine;
		int numBooks;
};

#endif