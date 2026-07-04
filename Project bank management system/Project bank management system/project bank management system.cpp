#include <iostream>
#include <vector>
#include <string>
using namespace std;

class User {

protected:

    string username;
    string password;

public:

    User(string uname, string pass)
    {
        username = uname;
        password = pass;
    }

    virtual bool login(string uname, string pass)
    {
        return (uname == username && pass == password);
    }
    virtual void showMenu() = 0; 
};


class Customer : public User {
public:
    Customer(string uname, string pass) : User(uname, pass)
    {
    };
    
    void showMenu() override 
    
    {
        cout << "Customer Menu" << endl;
        cout << "1. View Balance" << endl;
        cout << "2. Deposit Money" << endl;
        cout << "3. Withdraw Money"<<endl;
        cout << "4. Logout" << endl;
    }
};


class Admin : public User 
{
public:
    Admin(string uname, string pass) : User(uname, pass) {}
    
    void showMenu() override 
    {
        cout << "Admin Menu: " << endl;;
        cout << "1. View All Customers" << endl;
        cout << "2. Manage Accounts" << endl;
        cout << "3. Logout" << endl;
    }
};


class BankSystem 

{
    vector<Customer> customers;
    Admin admin;

public:
    BankSystem() : admin("admin", "admin1235") 
    {
        
        customers.push_back(Customer("abdul Wahab", "aw12345"));
        customers.push_back(Customer("mohid", "mohid12345"));
    }

    void start() {
        int choice;
        while (true) 
        {
            cout << "1. Admin Login" << endl;
            cout << "2. Customer Login" << endl;
            cout << "3. Exit" << endl;
            cout << "Choose option : " << endl;
            cin >> choice;
            
            if (choice == 1) 
            {
                handleLogin(&admin);
            }
            else if (choice == 2) 
            
            {
                string uname, pass;
                cout << "Enter Customer Username: " << endl;
                cin >> uname;
                cout << "Enter Password: " << endl;
                cin >> pass;
                bool found = false;
                for (auto& cust : customers) 
                {
                    if (cust.login(uname, pass)) 
                    
                    {
                        cout << "Login Successful" << endl;;
                        cust.showMenu();
                        found = true;
                        break;
                    }
                }
                if (!found) cout << "Invalid customer credentials." << endl;
            }
            else if (choice == 3) {
                break;
            }
            else {
                cout << "Invalid option." << endl;
            }
        }
    }

    void handleLogin(User* user) 
    
    {
        string uname, pass;
        
        cout << "Enter Username: " << endl;
        cin >> uname;
        cout << "Enter Password: " << endl;
        cin >> pass;
        if (user->login(uname, pass)) 
        {
            cout << "Login Successful!" << endl;
            user->showMenu(); 
        }
        else 
        {
            cout << "Login Failed!" << endl;
        }
    }
};
int main() {
    BankSystem bank;
    bank.start();
    return 0;
}
