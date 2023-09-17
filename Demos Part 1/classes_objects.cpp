#include <iostream>
using namespace std;

class Division {
public:
    double numerator;
    double denominator;

    double divide() {
        try {
            if (denominator == 0) {
                throw 0; // Throw an exception if denominator is zero
            }

            double answer = numerator / denominator;
            cout << "Answer: " << numerator << "/" << denominator << " is " << answer << endl;

        }
        catch (int num_exception) {
            cout << "Invalid! Denominator cannot be " << num_exception << endl;
        }
        return 0;
    }
};

int main() {
    int num1, num2;

    cout << "Enter the numerator: ";
    cin >> num1;
    cout << "\nEnter the denominator: ";
    cin >> num2;

    Division div1;
    div1.numerator = num1;
    div1.denominator = num2;

    cout << div1.divide() << endl; // Call the divide method and display the result
    return 0;
}

