#include <iostream>
#include <fstream>


using namespace std;

    int A[300][500]={0};
    int B[100][100]={0};

int main() {
   

    for (int i = 0; i < 300; i++) {
        for (int j = 0; j < 500; j++) {
            A[i][j] = i * j;
        }
    }

    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            B[i][j] = i * j * 10;
        }
    }

    int row_value, col_value;
    cout << "Insert row number ";
    cin >> row_value;
    cout << "Insert column number ";
    cin >> col_value;

    
    if (row_value + 100 > 300 || col_value + 100 > 500) {
        cout << "Error the output is out of bounds" << endl;
        return 1;
    }


    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            A[row_value + i][col_value + j] = B[i][j];
        }
    }

    std::ofstream outfile ("new_array.csv");
for (int i=0; i<300; i++){
    for (int j=0; j< 500; j++){
        outfile << A[i][j] << ",";
    }
    outfile << endl;
}
outfile.close();
return 0;
}