#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int ROWS = 5;
const int COLS = 4;

void fillArray(double arr[ROWS][COLS]) {
    srand(time(0));
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            arr[i][j] = (rand() % 100) / 10.0;
        }
    }
}

void printArray(double arr[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
}

int findMaxRow(double arr[ROWS][COLS]) {
    int maxRow = 0;
    double maxVal = arr[0][0];

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (arr[i][j] > maxVal) {
                maxVal = arr[i][j];
                maxRow = i;
            }
        }
    }
    return maxRow;
}

double avgEvenColumns(double arr[ROWS][COLS]) {
    double sum = 0;
    int count = 0;

    for (int j = 0; j < COLS; j += 2) {
        for (int i = 0; i < ROWS; i++) {
            sum += arr[i][j];
            count++;
        }
    }
    return (count > 0) ? sum / count : 0;
}

int main() {
    double array[ROWS][COLS];

    fillArray(array);

    cout << "Two-dimensional array:\n";
    printArray(array);

    int maxRow = findMaxRow(array);
    double avg = avgEvenColumns(array);

    cout << "Row with the maximum element: " << maxRow + 1 << endl;
    cout << "Average of elements in even columns: " << avg << endl;

    return 0;
}
