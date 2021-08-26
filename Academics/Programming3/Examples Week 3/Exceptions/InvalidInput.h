#pragma once
#include <string>
using namespace std;

class InvalidInput
{
	private:
		string msg;
		int value;
	public:
		InvalidInput(string msg, int value);
		string GetMsg();
		int GetValue();
};

