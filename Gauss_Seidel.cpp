//Carlos A. Galan De Arce (L25)
//Javier Gonzalez Martinez (L10)
//CCOM 4065
//Programa: Resuelve un sistema de equaciones lineales utilizando Gauss Seidel o Gauss 


#include<iostream>
#include<iomanip>
#include <cmath>

using namespace std;

int main()
{
    float a[10][10],
        b[10],
        x[10],
        y[10],
        iv[50][5],
        er[5] = { 1 },
        m = 0; //Relative error
    int n = 0, //Size of the 2d array which will have a max of 5.
        it = 0; //Result of all iterations.
    float table[50][5];
    cout << "Enter size of 2d array from 0 to 5 (Square matrix): ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "Enter Coefficient (" << i << ", " << j << ") ";
            cin >> a[i][j];
        }
    }
    cout << "\nEnter Values to the right side of equation\n";
    for (int i = 0; i < n; i++)
    {
        cout << "Enter values no :(" << i << ", " << n << ") ";
        cin >> b[i];
    }
    cout << "\nEnter initials values: \n";
    for (int i = 0; i < n; i++) {
        cout << "Enter values no :(" << i << "): ";
        cin >> iv[0][i];
        x[i] = iv[0][i];
        table[0][i] = iv[0][i];
    }
    cout << "\nEnter the relative error allow: ";
    cin >> m;

    system("cls");
    cout << "\nGauss Seidel Method \n\n";
    cout<< "\nSystem expresed by equation: \n";
    for (int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++){
            if (j == 0) {
                cout << a[i][j] << "x" << j << " ";
            }
            else {
                if(a[i][j] >= 0)
                    cout << "+ " << a[i][j] << "x" << j << " ";
                else {
                    cout << a[i][j] << "x" << j << " ";
                }
            }
        }
        cout << "= " << b[i] << endl;
    }

    cout << endl << "Maximum Accepted Error: " << m <<endl<<endl;

    while (m <= er[0] || m <= er[1] || m <= er[2] || m <= er[3] || m <= er[4])
    {
        it++;
        cout << endl << "Iteration " << it << ":" << endl<<endl;
        cout << "X values: ";
        for (int i = 0; i < n; i++)
        {
            y[i] = (b[i] / a[i][i]);
            for (int j = 0; j < n; j++)
            {
                if (j == i)
                    continue;
                y[i] = y[i] - ((a[i][j] / a[i][i]) * x[j]);
                x[i] = y[i];
            }
            cout << fixed << setw(10) << "x" << i << " = " << y[i];
            er[i] = abs(iv[it-1][i] - y[i]);
            iv[it][i] = y[i];
            table[it][i] = y[i];
        }
        cout << endl;
        for (int i = 0; i < n; i++) {
            cout << endl << "Error x" << i << " = | " << iv[it - 1][i] << " - " << table[it][i] << " | = " << er[i];
        }
        cout << endl;
    }
    cout << endl << "Final Values: " << endl;
    for (int i = 0; i < n; i++) {
        cout << fixed << "x" << i << " = " << table[it - 1][i] << setw(16);
    }
    cout << endl << endl << "TABLE SHOWING X's VALUES ON EACH ITERATION";
    cout << endl << endl << "Iteration";
    for (int i = 0; i < n; i++) {
        cout << setw(16) << "X" << i;
    }
    
    for (int i = 0; i < it; i++) {
        cout << fixed << right << endl << setw(16) << i << setw(16);
        for (int j = 0; j < n; j++) {
            cout << fixed << right << table[i][j] << setw(16);
        }
    }

    cout << endl << endl;
    return 0;
}