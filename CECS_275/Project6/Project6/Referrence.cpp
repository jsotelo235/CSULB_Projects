#include "Reference.h"

Reference::Reference(string _Title, int _Pages) {
	title = _Title;
	pages = _Pages;
	type = "Reference";
}

void Reference::Print() {
	cout <<"Name:" << setw(15) << left << title;
	Book::Print();
	cout << "Pages:"<< left << pages;
}