# Contributing Guide

This document defines the contribution rules and development workflow for the Student Information System project.

All contributors are expected to follow the guidelines below to ensure code quality, consistency, and effective teamwork.

Branch Strategy

The project follows a Git Flow–like branching model.

- main: Contains stable and production-ready code
- develop: Contains active development code
- feature/*: Used for developing new features or improvements

Direct pushes to the main and develop branches are not allowed.

Creating a New Feature

1. Create a new branch from develop:
git checkout develop
git checkout -b feature/feature-name

2. Implement the feature and commit changes with meaningful messages.

3. Push the branch to the remote repository:
git push origin feature/feature-name

4. Open a Pull Request targeting the develop branch.

Pull Request Rules

- All changes must be submitted via Pull Requests
- At least one team member review is required before merging
- Pull Requests must include a clear description of the changes
- All automated checks must pass before merging

Commit Message Guidelines

Commits should use clear and descriptive messages.

Example format:
feat: add student creation functionality
fix: resolve database connection issue
docs: update installation guide

Testing

- New features should be tested before submitting a Pull Request
- Unit tests should be added when applicable
- Existing tests must pass before merging

Code Style

- Follow consistent C++ coding standards
- Use meaningful variable and function names
- Keep functions small and focused
- Comment code where necessary

Issues and Project Management

- All tasks must be tracked using GitHub Issues
- Issues should be assigned to team members
- Progress should be updated regularly in GitHub Projects

Documentation

- Update documentation when introducing new features
- Keep README.md, INSTALL.md, and MANUAL.md up to date

Conclusion

Following these contribution rules ensures a structured and efficient development process and helps maintain the overall quality of the project.
