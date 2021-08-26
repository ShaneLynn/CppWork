/***************************************************************************************************************************
*Author: Christopher S Lynn
 CISS 243 -  Programming III
*Programming Assignment 8 - Course Project
 Created: 8/12/2021

 ----------------------------------------------------------------------------------------------------------------------------

 Description:
 This file describes the methods listed in the header file: CD.h

***************************************************************************************************************************/

#include "CD.h"

//----------------------------------------------------------------
// CONSTRUCTORS
//----------------------------------------------------------------

/*************************************
* Default constructor
**************************************/
CD::CD() : Media()
{
    artistName = "";
}

/******************************************************************
* Parameter constructor that accepts the title, length, and artist
* of the CD.
******************************************************************/
CD::CD(string cdTitle, int cdLength, string aName) : Media(cdTitle, cdLength)
{
    artistName = aName;
}

//----------------------------------------------------------------
// ACCESSORS AND MUTATORS = GETTERS AND SETTERS
//----------------------------------------------------------------

/******************************************************************
* This function gets the value stored in the data member: artistName
******************************************************************/
string CD::GetArtistName() const
{
    return artistName;
}

/******************************************************************
* This function sets the value stored in the data member: artistName
******************************************************************/
void CD::SetArtistName(string aName)
{
    artistName = aName;
}

/******************************************************************
* This function gets the value stored in the structure data member: songTitle
******************************************************************/
string CD::GetCurrSongTitle() const
{
    return song.songTitle;
}

/******************************************************************
* This function gets the value stored in the structure data member: songLength
******************************************************************/
int CD::GetCurrSongLen() const 
{
    return song.songLength;
}


/******************************************************************
* This function sets the value stored in the structure data member: song
******************************************************************/
void CD::SetCurrSong(string title, int length)
{
    song.songTitle = title;
    song.songLength = length;
}



//----------------------------------------------------------------
// ACTION FUNCTIONS
//----------------------------------------------------------------

/******************************************************************
* This function adds a new song to the current linkedList: songs
* It prompts the user to enter the title and length before
* appending it to the linked list.  It also asks the user how many
* songs to add to the CD so they can enter more than 1 at a time.
******************************************************************/
void CD::AddNewSong()
{
    //Setup variables to use with adding songs
    Song newSong;
    string songInput;
    int songLenInput;
    int songsToAdd;
    
    //Prompt the user for the number of songs to add to the CD
    cout << "How many new songs would you like to add to: " << this->GetMediaTitle() << endl;
    cout << "<Enter 0 to skip this title>" << endl;
    cout << "-> ";
    cin >> songsToAdd;
    //cin.ignore();
    //Validate the input
    while (cin.fail() || songsToAdd < 0)
    {
        cout << "Not a valid choice!  Please enter 0 or higher." << endl;
        cout << "->";
        cin.clear();
        cin.ignore();
        cin >> songsToAdd;
        //cin.ignore();
    }

    //Setup a check to cancel the action if the user selects 0
    if (songsToAdd == 0)
    {
        return;
    }

    //Setup a loop to step through the each song from the amount entered by the user
    for (int index = 0; index < songsToAdd; index++)
    {
        cout << "\nWhat is song " << index+1 << "'s title to add? " << endl;
        cout << "-> ";
        cin.ignore();
        getline(cin, songInput);
        
        cout << "What is song " << index + 1 << "'s length in minutes?" << endl;
        cout << "-> ";
        cin >> songLenInput;
        //cin.ignore();
        //Validate the input
        while (cin.fail() || songLenInput < 0)
        {
            cout << "Not a valid choice!  Please enter 0 or higher minutes." << endl;
            cout << "->";
            cin.clear();
            cin.ignore();
            cin >> songLenInput;
            //cin.ignore();
        }

        //Update the structure variables
        newSong.songTitle = songInput;
        newSong.songLength = songLenInput;

        //Add the structure to the list
        songs->AppendNode(newSong);
        cout << "New Song Added!" << endl;
    }
}

