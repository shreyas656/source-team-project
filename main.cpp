#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// ------------------ Data Classes ------------------

class Patient {
public:
    int id;
    string name;
    int age;
    string diagnosis;
    string treatment;

    void display() const {
        cout << "Patient ID: " << id
             << ", Name: " << name
             << ", Age: " << age << "\nDiagnosis: " << diagnosis
             << "\nTreatment: " << treatment << "\n";
    }
};

class Doctor {
public:
    int id;
    string name;
    string specialization;

    void display() const {
        cout << "Doctor ID: " << id
             << ", Name: " << name
             << ", Specialization: " << specialization << "\n";
    }
};

class Medicine {
public:
    string name;
    int stock;

    void display() const {
        cout << "Medicine: " << name << ", Stock: " << stock << "\n";
    }
};

// ------------------ Global Vectors ------------------

vector<Patient> patients;
vector<Doctor> doctors;
vector<Medicine> medicines;

// ------------------ Chinami's Patient Age Validation ------------------

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

void displayPatients() {
    cout << "\nList of Patients:\n";
    if (patients.empty()) {
        cout << "No patients available.\n";
        return;
    }
    for (const auto& p : patients) {
        p.display();
    }
}

// ------------------ Suhas's Doctor Handling ------------------

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

void displayDoctors() {
    cout << "\nList of Doctors:\n";
    if (doctors.empty()) {
        cout << "No doctors available.\n";
        return;
    }
    for (const auto& d : doctors) {
        d.display();
    }
}

void searchDoctorBySpecialization(const string& specialization) {
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
    searchDoctorBySpecialization(spec);
}

// ------------------ Prajwal's Discharge Summary ------------------

string currentDate() {
    return "2025-05-23"; // Placeholder date
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

// ------------------ Sudhrashan's Medicine Stock ------------------

void addMedicine() {
    Medicine m;
    cout << "Enter medicine name: ";
    getline(cin, m.name);
    cout << "Enter medicine stock quantity: ";
    cin >> m.stock;
    cin.ignore();

    medicines.push_back(m);
    cout << "Medicine added successfully.\n";
}

void checkMedicineStock() {
    if (medicines.empty()) {
        cout << "No medicine stock available.\n";
        return;
    }

    cout << "Current Medicine Stock:\n";
    for (const auto& med : medicines) {
        med.display();
    }
}

// ------------------ Main Menu ------------------

void mainMenu() {
    int choice;
    while (true) {
        cout << "\n--- Hospital Management System Menu ---\n";
        cout << "1. Add Patient\n";
        cout << "2. Display Patients\n";
        cout << "3. Add Doctor\n";
        cout << "4. Display Doctors\n";
        cout << "5. Search Doctor by Specialization\n";
        cout << "6. Discharge Patient\n";
        cout << "7. Add Medicine Stock\n";
        cout << "8. Check Medicine Stock\n";
        cout << "9. Exit\n";
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
            case 7: addMedicine(); break;
            case 8: checkMedicineStock(); break;
            case 9: cout << "Exiting...\n"; return;
            default: cout << "Invalid choice. Please try again.\n"; break;
        }
    }
}

// ------------------ Entry Point ------------------

int main() {
    cout << "Welcome to the Hospital Management System\n";
    mainMenu();
    return 0;
}
