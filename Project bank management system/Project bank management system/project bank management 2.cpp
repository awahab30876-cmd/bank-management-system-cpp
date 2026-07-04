#include <iostream>
#include <vector>
#include <string>
using namespace std;

class User 

{

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

class Customer : public User 
{

private:
    
    float balance;

public:
    
    Customer(string uname, string pass) : User(uname, pass), balance(0.0f) 
    {
    }

    void deposit(float amount) 
    {
        if (amount > 0) 
        
        {
            balance += amount;
            cout << "Amount deposited successfully. New balance: " << balance << endl;
        }
        else 
        
        {
            cout << "Invalid amount." << endl;
        }
    }

    void withdraw(float amount) 
    {
        if (amount > 0 && amount <= balance) 
        
        {
            balance -= amount;
            cout << "Amount withdrawn successfully. New balance: " << balance << endl;
        }
        else 
        {
            cout << "Invalid amount or insufficient balance" << endl;
        }
    }

    void showMenu() override 
    
    {
        int option;
        do {
            cout << "Customer Menu:"<<endl;
            cout << "1. View Balance"<<endl;
            cout << "2. Deposit Money"<<endl;
            cout << "3. Withdraw Money" << endl;
            cout << "4. Logout"<<endl;
            cout << "Choose option: " << endl;
            cin >> option;

            if (option == 1) 
            {
                cout << "Your current balance is: " << balance << endl;
            }
            else if (option == 2) 
            {
                float amount;
                cout << "Enter the amount you want to deposit: " << endl;
                cin >> amount;
                deposit(amount);
            }
            else if (option == 3) 
            {
                float amount;
                cout << "Enter the amount you want to withdraw: "<<endl;
                cin >> amount;
                withdraw(amount);
            }
            else if (option == 4) 
            {
                cout << "Logging out..."<<endl;
            }
            else {
                cout << "Invalid option."<<endl;
            }
        } while (option != 4);
    }
};

class Admin : public User 

{

public:
    Admin(string uname, string pass) : User(uname, pass) 
    {
    }

    void showMenu() override 
    {
        cout << "Admin Menu:"<<endl;
        cout << "1. View All Customers"<<endl;
        cout << "2. Manage Accounts"<<endl;
        cout << "3. Logout"<<endl;
    }
};

class BankSystem 
{
    vector<Customer> customers;
    Admin admin;

public:
    
    BankSystem()  : admin("admin", "admin1235")
    {
        customers.push_back(Customer("wahab", "aw12345"));
        customers.push_back(Customer("mohid", "mohid12345"));
    }

    void main_menu() 
    
    {
        int choice;
        while (true) {
            cout << "1. Admin Login" << endl;
            cout << "2. Customer Login" << endl;
            cout<< "3.Exit" << endl;
            cout << "Choose option : " << endl;
            cin >> choice;

            if (choice == 1) 
            {
                Login_system(&admin);
            }
            else if (choice == 2) 
            {
                string uname, pass;
                cout << "Enter Customer Username: " << endl;
                cin >> uname;
                cout << "Enter Password: ";
                cin >> pass;
                bool found = false;
                for (auto& cust : customers) 
                {
                    if (cust.login(uname, pass)) 
                    {
                        cout << "Login Successful"<<endl;
                        cust.showMenu();
                        found = true;
                        break;
                    }
                }
                if (!found)
                    cout << "Invalid customer credentials."<<endl;
            }
            else if (choice == 3) {
                cout << "Exiting..."<<endl;
                break;
            }
            else {
                cout << "Invalid option."<<endl;
            }
        }
    }

    void Login_system(User* user) 
    {
        string uname, pass;
        cout << "Enter Username: "<<endl;
        cin >> uname;
        cout << "Enter Password: "<<endl;
        cin >> pass;
        if (user->login(uname, pass)) 
        {
            cout << "Login Successful!"<<endl;
            user->showMenu();
        }
        else 
        {
            cout << "Login Failed!"<<endl;
        }
    }
};

int main() 
{
    BankSystem bank;
    bank.main_menu();
    
    
    return 0;
}