/******************************************************************
* This function removes a current from the current linkedList: songs
* It prompts the user to enter the title and length before
* searching the linked list for a match.  If match is found it is removed.
******************************************************************/
void CD::RemoveSong()
{
    //Setup a check to cancel the action if no cds exist
    if (songs->CountNodes() == 0)
    {
        cout << "No songs to remove!" << endl;
        return;
    }
    
    //Setup variables to use with removing songs
    Song oldSong;
    string songInput;
    int songLenInput;
    int songsToRemove;

    //Prompt the user for the number of songs to remove from the CD
    cout << "How many songs would you like to remove from: " << this->GetMediaTitle() << endl;
    cout << "<Enter 0 to skip this title>" << endl;
    cout << "-> ";
    cin >> songsToRemove;
    //cin.ignore();
    //Validate the input
    while (cin.fail() || songsToRemove < 0)
    {
        cout << "Not a valid choice!  Please enter 0 or higher." << endl;
        cout << "->";
        cin.clear();
        cin.ignore();
        cin >> songsToRemove;
        //cin.ignore();
    }

    //Setup a check to cancel the action if the user selects 0
    if (songsToRemove == 0)
    {
        return;
    }

    //Setup a loop to step through the each song from the amount entered by the user
    for (int index = 0; index < songsToRemove; index++)
    {
        //Prompt the user for the title, and length the old song
        cout << "\nWhat is song " << index + 1 << "'s title to remove? " << endl;
        cout << "-> ";
        cin.ignore();
        getline(cin, songInput);

        cout << "What is song " << index + 1 << "'s length in minutes?" << endl;
        cout << "-> ";
        cin >> songLenInput;
       // cin.ignore();
        //Validate the input
        while (cin.fail() || songLenInput < 0)
        {
            cout << "Not a valid choice!  Please enter 0 or higher minutes." << endl;
            cout << "->";
            cin.clear();
            cin.ignore();
            cin >> songLenInput;
            //cin.ignore();

        }
        //Update the structure variables
        oldSong.songTitle = songInput;
        oldSong.songLength = songLenInput;

        //Validate the user's input to avoid crashing the program when deleting a node (exact matches required).
        //------------------------------------------------------------------------------------------------------
        //Setup validation variables
        string currTitle;
        int currLength;
        bool exactMatch = false;

        //Use a loop to step through the collection to find a match for the user input
        for (auto index = 0; index < songs->CountNodes(); index++)
        {
            currTitle = (*songs)[index].songTitle;
            currLength = (*songs)[index].songLength;
            
            if (oldSong.songTitle == currTitle && oldSong.songLength == currLength)
            {
                exactMatch = true;
                break;
            }
        }

        //If a match is found, process the node deletion, otherwise inform the user the input is not correct
        if (exactMatch == true)
        {
            songs->DeleteNode(oldSong);
            cout << "Old song removed!" << endl;
        }
        else
        {
            cout << "==>Unable to remove song.  Make sure all fields match exactly!" << endl;
            return;
        }
        //------------------------------------------------------------------------------------------------------
    }
}

/******************************************************************
* This function combines the functionality to update a song in the
* current linkedList: songs
* It prompts the user to enter the title, and length before
* searching the linked list for a match.  If match is found it is removed.
* Next, it prompts the user to update the songs's fields which is essentially
* adding a new node to the list which is invisible to the user.
******************************************************************/
void CD::UpdateSong()
{
    //Setup a check to cancel the action if no cds exist
    if (songs->CountNodes() == 0)
    {
        cout << "No songs to update!" << endl;
        return;
    }
    
    //Setup variables to use with removing songs
    Song update;
    string songInput;
    int songLenInput;
    int songsToUpdate;

    //Prompt the user for the number of songs to remove from the CD
    cout << "How many songs would you like to update from: " << this->GetMediaTitle() << endl;
    cout << "<Enter 0 to skip this title>" << endl;
    cout << "-> ";
    cin >> songsToUpdate;
    //cin.ignore();
    //Validate the input
    while (cin.fail() || songsToUpdate < 0)
    {
        cout << "Not a valid choice!  Please enter 0 or higher." << endl;
        cout << "->";
        cin.clear();
        cin.ignore();
        cin >> songsToUpdate;
        //cin.ignore();
    }

    //Setup a check to cancel the action if the user selects 0
    if (songsToUpdate == 0)
    {
        return;
    }

    //Setup a loop to step through the each song from the amount entered by the user
    for (int index = 0; index < songsToUpdate; index++)
    {
        cout << "\nWhat is song " << index + 1 << "'s title to update? " << endl;
        cout << "-> ";
        cin.ignore();
        getline(cin, songInput);

        cout << "What is song " << index + 1 << "'s length in minutes?" << endl;
        cout << "-> ";
        cin >> songLenInput;
        //cin.ignore();
        //Validate the input
        while (cin.fail() || songLenInput < 0)
        {
            cout << "Not a valid choice!  Please enter 0 or higher minutes." << endl;
            cout << "->";
            cin.clear();
            cin.ignore();
            cin >> songLenInput;
            //cin.ignore();
        }
        //Update the structure variables
        update.songTitle = songInput;
        update.songLength = songLenInput;

        //Validate the user's input to avoid crashing the program when deleting a node (exact matches required).
        //------------------------------------------------------------------------------------------------------
        //Setup validation variables
        string currTitle;
        int currLength;
        bool exactMatch = false;

        //Use a loop to step through the collection to find a match for the user input
        for (auto index = 0; index < songs->CountNodes(); index++)
        {
            currTitle = (*songs)[index].songTitle;
            currLength = (*songs)[index].songLength;

            if (update.songTitle == currTitle && update.songLength == currLength)
            {
                exactMatch = true;
                break;
            }
        }

        //If a match is found, process the node deletion, otherwise inform the user the input is not correct
        if (exactMatch == true)
        {
            songs->DeleteNode(update);
        }
        else
        {
            cout << "==>Unable to update song.  Make sure all fields match exactly!" << endl;
            return;
        }
        //------------------------------------------------------------------------------------------------------

        //============Add the new node==================================
        //Collect the new title and length for the update
        cout << "\nWhat is song " << index + 1 << "'s new title? " << endl;
        cout << "-> ";
        cin.ignore();
        getline(cin, songInput);

        cout << "What is song " << index + 1 << "'s new length in minutes?" << endl;
        cout << "-> ";
        cin >> songLenInput;
        //cin.ignore();
        //Validate the input
        while (cin.fail() || songLenInput < 0)
        {
            cout << "Not a valid choice!  Please enter 0 or higher minutes." << endl;
            cout << "->";
            cin.clear();
            cin.ignore();
            cin >> songLenInput;
        }
        
        //Update the structure variables
        update.songTitle = songInput;
        update.songLength = songLenInput;

        //Add the updated structure to the linked list
        songs->AppendNode(update);
        cout << "Song Updated!" << endl;
    }
}

