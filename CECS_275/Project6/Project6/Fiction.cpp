#include "Fiction.h"
#include <iostream>
using namespace std;

Fiction::Fiction(string _Genre, int _Pages, string _Title) {
	genre = _Genre;
	pages = _Pages;
	title = _Title;
	type = "Fiction";
}

void Fiction::Print() {
	cout << left << "Name:" << setw(15) << left << title;
	Book::Print();
	cout << left << "Pages:" << setw(12) << left << pages 
		 << left << "Genre:" << setw(12) << left << genre;
}