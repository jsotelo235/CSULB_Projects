#pragma once
#ifndef NONFICTION_H
#define NONFICTION_H
#include "Book.h"
using namespace std;

class NonFiction: public Book {
	string  title, subject;
	int  pages, numOfIllustrations;

public:
	NonFiction(string, int, string, int);
	void Print();
};
#endif // !NONFICTION_H

