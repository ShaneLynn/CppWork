/***************************************************************************************************************************
*Author: Christopher S Lynn
 CISS 243 -  Programming III
*Programming Assignment 8 - Course Project
 Created: 8/12/2021

 ----------------------------------------------------------------------------------------------------------------------------

 Description:
 This file describes the methods listed in the header file: DVD.h

***************************************************************************************************************************/


#include "DVD.h"

//----------------------------------------------------------------
// CONSTRUCTORS
//----------------------------------------------------------------

/*************************************
* Default constructor
**************************************/
DVD::DVD() : Media()
{
    releaseYear = 0;
}

/******************************************************************
* Parameter constructor that accepts the title, length, and release
* year of the DVD.
******************************************************************/
DVD::DVD(string dvdTitle, int dvdLength, int dvdYear) : Media(dvdTitle, dvdLength)
{
    releaseYear = dvdYear;
}

//----------------------------------------------------------------
// ACCESSORS AND MUTATORS = GETTERS AND SETTERS
//----------------------------------------------------------------

/******************************************************************
* This function gets the value stored in the data member: releaseYear
******************************************************************/
int DVD::GetReleaseYear() const
{
    return releaseYear;
}

/******************************************************************
* This function sets the value stored in the data member: releaseYear
******************************************************************/
void DVD::SetReleaseYear(int rYear)
{
    releaseYear = rYear;
}

/******************************************************************
* This function gets the value stored in the structure data member: actor.actorName
******************************************************************/
string DVD::GetCurrActorName() const
{
    return actor.actorName;
}

/******************************************************************
* This function gets the value stored in the structure data member: actor.characterName
******************************************************************/
string DVD::GetCurrActorChars() const
{
    return actor.characterName;
}

/******************************************************************
* This function sets the values stored in the structure data member: actor
******************************************************************/
void DVD::SetCurrActor(string actorIn, string characterIn)
{
    actor.actorName = actorIn;
    actor.characterName = characterIn;
}



//----------------------------------------------------------------
// ACTION FUNCTIONS
//----------------------------------------------------------------

/******************************************************************
* This function adds a new song to the current linkedList: actors
* It prompts the user to enter the name and character before
* appending it to the linked list.  It also asks the user how many
* actors to add to the DVD so they can enter more than 1 at a time.
******************************************************************/
void DVD::AddNewActor()
{
    //Setup variables to use with adding songs
    Cast newActor;
    string actorInput;
    string charInput;
    int actorsToAdd;

    //Prompt the user for the number of songs to add to the CD
    cout << "How many new actors/actresses would you like to add to: " << this->GetMediaTitle() << endl;
    cout << "<Enter 0 to skip this title>" << endl;
    cout << "-> ";
    cin >> actorsToAdd;
    //cin.ignore();
    //Validate the input
    while (cin.fail() || actorsToAdd < 0)
    {
        cout << "Not a valid choice!  Please enter 0 or higher." << endl;
        cout << "->";
        cin.clear();
        cin.ignore();
        cin >> actorsToAdd;
        //cin.ignore();
    }

    //Setup a check to cancel the action if the user selects 0
    if (actorsToAdd == 0)
    {
        return;
    }

    cin.ignore();
    //Setup a loop to step through the each song from the amount entered by the user
    for (int index = 0; index < actorsToAdd; index++)
    {
        cout << "\nWhat is actor/actress " << index + 1 << "'s name to add? " << endl;
        cout << "-> ";
        getline(cin, actorInput);

        cout << "What is actor/actress " << index + 1 << "'s character name to add? " << endl;
        cout << "-> ";
        //cin.ignore();
        getline(cin, charInput);

        //Update the structure variables
        newActor.actorName = actorInput;
        newActor.characterName = charInput;

        //Add the structure to the list
        actors->AppendNode(newActor);
        cout << "New Actor/Actress Added!" << endl;
    }
}

