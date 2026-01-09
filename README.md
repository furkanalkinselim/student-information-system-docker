# Student Information System with Docker Containers

## Project Overview
This project is a containerized **Student Information System** developed as part of the *System Programming* course.  
The system allows managing student information using a C++ application connected to a PostgreSQL database, all running inside Docker containers.

The project focuses on teamwork, version control, containerization, and system programming principles.

---

## Technologies Used
- **C++ (C++11+)**
- **PostgreSQL**
- **Docker & Docker Compose**
- **Git & GitHub**
- **GitHub Actions (CI/CD)**
- **Ubuntu**

---

## System Architecture
The system consists of two main containers:

1. **PostgreSQL Database Container**
   - Stores student information
   - Uses persistent volumes for data storage

2. **C++ Application Container**
   - Command Line Interface (CLI)
   - Connects to PostgreSQL using `libpqxx`
   - Performs CRUD operations

All containers communicate over a private Docker network using Docker Compose.

---

## Features
- Add new student information
- List all students
- Update existing student records
- Delete student records
- Transaction management
- Input validation and error handling

---

## Project Structure
