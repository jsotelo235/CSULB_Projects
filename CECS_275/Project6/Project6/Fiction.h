#pragma once
#ifndef FICTION_H
#define FICTION_H
#include <string>
#include "Book.h"

class Fiction: public Book {	//inheriting from Book class
	string genre, title;
	int pages;

public:
	//Constructor
	Fiction(string, int, string);
	void Print();
};
#endif // !FICTION_H

