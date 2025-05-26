//changes by prajwal
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

class Doctor {
public:
    int id;
    string name;
    string specialization;

    void display() const {
        cout << "Doctor ID: " << id << ", Name: " << name << ", Specialization: " << specialization << "\n";
    }
};

vector<Patient> patients;
vector<Doctor> doctors;

// --- Chinami's Patient Age Validation ---

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

// --- Suhas's contribution: Search doctor by specialization ---

void addDoctor() {
    Doctor d;
    cout << "Enter doctor ID: ";
    cin >> d.id;
    cin.ignore();

    cout << "Enter doctor name: ";
    getline(cin, d.name);

    cout << "Enter specialization: ";
    getline(cin, d.specialization);

    doctors.push_back(d);
    cout << "Doctor added successfully.\n";
}

void searchDoctorBySpecialization(const vector<Doctor>& doctors, const string& specialization) {
    bool found = false;
    for (const auto& doc : doctors) {
        if (doc.specialization == specialization) {
            doc.display();
            found = true;
        }
    }
    if (!found) {
        cout << "No doctors found with specialization: " << specialization << endl;
    }
}

void doctorSearchMenu() {
    cout << "Enter specialization to search doctor: ";
    string spec;
    getline(cin, spec);
    searchDoctorBySpecialization(doctors, spec);
}

// --- Prajwal's contribution: Discharge Summary ---

string currentDate() {
    // Static date placeholder; real code would get system date
    return "2025-05-23";
}

void printDischargeSummary(const Patient& patient, double totalCost) {
    cout << "\n----- Discharge Summary -----\n";
    cout << "Patient Name: " << patient.name << "\n";
    cout << "Patient ID: " << patient.id << "\n";
    cout << "Diagnosis: " << patient.diagnosis << "\n";
    cout << "Treatment Given: " << patient.treatment << "\n";
    cout << "Total Cost: $" << totalCost << "\n";
    cout << "Date of Discharge: " << currentDate() << "\n";
    cout << "-----------------------------\n";
}

void dischargePatient() {
    if (patients.empty()) {
        cout << "No patients available for discharge.\n";
        return;
    }

    int patientID;
    cout << "Enter Patient ID to discharge: ";
    cin >> patientID;
    cin.ignore();

    for (auto it = patients.begin(); it != patients.end(); ++it) {
        if (it->id == patientID) {
            double totalCost;
            cout << "Enter total treatment cost: $";
            cin >> totalCost;
            cin.ignore();

            printDischargeSummary(*it, totalCost);

            patients.erase(it);
            cout << "Patient discharged successfully.\n";
            return;
        }
    }

    cout << "Patient with ID " << patientID << " not found.\n";
}

// --- Display all patients ---

void displayPatients() {
    cout << "\nList of Patients:\n";
    for (const auto& p : patients) {
        p.display();
    }
}

// --- Display all doctors ---

void displayDoctors() {
    cout << "\nList of Doctors:\n";
    for (const auto& d : doctors) {
        d.display();
    }
}

// --- Main menu including new options ---

void mainMenu() {
    int choice;
    while (true) {
        cout << "\nHospital Management System Menu:\n";
        cout << "1. Add Patient\n";
        cout << "2. Display Patients\n";
        cout << "3. Add Doctor\n";
        cout << "4. Display Doctors\n";
        cout << "5. Search Doctor by Specialization\n";
        cout << "6. Discharge Patient\n";
        cout << "7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: addPatient(); break;
            case 2: displayPatients(); break;
            case 3: addDoctor(); break;
            case 4: displayDoctors(); break;
            case 5: doctorSearchMenu(); break;
            case 6: dischargePatient(); break;
            case 7: cout << "Exiting...\n"; return;
            default: cout << "Invalid choice, try again.\n"; break;
        }
    }
}

int main() {
    cout << "Welcome to Hospital Management System\n";
    mainMenu();
    return 0;
}


