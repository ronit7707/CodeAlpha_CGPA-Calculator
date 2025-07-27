#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;

// Function to convert letter grade to grade point
float gradeToPoint(string grade) {
    if (grade == "A+" || grade == "a+") return 10.0;
    if (grade == "A"  || grade == "a")  return 9.0;
    if (grade == "B+" || grade == "b+") return 8.0;
    if (grade == "B"  || grade == "b")  return 7.0;
    if (grade == "C+" || grade == "c+") return 6.0;
    if (grade == "C"  || grade == "c")  return 5.0;
    if (grade == "D"  || grade == "d")  return 4.0;
    return 0.0; // Fail or invalid
}

int main() {
    int numCourses;
    cout << "Enter number of Subjects: ";
    cin >> numCourses;

    vector<string> grades(numCourses);
    vector<int> credits(numCourses);

    float totalGradePoints = 0;
    int totalCredits = 0;

    // Input course details
    for (int i = 0; i < numCourses; i++) {
        cout << "\nCourse " << i + 1 << ":\n";

        cout << "Enter grade (A+, A, B+, B, C+, C, D, F): ";
        cin >> grades[i];

        cout << "Enter credit hours: ";
        cin >> credits[i];

        float gradePoint = gradeToPoint(grades[i]);
        totalGradePoints += gradePoint * credits[i];
        totalCredits += credits[i];
    }

    // GPA calculation
    float semesterGPA = totalGradePoints / totalCredits;

    // Optional: calculate overall CGPA
    float prevCGPA = 0;
    int prevCredits = 0;
    char hasPrevious;
    cout << "\nDo you want to enter previous CGPA and credits? (y/n): ";
    cin >> hasPrevious;

    if (hasPrevious == 'y' || hasPrevious == 'Y') {
        cout << "Enter previous CGPA: ";
        cin >> prevCGPA;
        cout << "Enter total previous credits: ";
        cin >> prevCredits;

        semesterGPA = totalGradePoints / totalCredits;
        float totalCombinedPoints = prevCGPA * prevCredits + semesterGPA * totalCredits;
        int totalCombinedCredits = prevCredits + totalCredits;

        float overallCGPA = totalCombinedPoints / totalCombinedCredits;

        cout << fixed << setprecision(2);
        cout << "\n-----------------------------\n";
        cout << "Course Details:\n";
        for (int i = 0; i < numCourses; i++) {
            cout << "Course " << i + 1 << ": Grade " << grades[i] << ", Credit " << credits[i] << endl;
        }
        cout << "Semester GPA: " << semesterGPA << endl;
        cout << "Overall CGPA: " << overallCGPA << endl;
    } else {
        cout << fixed << setprecision(2);
        cout << "\n-----------------------------\n";
        cout << "Course Details:\n";
        for (int i = 0; i < numCourses; i++) {
            cout << "Course " << i + 1 << ": Grade " << grades[i] << ", Credit " << credits[i] << endl;
        }
        cout << "Semester GPA: " << semesterGPA << endl;
    }

    return 0;
}
