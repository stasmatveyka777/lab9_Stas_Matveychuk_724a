#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int ROWS = 5;
const int COLS = 6;

void fillArray(int arr[ROWS][COLS]) {
    srand(time(0));
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            arr[i][j] = rand() % 10 - 2;
        }
    }
}

void printArray(int arr[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
}

int countNonZeroRows(int arr[ROWS][COLS]) {
    int count = 0;
    for (int i = 0; i < ROWS; i++) {
        bool hasZero = false;
        for (int j = 0; j < COLS; j++) {
            if (arr[i][j] == 0) {
                hasZero = true;
                break;
            }
        }
        if (!hasZero) {
            count++;
        }
    }
    return count;
}

int main() {
    int array[ROWS][COLS];

    fillArray(array);

    cout << "Matrix:\n";
    printArray(array);

    int nonZeroRows = countNonZeroRows(array);

    cout << "Number of rows without zero elements: " << nonZeroRows << endl;

    return 0;
}
