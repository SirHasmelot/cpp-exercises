//banking account

#include <iostream>    
using namespace std;

void showBalance(double balance){
    cout << "Your current balance is: $" << balance << " dollars." << endl << endl;
};

void deposit(double* balance){
    double amount = 0;
    cout << "Enter the value that you want to deposit: ";
    cin >> amount;

    if (amount >0)
    {
        *balance =  *balance + amount;
        cout << "New balance is: $" << *balance << " dollars." << endl << endl;
    }
    else{
        cout << "That's not a valid amount!" << endl;
    }
};

void withdraw(double* balance){
    double amount = 0;
    cout << "Enter the value that you want to withdraw: ";
    cin >> amount;

    if (amount > *balance)
    {
        cout << "Insufficient funds!!" << endl;
    }
    else if (amount < 0)
    {
        cout << "That's not a valid amaount!!" << endl;
    }
    else{
    *balance = *balance - amount;
    cout << "New balance is: $" << *balance << " dollars." << endl;
    }
};

int main(){

    double balance = 0;
    int choice;

    do{
    cout << "———————————————" << endl;
    cout << "Enter the number of your choice: " << endl;
    cout << "———————————————" << endl;
    cout << "1. Display Balance" << endl;
    cout << "2. Deposit" << endl;
    cout << "3. Withdraw" << endl;
    cout << "4. Exit" << endl;
    cin >> choice;

    switch (choice){
    case 1:
        showBalance(balance);
        break;
    case 2:
        deposit(&balance);
        break;
    case 3:
        withdraw(&balance);
        break;
    case 4:
        cout << "Thanks for visiting!!" << endl;
        break;
    default:
        cout << "Invalid choice!!" << endl;
        break;
    }
    }while (choice !=4);

    return 0;
}