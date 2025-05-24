// added Appointment Feature

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

class Patient {
public:
    int id;
    string name;
    int age;
    string disease;

    void inputBasic() {
        cout << "Enter Patient ID: ";
        cin >> id;
    }

    void inputDetails() {
        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Age: ";
        cin >> age;
        cout << "Enter Disease: ";
        cin.ignore();
        getline(cin, disease);
    }

    void display() const {
        cout << left << setw(10) << id
             << setw(20) << name
             << setw(10) << age
             << setw(20) << disease << endl;
    }
};

class Appointment {
public:
    int patientId;
    string date;
    string time;
    string doctor;

    void input() {
        cout << "Enter Patient ID: ";
        cin >> patientId;
        cin.ignore();
        cout << "Enter Appointment Date (DD-MM-YYYY): ";
        getline(cin, date);
        cout << "Enter Appointment Time (HH:MM): ";
        getline(cin, time);
        cout << "Enter Doctor's Name: ";
        getline(cin, doctor);
    }

    void display() const {
        cout << left << setw(12) << patientId
             << setw(15) << date
             << setw(10) << time
             << setw(20) << doctor << endl;
    }
};

class Hospital {
private:
    vector<Patient> patients;
    vector<Appointment> appointments;
    const string patientFile = "patients.dat";
    const string appointmentFile = "appointments.dat";

    void loadPatients() {
        ifstream fin(patientFile);
        Patient p;
        while (fin >> p.id) {
            fin.ignore();
            getline(fin, p.name);
            fin >> p.age;
            fin.ignore();
            getline(fin, p.disease);
            patients.push_back(p);
        }
        fin.close();
    }

    void savePatients() {
        ofstream fout(patientFile);
        for (const auto& p : patients) {
            fout << p.id << endl
                 << p.name << endl
                 << p.age << endl
                 << p.disease << endl;
        }
        fout.close();
    }

    void loadAppointments() {
        ifstream fin(appointmentFile);
        Appointment a;
        while (fin >> a.patientId) {
            fin.ignore();
            getline(fin, a.date);
            getline(fin, a.time);
            getline(fin, a.doctor);
            appointments.push_back(a);
        }
        fin.close();
    }

    void saveAppointments() {
        ofstream fout(appointmentFile);
        for (const auto& a : appointments) {
            fout << a.patientId << endl
                 << a.date << endl
                 << a.time << endl
                 << a.doctor << endl;
        }
        fout.close();
    }

public:
    Hospital() {
        loadPatients();
        loadAppointments();
    }

    ~Hospital() {
        savePatients();
        saveAppointments();
    }

    void addPatient() {
        Patient p;
        cout << "\n--- Add New Patient ---\n";
        p.inputBasic();

        // Check for duplicate ID
        for (const auto& existing : patients) {
            if (existing.id == p.id) {
                cout << "Error: A patient with ID " << p.id << " already exists.\n";
                return;
            }
        }

        p.inputDetails();
        patients.push_back(p);
        cout << "Patient added successfully!\n";
    }

    void viewPatients() {
        if (patients.empty()) {
            cout << "No patients available.\n";
            return;
        }

        cout << "\n--- Patient List ---\n";
        cout << left << setw(10) << "ID"
             << setw(20) << "Name"
             << setw(10) << "Age"
             << setw(20) << "Disease" << endl;
        for (const auto& p : patients)
            p.display();
    }

    void searchPatient() {
        int id;
        cout << "Enter ID to search: ";
        cin >> id;
        bool found = false;
        for (const auto& p : patients) {
            if (p.id == id) {
                cout << "\n--- Patient Found ---\n";
                p.display();
                found = true;
                break;
            }
        }
        if (!found) cout << "Patient not found.\n";
    }

    void deletePatient() {
        int id;
        cout << "Enter ID to delete: ";
        cin >> id;
        bool found = false;
        for (auto it = patients.begin(); it != patients.end(); ++it) {
            if (it->id == id) {
                patients.erase(it);
                cout << "Patient deleted successfully.\n";
                found = true;
                break;
            }
        }
        if (!found) cout << "Patient not found.\n";
    }

    void addAppointment() {
        Appointment a;
        cout << "\n--- Add Appointment ---\n";
        a.input();

        // Validate patient ID
        bool exists = false;
        for (const auto& p : patients) {
            if (p.id == a.patientId) {
                exists = true;
                break;
            }
        }
        if (!exists) {
            cout << "Error: Patient ID does not exist.\n";
            return;
        }

        appointments.push_back(a);
        cout << "Appointment scheduled successfully!\n";
    }

    void viewAppointments() {
        if (appointments.empty()) {
            cout << "No appointments scheduled.\n";
            return;
        }

        cout << "\n--- Appointment List ---\n";
        cout << left << setw(12) << "Patient ID"
             << setw(15) << "Date"
             << setw(10) << "Time"
             << setw(20) << "Doctor" << endl;
        for (const auto& a : appointments)
            a.display();
    }
};

int main() {
    Hospital h;
    int choice;
    do {
        cout << "\n=== Hospital Management Menu ===\n";
        cout << "1. Add Patient\n";
        cout << "2. View Patients\n";
        cout << "3. Search Patient\n";
        cout << "4. Delete Patient\n";
        cout << "5. Add Appointment\n";
        cout << "6. View Appointments\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: h.addPatient(); break;
        case 2: h.viewPatients(); break;
        case 3: h.searchPatient(); break;
        case 4: h.deletePatient(); break;
        case 5: h.addAppointment(); break;
        case 6: h.viewAppointments(); break;
        case 0: cout << "Exiting...\n"; break;
        default: cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 0);
    return 0;
}

