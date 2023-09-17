#include <iostream>
using namespace std;

void add(int arr[], int max) {
	int answer = 0;  // Initialize answer to zero
	for (int i = 0; i < max; i++) {
		answer += arr[i];  // Accumulate sum
	}
	cout << "Sum: " << answer;
}

int main() {
	int max_length;

	cout << "How many numbers to add: ";
	cin >> max_length;

	int numbers[max_length];  // Declare an array
	int input;

	for (int i = 0; i < max_length; i++) {
		cout << "Enter a number: ";
		cin >> input;
		numbers[i] = input;  // Store input in the array
	}

	add(numbers, max_length);  // Call the add function
	return 0;
}
