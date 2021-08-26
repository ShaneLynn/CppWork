// A class template for holding a linked list,   Provided in lecture notes, with a few alterations to work
// with the assignment.
#pragma once
#include <iostream>
using namespace std;

/*template <class T>
struct ListNode
{
	T data;
	ListNode* next;
};*/

template <class T>
class ListNode
{
public:
	T data;
	ListNode<T>* next;

	ListNode(T data)
	{
		this->data = data;
		next = nullptr;
	}
};

template <class T>
class LinkedList
{
protected:									//Was private originally, changed to allow inheritance to work correctly
	ListNode<T>* head;

public:
	LinkedList();
	~LinkedList();
	void AppendNode(T data);
	void InsertNode(T data);
	void DeleteNode(T data);
	void DisplayList();
	T operator [] (const int);				//Added function to overload [] to act like an array getting data
};


template <class T>
LinkedList<T>::LinkedList()
{
	head = nullptr;
}

template <class T>
LinkedList<T>::~LinkedList()
{
	ListNode<T>* nextNode = nullptr;
	ListNode<T>* nodePtr = nullptr;

	nodePtr = head;

	while (nodePtr != nullptr)
	{
		nextNode = nodePtr->next;

		delete nodePtr;

		nodePtr = nextNode;
	}
}

template <class T>
void LinkedList<T>::AppendNode(T data)
{
	ListNode<T>* newNode = nullptr;
	ListNode<T>* nodePtr = nullptr;

	newNode = new ListNode<T>(data);

	if (head == nullptr)
		head = newNode;
	else
	{
		nodePtr = head;

		while (nodePtr->next != nullptr)
		{
			nodePtr = nodePtr->next;
		}

		nodePtr->next = newNode;
	}
}

template <class T>
void LinkedList<T>::InsertNode(T data)
{
	ListNode<T>* newNode = nullptr;
	ListNode<T>* currentNode = nullptr;
	ListNode<T>* previousNode = nullptr;

	newNode = new ListNode<T>(data);


	if (head == nullptr)
	{
		head = newNode;
	}
	else if (head->data >= newNode->data)
	{
		newNode->next = head;
		head = newNode;
	}
	else
	{
		currentNode = head;
		previousNode = nullptr;

		while (currentNode != nullptr && currentNode->data < newNode->data)
		{
			previousNode = currentNode;
			currentNode = currentNode->next;
		}

		previousNode->next = newNode;
		newNode->next = currentNode;
	}
}

template <class T>
void LinkedList<T>::DeleteNode(T data)
{
	ListNode<T>* currentNode = nullptr;
	ListNode<T>* previousNode = nullptr;

	if (head != nullptr)
	{
		if (head->data == data)
		{
			currentNode = head->next;
			delete head;
			head = currentNode;
		}
		else
		{
			currentNode = head;

			while (currentNode != nullptr && currentNode->data != data)
			{
				previousNode = currentNode;
				currentNode = currentNode->next;
			}

			if (currentNode != nullptr)
			{
				previousNode->next = currentNode->next;
				delete currentNode;
			}
		}
	}
}

template <class T>
void LinkedList<T>::DisplayList()
{
	ListNode<T>* nodePtr = nullptr;

	nodePtr = head;

	while (nodePtr != nullptr)
	{
		cout << nodePtr->data << endl;
		nodePtr = nodePtr->next;
	}
}


/******************************************************************
* This function overloads the [] operator through the linkedlist nodes
to identify the node by the provided index number.
******************************************************************/
template <class T>

T LinkedList<T>::operator [] (const int index)
{

	if (head == NULL)
	{
		return T();
	}
	else
	{
		//Setup a counter variable
		int count = 0;

		//Create a pointer and set it to the beginning of the list
		ListNode<T>* currPTR = head;

		//Setup the while loop to step through the linked list
		while (currPTR != NULL && count < index)
		{
			currPTR = currPTR->next;
			count++;					//Increase the counter variable 
		}

		//Setup a check to compare the counter variable to the index variable and
		//return that value if it is found.
		if (count == index && currPTR != NULL)
		{
			return currPTR->data;
		}
		else
		{
			return T();
		}
	}
}
