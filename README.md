# C System Utility

A menu-driven command-line application built in C to practise fundamental programming concepts, file handling, structures, functions, and data management.

## 📌 About the Project

C System Utility is a beginner-level project developed as part of my journey in learning C programming.

It combines a student record management system, a simple file manager, and a student statistics module in one application.

## ✨ Features

### 1. Student Record Management

* Add student records with a name, age, and mark.
* View stored student records.
* Search for students by name.
* Update student age and marks.
* Delete student records.
* Validate student names, ages, and marks.
* Store student records in a text file for later use.

### 2. File Manager

* Create a text file and write content to it.
* View the contents of an existing file.
* Append content to an existing file.

### 3. Student Statistics

* Display the total number of students.
* Calculate the average mark.
* Find the highest mark.
* Find the lowest mark.

## 🛠️ Technologies Used

* **Language:** C
* **Standard libraries:** `stdio.h`, `string.h`, `ctype.h`
* **Data storage:** Text files
* **Development environment:** Visual Studio Code and a C compiler

## 📂 Project Structure

```text
C-utility-project/
│
├── System_utility.c
└── README.md
```

## ⚙️ Getting Started

### Prerequisites

You need:

* A C compiler.
* A terminal or command prompt.

### Installation

**1. Clone the repository**

```bash
git clone https://github.com/aasif12305-lumen/C-utility-project.git
```

**2. Open the project directory**

```bash
cd C-utility-project
```

**3. Compile the program**

If GCC is installed:

```bash
gcc System_utility.c -o System_utility
```

**4. Run the program**

On Windows:

```bash
System_utility.exe
```

On Linux or macOS:

```bash
./System_utility
```

> Note: These GCC commands assume GCC is installed and available in your terminal. If you use Microsoft's MSVC compiler, use the appropriate Visual Studio Developer Command Prompt instead.

## 🖥️ How to Use

When you launch the program, you will see the main menu:

1. Student Records
2. File Manager
3. Statistics
4. Exit

Choose an option by entering its corresponding number and following the instructions displayed in the terminal.

### Student Records

Open the Student Records menu to add, view, search, update, or delete student information.

### File Manager

Use the File Manager menu to create files, view file contents, or append new content.

### Statistics

Select Statistics to calculate and display the total number of students, average mark, highest mark, and lowest mark.

## 📚 Concepts Practised

This project helped me practise:

* Variables and data types
* Conditional statements and loops
* Functions and function declarations
* Arrays and structures
* Pointers and passing arguments to functions
* String manipulation
* Input validation
* File handling using `fopen()`, `fscanf()`, `fprintf()`, and `fclose()`
* Searching and updating records
* Basic data analysis using functions

## 🚀 Future Improvements

Possible improvements include:

* Support for more student records.
* Stronger input validation and error handling.
* Improved file storage and data integrity.
* Better separation of functions into multiple source files.
* Additional student performance reports.

## 👨‍💻 Author

**Aasif**

First-year Computer Science and Engineering student learning C programming and building practical projects.

[GitHub Profile](https://github.com/aasif12305-lumen)

---

*This project was created for learning and educational purposes.*
