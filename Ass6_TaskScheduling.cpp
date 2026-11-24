/* Assignment 6
	Design and Implement a Queue Using Arrays
	for a Task Scheduling System
*/
#include <iostream>
#include <string>
using namespace std;

class Queue {
    string tasks[5];
    int front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    void enqueue(string task) {
        if (rear == 4) {
            cout << "Queue is full!" << endl;
            return;
        }

        if (front == -1)
            front = 0;

        tasks[++rear] = task;
        cout << "Task added: " << task << endl;
    }

    void dequeue() {
        if (front == -1) {
            cout << "Queue is empty!" << endl;
            return;
        }

        cout << "Task processed: "
             << tasks[front] << endl;

        if (front == rear) {
            front = rear = -1;
        } else {
            front++;
        }
    }

    void display() {
        if (front == -1) {
            cout << "No pending tasks." << endl;
            return;
        }

        cout << "Pending tasks: ";

        for (int i = front; i <= rear; i++) {
            cout << tasks[i] << " ";
        }

        cout << endl;
    }
};

int main() {
    Queue q;
    int choice;
    string task;

    do {
        cout << "\n1. Add Task";
        cout << "\n2. Process Task";
        cout << "\n3. Display Tasks";
        cout << "\n4. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter task name: ";
                cin >> task;
                q.enqueue(task);
                break;

            case 2:
                q.dequeue();
                break;

            case 3:
                q.display();
                break;

            case 4:
                cout << "Exiting program." << endl;
                break;

            default:
                cout << "Invalid choice!" << endl;
        }

    } while (choice != 4);

    return 0;
}

/*
Sample Output:

1. Add Task
2. Process Task
3. Display Tasks
4. Exit
Enter choice: 1
Enter task name: PrintJob1
Task added: PrintJob1

1. Add Task
2. Process Task
3. Display Tasks
4. Exit
Enter choice: 1
Enter task name: PrintJob2
Task added: PrintJob2

1. Add Task
2. Process Task
3. Display Tasks
4. Exit
Enter choice: 3
Pending tasks: PrintJob1 PrintJob2

1. Add Task
2. Process Task
3. Display Tasks
4. Exit
Enter choice: 2
Task processed: PrintJob1

1. Add Task
2. Process Task
3. Display Tasks
4. Exit
Enter choice: 3
Pending tasks: PrintJob2

1. Add Task
2. Process Task
3. Display Tasks
4. Exit
Enter choice: 4
Exiting program.
*/
