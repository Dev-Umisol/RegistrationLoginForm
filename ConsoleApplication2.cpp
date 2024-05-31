// Simple User Registration and Login form to get a better understanding of C++.

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class User {
    private:
        string username;
        string password;

    public:
        User(string name, string pass) {
            username = name;
            password = pass;
        }

    string getUsername() {
        return username;
    }

    string getPassword() {
        return password;
    }
};

class UserManager {
    private:
        vector<User> users; //create object of vector

    public:
        void RegisterUser() {
            string username;
            string password;

            cout << "\t\tEnter Username: ";
            cin >> username;

            cout << "\t\tEnter Password: ";
            cin >> password;

            User newUser(username, password);
            users.push_back(newUser); //push_back inserts a new element at the back

            cout << "\t\tUser Registered Successfully" << endl;
        }

        //for all users, if username and password is correct then login is successfull
        bool UserLogin(string name, string pass) {
            for (int i = 0; i < users.size(); i++) {
                if (users[i].getUsername() == name && users[i].getPassword() == pass) {
                    cout << "\t\tLogin Successfully" << endl;

                    return true;
                }
            }

            cout << "\t\tInvalid Username or Password" << endl;

            return false;
        }

        //loop through all users and grab usernames
        void ShowUserList() {
            cout << "\t\t---User List---" << endl;

            for (int i = 0; users.size(); i++) {
                cout << "\t\t" << users[i].getUsername() << endl;
            }
        }

        //for all users, grab specific user that is being searched
        void SearchUser(string username) {
            for (int i = 0; i < users.size(); i++) {
                if (users[i].getUsername() == username) {
                    cout << "\t\t User Found" << endl;
                }
            }
        }

        //for all users, if the username matches the to be deleted username then erase.
        void DeleteUser(string username) {
            for (int i = 0; i < users.size(); i++) {
                if (users[i].getUsername() == username) {
                    users.erase(users.begin() + i); //.begin is used to return an iterator point to the first element. + i loops through all the elements

                    cout << "\t\tUser Removed Successfully" << endl;
                }
            }
        }
};

int main() {
    UserManager userManage;

    int options;

    char choice;

    do {
        system("cls");
        cout << "\n\n\t\t1. Register User" << endl;
        cout << "\t\t2. Login" << endl;
        cout << "\t\t3. Show User List" << endl;
        cout << "\t\t4. Search User" << endl;
        cout << "\t\t5. Delete User" << endl;
        cout << "\t\t6. Exit" << endl;
        cout << "\t\tEnter your choice: ";
        cin >> options;

        switch (options) {
        case 1: {
            userManage.RegisterUser();
            break;
            }
                
        case 2: {
            string username;
            string password;

            cout << "\t\tEnter Username: ";
            cin >> username;

            cout << "\t\tEnter Password: ";
            cin >> password;

            userManage.UserLogin(username, password);
            break;
            }
                
        case 3: {
            userManage.ShowUserList();
            break;
            }

        case 4: {
            string username;

            cout << "\t\tEnter Username: ";
            cin >> username;

            userManage.SearchUser(username);
            break;
            }

        case 5: {
            string username;

            cout << "\t\tEnter Username to Delete: ";
            cin >> username;

            userManage.DeleteUser(username);
            break;
            }

        case 6: {
            exit(1);
            }
        }

        cout << "\t\tDo you want to continue? [Y/N]?: ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');
}