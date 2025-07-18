#include <iostream>
#include <iomanip>
#include <string> // Required for getline

using namespace std;

int main() {
    int numCourses;

    cout << "Enter the number of courses: ";
    cin >> numCourses;

    // Arrays to store data
    string courseNames[100];
    double grades[100];
    int creditHours[100];

    double totalGradePoints = 0;
    int totalCredits = 0;

    for (int i = 0; i < numCourses; i++) {
        cout << "\nCourse " << i + 1 << ":\n";

        cout << "Enter course name: ";
        cin >> ws; // Clear input buffer (important before getline)
        getline(cin, courseNames[i]);

        cout << "Enter grade (on 4.0 scale): ";
        cin >> grades[i];

        cout << "Enter credit hours: ";
        cin >> creditHours[i];

        totalGradePoints += grades[i] * creditHours[i];
        totalCredits += creditHours[i];
    }

    // Calculate CGPA
    double cgpa = 0;
    if (totalCredits > 0) {
        cgpa = totalGradePoints / totalCredits;
    }

    // Display results
    cout << "\n----- Course Details -----\n";
    cout << left << setw(20) << "Course"
        << setw(10) << "Grade"
        << "Credit Hours" << endl;

    for (int i = 0; i < numCourses; i++) {
        cout << left << setw(20) << courseNames[i]
            << setw(10) << grades[i]
            << creditHours[i] << endl;
    }

    cout << fixed << setprecision(2);
    cout << "\nYour Final CGPA is: " << cgpa << endl;

    return 0;
}
