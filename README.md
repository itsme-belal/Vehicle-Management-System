# 🚗 Vehicle Management System

### CSE101 – Structured Programming Project

This project is a **console-based Vehicle Management System** developed using the **C programming language**. The system allows users to efficiently manage vehicle records by adding, viewing, updating, searching, and deleting vehicle information.

The program also demonstrates the use of **structured programming concepts**, including structures, file handling, modular functions, and menu-driven control flow.

---

## 🌟 Key Features

**➤ Add Vehicle Record**
Allows users to input and store vehicle information such as **Vehicle ID, Model, Owner Name, and Plate Number**.

**➤ View All Vehicles**
Displays a list of all vehicles currently stored in the system.

**➤ Search Vehicle**
Users can quickly find a specific vehicle using its **unique Vehicle ID**.

**➤ Update Vehicle Information**
Existing vehicle records can be modified if any information changes.

**➤ Delete Vehicle Record**
Removes unwanted or outdated vehicle records permanently from the system.

**➤ File Handling (Data Persistence)**
All vehicle data is stored in a file (`vehicle_data.txt`), ensuring that the information remains saved even after the program is closed.

---

## 🛠️ Technical Implementation

This project demonstrates several important concepts of **Structured Programming in C**:

* **Structures (`struct`)**
  Used to represent vehicle information as a single data entity.

* **File Handling (File I/O)**
  Functions such as `fopen()`, `fprintf()`, `fscanf()`, and `fclose()` are used to store and retrieve data from files.

* **Control Flow**
  A **menu-driven interface** implemented using `switch-case` and `while` loops.

* **Modular Programming**
  The program is divided into multiple functions to improve readability and maintainability.

---

## 📂 File Structure

```
Vehicle-Management-System/
│
├── main.c
├── vehicle_data.txt
└── README.md
```

* **main.c** → Contains the main source code of the program
* **vehicle_data.txt** → Stores all vehicle records

---

## 🚀 How to Run

1. Clone or download this repository.
2. Open `main.c` using a C compiler such as:

   * CodeBlocks
   * Dev-C++
   * VS Code
   * GCC
3. Compile and run the program.

Example (using GCC):

```
gcc main.c -o vehicle
./vehicle
```

---

## 👨‍💻 Author

**Belal Hossain**
BSc in Computer Science & Engineering
East West University
