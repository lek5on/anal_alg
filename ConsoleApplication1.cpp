
#include <iostream>
#include <fstream>
using namespace std;


int main() {
    setlocale(LC_ALL,"RU");
    ofstream outfile("result.txt");
    if (!outfile)
    {
        cerr << oshibka pri otritie faila" << endl;
        return 1;
    }
    int max_n = 30;
    int step = 2;
    int size = (max_n / step);
    int* results = new int[size];
    int index = 0;
    for (int n = 2; n <= max_n; n += step) {
        int** matrix = new int* [n];               
        int* vector = new int[n];                 
        int operations = 0;
        for (int i = 0; i < n; i++) {
            matrix[i] = new int[n];
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                matrix[i][j] = 1;
                operations++;
            }
        }


        for (int i = 0; i < n; i++) {
            vector[i] = 2;
            operations++;
        }

        for (int i = 0; i < n; i++) {               
            for (int j = 0; j < n; j++) {
                matrix[i][j] *= vector[i];
                operations+=2;
            }
        }
        for (int i = 0; i < n; i++)
        {
            vector[i] = 0;  
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                vector[i] += matrix[i][j];         
                operations+=2;
            }
        }
        results[index] = operations;
        index++;
    }
    cout << endl;
    for (int i = 0, n = 2; i < size; i++, n += step) {
        outfile << results[i] << " ";
    }
    cout << endl;
}
