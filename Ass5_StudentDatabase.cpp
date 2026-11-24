/*Assignment 5.
Consider a student database of SEIT class (at least 15 records) and create it using Array of structures.
*/
#include <iostream>
#include <string>
using namespace std;

struct student {
    int rollNo;
    string name;
    float sgpa;
};

student s[20];
int n;

void display() {
    for (int i = 0; i < n; i++)
        cout << s[i].rollNo << " " << s[i].name 
             << " " << s[i].sgpa << endl;
}

// Bubble Sort: Roll number
void bubbleSort() {
    student t;
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (s[j].rollNo > s[j + 1].rollNo)
            {
                t = s[j];
                s[j] = s[j + 1];
                s[j + 1] = t;
            }
}

// Insertion Sort: Name
void insertionSort() {
    student key;
    for (int i = 1; i < n; i++)
    {
        key = s[i];
        int j = i - 1;

        while (j >= 0 && s[j].name > key.name)
        {
            s[j + 1] = s[j];
            j--;
        }
        s[j + 1] = key;
    }
}

// Quick Sort: SGPA in descending order
int partition(int low, int high) {
    float pivot = s[high].sgpa;
    int i = low - 1;
    student t;

    for (int j = low; j < high; j++)
        if (s[j].sgpa >= pivot)
        {
            i++;
            t = s[i];
            s[i] = s[j];
            s[j] = t;
        }

    t = s[i + 1];
    s[i + 1] = s[high];
    s[high] = t;

    return i + 1;
}

void quickSort(int low, int high) {
    if (low < high)
    {
        int p = partition(low, high);
        quickSort(low, p - 1);
        quickSort(p + 1, high);
    }
}

// Search all students having the same SGPA
void searchSGPA(float x) {
    bool found = false;

    for (int i = 0; i < n; i++)
        if (s[i].sgpa == x)
        {
            cout << s[i].rollNo << " " << s[i].name 
                 << " " << s[i].sgpa << endl;
            found = true;
        }

    if (!found)
        cout << "Student not found." << endl;
}

// Non-recursive Binary Search by name
// Assumes records are sorted alphabetically.
void binarySearch(string key) {
    int low = 0, high = n - 1, mid, pos = -1;

    while (low <= high)
    {
        mid = (low + high) / 2;

        if (s[mid].name == key)
        {
            pos = mid;
            break;
        }
        else if (s[mid].name < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    if (pos == -1)
    {
        cout << "Student not found." << endl;
        return;
    }

    // Display duplicate names on both sides
    int i = pos;
    while (i > 0 && s[i - 1].name == key)
        i--;

    while (i < n && s[i].name == key)
    {
        cout << s[i].rollNo << " " << s[i].name 
             << " " << s[i].sgpa << endl;
        i++;
    }
}

int main() {
    cout << "Enter number of students (15 to 20): ";
    cin >> n;

    if (n < 15 || n > 20)
    {
        cout << "Invalid number of students.";
        return 0;
    }

    for (int i = 0; i < n; i++)
    {
        cout << "\nEnter Roll No, Name and SGPA: ";
        cin >> s[i].rollNo >> s[i].name >> s[i].sgpa;
    }

    int choice;
    do
    {
        cout << "\n1. Roll Call List";
        cout << "\n2. Alphabetical List";
        cout << "\n3. Top 10 Toppers";
        cout << "\n4. Search by SGPA";
        cout << "\n5. Search by Name";
        cout << "\n6. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                bubbleSort();
                display();
                break;

            case 2:
                insertionSort();
                display();
                break;

            case 3:
                quickSort(0, n - 1);
                cout << "\nTop 10 Toppers:\n";
                for (int i = 0; i < n && i < 10; i++)
                    cout << s[i].rollNo << " " << s[i].name 
                         << " " << s[i].sgpa << endl;
                break;

            case 4:
            {
                float x;
                cout << "Enter SGPA: ";
                cin >> x;
                searchSGPA(x);
                break;
            }

            case 5:
            {
                string key;
                insertionSort();
                cout << "Enter name (single word): ";
                cin >> key;
                binarySearch(key);
                break;
            }

            case 6:
                cout << "Exiting...";
                break;

            default:
                cout << "Invalid choice.";
        }
    } while (choice != 6);

    return 0;
}
