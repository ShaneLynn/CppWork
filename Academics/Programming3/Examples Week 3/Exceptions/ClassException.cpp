#include "utils.h"
#include "Book.h"
#include "InvalidInput.h"

int main()
{
	try
	{
		Book aBook(100);
		cout << "The number of pages is " << aBook.GetPages() << endl;
		aBook.SetPages(-222);
		cout << "The number of pages is " << aBook.GetPages() << endl;
	}
	catch(InvalidInput ex)
	{
		cout << ex.GetMsg() << endl;
		cout << "Invalid input was " << ex.GetValue() << endl;
	}

	PauseProgram();
	return 0;
}