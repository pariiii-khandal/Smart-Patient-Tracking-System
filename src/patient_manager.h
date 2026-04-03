// patient_manager.h
// PatientManager module — stores patient info, tracks position, raises alerts
// Branch: feature/patient-mgmt
// Author: [Pari Khandal]

#ifndef PATIENT_MANAGER_H
#define PATIENT_MANAGER_H

#include <string>
#include <map>
#include <iostream>

// Struct to hold 3D position (received from pose estimation module)
struct Position {
    double x, y, z;
};

// Struct to define safe zone boundaries (2D — x and y limits)
struct SafeZone {
    double x_min, x_max;
    double y_min, y_max;
};

// PatientManager class — core of this module
class PatientManager {
private:
    // Maps marker ID → patient name
    std::map<int, std::string> patientRegistry;

    // Maps marker ID → last known position
    std::map<int, Position> patientPositions;

    // Single safe zone applied to all patients
    SafeZone safeZone;

public:
    // Constructor: initialize with safe zone boundaries
    PatientManager(double x_min, double x_max, double y_min, double y_max);

    // Register a patient with their marker ID and name
    void registerPatient(int markerID, const std::string& name);

    // Update position of a patient (called after pose estimation)
    void updatePosition(int markerID, double x, double y, double z);

    // Check if a given position is inside the safe zone
    bool isInsideSafeZone(const Position& pos) const;

    // Display all patient details + current positions + alert status
    void displayAllPatients() const;

    // Check and trigger alert for a specific patient
    void checkAndAlert(int markerID) const;

    // Get patient name by ID (returns "Unknown" if not found)
    std::string getPatientName(int markerID) const;
};

#endif // PATIENT_MANAGER_H