/******************************************************************
* This function displays all songs in the current linkedList: songs
* It is formatted to display in a table structure with songs per CD.
******************************************************************/
void CD::DisplayCDSongs()
{
    cout << "\nCD ===========================================" << endl;
    cout << setw(5) << left << "Title: " << GetMediaTitle() << setw(15) << left << " || Length: " << GetMediaLength() << setw(15) << left << " || Artist: " << GetArtistName();
    cout << "\n----------------------------------------------" << endl;
    cout << "Total Tracks: " << songs->CountNodes();
    cout << "\n==============================================" << endl;
    cout << "Songs On the CD" << endl;
    cout << "===============" << endl;
    cout << "Title             || Length (minutes)         " << endl;
    cout << "-----                ----------------         " << endl;
    songs->DisplayList();
    cout << endl;
}


//----------------------------------------------------------------
// OVERLOADED OPERATORS
//----------------------------------------------------------------

/******************************************************************
* This function overloads the << (outgoing stream) operator to
display the values from the class object's data members.
******************************************************************/
ostream& operator << (ostream& out, const Song& songs)
{
    out << left << setw(17) << songs.songTitle << " || " << left << setw(16) << songs.songLength; 
    
    return out;
}

/******************************************************************
* This function overloads the << (outgoing stream) operator to
display the values from the class object's data members.
******************************************************************/
ostream& operator << (ostream& out, const CD& cd)
{
    out << 
          left << setw(17) << cd.GetMediaTitle() << " || " << left << setw(16) << cd.GetMediaLength() << " || " << left << setw(25) << cd.GetArtistName();
    return out;
}

/******************************************************************
* This function overloads the == (equal to) operator to
compare the values from the class object's data members.
******************************************************************/
bool operator == (const Song& lhs, const Song& rhs)
{
    bool titleValid = false;
    bool lengthValid = false;
    bool valid = false;

    if (lhs.songTitle == rhs.songTitle)
    {
        titleValid = true;
    }

    if (lhs.songLength == rhs.songLength)
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
bool operator != (const Song& lhs, const Song& rhs)
{
    bool titleValid = false;
    bool lengthValid = false;
    bool valid = false;

    if (lhs.songTitle != rhs.songTitle)
    {
        titleValid = true;
    }

    if (lhs.songLength != rhs.songLength)
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
bool CD::operator == (CD& right) const
{
    bool titleValid = false;
    bool lengthValid = false;
    bool artistValid = false;
    bool valid = false;
    
    if (this->mediaTitle == right.mediaTitle)
    {
        titleValid = true;
    }

    if (this->mediaLength == right.mediaLength)
    {
        lengthValid = true;
    }

    if (this->artistName == right.artistName)
    {
        artistValid = true;
    }

    if (titleValid == true && lengthValid == true && artistValid == true)
    {
        valid = true;
    }

    return valid;
}

/******************************************************************
* This function overloads the == (equal to) operator to
compare the values from the class object's data members.
******************************************************************/
bool CD::operator != (CD& right) const
{
    bool titleValid = false;
    bool lengthValid = false;
    bool artistValid = false;
    bool valid = false;

    if (this->mediaTitle != right.mediaTitle)
    {
        titleValid = true;
    }

    if (this->mediaLength != right.mediaLength)
    {
        lengthValid = true;
    }

    if (this->artistName != right.artistName)
    {
        artistValid = true;
    }

    if (titleValid == true && lengthValid == true && artistValid == true)
    {
        valid = true;
    }

    return valid;
}