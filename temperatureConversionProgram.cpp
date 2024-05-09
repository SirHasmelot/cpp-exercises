#include <iostream>     //temperature conversion program
using namespace std;

int main(){

    char unit;
    double value;
    bool choice = false;

    cout << "*****   Temperature converter   *****" << endl << endl;

    while(true){
        cout << "Enter the temperature unit you want to convert\n(F for Fahrenheit, C for Celcius, Q to quit): ";
        cin >> unit;

        if (unit == 'q' || unit == 'Q')
        {
            cout << "Good Day!!";
            break;
        }

        else;
        {
        cout << "Enter the temperature value: ";
        cin >> value;

        switch (unit)
        {
        case 'c':
        case 'C':
            choice = true;
            value = (1.8 * value) + 32.0;
            cout << "The Fahrenheit equivalent is: " << value << "°F." << endl;
            break;
        
        case 'f':
        case 'F':
            choice = true;
            value = (value - 32)/1.8;
            cout << "The Celcius equivalent is: " << value << "°C." << endl;
            break;
        
        default:
            cout << "Please select one of the followings: 'F' or 'C'! " << endl;
            continue;
        }
        }
    }

    return 0;
}

