
#include<iostream>
#include<fstream>
#include<string>

using namespace std;

void registerUser()
{
    string username, password;

    cout << "\n===== USER REGISTRATION =====\n";

    cout << "Enter Username: ";
    cin >> username;

    cout << "Enter Password: ";
    cin >> password;

    // Create file for user
    ofstream file((username + ".txt").c_str());

    if(file.is_open())
    {
        file << username << endl;
        file << password << endl;

        file.close();

        cout << "\nRegistration Successful!\n";
    }
    else
    {
        cout << "\nError Creating File!\n";
    }
}

void loginUser()
{
    string username, password;
    string storedUsername, storedPassword;

    cout << "\n===== USER LOGIN =====\n";

    cout << "Enter Username: ";
    cin >> username;

    cout << "Enter Password: ";
    cin >> password;

    // Open file
    ifstream file((username + ".txt").c_str());

    if(file.is_open())
    {
        getline(file, storedUsername);
        getline(file, storedPassword);

        file.close();

        if(username == storedUsername && password == storedPassword)
        {
            cout << "\nLogin Successful!\n";
            cout << "Welcome " << username << "!\n";
        }
        else
        {
            cout << "\nIncorrect Password!\n";
        }
    }
    else
    {
        cout << "\nUser Not Found!\n";
    }
}

int main()
{
    int choice;

    do
    {
        cout << "\n========== MENU ==========\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";

        cout << "Enter Choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                registerUser();
                break;

            case 2:
                loginUser();
                break;

            case 3:
                cout << "\nProgram Exited.\n";
                break;

            default:
                cout << "\nInvalid Choice!\n";
        }

    } while(choice != 3);

    return 0;
}

