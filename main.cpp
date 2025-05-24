//  Hospital Management System 

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

    void input() {
        cout << "Enter Patient ID: ";
        cin >> id;
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
        cout << left << setw(10) << id << setw(20) << name << setw(10) << age << setw(20) << disease << endl;
    }
};

class Hospital {
private:
    vector<Patient> patients;
    const string filename = "patients.dat";

    void loadFromFile() {
        ifstream fin(filename);
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

    void saveToFile() {
        ofstream fout(filename);
        for (const auto& p : patients) {
            fout << p.id << endl
                 << p.name << endl
                 << p.age << endl
                 << p.disease << endl;
        }
        fout.close();
    }

public:
    Hospital() { loadFromFile(); }
    ~Hospital() { saveToFile(); }

    void addPatient() {
        Patient p;
        p.input();
        patients.push_back(p);
        cout << "Patient added successfully!\n";
    }

    void viewPatients() {
        cout << left << setw(10) << "ID" << setw(20) << "Name" << setw(10) << "Age" << setw(20) << "Disease" << endl;
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
                cout << "Patient deleted.\n";
                found = true;
                break;
            }
        }
        if (!found) cout << "Patient not found.\n";
    }
};

int main() {
    Hospital h;
    int choice;
    do {
        cout << "\n--- Hospital Management Menu ---\n";
        cout << "1. Add Patient\n";
        cout << "2. View All Patients\n";
        cout << "3. Search Patient\n";
        cout << "4. Delete Patient\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
	switch (choice) {
        case 1:
            h.addPatient();
            break;
        case 2:
            h.viewPatients();
            break;
        case 3:
            h.searchPatient();
            break;
        case 4:
            h.deletePatient();
            break;
        case 0:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice.\n";
        }
    } while (choice != 0);
    return 0;
}
