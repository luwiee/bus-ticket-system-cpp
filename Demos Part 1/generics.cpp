#include <iostream>
using namespace std;

template <typename T>
T add(T a, T b) {
    return a + b;
}

int main() {
    int x = 5, y = 10;
    double p = 3.5, q = 2.5;

    cout << "Sum of integers: " << add(x, y) << endl;
    cout << "Sum of doubles: " << add(p, q) << endl;

    return 0;
}
