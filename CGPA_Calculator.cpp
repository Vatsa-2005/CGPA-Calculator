#include <iostream>
#include <iomanip>
using namespace std;

double gradeToPoint(char grade) {
    switch (toupper(grade)) {
        case 'S': return 10.0;
        case 'A': return 8.0;
        case 'B': return 6.0;
        case 'C': return 4.0;
        case 'D': return 2.0;
        case 'E': return 1.0;
        case 'F': return 0.0;
        default:  return 0.0;
    }
}

int main() {
    int semesters;
    cout << "Enter number of semesters: ";
    cin >> semesters;

    const int MAX = 20; // To keep it simple, assume max 20 courses in total per semester
    int semOfCourse[MAX], idxInSem[MAX], credits[MAX];
    char grades[MAX];
    double gradePointsCourse[MAX];

    int courseCount = 0;

    double overallGradePoints = 0.0;
    int overallCredits = 0;

    cout << fixed << setprecision(2);

    for (int sem = 1; sem <= semesters; ++sem) {
        int n;
        cout << "\nSemester " << sem << ":\n";
        cout << "Enter number of courses: ";
        cin >> n;

        double semGradePoints = 0.0;
        int semCredits = 0;

        cout << "Enter course details (Grade Letter and Credit Hours):\n";
        for (int i = 1; i <= n; ++i) {
            char grade;
            int credit;

            cout << "Course " << i << " grade (S/A/B/C/D/E/F): ";
            cin >> grade;
            cout << "Course " << i << " credit hours: ";
            cin >> credit;

            double gp = gradeToPoint(grade);
            double gpCourse = gp * credit;

            semOfCourse[courseCount] = sem;
            idxInSem[courseCount]    = i;
            grades[courseCount]      = grade;
            credits[courseCount]     = credit;
            gradePointsCourse[courseCount] = gpCourse;
            courseCount++;

            semGradePoints += gpCourse;
            semCredits += credit;
        }

        double semGPA = (semCredits > 0) ? (semGradePoints / semCredits) : 0.0;
        cout << "Semester " << sem << " GPA: " << semGPA << "\n";

        overallGradePoints += semGradePoints;
        overallCredits += semCredits;
    }

    double cgpa = (overallCredits > 0) ? (overallGradePoints / overallCredits) : 0.0;

    cout << "\n================ RESULT ================\n";

    for (int sem = 1; sem <= semesters; ++sem) {
        cout << "\nSemester " << sem << " Courses:\n";
        cout << "Course  Grade  Credits  GradePoints\n";
        for (int i = 0; i < courseCount; ++i) {
            if (semOfCourse[i] == sem) {
                cout << "  " << idxInSem[i]
                     << "      " << grades[i]
                     << "       " << credits[i]
                     << "        " << gradePointsCourse[i] << "\n";
            }
        }
    }

    cout << "\nTotal Credits (all courses): " << overallCredits << "\n";
    cout << "Total Grade Points (all courses): " << overallGradePoints << "\n";
    cout << "Overall CGPA: " << cgpa << "\n";
    cout << "=======================================\n";

    return 0;
}
