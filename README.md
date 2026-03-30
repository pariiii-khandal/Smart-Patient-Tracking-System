# Smart Patient Tracking System using ArUco Markers

## Overview
The **Smart Patient Tracking System** is an Object-Oriented Programming (OOP) case study built with C++ and OpenCV. This system is designed to monitor patients in real-time by detecting assigned ArUco markers, tracking their precise 3D positions, and triggering automated alerts if a patient wanders outside of a designated safe zone. Smart Patient Tracking System using OpenCV ArUco markers for real-time detection, pose estimation, and safety monitoring with zone-based alerts

## Key Features
* **Real-Time Marker Detection:** Identifies individual patients via unique ArUco markers.
* **3D Pose Estimation:** Calculates the exact spatial coordinates (x, y, z) of the markers.
* **Safe Zone Alert System:** Continuously monitors patient coordinates against predefined safe boundaries, triggering alerts upon violation.
* **OOP Architecture:** Modular, maintainable codebase utilizing modern C++ design principles.

## Tech Stack & Requirements
* **Language:** C++ (Compiled with `-std=c++14` to support modern features like lambda closures for the event-driven alert callbacks and universal references for optimized data handling).
* **Computer Vision Library:** OpenCV (with `opencv_contrib` for the ArUco module).
* **Version Control:** Git & GitHub.

## Project Structure
The project is divided into distinct modular files to ensure clean integration:
* `tracking.cpp` - Handles core ArUco marker detection and ID extraction.
* `pose.cpp` - Manages `estimatePoseSingleMarkers()` and coordinate translation.
* `main.cpp` - Final integration, system loop, and safe zone alert logic.
* `README.md` - Project documentation and setup guide.

## Evaluation Metrics
To ensure system reliability, the following metrics are actively monitored and will be documented upon final release:
| Metric | Target / Measurement | Description |
| :--- | :--- | :--- |
| **Accuracy** | High | Precision of marker detection and spatial estimation (approximate bounds). |
| **FPS** | > 24 FPS | Frames Per Second to ensure smooth, real-time tracking without lag. |
| **Stability** | Continuous | System uptime and consistency under varying lighting conditions. |
