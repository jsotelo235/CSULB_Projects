#pragma once
#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Book {

protected:
	string type;

public:

	virtual void Print() {
		cout << left <<"Type:"<< setw(15) << left << type;
	}
};
#endif // !BOOK_H

