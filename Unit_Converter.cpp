#include <iostream>
#include <iomanip>
using namespace std;

enum class AllUnits{Meter, Inch, Feet, Yard, Mile,
                    Kilogram, Pound, Stone, Ounce, Ton,
                    Litre, ImperialPint, ImperialQuart, ImperialGallon,
                    USPint, USQuart, USGallon,
                    Kelvin, Fahrenheit};
class UnitConverter {
public:
    virtual double convertToSi(double result, AllUnits unit) = 0;
    virtual double convertToIm(double result, AllUnits unit) = 0;
    virtual double convertToUs(double result, AllUnits unit) = 0;
};
class SIUnits : public UnitConverter {
public:
    double convertToSi(double result, AllUnits unit) override {return 0;}
    double convertToIm(double result, AllUnits unit) override {
        switch (unit)
        {
        case AllUnits::Inch :
            return result * 39.3701;
        case AllUnits::Feet :
            return result * 3.28084;
        case AllUnits::Yard :
            return result * 1.09361;
        case AllUnits::Mile :
            return result * 0.000621371;
        case AllUnits::Pound :
            return result * 2.20462;
        case AllUnits::Stone :
            return result * 0.157473;
        case AllUnits::Ounce :
            return result * 35.274;
        case AllUnits::Ton :
            return result * 0.001;
        case AllUnits::ImperialPint :
            return result * 1.75975;
        case AllUnits::ImperialQuart :
            return result * 0.879877;
        case AllUnits::ImperialGallon :
            return result * 0.219969;
        case AllUnits::Kelvin :         
            return (result - 273.15) * 9.0 / 5.0 + 32.0;
        default:
            throw runtime_error("Invalid unit conversion!");
        }
    };
    double convertToUs(double result, AllUnits unit) override {
        switch (unit)
        {
        case AllUnits::USPint :
            return result * 2.11338;
        case AllUnits::USQuart :
            return result * 1.05669;
        case AllUnits::USGallon :
            return result * 0.264172;
        case AllUnits::Fahrenheit :
            return (result - 273.15) * 9.0 / 5.0 + 32.0;
        default:
            throw runtime_error("Invalid unit conversion!");
        }
    }
};
class ImperialUnits : public UnitConverter {
public:
    double convertToIm(double result, AllUnits unit) override {return 0;}
    double convertToSi(double result, AllUnits unit) override {
        switch (unit)
        {
        case AllUnits::Inch :
            return result * 0.0254;
        case AllUnits::Feet :            
            return result * 0.3048;
        case AllUnits::Yard :            
            return result * 0.9144;
        case AllUnits::Mile :            
            return result * 1609.34;
        case AllUnits::Pound :           
            return result * 0.453592;
        case AllUnits::Stone :
            return result * 6.35029;
        case AllUnits::Ounce :
            return result * 0.0283495;
        case AllUnits::Ton :
            return result * 1000;
        case AllUnits::ImperialPint :
            return result * 0.568261;
        case AllUnits::ImperialQuart :
            return result * 1.136522;
        case AllUnits::ImperialGallon :
            return result * 4.54609;
        case AllUnits::Fahrenheit :
            return (5.0 / 9.0) * (result - 32) + 273.15;
        default:
            throw runtime_error("Invalid unit conversion!");
        }
    }
    double convertToUs(double result, AllUnits unit) override{
        switch (unit)
        {
        case AllUnits::USPint :
            return result * 1.20095;
        case AllUnits::USQuart :
            return result * 1.20095;
        case AllUnits::USGallon :
            return result * 1.20095;    
        default:
            throw runtime_error("Invalid unit conversion!");
        }
    }
};
class UsUnits : public UnitConverter {
public:
    double convertToUs(double result, AllUnits unit) override { return 0; } 
    double convertToSi(double result, AllUnits unit) override { 
        switch (unit)
        {
        case AllUnits::USPint :
            return result * 0.473176;
        case AllUnits::USQuart :
            return result * 0.946353;
        case AllUnits::USGallon :
            return result * 3.78541;
        default:
            throw runtime_error("Invalid unit conversion!");
        }
    }
    double convertToIm(double result, AllUnits unit) override {
        switch (unit)
        {
        case AllUnits::ImperialPint :
            return result * 0.832674;
        case AllUnits::ImperialQuart :
            return result * .832674;
        case AllUnits::ImperialGallon :
            return result * 0.832674;
        default:
            throw runtime_error("Invalid unit conversion!");
        }
    }
};
class Display : public SIUnits , public ImperialUnits, public UsUnits{
public:
    int unit, unitSystem, unitType;
    double magnitude;

    string si[4]  ={" meters", " kilograms", " liters" , " Kelvin"};
    string im[12] ={" inches", " feet"     , " yards"  , " miles",
                    " pounds", " stones"   , " ounce"  , " tons" ,
                    " pints" , " quarts"   , " gallons", " Fahrenheit"};
    
