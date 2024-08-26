#include <iostream>
using namespace std;

void MaxMin(int x[], int i, int j, int &max, int &min) {
    if (i == j) {
        // Case when there's only one element
        max = min = x[i];
    } else if (i == j - 1) {
        // Case when there are two elements
        if (x[i] < x[j]) {
            max = x[j];
            min = x[i];
        } else {
            max = x[i];
            min = x[j];
        }
    } else {
        // Case when there are more than two elements
        int mid = (i + j) / 2;
        int max1, min1;
        // Recursively find the max and min in the left half
        MaxMin(x, i, mid, max, min);
        // Recursively find the max and min in the right half
        MaxMin(x, mid + 1, j, max1, min1);
        // Combine the results
        if (max < max1) {
            max = max1;
        }
        if (min > min1) {
            min = min1;
        }
    }
}

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    int x[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    int max, min;
    // Call MaxMin function for the entire array
    MaxMin(x, 0, n - 1, max, min);

    cout << "Maximum element: " << max << endl;
    cout << "Minimum element: " << min << endl;

    return 0;
}
