#include <iostream>
#include <string>
using namespace std;

const int MAX_STUDENTS = 100;

struct Student {
    int roll;
    string name;
    int DSA;
    int OS;
    int DLD;
    int total;
    int percent;
    char grade;
};

Student db[MAX_STUDENTS];
int countStudents = 0;

void computeResult(Student &s) {
    s.total = s.DLD + s.DSA + s.OS;
    s.percent = s.total / 3;

    if (s.percent >= 80) s.grade = 'A';
    else if (s.percent >= 70) s.grade = 'B';
    else if (s.percent >= 60) s.grade = 'C';
    else if (s.percent >= 50) s.grade = 'D';
    else s.grade = 'F';
}

int findIndexByRoll(int roll) {
    for (int i = 0; i < countStudents; i++) {
        if (db[i].roll == roll) return i;
    }
    return -1;
}

void addStudent() {
    if (countStudents >= MAX_STUDENTS) {
        cout << "Database full.\n";
        return;
    }

    Student s;
    cout << "Enter Roll No: ";
    cin >> s.roll;

    if (findIndexByRoll(s.roll) != -1) {
        cout << "Roll No already exists.\n";
        return;
    }

    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, s.name);

    cout << "Enter DSA marks: ";
    cin >> s.DSA;

    cout << "Enter OS marks: ";
    cin >> s.OS;

    cout << "Enter DLD marks: ";
    cin >> s.DLD;

    computeResult(s);
    db[countStudents] = s;
    countStudents++;

    cout << "Student added.\n";
}

void showAll() {
    if (countStudents == 0) {
        cout << "No Records.\n";
        return;
    }

    cout << "\nRoll\tName\tDSA\tOS\tDLD\tTotal\t%\tGrade\n";
    cout << "----------------------------------------------------------\n";

    for (int i = 0; i < countStudents; i++) {
        cout << db[i].roll << "\t"
             << db[i].name << "\t"
             << db[i].DSA << "\t"
             << db[i].OS << "\t"
             << db[i].DLD << "\t"
             << db[i].total << "\t"
             << db[i].percent << "\t"
             << db[i].grade << "\n";
    }

    cout << "----------------------------------------------------------\n";
}

void searchStudent() {
    int roll;
    cout << "Enter Roll No: ";
    cin >> roll;

    int idx = findIndexByRoll(roll);
    if (idx == -1) {
        cout << "Not found.\n";
        return;
    }

    Student s = db[idx];

    cout << "\nRoll: " << s.roll;
    cout << "\nName: " << s.name;
    cout << "\nDSA: " << s.DSA;
    cout << "\nOS: " << s.OS;
    cout << "\nDLD: " << s.DLD;
    cout << "\nTotal: " << s.total;
    cout << "\nPercent: " << s.percent;
    cout << "\nGrade: " << s.grade << endl;
}

void updateMarks() {
    int roll;
    cout << "Enter Roll No: ";
    cin >> roll;

    int idx = findIndexByRoll(roll);
    if (idx == -1) {
        cout << "Not found.\n";
        return;
    }

    cout << "Updating marks for " << db[idx].name << endl;

    cout << "Enter New DSA marks: ";
    cin >> db[idx].DSA;

    cout << "Enter New OS marks: ";
    cin >> db[idx].OS;

    cout << "Enter New DLD marks: ";
    cin >> db[idx].DLD;

    computeResult(db[idx]);
    cout << "Updated.\n";
}

void deleteStudent() {
    int roll;
    cout << "Enter Roll No: ";
    cin >> roll;

    int idx = findIndexByRoll(roll);
    if (idx == -1) {
        cout << "Not found.\n";
        return;
    }

    for (int i = idx; i < countStudents - 1; i++) {
        db[i] = db[i + 1];
    }

    countStudents--;
    cout << "Deleted.\n";
}

void showMenu() {
    cout << "\n==============================\n";
    cout << "Student Result Management\n";
    cout << "==============================\n";
    cout << "1) Add Student\n";
    cout << "2) Show All Students\n";
    cout << "3) Search by Roll\n";
    cout << "4) Update Marks\n";
    cout << "5) Delete Student\n";
    cout << "6) Exit\n";
    cout << "Choose (1-6): ";
}

int main() {
    cout << "Student Result System (C++)\n";

    while (true) {
        showMenu();
        int choice;
        cin >> choice;

        if (choice == 1) addStudent();
        else if (choice == 2) showAll();
        else if (choice == 3) searchStudent();
        else if (choice == 4) updateMarks();
        else if (choice == 5) deleteStudent();
        else if (choice == 6) {
            cout << "Goodbye!\n";
            break;
        } else {
            cout << "Invalid option.\n";
        }
    }
    return 0;
}

