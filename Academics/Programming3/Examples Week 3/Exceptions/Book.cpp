#include "Book.h"
#include "InvalidInput.h"

Book::Book(int pages)
{
	SetPages(pages);
}

int Book::GetPages()
{
	return pages;
}

void Book::SetPages(int pages)
{
	if (pages < 0)
	{
		InvalidInput temp("The number of pages cannot be less than zero", pages);
		throw temp;
	}
	this->pages = pages;
}

void Book::DisplayStats()
{
	cout << "Book information" << endl;
	cout << "Total number of Pages " << pages << endl << endl;
}


