#include "InvalidInput.h"

InvalidInput::InvalidInput(string msg, int value)
{
	this->msg = msg;
	this->value = value;
}

string InvalidInput::GetMsg()
{
	return msg;
}

int InvalidInput::GetValue()
{
	return value;
}
