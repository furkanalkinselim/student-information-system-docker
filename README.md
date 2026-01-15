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

## Docker Hub Images

The Docker images used in this project are publicly available on Docker Hub as required by the course.

- **C++ Application Image:**  
  https://hub.docker.com/r/semihgrcnn/sis-project-app

- **PostgreSQL Database Image:**  
  https://hub.docker.com/r/semihgrcnn/sis-project-postgres

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

```text
student-information-system-docker/
├── .github/
│   └── workflows/        # CI/CD Pipeline configurations
├── docs/                 # Project documentation
│   ├── CONTRIBUTING.md   # Contribution guidelines
│   ├── INSTALL.md        # Installation & setup guide
│   └── MANUAL.md         # User manual & instructions
├── src/                  # Source code directory
│   └── main.cpp          # Main C++ application logic
├── .dockerignore         # Files excluded from Docker build
├── .gitignore            # Files ignored by Git
├── docker-compose.yml    # Orchestration config (App + DB)
├── Dockerfile            # C++ image build instructions
├── LICENSE               # MIT License
├── Makefile              # Build commands
└── README.md             # Project overview
