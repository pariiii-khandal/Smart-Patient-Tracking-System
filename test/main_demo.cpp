// main_demo.cpp
// Demo/test driver for PatientManager module
// Shows full workflow: register → update position → display → alert
// Branch: feature/patient-mgmt
// Author: [Pari Khandal]

#include "patient_manager.h"

int main() {
    // Define safe zone: X from -1.0 to 1.0, Y from -1.0 to 1.0
    PatientManager manager(-1.0, 1.0, -1.0, 1.0);

    // Register patients (linked to ArUco marker IDs)
    manager.registerPatient(1, "Ramesh");
    manager.registerPatient(2, "Priya");
    manager.registerPatient(3, "Anil");

    std::cout << "\n--- Simulating position updates ---\n\n";

    // Simulate positions received from pose estimation (pose.cpp)
    // Patient 1 — inside safe zone
    manager.updatePosition(1, 0.3, 0.5, 0.1);

    // Patient 2 — outside safe zone (should trigger alert)
    manager.updatePosition(2, 2.5, 3.1, 0.0);

    // Patient 3 — on the boundary (inside)
    manager.updatePosition(3, -0.9, 0.9, 0.2);

    // Display full report
    manager.displayAllPatients();

    // Simulate patient 1 moving outside zone
    std::cout << "--- Simulating Patient 1 moving outside zone ---\n";
    manager.updatePosition(1, 1.8, 0.2, 0.1);

    // Final report
    manager.displayAllPatients();

    return 0;
}
