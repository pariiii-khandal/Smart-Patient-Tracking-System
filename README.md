Smart Patient Tracking System using ArUco Markers

Overview

This project is an Object-Oriented Programming (OOP) based system built using C++ and OpenCV. It detects ArUco markers in real-time, estimates their position, and monitors whether a patient remains inside a predefined safe zone. If the patient moves outside the safe zone, the system triggers an alert and logs the event.

---

Key Features

- Real-Time ArUco Marker Detection
- 3D Pose Estimation (X, Y, Z coordinates)
- Safe Zone Monitoring with visual boundary box
- Alert System when patient exits safe zone
- Logging system to record events ("patient_log.txt")
- FPS display for performance monitoring

---

Tech Stack

- Language: C++
- Library: OpenCV (with ArUco module)
- IDE: Visual Studio
- Version Control: Git & GitHub

---

Project Structure

- "main.cpp" → Main system loop and integration
- "logger.cpp / logger.h" → Event logging functionality
- "patient_utils.cpp / patient_utils.h" → Safe zone and utility functions
- "patient_log.txt" → Stores logged alerts
- ".gitignore" → Excludes unnecessary build files

---

Working

1. Camera captures live video
2. ArUco markers are detected
3. Marker position is calculated
4. System checks if marker lies inside safe zone
5. If outside → alert displayed + event logged

---

Evaluation Metrics

- Accuracy → Correct detection of markers
- FPS → ~30 FPS real-time performance
- Stability → Consistent tracking under normal lighting

---

Contributors

- Parthvi Mishra
- Aditya Priyan
- Pari Khandelwal
- Kaarthik
