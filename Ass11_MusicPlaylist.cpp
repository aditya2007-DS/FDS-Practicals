/*Assignment 11.
Music Playlist*/
#include <iostream>
#include <string>
using namespace std;

struct Node
{
    string song;
    Node* next;
};

Node* head = NULL;

// Add a new song
void addSong(string name)
{
    Node* newNode = new Node;
    newNode->song = name;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        Node* temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    cout << "Song added successfully!\n";
}

// Display all songs
void display()
{
    if (head == NULL)
    {
        cout << "Playlist is empty!\n";
        return;
    }

    Node* temp = head;

    cout << "\nMusic Playlist:\n";

    while (temp != NULL)
    {
        cout << temp->song << endl;
        temp = temp->next;
    }
}

// Search for a song
void searchSong(string name)
{
    Node* temp = head;

    while (temp != NULL)
    {
        if (temp->song == name)
        {
            cout << "Song found!\n";
            return;
        }

        temp = temp->next;
    }

    cout << "Song not found!\n";
}

// Delete a song
void deleteSong(string name)
{
    Node* temp = head;
    Node* prev = NULL;

    while (temp != NULL && temp->song != name)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        cout << "Song not found!\n";
        return;
    }

    if (prev == NULL)
    {
        head = temp->next;
    }
    else
    {
        prev->next = temp->next;
    }

    delete temp;
    cout << "Song deleted successfully!\n";
}

// Reverse the playlist
void reversePlaylist()
{
    Node* prev = NULL;
    Node* current = head;
    Node* nextNode = NULL;

    while (current != NULL)
    {
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }

    head = prev;

    cout << "Playlist reversed successfully!\n";
}

int main()
{
    int choice;
    string name;

    do
    {
        cout << "\n--- MUSIC PLAYER MENU ---\n";
        cout << "1. Add Song\n";
        cout << "2. Delete Song\n";
        cout << "3. Search Song\n";
        cout << "4. Reverse Playlist\n";
        cout << "5. Display Playlist\n";
        cout << "6. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter song name: ";
                getline(cin >> ws, name);
                addSong(name);
                break;

            case 2:
                cout << "Enter song name to delete: ";
                getline(cin >> ws, name);
                deleteSong(name);
                break;

            case 3:
                cout << "Enter song name to search: ";
                getline(cin >> ws, name);
                searchSong(name);
                break;

            case 4:
                reversePlaylist();
                break;

            case 5:
                display();
                break;

            case 6:
                cout << "Exiting Music Player...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 6);

    // Free remaining memory
    while (head != NULL)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
/*  --- MUSIC PLAYER MENU ---
1. Add Song
2. Delete Song
3. Search Song
4. Reverse Playlist
5. Display Playlist
6. Exit

Enter your choice: 1
Enter song name: Believer
Song added successfully!

Enter your choice: 1
Enter song name: Shape of You
Song added successfully!

Enter your choice: 1
Enter song name: Perfect
Song added successfully!

Enter your choice: 5

Music Playlist:
Believer
Shape of You
Perfect

Enter your choice: 3
Enter song name to search: Perfect
Song found!

Enter your choice: 2
Enter song name to delete: Shape of You
Song deleted successfully!

Enter your choice: 5

Music Playlist:
Believer
Perfect

Enter your choice: 4
Playlist reversed successfully!

Enter your choice: 5

Music Playlist:
Perfect
Believer

Enter your choice: 6
Exiting Music Player...
*/
