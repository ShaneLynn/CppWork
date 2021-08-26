#pragma once
#include <iostream>
using namespace std;

class Book
{
	protected:
		int pages = 15;

	public:
		Book(int pages);
		int GetPages();
		void SetPages(int pages);
		void DisplayStats();
};

