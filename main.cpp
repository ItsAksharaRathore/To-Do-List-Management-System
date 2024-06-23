#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Structure for Task node
struct Task
{
    string description;
    Task *next;
};

// Structure for User node
struct User
{
    string Username;
    string Password;
    Task *taskHead;
    User *next;
} *head = NULL;

int nUsers = 0; // Variable to keep track of number of users

// Function to save user data to a CSV file
void saveData()
{
    fstream file;
    file.open("users.csv", ios::out);
    if (file.is_open())
    {
        // Traverse through each user node
        for (User *tempU = head; tempU != NULL; tempU = tempU->next)
        {
            file << tempU->Username << "," << tempU->Password << ",";

            // Traverse through each task of the current user
            Task *temp = tempU->taskHead;
            while (temp != NULL)
            {
                file << temp->description << ",";
                temp = temp->next;
            }
            file << endl;
        }
    }
    file.close();
}

// Function to load user data from CSV file
void loadData()
{
    fstream file;
    file.open("users.csv", ios::in);
    if (file.is_open())
    {
        if (!file.eof())
        {
            string line;
            while (getline(file, line))
            {
                string username, password, taskDesc;
                int i;

                // Extract username
                for (i = 0; line[i] != ','; i++)
                {
                    username = username + line[i];
                }

                // Extract password
                for (i = i + 1; line[i] != ','; i++)
                {
                    password = password + line[i];
                }

                // Create new user node
                User *user = new User;
                user->Username = username;
                user->Password = password;
                user->taskHead = NULL;
                user->next = NULL;

                // Extract tasks for the user
                while (line[i + 1] != '\0')
                {
                    Task *newTask = new Task;
                    newTask->next = NULL;

                    // Extract task description
                    for (i = i + 1; line[i] != ','; i++)
                    {
                        newTask->description = newTask->description + line[i];
                    }

                    // Add task to user's task list
                    if (user->taskHead == NULL)
                    {
                        user->taskHead = newTask;
                    }
                    else
                    {
                        Task *temp = user->taskHead;
                        while (temp->next != NULL)
                        {
                            temp = temp->next;
                        }
                        temp->next = newTask;
                    }
                }

                // Add user to the linked list of users
                if (head == NULL)
                {
                    head = user;
                }
                else
                {
                    User *temp = head;
                    while (temp->next != NULL)
                    {
                        temp = temp->next;
                    }
                    temp->next = user;
                }
            }
        }
        file.close();
    }
}

// Function to register a new user
void registerUser()
{
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter Password: ";
    cin >> password;

    // Create new user node
    User *newUser = new User;
    newUser->Username = username;
    newUser->Password = password;
    newUser->taskHead = NULL;
    newUser->next = NULL;

    // Add new user to the linked list of users
    if (head == NULL)
    {
        head = newUser;
    }
    else
    {
        User *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newUser;
    }

    cout << "User Registered Successfully." << endl;
    saveData();
}

// Function to authenticate user login
bool authUser(string username, string password)
{
    for (User *tempU = head; tempU != NULL; tempU = tempU->next)
    {
        if (tempU->Username == username && tempU->Password == password)
        {
            return true; // User found and authenticated
        }
    }
    return false; // User not found or authentication failed
}

// Function to add a task for a specific user
void addTask(string username, string taskdesc)
{
    for (User *tempU = head; tempU != NULL; tempU = tempU->next)
    {
        if (tempU->Username == username)
        {
            Task *newTask = new Task;
            newTask->description = taskdesc;
            newTask->next = NULL;

            // Add new task to user's task list
            if (tempU->taskHead == NULL)
            {
                tempU->taskHead = newTask;
            }
            else
            {
                Task *temp = tempU->taskHead;
                while (temp->next != NULL)
                {
                    temp = temp->next;
                }
                temp->next = newTask;
            }

            saveData();
            cout << "Task added Successfully." << endl;
            return;
        }
        else
        {
            cout << "User not found" << endl;
        }
    }
}

// Function to display all tasks of a user
void display(string username)
{
    if (head == NULL)
    {
        cout << "Directory is empty." << endl;
    }
    else
    {
        for (User *tempU = head; tempU != NULL; tempU = tempU->next)
        {
            if (tempU->Username == username)
            {
                int j = 1;
                if (tempU->taskHead != NULL)
                {
                    // Display all tasks of the user
                    for (Task *temp = tempU->taskHead; temp != NULL; temp = temp->next)
                    {
                        cout << "Task " << j << ": " << temp->description << endl;
                        j++;
                    }
                }
                else
                {
                    cout << "No Available Task." << endl;
                    break;
                }
                return;
            }
        }
    }
}

