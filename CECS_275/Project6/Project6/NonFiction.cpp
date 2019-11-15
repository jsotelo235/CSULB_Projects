#include "Nonfiction.h"

NonFiction::NonFiction(string _Title, int _Pages, string _Subject, int _Illustrations) {

	title = _Title;
	pages = _Pages;
	subject = _Subject;
	numOfIllustrations = _Illustrations;
	type = "NonFiction";
	
}

void NonFiction::Print() {
	cout << "Name:" << setw(15) << left << title;
	Book::Print();
	cout << setw(5) << left << "Pages:" << setw(12) << left << pages 
		 << setw(5) << left << "Subject:" << setw(10) << left << subject << setw(12) 
		 << left << "Illustrations: " << numOfIllustrations;
}