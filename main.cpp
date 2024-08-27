#include<iostream>
using namespace std;

void input_matrix(int m, int n, int arr[100][100]) {
    cout << "Enter the matrix of " << m << "x" << n << " order :" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
}

void output_matrix(int m, int n, int arr[100][100]) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void row_echelon_form(int m, int n, int arr[100][100]) {// Function to convert matrix to Row Echelon Form
    int lead = 0;
    for (int r = 0; r < m; r++) {
        if (lead >= n) {
            return;
        }
        int i = r;
        while (arr[i][lead] == 0) {
            i++;
            if (i == m) {
                i = r;
                lead++;
                if (lead == n) {
                    return;
                }
            }
        }

        
        for (int k = 0; k < n; k++) { // Swap rows .....
            int temp = arr[i][k];
            arr[i][k] = arr[r][k];
            arr[r][k] = temp;
        }

        // make lead value as 1 
        int leadValue = arr[r][lead];
        if (leadValue != 0) {
            for (int k = 0; k < n; k++) {
                arr[r][k] = arr[r][k] / leadValue;
            }
        }

        
        for (int i = 0; i < m; i++) { // Make all rows below this one 0 in the current column
            if (i != r) {
                int f = arr[i][lead];
                for (int k = 0; k < n; k++) {
                    arr[i][k] -= f * arr[r][k];
                }
            }
        }
        lead++;
    }
}

int main() {
   int m, n;
   cout<<"Enter the row and column of matrix : ";
   cin>>m>>n;
    int arr[100][100];

    
    input_matrix(m, n, arr);

    
    row_echelon_form(m, n, arr);

    
    cout << "Matrix in Row Echelon Form:" << endl;
    output_matrix(m, n, arr);

    return 0;
}
