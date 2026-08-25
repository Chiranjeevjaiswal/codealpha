#include <iostream>
#include <fstream>
using namespace std;

// Registration function
void registration()
{
    string username, password;

    cout << "\n--- Registration ---" << endl;

    cout << "Enter username: ";
    cin >> username;

    cout << "Enter password: ";
    cin >> password;

    // Open file
    ofstream file("users.txt", ios::app);

    file << username << " " << password << endl;

    file.close();

    cout << "Registration successful!" << endl;
}

// Login function
void login()
{
    string username, password;
    string user, pass;
    bool loginSuccess = false;

    cout << "\n--- Login ---" << endl;

    cout << "Enter username: ";
    cin >> username;

    cout << "Enter password: ";
    cin >> password;

    // Open file
    ifstream file("users.txt");

    // Read username and password from file
    while (file >> user >> pass)
    {
        if (username == user && password == pass)
        {
            loginSuccess = true;
            break;
        }
    }

    file.close();

    if (loginSuccess)
    {
        cout << "Login successful!" << endl;
        cout << "Welcome, " << username << "!" << endl;
    }
    else
    {
        cout << "Invalid username or password!" << endl;
    }
}

int main()
{
    int choice;

    while (true)
    {
        cout << "\n===== LOGIN SYSTEM =====" << endl;
        cout << "1. Register" << endl;
        cout << "2. Login" << endl;
        cout << "3. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            registration();
        }
        else if (choice == 2)
        {
            login();
        }
        else if (choice == 3)
        {
            cout << "Program ended." << endl;
            break;
        }
        else
        {
            cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}
