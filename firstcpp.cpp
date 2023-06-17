#include <iostream>
using namespace std;

class Calculator {
public:
    void calculateSGPA();
    void calculateCGPA();
    void instructions();
};

void Calculator::calculateSGPA() {
    double SGPA;
    int NoOfSubs;
    double total = 0;
    double totalpoints = 0;
    double totalCredits = 0;
    cout << "------------------------------------------------" << endl;
    cout << "|                SGPA Calculator                |" << endl;
    cout << "------------------------------------------------" << endl;
    cout << "Enter No of Subjects: ";
    cin >> NoOfSubs;
    cout << endl;
    double* credits = new double[NoOfSubs];
    double* points = new double[NoOfSubs];
    for (int i = 1; i <= NoOfSubs; i++) {
        cout << "Enter Credits of subjects " << i << ": ";
        cin >> credits[i - 1];
        cout << "Enter Obtained Points of Subjects by grade " << i << ": ";
        cin >> points[i - 1];
        cout << "------------------------------------------------" << endl;
    }
    for (int i = 1; i <= NoOfSubs; i++) {
        total = 0;
        total = credits[i - 1] * points[i - 1];
        //total Obtained points of all subjects
        totalpoints += total;
    }
    for (int i = 1; i <= NoOfSubs; i++) {
        //total credits of all subjects
        totalCredits += credits[i - 1];
    }
    cout << endl << endl;
    cout << "Total Points: " << totalpoints << endl;
    cout << "Total Credits: " << totalCredits << endl;
    cout << "Total SGPA: " << totalpoints / totalCredits << endl;

    delete[] credits;
    delete[] points;
}

void Calculator::calculateCGPA() {
    int NoOfSems;
    cout << "------------------------------------------------" << endl;
    cout << "|               CGPA Calculator                |" << endl;
    cout << "------------------------------------------------" << endl;
    cout << "Enter No of Semesters: ";
    cin >> NoOfSems;
    double* semesters = new double[NoOfSems];
    double semTotal = 0;
    for (int i = 1; i <= NoOfSems; i++) {
        cout << "Enter Semester #" << i << " GPA: ";
        cin >> semesters[i];
    }
    for (int i = 1; i <= NoOfSems; i++) {
        // semTotal- Total SGPA of all semesters
        semTotal += semesters[i];
    }
    cout << "Your CGPA: " << semTotal / NoOfSems << endl;

    delete[] semesters;
}

void Calculator::instructions() {
    cout << endl << endl;
    cout << "How to Calculate GPA and CGPA :" << endl;
    cout << "-------------------------------" << endl << endl;
    cout << "GPA = sum of (credit*point) / total of credits " << endl;
    cout << "CGPA = sum of all semesters GPA / number of semesters " << endl;
    cout << endl << endl;
    cout << "Grade - Point Table : " << endl;
    cout << "------------------------------------------------" << endl;
    cout << "\tGrade\t 9.0 Scale" << endl;
    cout << "------------------------------------------------" << endl;
    cout << "\tA+ \t\t 9 " << endl;
    cout << "\tA  \t\t 8 " << endl;
    cout << "\tA- \t\t 7 " << endl;
    cout << "\tB+ \t\t 6 " << endl;
    cout << "\tB  \t\t 5 " << endl;
    cout << "\tB- \t\t 4 " << endl;
    cout << "\tC+ \t\t 3 " << endl;
    cout << "\tC  \t\t 2 " << endl;
    cout << "\tC- \t\t 1 " << endl;
    cout << "\tF  \t\t 0 " << endl;

    }
    
    int main() {
    Calculator calculator;

    do {
        cout << "------------------------------------------------" << endl;
        cout << "|                GPA Calculator                |" << endl;
        cout << "------------------------------------------------" << endl;
        cout << "1. Calculate SGPA" << endl;
        cout << "2. Calculate CGPA" << endl;
        cout << "3. How to Calculate GPA?" << endl;
        cout << "4. Quit" << endl << endl;
        cout << "Select Option: ";

        char op;
        cin >> op;

        if (op == '1')
            calculator.calculateSGPA();
        else if (op == '2')
            calculator.calculateCGPA();
        else if (op == '3')
            calculator.instructions();
        else if (op == '4')
            exit(0);

    } while (true);

    return 0;
}