/******************************************************************
* This function removes a current from the current linkedList: actors
* It prompts the user to enter the name and character before
* searching the linked list for a match.  If match is found it is removed.
******************************************************************/
void DVD::RemoveActor()
{
    //Setup a check to cancel the action if no cds exist
    if (actors->CountNodes() == 0)
    {
        cout << "No actors/actresses to remove!" << endl;
        return;
    }

    //Setup variables to use with removing songs
    Cast oldActor;
    string actorInput;
    string charInput;
    int actorToRemove;

    //Prompt the user for the number of songs to remove from the CD
    cout << "How many actors/actresses would you like to remove from: " << this->GetMediaTitle() << endl;
    cout << "<Enter 0 to skip this title>" << endl;
    cout << "-> ";
    cin >> actorToRemove;
    //cin.ignore();
    //Validate the input
    while (cin.fail() || actorToRemove < 0)
    {
        cout << "Not a valid choice!  Please enter 0 or higher." << endl;
        cout << "->";
        cin.clear();
        cin.ignore();
        cin >> actorToRemove;
        //cin.ignore();
    }

    //Setup a check to cancel the action if the user selects 0
    if (actorToRemove == 0)
    {
        return;
    }

    cin.ignore();
    //Setup a loop to step through the each song from the amount entered by the user
    for (int index = 0; index < actorToRemove; index++)
    {
        //Prompt the user for the title, and length the old song
        cout << "\nWhat is Actor/Actress " << index + 1 << "'s name to remove? " << endl;
        cout << "-> ";
        
        getline(cin, actorInput);

        cout << "What is Actor/Actress " << index + 1 << "'s character name to remove? " << endl;
        cout << "-> ";
        //cin.ignore();
        getline(cin, charInput);

        //Update the structure variables
        oldActor.actorName = actorInput;
        oldActor.characterName = charInput;

        //Validate the user's input to avoid crashing the program when deleting a node (exact matches required).
        //------------------------------------------------------------------------------------------------------
        //Setup validation variables
        string currActor;
        string currChar;
        bool exactMatch = false;

        //Use a loop to step through the collection to find a match for the user input
        for (auto index = 0; index < actors->CountNodes(); index++)
        {
            currActor = (*actors)[index].actorName;
            currChar = (*actors)[index].characterName;

            if (oldActor.actorName == currActor && oldActor.characterName == currChar)
            {
                exactMatch = true;
                break;
            }
        }

        //If a match is found, process the node deletion, otherwise inform the user the input is not correct
        if (exactMatch == true)
        {
            actors->DeleteNode(oldActor);
            cout << "Old Actor/Actress removed!" << endl;
        }
        else
        {
            cout << "==>Unable to remove Actor/Actress.  Make sure all fields match exactly!" << endl;
            return;
        }
        //------------------------------------------------------------------------------------------------------
    }
}

/******************************************************************
* This function combines the functionality to update an actor/actress in the
* current linkedList: actors
* It prompts the user to enter the name and character before
* searching the linked list for a match.  If match is found it is removed.
* Next, it prompts the user to update the actor/actress's fields which is essentially
* adding a new node to the list which is invisible to the user.
******************************************************************/
void DVD::UpdateActor()
{
    //Setup a check to cancel the action if no cds exist
    if (actors->CountNodes() == 0)
    {
        cout << "No actors/actresses to update!" << endl;
        return;
    }

    //Setup variables to use with removing songs
    Cast update;
    string actorInput;
    string charInput;
    int actorToUpdate;

    //Prompt the user for the number of songs to remove from the CD
    cout << "How many actors/actresses would you like to update from: " << this->GetMediaTitle() << endl;
    cout << "<Enter 0 to skip this title>" << endl;
    cout << "-> ";
    cin >> actorToUpdate;
    //cin.ignore();
    //Validate the input
    while (cin.fail() || actorToUpdate < 0)
    {
        cout << "Not a valid choice!  Please enter 0 or higher." << endl;
        cout << "->";
        cin.clear();
        cin.ignore();
        cin >> actorToUpdate;
        //cin.ignore();
    }

    //Setup a check to cancel the action if the user selects 0
    if (actorToUpdate == 0)
    {
        return;
    }

    cin.ignore();
    //Setup a loop to step through the each song from the amount entered by the user
    for (int index = 0; index < actorToUpdate; index++)
    {
        cout << "\nWhat is Actor/Actress " << index + 1 << "'s name to update? " << endl;
        cout << "-> ";
        getline(cin, actorInput);

        cout << "What is Actor/Actress " << index + 1 << "'s character name to update? " << endl;
        cout << "-> ";
        //cin.ignore();
        getline(cin, charInput);

        //Update the structure variables
        update.actorName = actorInput;
        update.characterName = charInput;

        //Validate the user's input to avoid crashing the program when deleting a node (exact matches required).
        //------------------------------------------------------------------------------------------------------
        //Setup validation variables
        string currActor;
        string currChar;
        bool exactMatch = false;

        //Use a loop to step through the collection to find a match for the user input
        for (auto index = 0; index < actors->CountNodes(); index++)
        {
            currActor = (*actors)[index].actorName;
            currChar = (*actors)[index].characterName;

            if (update.actorName == currActor && update.characterName == currChar)
            {
                exactMatch = true;
                break;
            }
        }

        //If a match is found, process the node deletion, otherwise inform the user the input is not correct
        if (exactMatch == true)
        {
            actors->DeleteNode(update);
        }
        else
        {
            cout << "==>Unable to update actor/actress.  Make sure all fields match exactly!" << endl;
            return;
        }
        //------------------------------------------------------------------------------------------------------

        //============Add the new node==================================
        //Collect the new title and length for the update
        cout << "\nWhat is the Actor/Actress " << index + 1 << "'s new name? " << endl;
        cout << "-> ";
        //cin.ignore();
        getline(cin, actorInput);

        cout << "What is the Actor/Actress " << index + 1 << "'s new character name? " << endl;
        cout << "-> ";
        //cin.ignore();
        getline(cin, charInput);

        //Update the structure variables
        update.actorName = actorInput;
        update.characterName = charInput;

        //Add the updated structure to the linked list
        actors->AppendNode(update);
        cout << "Actor/Actress Updated!" << endl;
    }
}

