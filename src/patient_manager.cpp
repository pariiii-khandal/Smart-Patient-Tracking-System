// patient_manager.cpp
// Implementation of PatientManager class
// Branch: feature/patient-mgmt
// Author: [Pari Khandal]

#include "patient_manager.h"
#include <iomanip>

// Constructor: set safe zone limits
PatientManager::PatientManager(double x_min, double x_max,
                               double y_min, double y_max) {
    safeZone = {x_min, x_max, y_min, y_max};
    std::cout << "[PatientManager] Initialized. Safe zone: "
              << "X[" << x_min << " to " << x_max << "] "
              << "Y[" << y_min << " to " << y_max << "]\n";
}

// Register a new patient with their ArUco marker ID
void PatientManager::registerPatient(int markerID, const std::string& name) {
    patientRegistry[markerID] = name;
    // Initialize position to origin by default
    patientPositions[markerID] = {0.0, 0.0, 0.0};
    std::cout << "[PatientManager] Registered: ID=" << markerID
              << " Name=" << name << "\n";
}

// Update patient's 3D coordinates (fed from pose.cpp output)
void PatientManager::updatePosition(int markerID, double x, double y, double z) {
    // Only update if patient is registered
    if (patientRegistry.find(markerID) == patientRegistry.end()) {
        std::cout << "[WARNING] Marker ID " << markerID
                  << " not registered. Skipping update.\n";
        return;
    }

    patientPositions[markerID] = {x, y, z};

    // Immediately check alert after every position update
    checkAndAlert(markerID);
}

// Returns true if position is within defined safe zone boundaries
bool PatientManager::isInsideSafeZone(const Position& pos) const {
    return (pos.x >= safeZone.x_min && pos.x <= safeZone.x_max &&
            pos.y >= safeZone.y_min && pos.y <= safeZone.y_max);
}

// Trigger alert if patient has left the safe zone
void PatientManager::checkAndAlert(int markerID) const {
    // Look up position
    auto posIt = patientPositions.find(markerID);
    auto nameIt = patientRegistry.find(markerID);

    if (posIt == patientPositions.end() || nameIt == patientRegistry.end()) {
        return; // Patient not found, skip
    }

    const Position& pos = posIt->second;
    const std::string& name = nameIt->second;

    if (!isInsideSafeZone(pos)) {
        // ALERT: patient outside safe zone
        std::cout << "\n*** ALERT *** Patient [" << name << "] (ID=" << markerID
                  << ") has LEFT the safe zone!\n"
                  << "  Position: X=" << std::fixed << std::setprecision(2)
                  << pos.x << "  Y=" << pos.y << "  Z=" << pos.z << "\n\n";
    } else {
        std::cout << "[OK] " << name << " (ID=" << markerID
                  << ") is inside safe zone. "
                  << "X=" << pos.x << " Y=" << pos.y << " Z=" << pos.z << "\n";
    }
}

// Print all registered patients with their positions and zone status
void PatientManager::displayAllPatients() const {
    std::cout << "\n===== Patient Status Report =====\n";
    std::cout << std::left
              << std::setw(6)  << "ID"
              << std::setw(16) << "Name"
              << std::setw(10) << "X"
              << std::setw(10) << "Y"
              << std::setw(10) << "Z"
              << "Status\n";
    std::cout << std::string(60, '-') << "\n";

    for (const auto& entry : patientRegistry) {
        int id = entry.first;
        const std::string& name = entry.second;
        const Position& pos = patientPositions.at(id);
        std::string status = isInsideSafeZone(pos) ? "SAFE" : "*** ALERT ***";

        std::cout << std::left
                  << std::setw(6)  << id
                  << std::setw(16) << name
                  << std::setw(10) << std::fixed << std::setprecision(2) << pos.x
                  << std::setw(10) << pos.y
                  << std::setw(10) << pos.z
                  << status << "\n";
    }
    std::cout << "=================================\n\n";
}

// Get patient name from ID
std::string PatientManager::getPatientName(int markerID) const {
    auto it = patientRegistry.find(markerID);
    if (it != patientRegistry.end()) {
        return it->second;
    }
    return "Unknown";
}
