#pragma once
#ifndef REFERENCE_H
#define REFERENCE_H

#include "Book.h"
#include <string>
using namespace std;

class Reference: public Book{
	string title;
	int pages;

public:
	Reference(string, int);

	void Print();
};
#endif // !REFERENCE_H

