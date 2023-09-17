#include <iostream>
#include <vector>
using namespace std;

int main() {
    int num;
    cout << "Enter number of students: ";
    cin >> num;

    // Arrays for student names and years (fixed size)
    const int maxStudents = 100; // Define a maximum number of students
    string nameArray[maxStudents];
    int yearArray[maxStudents];

    // Vector to dynamically store student names and years
    vector<string> nameVector;
    vector<int> yearVector;

    cout << "\n";

    // Input student data and populate arrays and vectors
    for (int i = 1; i <= num; i++) {
        cout << i << ". Enter student name: ";
        string name;
        cin >> name;

        if (i <= maxStudents) {
            nameArray[i] = name; // Store in array if within array size
        }
        nameVector.push_back(name); // Store in vector

        cout << "\nWhat year is the student? ";
        int year;
        cin >> year;

        if (i <= maxStudents) {
            yearArray[i] = year; // Store in array if within array size
        }
        yearVector.push_back(year); // Store in vector
    }

    cout << endl;

    // Display list of students from arrays
    cout << "\nList of Students (from arrays):";
    for (int i = 1; i <= num && i <= maxStudents; i++) {
        cout << "\n Student name: " << nameArray[i] << ". Year Level: " << yearArray[i];
    }

    cout << endl;

    // Display list of students from vectors
    cout << "\nList of Students (from vectors):";
    for (int i = 0; i < num; i++) {
        cout << "\n Student name: " << nameVector[i] << ". Year Level: " << yearVector[i];
    }

    cout << endl;
    return 0;
}