    SIUnits siUnits;
    ImperialUnits imUnits;
    UsUnits usUnits;

    void display(int unitsystem, int unit){
    this->unit = unit;
    this->unitSystem = unitsystem;

    cout << fixed << setprecision(2);

    if (unitSystem == 1)
    {
        switch (unit)
        {
        case 1:
            cout << "Enter the magnitude for Meters(m): ";
            cin >> magnitude;

            cout<< "The equivalent of  " << magnitude << si[0] << " for both Imperial Unit System and US Customary System: " << endl;
            cout<< siUnits.convertToIm(magnitude, AllUnits::Inch) << im[0] << '\n'
                << siUnits.convertToIm(magnitude, AllUnits::Feet) << im[1] << '\n'
                << siUnits.convertToIm(magnitude, AllUnits::Yard) << im[2] << '\n'
                << siUnits.convertToIm(magnitude, AllUnits::Mile) << im[3] << endl;
            break;
        case 2:
            cout << "Enter the magnitude for Kilograms(kg): ";
            cin >> magnitude;

            cout<< "The equivalent of  " << magnitude << si[1] << " for both Imperial Unit System and US Customary System: " << endl;
            cout<< siUnits.convertToIm(magnitude, AllUnits::Pound) << im[4] << '\n'
                << siUnits.convertToIm(magnitude, AllUnits::Stone) << im[5] << '\n'
                << siUnits.convertToIm(magnitude, AllUnits::Ounce) << im[6] << '\n'
                << siUnits.convertToIm(magnitude, AllUnits::Ton)   << im[7] << endl;
            break;
        case 3:
            cout << "Enter the magnitude for Liters(l): ";
            cin >> magnitude;

            cout<< "The equivalent of  " << magnitude << si[2] << " for Imperial Unit System : " << endl;
            cout<< siUnits.convertToIm(magnitude, AllUnits::ImperialPint)   << im[8]  << '\n'
                << siUnits.convertToIm(magnitude, AllUnits::ImperialQuart)  << im[9]  << '\n'
                << siUnits.convertToIm(magnitude, AllUnits::ImperialGallon) << im[10] << endl << endl;
            cout<< "US Customary System: " << endl;
            cout<< siUnits.convertToUs(magnitude, AllUnits::USPint)         << im[8]  << '\n'
                << siUnits.convertToUs(magnitude, AllUnits::USQuart)        << im[9]  << '\n'
                << siUnits.convertToUs(magnitude, AllUnits::USGallon)       << im[10] << endl;
            break;
        case 4:
            while (true){
                cout<< "Enter the magnitude for Kelvin(K°): ";
                cin >> magnitude;
                if (magnitude >= 0)
                {
                    cout<< "The equivalent of " << magnitude << " " << si[3] << " for SI Unit System:" << endl;
                    cout << siUnits.convertToIm(magnitude, AllUnits::Kelvin) << " " << im[11] << endl;
                    break;
                }else{
                    cout << "You can not enter negative value for K°, please enter a valid number:"<< endl;
                }
            }
            break;
        default:
            cout << "invalid unit type!";
        }
    }
    else if (unitSystem == 2)
    {
        if (unit == 1)
        {
            cout << "Select the unit type you want to convert: " << endl;
            cout << "1: inch\n2: feet\n3: yard\n4: mile" << endl;
            cin  >> unitType;

            switch (unitType)
            {
            case 1:
                cout << "Enter the magnitude for inches: ";
                cin >> magnitude;

                cout << "The equivalent of " << magnitude << im[0] << " for SI Unit System: ";
                cout << imUnits.convertToSi(magnitude, AllUnits::Inch) << si[0] << endl;
                break;
            case 2:
                cout << "Enter the magnitude for feet: ";
                cin >> magnitude;

                cout << "The equivalent of " << magnitude << im[1] << " for SI Unit System: ";
                cout << imUnits.convertToSi(magnitude, AllUnits::Feet) << si[0] << endl;
                break;
            case 3:
                cout << "Enter the magnitude for yards: ";
                cin >> magnitude;

                cout << "The equivalent of " << magnitude << im[2] << " for SI Unit System: ";
                cout << imUnits.convertToSi(magnitude, AllUnits::Yard) << si[0] << endl;
                break;
            case 4:
                cout << "Enter the magnitude for miles: ";
                cin >> magnitude;

                cout << "The equivalent of " << magnitude << im[3] << " for SI Unit System: ";
                cout << imUnits.convertToSi(magnitude, AllUnits::Mile) << si[0] << endl;
                break;

            default:
                cout<< "Invalid unit type!" << endl;
                break;
            } 
        }
        else if (unit == 2)
        {
            cout << "Select the unit type you want to convert: " << endl;
            cout << "1: pound\n2: stone\n3: oz\n4: ton" << endl;
            cin  >> unitType;

            switch (unitType)
            {
            case 1:
                cout<< "Enter the magnitude for pounds(lb): ";
                cin >> magnitude;

                cout<< "The equivalent of " << magnitude << im[4] << " for SI Unit System: ";
                cout << imUnits.convertToSi(magnitude, AllUnits::Pound) << si[1] << endl;
                break;
            case 2:
                cout<< "Enter the magnitude for stones: ";
                cin >> magnitude;

                cout<< "The equivalent of " << magnitude << im[5] << " for SI Unit System: ";
                cout << imUnits.convertToSi(magnitude, AllUnits::Stone) << si[1] << endl;
                break;
            case 3:
                cout<< "Enter the magnitude for ounce(oz): ";
                cin >> magnitude;

                cout<< "The equivalent of " << magnitude << im[6] << " for SI Unit System: ";
                cout << imUnits.convertToSi(magnitude, AllUnits::Ounce) << si[1] << endl;
                break;
            case 4:
                cout<< "Enter the magnitude for tons: ";
                cin >> magnitude;

                cout<< "The equivalent of " << magnitude << im[7] << " for SI Unit System: ";
                cout << imUnits.convertToSi(magnitude, AllUnits::Ton) << si[1] << endl;
                break;
            default:
                cout<< "Invalid unit type!" << endl;
                break;
            }
        }
        else if (unit == 3)
        {
            cout << "Select the unit type you want to convert: " << endl;
            cout << "1: pint\n2: quart\n3: gallon" << endl;
            cin  >> unitType;

            switch (unitType)
            {
            case 1:
                cout<< "Enter the magnitude for pints: ";
                cin >> magnitude;

                cout<< "The equivalent of " << magnitude << im[8] << " for SI Unit System: ";
                cout<< imUnits.convertToSi(magnitude, AllUnits::ImperialPint) << si[2] << "\n\n"
                    << "US Customary System: " << endl;
                cout<< imUnits.convertToUs(magnitude, AllUnits::USPint) << im[8] << endl;
                break;
            case 2:
                cout<< "Enter the magnitude for quarts: ";
                cin >> magnitude;

                cout<< "The equivalent of " << magnitude << im[9] << " for SI Unit System: ";
                cout<< imUnits.convertToSi(magnitude, AllUnits::ImperialQuart) << si[2] << "\n\n"
                    << "US Customary System: " << endl;
                cout<< imUnits.convertToUs(magnitude, AllUnits::USQuart) << im[9] << endl;
                break;
            case 3:
                cout<< "Enter the magnitude for gallons: ";
                cin >> magnitude;

                cout<< "The equivalent of " << magnitude << im[10] << " for SI Unit System: ";
                cout<< imUnits.convertToSi(magnitude, AllUnits::ImperialGallon) << si[2] << "\n\n"
                    << "US Customary System: " << endl;
                cout<< imUnits.convertToUs(magnitude, AllUnits::USGallon) << im[10] << endl;
                break;
            default:
            cout << "invalid unit type!";
                break;
            }
        }
        else if (unit == 4)
        {
            while (true){
                cout<< "Enter the magnitude for Fahrenheit(F°): ";
                cin >> magnitude;
                if (magnitude > -459.67)
                {
                    cout<< "The equivalent of " << magnitude << " " << im[11] << " for SI Unit System:" << endl;
                    cout << imUnits.convertToSi(magnitude, AllUnits::Fahrenheit) << " " << si[3] << endl;
                    break;
                }else{
                    cout << "You can not enter a value below -459.67 for F°, please enter a valid number:"<< endl;
                }
            }
        }
    }
    else if (unitSystem == 3)
    {
        if (unit == 1)
        {
            cout << "Select the unit type you want to convert: " << endl;
            cout << "1: inch\n2: feet\n3: yard\n4: mile" << endl;
            cin  >> unitType;

            switch (unitType)
            {
            case 1:
                cout << "Enter the magnitude for inches: ";
                cin >> magnitude;

                cout << "The equivalent of " << magnitude << im[0] << " for SI Unit System: ";
                cout << imUnits.convertToSi(magnitude, AllUnits::Inch) << si[0] << endl;
                break;
            case 2:
                cout << "Enter the magnitude for feet: ";
                cin >> magnitude;

                cout << "The equivalent of " << magnitude << im[1] << " for SI Unit System: ";
                cout << imUnits.convertToSi(magnitude, AllUnits::Feet) << si[0] << endl;
                break;
            case 3:
                cout << "Enter the magnitude for yards: ";
                cin >> magnitude;

                cout << "The equivalent of " << magnitude << im[2] << " for SI Unit System: ";
                cout << imUnits.convertToSi(magnitude, AllUnits::Yard) << si[0] << endl;
                break;
            case 4:
                cout << "Enter the magnitude for miles: ";
                cin >> magnitude;

                cout << "The equivalent of " << magnitude << im[3] << " for SI Unit System: ";
                cout << imUnits.convertToSi(magnitude, AllUnits::Mile) << si[0] << endl;
                break;

            default:
                cout<< "Invalid unit type!" << endl;
                break;
            } 
        }
        else if (unit == 2)
        {
            cout << "Select the unit type you want to convert: " << endl;
            cout << "1: pound\n2: stone\n3: oz\n4: ton" << endl;
            cin  >> unitType;

            switch (unitType)
            {
            case 1:
                cout<< "Enter the magnitude for pounds(lb): ";
                cin >> magnitude;

                cout<< "The equivalent of " << magnitude << im[4] << " for SI Unit System: ";
                cout << imUnits.convertToSi(magnitude, AllUnits::Pound) << si[1] << endl;
                break;
            case 2:
                cout<< "Enter the magnitude for stones: ";
                cin >> magnitude;

                cout<< "The equivalent of " << magnitude << im[5] << " for SI Unit System: ";
                cout << imUnits.convertToSi(magnitude, AllUnits::Stone) << si[1] << endl;
                break;
            case 3:
                cout<< "Enter the magnitude for ounce(oz): ";
                cin >> magnitude;

                cout<< "The equivalent of " << magnitude << im[6] << " for SI Unit System: ";
                cout << imUnits.convertToSi(magnitude, AllUnits::Ounce) << si[1] << endl;
                break;
            case 4:
                cout<< "Enter the magnitude for tons: ";
                cin >> magnitude;

                cout<< "The equivalent of " << magnitude << im[7] << " for SI Unit System: ";
                cout << imUnits.convertToSi(magnitude, AllUnits::Ton) << si[1] << endl;
                break;
            default:
                cout<< "Invalid unit type!" << endl;
                break;
            }
        }
        else if (unit == 3)     
        {
            cout << "Select the unit type you want to convert: " << endl;
            cout << "1: pint\n2: quart\n3: gallon"<< endl;
            cin >> unitType;

            switch (unitType)
            {
            case 1:
            cout<< "Enter the magnitude for pint: ";
            cin >> magnitude;

            cout<< "The equivalent of " << magnitude << im[8] << " for SI Unit System: " << endl;
            cout<< usUnits.convertToSi(magnitude, AllUnits::USPint) << si[2] << "\n\n"
                << "Imperial Unit System: " << '\n'
                << usUnits.convertToIm(magnitude, AllUnits::ImperialPint) << im[8] << endl; 
                break;
            case 2:
            cout<< "Enter the magnitude for quart: ";
            cin >> magnitude;

            cout<< "The equivalent of " << magnitude << im[9] << " for  SI Unit System: " << endl;
            cout<< usUnits.convertToSi(magnitude, AllUnits::USQuart) << si[2] << "\n\n"
                << "Imperial Unit System: " << '\n'
                << usUnits.convertToIm(magnitude, AllUnits::ImperialQuart) << im[9] << endl; 
                break;
            case 3:
            cout<< "Enter the magnitude for gallons: ";
            cin >> magnitude;

            cout<< "The equivalent of " << magnitude << im[10] << " for  SI Unit System: " << endl;
            cout<< usUnits.convertToSi(magnitude, AllUnits::USGallon) << si[2] << "\n\n"
                << "Imperial Unit System: " << '\n'
                << usUnits.convertToIm(magnitude, AllUnits::ImperialGallon) << im[10] << endl; 
                break;
            default:
                cout<< "Invalid unit type!" << endl;
                break;
            }
        }
        else if (unit == 4)
        {
            while (true){
                cout<< "Enter the magnitude for Fahrenheit(F°): ";
                cin >> magnitude;
                if (magnitude > -459.67)
                {
                    cout<< "The equivalent of " << magnitude << " " << im[11] << " for SI Unit System:" << endl;
                    cout << imUnits.convertToSi(magnitude, AllUnits::Fahrenheit) << " " << si[3] << endl;
                    break;
                }else{
                    cout << "You can not enter a value below -459.67 for F°, please enter a valid number:"<< endl;
                }
            }
        }
    }
    else{
        cout << "Invalid entry!!" << endl;
        }
    }
};
int main()
{
    int unitSystem, unit;

    Display display;

    cout << endl;
    cout << "Which system do you use: " << endl;
    cout << "1: SI Unit System\n2: Imperial Unit System\n3: American Unit System" << endl;
    cin >> unitSystem;

    cout << "What would you like to convert? " << endl;
    cout << "1: Length\n2: Mass\n3: Volume\n4: Temperature" << endl;
    cin >> unit;

    display.display(unitSystem, unit);
    return 0;
}