// Function to display the current task of a user
void displayCurrent(string username)
{
    if (head == NULL)
    {
        cout << "Directory is empty." << endl;
    }
    else
    {
        for (User *tempU = head; tempU != NULL; tempU = tempU->next)
        {
            if (tempU->Username == username)
            {
                if (tempU->taskHead == NULL)
                {
                    cout << "No Available Tasks." << endl;
                    break;
                }
                else
                {
                    cout << "Current Task: " << tempU->taskHead->description << endl;
                }
                return;
            }
        }
    }
}

// Function to mark the current task of a user as done
void markDone(string username)
{
    if (head == NULL)
    {
        cout << "Directory is empty." << endl;
    }
    else
    {
        for (User *tempU = head; tempU != NULL; tempU = tempU->next)
        {
            if (tempU->Username == username)
            {
                if (tempU->taskHead == NULL)
                {
                    cout << "No Task Available to mark as done." << endl;
                    break;
                }
                else
                {
                    cout << "Current Task: " << tempU->taskHead->description << " -> marked as Done." << endl;
                    tempU->taskHead = (tempU->taskHead)->next;
                    cout << "Done";
                    saveData();
                }
                return;
            }
        }
    }
}

// Function to export the to-do list of a user to a text file
void exportList(string username)
{
    fstream file;
    file.open(username + ".txt", ios::out);
    if (file.is_open())
    {
        file << "TO-DO LIST of " << username << endl;
        for (User *tempU = head; tempU != NULL; tempU = tempU->next)
        {
            if (tempU->Username == username)
            {
                int j = 1;
                // Write all tasks of the user to the file
                for (Task *temp = tempU->taskHead; temp != NULL; temp = temp->next)
                {
                    file << "Task " << j << ": " << temp->description << endl;
                    j++;
                }
                cout << "File Exported Successfully : " << username + ".txt" << endl;
                file.close();
                return;
            }
        }
    }
}

// Function to change the password of a user
void changePassword(string username, string password)
{
    for (User *tempU = head; tempU != NULL; tempU = tempU->next)
    {
        if (tempU->Username == username)
        {
            tempU->Password = password;
            saveData();
            break;
        }
    }
    return;
}

// Main function
int main()
{
    loadData(); // Load existing user data from file
    int choice;
    string username, password, taskdescription;
    bool loggedIn = false;

    // Display project information
    cout << "SKILL BASED MICRO PROJECT" << endl
         << "TO-DO LIST" << endl
         << "AKSHARA RATHORE (@itsAksharaRathore)"
         << "VAIBHAV SHARMA (@itsVaibhavSharma)" << endl;

    // Main menu loop
    while (true)
    {
        cout << endl
             << "1. Login" << endl
             << "2. Register" << endl
             << "3. Exit" << endl
             << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            cout << "Enter username: ";
            cin >> username;
            cout << "Enter Password: ";
            cin >> password;
            if (authUser(username, password))
            {
                loggedIn = true;
                cout << "Logged in Successfully." << endl;
                cout << endl
                     << "Welcome " << username << endl;
            }
            else
            {
                cout << "Invalid username or password." << endl;
            }
        }
        break;
        case 2:
            registerUser();
            break;
        case 3:
        {
            cout << endl
                 << "SKILL BASED MICRO PROJECT BY: " << endl
                 << "AKSHARA RATHORE (@itsAksharaRathore)" << endl
                 << "VAIBHAV SHARMA (@itsVaibhavSharma)" << endl
                 << endl
                 << "PROGRAM EXITED!!" << endl;
            saveData(); // Save all data before exiting
            return 0;
        }
        break;
        }

        // User's task management loop
        while (loggedIn)
        {
            int ch;
            cout << endl
                 << "1. Add Task" << endl
                 << "2. Display Tasks" << endl
                 << "3. Display current task" << endl
                 << "4. Mark current task as done" << endl
                 << "5. Export To-Do List" << endl
                 << "6. Change Password" << endl
                 << "7. Logout" << endl
                 << "Enter choice: ";
            cin >> ch;

            switch (ch)
            {
            case 1:
            {
                cout << "Enter Task Description: ";
                cin.ignore(); // Clear buffer
                getline(cin, taskdescription);
                addTask(username, taskdescription);
            }
            break;
            case 2:
                display(username);
                break;
            case 3:
                displayCurrent(username);
                break;
            case 4:
                markDone(username);
                break;
            case 5:
                exportList(username);
                break;
            case 6:
            {
                string pass;
                cout << "Enter old password: ";
                cin >> pass;
                if (authUser(username, pass))
                {
                    cout << "Enter new password: ";
                    cin >> password;
                    changePassword(username, password);
                    cout << "Password changed successfully." << endl;
                }
                else
                {
                    cout << "Invalid Password." << endl;
                }
            }
            break;
            case 7:
                loggedIn = false;
                cout << "Logged out successfully." << endl;
                break;
            }
        }
    }
    return 0;
}
