/*Assignment 12
Photo Gallery*/
#include <iostream>
#include <string>
using namespace std;

struct Node
{
    string photo;
    Node* prev;
    Node* next;
};

Node* head = NULL;
Node* tail = NULL;
Node* current = NULL;

// Add a new photo
void addPhoto(string name)
{
    Node* newNode = new Node;

    newNode->photo = name;

    if (head == NULL)
    {
        head = tail = newNode;
        newNode->next = head;
        newNode->prev = tail;
        current = head;
    }
    else
    {
        newNode->prev = tail;
        newNode->next = head;

        tail->next = newNode;
        head->prev = newNode;

        tail = newNode;
    }

    cout << "Photo added successfully!" << endl;
}

// Move to next photo
void nextPhoto()
{
    if (current == NULL)
    {
        cout << "Gallery is empty!" << endl;
        return;
    }

    current = current->next;

    cout << "Current Photo: "
         << current->photo << endl;
}

// Move to previous photo
void previousPhoto()
{
    if (current == NULL)
    {
        cout << "Gallery is empty!" << endl;
        return;
    }

    current = current->prev;

    cout << "Current Photo: "
         << current->photo << endl;
}

// Display all photos
void displayPhotos()
{
    if (head == NULL)
    {
        cout << "Gallery is empty!" << endl;
        return;
    }

    Node* temp = head;

    cout << "\nAvailable Photos:" << endl;

    do
    {
        cout << temp->photo << endl;
        temp = temp->next;

    } while (temp != head);
}

// Main function
int main()
{
    int choice;
    string name;

    do
    {
        cout << "\n--- PHOTO GALLERY MENU ---" << endl;
        cout << "1. Add Photo" << endl;
        cout << "2. Next Photo" << endl;
        cout << "3. Previous Photo" << endl;
        cout << "4. Display All Photos" << endl;
        cout << "5. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter photo name: ";
                getline(cin >> ws, name);
                addPhoto(name);
                break;

            case 2:
                nextPhoto();
                break;

            case 3:
                previousPhoto();
                break;

            case 4:
                displayPhotos();
                break;

            case 5:
                cout << "Exiting Photo Gallery..." << endl;
                break;

            default:
                cout << "Invalid choice!" << endl;
        }

    } while (choice != 5);

    // Free allocated memory
    if (head != NULL)
    {
        Node* temp = head->next;

        while (temp != head)
        {
            Node* nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }

        delete head;
    }

    return 0;
}

/*
SAMPLE OUTPUT:

--- PHOTO GALLERY MENU ---
1. Add Photo
2. Next Photo
3. Previous Photo
4. Display All Photos
5. Exit

Enter your choice: 1
Enter photo name: Nature
Photo added successfully!

Enter your choice: 1
Enter photo name: Family
Photo added successfully!

Enter your choice: 1
Enter photo name: Vacation
Photo added successfully!

Enter your choice: 4

Available Photos:
Nature
Family
Vacation

Enter your choice: 2
Current Photo: Family

Enter your choice: 2
Current Photo: Vacation

Enter your choice: 2
Current Photo: Nature

Enter your choice: 3
Current Photo: Vacation

Enter your choice: 4

Available Photos:
Nature
Family
Vacation

Enter your choice: 5
Exiting Photo Gallery...
*/
