#include <iostream>
using namespace std;

int main() {
	string first_name;
	int age;

	cout << "Your name: ";  // Prompt for name
	cin >> first_name;
	cout << "Your age: ";   // Prompt for age
	cin >> age;

	if (age < 18) {
		cout << "Response: Must be 18+ to drink.";
	}
	else {
		cout << "Response: " << first_name << " can drink.";
	}

	return 0;
}
