#ifndef LOANS_H
#define LOANS_H
#include "Loan.h"
#include "Patron.h"
#include "Patrons.h"
#include <vector>

class Loans{
	public:
		void CheckOut(Loan item);
		void CheckIn(string name, string title);
		void ListOverdue();
		void ListBooksForPatron(string name);
		void UpdateLoanStatus();
		void ReCheck(string name, string title);
		void EditLoan();
		void ReportLost(string name, string title);
		void StoreLoans();
		void LoadLoans();
		void print();
	private:
		vector<Loan> borrow;
};

#endif