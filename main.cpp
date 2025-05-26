// changes by chinmai

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Patient {
public:
    int id;
    string name;
    int age;
    string diagnosis;
    string treatment;

    void display() const {
        cout << "Patient ID: " << id << ", Name: " << name << ", Age: " << age << "\nDiagnosis: " << diagnosis << "\nTreatment: " << treatment << "\n";
    }
};

vector<Patient> patients;

// --- Chinami's contribution: Patient Age Validation ---

bool isValidAge(int age) {
    return age > 0 && age < 120;
}

void addPatient() {
    Patient p;
    cout << "Enter patient ID: ";
    cin >> p.id;
    cin.ignore();

    cout << "Enter patient name: ";
    getline(cin, p.name);

    // Age input with validation loop
    while (true) {
        cout << "Enter patient age: ";
        cin >> p.age;
        if (isValidAge(p.age)) break;
        cout << "Invalid age entered. Please enter age between 1 and 119.\n";
    }
    cin.ignore();

    cout << "Enter diagnosis: ";
    getline(cin, p.diagnosis);

    cout << "Enter treatment: ";
    getline(cin, p.treatment);

    patients.push_back(p);
    cout << "Patient added successfully.\n";
}

void displayPatients() {
    cout << "\nList of Patients:\n";
    for (const auto& p : patients) {
        p.display();
    }
}

void mainMenu() {
    int choice;
    while (true) {
        cout << "\nHospital Management System Menu:\n";
        cout << "1. Add Patient\n";
        cout << "2. Display Patients\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: addPatient(); break;
            case 2: displayPatients(); break;
            case 3: cout << "Exiting...\n"; return;
            default: cout << "Invalid choice, try again.\n"; break;
        }
    }
}

int main() {
    cout << "Welcome to Hospital Management System\n";
    mainMenu();
    return 0;
}
