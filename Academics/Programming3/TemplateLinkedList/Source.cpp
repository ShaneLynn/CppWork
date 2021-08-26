#include "LinkedList.h"
#include <string>
using namespace std;

void PauseProgram()
{
	string temp;
	cout << "Press Enter to Continue" << endl;
	getline(cin, temp);
}

int main()
{
	LinkedList<int>* myList = new LinkedList<int>();

	myList->AppendNode(5);
	myList->AppendNode(2);
	myList->AppendNode(7);

	myList->DisplayList();

	cout << "Sorted List" << endl;
	LinkedList<int>* myList2 = new LinkedList<int>();
	myList2->InsertNode(5);
	myList2->InsertNode(2);
	myList2->InsertNode(7);
	myList2->InsertNode(6);

	myList2->DisplayList();

	cout << "Deleting from lists" << endl;

	LinkedList<int>* myList3 = new LinkedList<int>();

	myList3->DeleteNode(9);//Delete with empty list
	cout << endl;

	myList->DeleteNode(5); //Delete first node
	myList->DisplayList();
	cout << endl;

	myList2->DeleteNode(5); //Delete middle of list
	myList2->DisplayList();
	cout << endl;
	myList2->DeleteNode(7); //Delete last node
	myList2->DisplayList();
	cout << endl;

	delete myList;
	delete myList2;
	delete myList3;

	PauseProgram();
	return 0;
}