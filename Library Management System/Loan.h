#ifndef LOAN_H
#define LOAN_H
#include "Patron.h"
#include "Patrons.h"
using namespace std;

class Loan{
	public:
		Loan(string name, string title);
		void SetLoanID(int lid);
		void SetBookID(string title);
		void SetPatronID(string name);
		void SetBookIDs(int title);
		void SetPatronIDs(int name);
		void SetDueDate();
		void SetReDate();
		void SetStatus();
		void SetNormal();
		void SetDueDates(int due);
		void SetStatuses(string cur);
		void SetRee(int ree);
		int GetLoanID();
		int GetBookID();
		int GetPatronID();
		long int GetDueDate();
		string GetStatus();
		int GetRe();
		void SetRe();
		static int l;
	private:
		int loanID;
		int bookID;
		int patronID;
		long int dueDate;
		string currentStatus;
		int re;
};

#endif