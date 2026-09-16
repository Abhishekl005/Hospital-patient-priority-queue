#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct Patient {
    string name;
    int priority;

    // For min-heap: smaller priority number comes first
    bool operator>(const Patient& other) const {
        return priority > other.priority;
    }
};

class HospitalQueue {
private:
    priority_queue<Patient, vector<Patient>, greater<Patient>> patients;

public:
    // Function 1: Add a patient
    void addPatient(string name, int priority) {
        patients.push({name, priority});
        cout << "Added: " << name
             << " (Priority " << priority << ")" << endl;
    }

    // Function 2: Treat next patient
    void treatNext() {
        if (patients.empty()) {
            cout << "No patients waiting." << endl;
            return;
        }

        Patient next = patients.top();
        patients.pop();

        cout << "Treating: " << next.name
             << " (Priority " << next.priority << ")" << endl;
    }
};

int main() {
    HospitalQueue hospital;

    // Step 3: Add P1-P6
    hospital.addPatient("P1", 3);
    hospital.addPatient("P2", 1);
    hospital.addPatient("P3", 2);
    hospital.addPatient("P4", 1);
    hospital.addPatient("P5", 3);
    hospital.addPatient("P6", 2);

    cout << "\n--- Treatment Order ---\n";

    // Treat 3 patients
    hospital.treatNext();
    hospital.treatNext();
    hospital.treatNext();

    // Add a new Emergency patient
    cout << "\n--- New Emergency Patient ---\n";
    hospital.addPatient("P7", 1);

    // Continue treating everyone
    cout << "\n--- Remaining Treatment Order ---\n";

    hospital.treatNext();
    hospital.treatNext();
    hospital.treatNext();
    hospital.treatNext();
}