/******************************************************************
* This function displays all songs in the current linkedList: actors
* It is formatted to display in a table structure with actors/actresses
* per DVD.
******************************************************************/
void DVD::DisplayDVDActors()
{
    cout << "\nDVD ===========================================" << endl;
    cout << setw(5) << left << "Title: " << GetMediaTitle() << setw(15) << left << " || Length: " << GetMediaLength() << setw(15) << left << " || Release Year: " << GetReleaseYear();
    cout << "\n----------------------------------------------" << endl;
    cout << "Total Actors: " << actors->CountNodes();
    cout << "\n==============================================" << endl;
    cout << "Actors/Actresses and Characters on the DVD" << endl;
    cout << "==========================================" << endl;
    cout << "Name              || Character                 " << endl;
    cout << "-----             || ----------------          " << endl;
    actors->DisplayList();
    cout << endl;
}


//----------------------------------------------------------------
// OVERLOADED OPERATORS
//----------------------------------------------------------------

/******************************************************************
* This function overloads the << (outgoing stream) operator to
display the values from the class object's data members.
******************************************************************/
ostream& operator << (ostream& out, const Cast& actors)
{
    out << left << setw(17) << actors.actorName << " || " << left << setw(16) << actors.characterName;

    return out;
}

/******************************************************************
* This function overloads the << (outgoing stream) operator to
display the values from the class object's data members.
******************************************************************/
ostream& operator << (ostream& out, const DVD& dvd)
{
    out <<
        left << setw(17) << dvd.GetMediaTitle() << " || " << left << setw(16) << dvd.GetMediaLength() << " || " << left << setw(25) << dvd.GetReleaseYear();
    return out;
}

/******************************************************************
* This function overloads the == (equal to) operator to
compare the values from the class object's data members.
******************************************************************/
bool operator == (const Cast& lhs, const Cast& rhs)
{
    bool titleValid = false;
    bool lengthValid = false;
    bool valid = false;

    if (lhs.actorName == rhs.actorName)
    {
        titleValid = true;
    }

    if (lhs.characterName == rhs.characterName)
    {
        lengthValid = true;
    }

    if (titleValid == true && lengthValid == true)
    {
        valid = true;
    }

    return valid;
}


/******************************************************************
* This function overloads the == (equal to) operator to
compare the values from the class object's data members.
******************************************************************/
bool operator != (const Cast& lhs, const Cast& rhs)
{
    bool titleValid = false;
    bool lengthValid = false;
    bool valid = false;

    if (lhs.actorName != rhs.actorName)
    {
        titleValid = true;
    }

    if (lhs.characterName != rhs.characterName)
    {
        lengthValid = true;
    }

    if (titleValid == true && lengthValid == true)
    {
        valid = true;
    }

    return valid;
}

/******************************************************************
* This function overloads the == (equal to) operator to
compare the values from the class object's data members.
******************************************************************/
bool DVD::operator == (DVD& right) const
{
    bool titleValid = false;
    bool lengthValid = false;
    bool yearValid = false;
    bool valid = false;

    if (this->mediaTitle == right.mediaTitle)
    {
        titleValid = true;
    }

    if (this->mediaLength == right.mediaLength)
    {
        lengthValid = true;
    }

    if (this->releaseYear == right.releaseYear)
    {
        yearValid = true;
    }

    if (titleValid == true && lengthValid == true && yearValid == true)
    {
        valid = true;
    }

    return valid;
}

/******************************************************************
* This function overloads the == (equal to) operator to
compare the values from the class object's data members.
******************************************************************/
bool DVD::operator != (DVD& right) const
{
    bool titleValid = false;
    bool lengthValid = false;
    bool yearValid = false;
    bool valid = false;

    if (this->mediaTitle != right.mediaTitle)
    {
        titleValid = true;
    }

    if (this->mediaLength != right.mediaLength)
    {
        lengthValid = true;
    }

    if (this->releaseYear != right.releaseYear)
    {
        yearValid = true;
    }

    if (titleValid == true && lengthValid == true && yearValid == true)
    {
        valid = true;
    }

    return valid;
}