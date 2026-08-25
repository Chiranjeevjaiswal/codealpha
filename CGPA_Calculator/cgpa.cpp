#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;

    cout << "==============================" << endl;
    cout << "       CGPA CALCULATOR" << endl;
    cout << "==============================" << endl;

    // Number of courses
    cout << "\nEnter number of courses: ";
    cin >> n;

    string courseName[20];
    char grade[20];
    float credit[20];
    float gradePoint[20];

    float totalCredits = 0;
    float totalGradePoints = 0;

    // Input course details
    for (int i = 0; i < n; i++)
    {
        cout << "\nEnter Course " << i + 1 << " Name: ";
        cin >> courseName[i];

        cout << "Enter Grade (A/B/C/D/F): ";
        cin >> grade[i];

        cout << "Enter Credit Hours: ";
        cin >> credit[i];

        // Convert grade into grade point
        if (grade[i] == 'A' || grade[i] == 'a')
        {
            gradePoint[i] = 10;
        }
        else if (grade[i] == 'B' || grade[i] == 'b')
        {
            gradePoint[i] = 8;
        }
        else if (grade[i] == 'C' || grade[i] == 'c')
        {
            gradePoint[i] = 6;
        }
        else if (grade[i] == 'D' || grade[i] == 'd')
        {
            gradePoint[i] = 5;
        }
        else if (grade[i] == 'F' || grade[i] == 'f')
        {
            gradePoint[i] = 0;
        }
        else
        {
            cout << "Invalid Grade!" << endl;
            gradePoint[i] = 0;
        }

        // Calculate grade points
        totalCredits = totalCredits + credit[i];

        totalGradePoints =
            totalGradePoints +
            (gradePoint[i] * credit[i]);
    }

    // Calculate GPA
    float GPA = totalGradePoints / totalCredits;

    // Display course details
    cout << "\n\n========================================" << endl;
    cout << "          COURSE DETAILS" << endl;
    cout << "========================================" << endl;

    cout << "Course\tGrade\tCredits\tGrade Point" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << courseName[i] << "\t"
             << grade[i] << "\t"
             << credit[i] << "\t"
             << gradePoint[i] << endl;
    }

    // Display result
    cout << "\n========================================" << endl;
    cout << "Total Credits: " << totalCredits << endl;
    cout << "Total Grade Points: "
         << totalGradePoints << endl;

    cout << "Semester GPA: " << GPA << endl;

    // For one semester
    cout << "Overall CGPA: " << GPA << endl;

    cout << "========================================" << endl;

    return 0;
}
