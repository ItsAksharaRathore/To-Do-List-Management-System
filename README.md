# To-Do List Management System

### Overview
This project is a Skill-Based Micro Project developed by Akshara Rathore and Vaibhav Sharma. It provides a command-line interface for managing to-do lists for multiple users, storing data persistently in a CSV format.

### Features
- **User Management**: Register and login functionalities for users.
- **Task Management**: Add tasks, display tasks, mark tasks as done, and export tasks to a text file.
- **Password Management**: Users can change their passwords securely.
- **Data Persistence**: User information and tasks are stored in a `users.csv` file.

### Project Structure
The project utilizes C++ and includes the following main components:
- **User Struct**: Stores username, password, and a linked list of tasks.
- **Task Struct**: Represents individual tasks linked to each user.
- **Main Functions**:
  - `saveData()`: Saves user data to `users.csv`.
  - `loadData()`: Loads user data from `users.csv` on program start.
  - `registerUser()`: Registers a new user with username and password.
  - `authUser(string username, string password)`: Authenticates user credentials.
  - `addTask(string username, string taskdesc)`: Adds a task to a user's list.
  - `display(string username)`: Displays all tasks for a specific user.
  - `displayCurrent(string username)`: Displays the current task for a user.
  - `markDone(string username)`: Marks the current task as done for a user.
  - `exportList(string username)`: Exports a user's task list to a text file.
  - `changePassword(string username, string password)`: Allows a user to change their password.

### Usage
1. **Registration and Login**: Users can register with a unique username and password. Existing users can log in securely.
2. **Task Management**: Once logged in, users can add tasks, view their tasks, mark tasks as done, and export their task list.
3. **Password Change**: Users can change their passwords to maintain security.

### Installation
No special installation steps are required. Simply compile and run the program in a C++ environment that supports standard input/output operations.

## How to Use?
To use the To-Do List Management System project developed by Akshara Rathore and Vaibhav Sharma, follow these steps:

### Prerequisites
- Ensure you have a C++ compiler installed on your system. Popular choices include GCC (GNU Compiler Collection) for Linux and MinGW for Windows.

### Steps to Use:

1. **Clone the Repository:**
   Clone the GitHub repository to your local machine using Git. Open your terminal or command prompt and run:
   ```
   git clone https://github.com/itsVaibhavSharma/ToDoListManagementSystem.git
   ```
   This will create a local copy of the project on your machine.

2. **Compile the Code:**
   Navigate to the directory where you cloned the repository. Compile the C++ code using your preferred compiler. For example, with GCC on Linux, you can compile using:
   ```
   g++ -o ToDoListManagementSystem main.cpp
   ```
   Replace `main.cpp` with the actual name of the main C++ file if it differs.

3. **Run the Executable:**
   After compilation, run the generated executable file. In the terminal or command prompt, execute:
   ```
   ./ToDoListManagementSystem
   ```
   This will start the To-Do List Management System application.

4. **Functionality:**
   - **Registration and Login:**
     - Choose option `2` to register a new user by entering a username and password.
     - Choose option `1` to log in with an existing username and password.

   - **Task Management:**
     - After logging in, you can manage tasks:
       - Option `1`: Add a new task by providing a description.
       - Option `2`: Display all tasks associated with your username.
       - Option `3`: Display the current task.
       - Option `4`: Mark the current task as done.
       - Option `5`: Export the task list to a text file.

   - **Password Management:**
     - Option `6`: Change your password by entering your old password and then the new password.

   - **Logout and Exit:**
     - Option `7`: Logout from the current session.
     - Option `3` (Main menu): Exit the program.

5. **Data Persistence:**
   - User data and task lists are stored in a file named `users.csv` in the same directory as the executable. This file persists user information across sessions.

6. **Further Customization:**
   - Modify the code or extend functionalities as needed based on the provided C++ source code (`main.cpp`).

### Notes:
- Ensure proper input format when interacting with the application (e.g., usernames, passwords, task descriptions).
- Follow the on-screen instructions and prompts provided by the application for a smooth user experience.

By following these steps, you can effectively use the To-Do List Management System to organize tasks and manage user accounts securely.

## Special Features
The To-Do List Management System developed by Akshara Rathore and Vaibhav Sharma incorporates several special features that enhance its functionality and usability:

### 1. **User Authentication and Security**
   - **Registration and Login**: Users can securely register with unique usernames and passwords. Existing users can log in to access their task lists.
   - **Password Change**: Provides the ability for users to change their passwords, ensuring account security.

### 2. **Task Management**
   - **Add Tasks**: Users can add new tasks with descriptions.
   - **Display Tasks**: View all tasks associated with a user.
   - **Display Current Task**: Quickly check the current task in the list.
   - **Mark Tasks as Done**: Easily mark tasks as completed and remove them from the active list.
   - **Export Task List**: Export the entire task list to a text file for external use or storage.

### 3. **Data Persistence**
   - **CSV File Storage**: User information (username, password) and task lists are stored persistently in a CSV file (`users.csv`). This ensures that data is retained between program executions.

### 4. **User Interface**
   - **Command-Line Interface (CLI)**: The system utilizes a straightforward CLI, making it accessible and easy to use for all users.

### 5. **Error Handling and User Feedback**
   - **Input Validation**: Ensures that user inputs are validated to prevent errors and provide a seamless user experience.
   - **Feedback Messages**: Provides clear and informative messages to users during operations such as task addition, authentication, and password changes.

### 6. **Scalability and Extensibility**
   - **Modular Structure**: The code is organized into functions and structures (like `User` and `Task`), making it easy to extend functionality or modify existing features.
   - **Potential Additions**: The system can be extended with additional features such as task prioritization, due dates, or collaborative task management.

### 7. **Documentation and Support**
   - **ReadMe**: Includes comprehensive documentation in the ReadMe file (`README.md`), detailing installation instructions, usage guidelines, and project overview.
   - **Contributor Information**: Clearly identifies the developers (Akshara Rathore and Vaibhav Sharma) and their roles in the project.

### 8. **Educational Value**
   - **Skill-Based Project**: Designed as a micro project to reinforce C++ programming concepts such as file handling, data structures (linked lists), and user input/output operations.

## Contributors
- **Akshara Rathore** (GitHub: [@itsAksharaRathore](https://github.com/itsAksharaRathore))
- **Vaibhav Sharma** (GitHub: [@itsVaibhavSharma](https://github.com/itsVaibhavSharma))

## Conclusion
This project demonstrates fundamental concepts in C++ programming including file handling, data structures (linked lists), and user input/output operations. It provides a practical implementation of a to-do list management system with user authentication and data persistence.

For more details, please refer to the source code and documentation within this repository.
