#include <iostream>
#include <fstream>

using namespace std;

int main() {

    int A[300][500];
    int B[100][100];


    for (int a=0 ; a<300 ; a++){
        for (int b=0 ; b<500 ; b++){
            A[a][b] = a*b;
        }
    }

     for (int c=0 ; c<300 ; c++){
        for (int d=0 ; d<500 ; d++){
            B[c][d] = c*d*10;
        }
     }


    int Row_value,Col_value;
    cout<<"Insert number of rows" << endl;
    cin>> Row_value;
    cout<< "insert number of columns" <<endl;
    cin>> Col_value;

    for (int i=0;i<100;i++){
        for (int j=0;j<100;j++){
    A[Row_value+i][Col_value+j]=B[i][j];
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