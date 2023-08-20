# University-management-system

The University Management System is a C++ project that implements a simple model of a university's operations, including managing departments, professors, students, and courses. The project follows object-oriented programming principles and incorporates the Singleton design pattern for efficient data management.

## Table of Contents
- [Introduction](#introduction)
- [Classes](#classes)
- [Usage](#usage)
- [Contributors](#contributors)

## Contributors

- Aml Moawad (https://github.com/amlmoawad)
- Ali Salama (https://github.com/3lis0)

## Introduction

The University Management System project aims to simulate the core functionalities of a university environment. It includes classes such as `Person`, `Department`, `Professor`, `Student`, `Course`, and `University` to represent various aspects of the university structure.

## Classes

- **Person**: Base class representing individuals with attributes like ID, name, age, and gender.

- **Department**: Represents a department within the university, with attributes such as name, capacity, and required GPA.

- **Professor**: Subclass of Person, representing professors with additional attributes like department affiliation, salary, and degree.

- **Student**: Subclass of Person, representing students with attributes such as level and GPA.

- **Course**: Represents courses with details like name, code, hours, prerequisites, professor, and enrolled students.

- **University**: Singleton class managing various operations such as adding and updating courses, students, departments, and professors.

## Usage

1. Compile the code: Use a C++ compiler to compile the provided source code.
   
2. Run the executable: Execute the compiled binary to run the University Management System simulation.

3. Interact with the system: Observe how the project models various university-related operations, including adding and updating courses, students, departments, and professors.



