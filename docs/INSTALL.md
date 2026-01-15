# Installation Guide

This document describes the steps required to install and run the Student Information System with Docker Containers on a local machine.

System Requirements

- Operating System: Ubuntu 20.04+ or any Linux distribution
- Git
- Docker (version 20.10 or higher)
- Docker Compose (version 1.29 or higher)

Installing Required Tools

Install Git
sudo apt update
sudo apt install git -y

Install Docker
sudo apt update
sudo apt install docker.io -y
sudo systemctl start docker
sudo systemctl enable docker
sudo usermod -aG docker $USER

Install Docker Compose
sudo apt install docker-compose -y
docker-compose --version

Project Installation

Clone the repository
git clone <repository-url>
cd student-information-system-docker

Build and run the project
docker-compose up --build

Verifying the Installation

Check running containers
docker ps

Stopping the Project

Stop containers
docker-compose down

Stop and remove volumes
docker-compose down -v

Troubleshooting

Check Docker service and container logs
docker logs <container-name>

Notes

Database data is stored using Docker volumes and persists between restarts.
No local database installation is required.

Conclusion

By following this guide, the project can be successfully installed and executed using Docker and Docker Compose.
