/* Assignment 7.
Design and Implement a Stack Using Linked Lists
for Undo/Redo Functionality
*/
#include <iostream>
#include <string>
using namespace std;

struct Node {
    string data;
    Node* next;
};

class Stack {
    Node* top;

public:
    Stack() {
        top = NULL;
    }

    bool isEmpty() {
        return top == NULL;
    }

    void push(string value) {
        Node* newNode = new Node;

        newNode->data = value;
        newNode->next = top;
        top = newNode;
    }

    string pop() {
        if (isEmpty())
            return "";

        Node* temp = top;
        string value = temp->data;

        top = top->next;
        delete temp;

        return value;
    }

    void clear() {
        while (!isEmpty())
            pop();
    }
};

int main() {
    Stack undoStack, redoStack;
    string text = "", word;
    int choice;

    do {
        cout << "\n1. Perform Action";
        cout << "\n2. Undo";
        cout << "\n3. Redo";
        cout << "\n4. Display Text";
        cout << "\n5. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter word to add: ";
                cin >> word;

                text += word + " ";

                undoStack.push(word);
                redoStack.clear();

                cout << "Action performed.\n";
                break;

            case 2:
                if (undoStack.isEmpty()) {
                    cout << "Nothing to undo.\n";
                } else {
                    word = undoStack.pop();

                    // Remove the last word from text
                    text.erase(text.size() - word.size() - 1);

                    redoStack.push(word);

                    cout << "Undo successful.\n";
                }
                break;

            case 3:
                if (redoStack.isEmpty()) {
                    cout << "Nothing to redo.\n";
                } else {
                    word = redoStack.pop();

                    text += word + " ";
                    undoStack.push(word);

                    cout << "Redo successful.\n";
                }
                break;

            case 4:
                cout << "Current Text: " << text << endl;
                break;

            case 5:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 5);

    return 0;
}

/*
Sample Output:

1. Perform Action
2. Undo
3. Redo
4. Display Text
5. Exit
Enter choice: 1
Enter word to add: Hello
Action performed.

Enter choice: 1
Enter word to add: World
Action performed.

Enter choice: 4
Current Text: Hello World

Enter choice: 2
Undo successful.

Enter choice: 4
Current Text: Hello

Enter choice: 3
Redo successful.

Enter choice: 4
Current Text: Hello World

Enter choice: 5
Exiting program.
*/
