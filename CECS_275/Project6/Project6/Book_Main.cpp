#include <iostream>
#include <fstream>
#include  <sstream>
#include <string>
#include "Book.h"
#include "Fiction.h"
#include "Nonfiction.h"
#include "Reference.h"

using namespace std;

const string NEWLINE = "\n";

enum Books {
	FICTION,
	NONFICTION,
	REFERENCE
};

istream &operator >> (istream &, Books &);
Book *BookFactory(istream &);
void PrintAll(Book *);

int main()
{
	fstream infile, infile1;
	Book *_Books;
	int totalPages = 0;

	infile.open("books.txt", ios::in);

	// Checks to see if the the file exits
	if (infile.fail())
	{
		cout << "ERROR: Cannot open the file.\n";
		return 0;
	}

	while (!infile.eof())
	{
		_Books = BookFactory(infile);
		PrintAll(_Books);
	}

	cout << "Total pages: " << endl;
	system("pause");
	return 0;
}

/*
Overload operator insertion function
*/
istream &operator >> (istream &in, Books &book) 
{
	int s;
	in >> s;

	book = (Books)s;

	return in;
}

/*
Print All Function
*/
void PrintAll(Book *book) {

	if (book != nullptr) {
		book->Print();
	}

	cout << NEWLINE;
}

/*
Book factory 
*/
Book *BookFactory(istream &in) {

	Books code;		// enums
	in >> code;
	
	int pages = 0;

	switch (code)
	{
		case FICTION:
		{
			string genre, title;
			in >> title >> pages >> genre;
			return new Fiction(title, pages, genre);
			break;
		}
		case NONFICTION:
		{
			string title, subject;
			int illustrations;
			in >> title >> pages >> subject >> illustrations;
			return new NonFiction(title, pages, subject, illustrations);
			break;
		}
		case REFERENCE:
		{
			string title;
			in >> title >> pages;
			return new Reference(title, pages);
			break;
		}
	}
	return 0;
}