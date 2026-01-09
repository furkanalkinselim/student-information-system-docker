# User Manual

This document explains how to use the Student Information System application after it has been successfully installed and started using Docker.

The application is a command-line based system that allows users to manage student information stored in a PostgreSQL database.

Starting the Application

After running the project with Docker Compose, the C++ application starts automatically inside its container. The user interacts with the system through the terminal.

If the containers are running, the application is ready to accept commands.

Main Menu

When the application starts, a menu similar to the following is displayed:

1. Add Student  
2. List Students  
3. Update Student  
4. Delete Student  
5. Exit  

The user selects an operation by entering the corresponding number.

Adding a Student

To add a new student, select the Add Student option from the menu.

The system will ask for the following information:
- Student ID
- Name
- Surname
- Department
- Email address

After entering valid information, the student record is saved to the database.

Listing Students

By selecting the List Students option, all student records stored in the database are displayed on the screen.

Each record includes:
- Student ID
- Name
- Surname
- Department
- Email

Updating a Student

To update an existing student, select the Update Student option.

The system will ask for the Student ID of the record to be updated. After that, the user can enter new values for the student’s information.

If the specified Student ID does not exist, an error message is displayed.

Deleting a Student

To delete a student record, select the Delete Student option.

The system will request the Student ID of the student to be removed. After confirmation, the record is deleted from the database.

Exiting the Application

To exit the application, select the Exit option from the menu. The application will terminate safely without affecting the database.

Error Handling

The application includes basic error handling mechanisms:
- Invalid menu selections are rejected
- Empty or invalid input values are not accepted
- Database connection errors are reported to the user

Notes

- All data is stored persistently in the PostgreSQL database using Docker volumes.
- Restarting the containers does not result in data loss.
- The application is intended for educational purposes and runs entirely in a containerized environment.

Conclusion

This manual provides a basic guide for using the Student Information System. By following the steps described above, users can manage student records effectively through the command-line interface.
