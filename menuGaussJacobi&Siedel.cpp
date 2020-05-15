#include<iostream>
#include<iomanip>
#include<math.h>




using namespace std;

void setfloat(float &);
void setn(int &);
void setCoef(int n, float coef[][5]);
void setRes(int n, float results[]);
void printSist(int n,float coef[][5],float b[]);
void GaussJacobi(int n, float unknowns[], float coef[][5], float b[],float x_0[], float x_e[],int step,float e);
void GaussJacobiTable(int n, float unknowns[], float c[][5], float b[],float x_0[], float x_e[],int step,float e);

/* Main function */
int main()
{
    cout<<"Methods:"<<endl<<"1. Gauss Jacobi"<<endl<<"2. Gauss Siedel"<<endl<<endl;
    int method;
    cout<<"Enter the number of desired method to use :";
    cin>>method;
    cout<<endl;
    do{
    switch(method){
        case 1: {   cout<<"Using Gauss Jacobi Method:"<<endl;
                    cout<< setprecision(6)<< fixed;
                    int n;
                    float e;
                    /* Input */
                    /* Reading tolerable error */
                    setfloat(e);
                    setn(n);
                    float x[n]; // x values
                    float coef[n][5];// coeficients
                    float b[n];// linear equations results
                    float x0[3] ={-1,0,2};//x0 value
                    float xe[n];//x error
                    int step=1;
                    
                    setCoef(n,coef);
                    setRes(n,b);
                    printSist(n,coef,b);
                    GaussJacobi(n,x,coef,b,x0,xe,step,e);
                    GaussJacobiTable(n,x,coef,b,x0,xe,step,e);
                    break;
                }
        case 2:{
                    cout<<"Using Gauss Siedel Method:"<<endl;
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
                break;
            }
            default: cout<<"MUST ENTER THE NUMBER OF THE DESIRED METHOD."<<endl;
                    cin>>method;
    }
    }while(method != 1 || method !=2);
    

 /* Setting precision and writing floating point values in fixed-point notation. */
 

 

 
 return 0;
}

// SET float NUMBER
void setfloat(float &number){
cout<<"Enter tolerable error: ";
while (!(cin >> number))
{
    // Explain error
    cout << "ERROR: a number must be entered: ";

    // Clear input stream
    cin.clear();

    // Discard previous input
    cin.ignore(123456, '\n');
}
// Display the number the user has entered
cout << "Your decimal number is: " << number << endl;
}

//SET N
void setn(int &n){
cout<<"Enter n which will be the amount of unknowns and equations: ";
while (!(cin >> n))
{
    // Explain error
    cout << "ERROR: a number between 1 and 5 must be entered: ";
    
    // Clear input stream
    cin.clear();

    // Discard previous input
    cin.ignore(1, '\n');
}
if(n < 1){
    cout<< "n set to lowest amount 1"<<endl;
    n=1;
}
else if(n>5){
    cout<< "n set to highest amount 5"<<endl;
    n=5;
}

// Display the number the user has entered
cout << "Your value n is: " << n << endl;
}



//SET COEFICIENTS
void setCoef(int n, float coef[][5]){
    float value=0;
    for(int i = 0; i<n;i++){
        for(int j = 0; j<n; j++){
        cout<<"Enter coeficient["<<i+1<<"]["<<j+1<<"]"<<" "<<i+1<<" : ";
        while (!(cin >> value))
        {
            // Explain error
            cout << "ERROR: a number must be entered: ";
        
            // Clear input stream
            cin.clear();
        
            // Discard previous input
            cin.ignore(12345, '\n');
        }
        coef[i][j]=value;
    // Display the number the user has entered
    cout << "Your coeficient["<<i+1<<"]["<<j+1<<"]"<<" value is: " << value << endl;
    
        }
    }
}


// SET b VALUES 
void setRes(int n, float results[]){
    float value;
    for(int i = 0; i<n;i++){
        cout<<"Enter result b"<<i+1<<" : ";
        while (!(cin >> value))
        {
            // Explain error
            cout << "ERROR: a number must be entered: ";
        
            // Clear input stream
            cin.clear();
        
            // Discard previous input
            cin.ignore(12345, '\n');
        }
        results[i]=value;
    // Display the number the user has entered
    cout << "Your b"<<i<<" is: " << value << endl;
    
    }
}

//PRINT LINEAR EQUATIONS 
void printSist(int n,float coef[][5],float b[]){
cout<<endl<<"SYSTEM EXPRESSED BY EQUATIONS"<<endl;
    for(int i = 0; i<n ; i++){
        for(int j=0; j<n;j++){
            float coefi = coef[i][j];
            if(coefi == (n-1)){
                cout<<coef[i][j]<<"x"<<j<<" ";
            }
            else
                if(j>0 && coef[i][j] >= 0){
                    cout<<"+ ";
                }
                else if(j>0 && coef[i][j] < 0)
                    cout<<"- ";
                cout<<fabs(coef[i][j])<<"x"<<j<<" " ;   
        }
        cout<<" = "<<b[i]<<endl;
    }
    cout<<endl;
}

//SOLVE USING GAUSS JACOBI
void GaussJacobi(int n, float unknowns[], float c[][5], float b[],float x_0[], float x_e[],int step,float e){
cout<<endl<<"Maximum Accepted Error: "<<e<<endl<<endl;    
cout<<"ITERATION BY ITERATION PROCEDURE USING GAUSS JACOBI METHOD"<<endl<<endl;
//COPY ARRAYS INTO NEW VARIABLES
    float x[n];
    for(int i=0; i<n ;i++){
        x[i]= unknowns[i];
    }
    
    float coef[n][5];
    for(int i=0; i<n ;i++){
        for(int j =0;j<n;j++){
            coef[i][j]= c[i][j];
        }
    }
    
    float x0[n];
    for(int i=0; i<n ;i++){
        x0[i]= x_0[i];
    }
    
    float xe[n];
    for(int i=0; i<n ;i++){
        xe[i]= x_e[i];
    }
    
    cout<<endl;
    int errorPassed;//THIS WILL DETERMINE IF ALL ERRORS ARE UNDER THE ACCEPTED ONE
     do{ 
         errorPassed =0;
         cout<<"Iteration: "<<step<<endl;
         //CALCULATE NEXT ITERATIONS X VALUES
         switch(n){
            case 1:  x[0] = (b[0])/coef[0][0];
                     cout<<"x1"<<" = "<<"("<<b[0]<<")/"<<coef[0][0]<<"="<<x[0]<<endl<<endl;
                     break; 
            case 2:  x[0] = (b[0]-(coef[0][1]*x0[1]))/coef[0][0];
                     x[1] = (b[1]-(coef[1][0]*x0[0]))/coef[1][1];
                     cout<<"x1"<<" = "<<"("<<b[0]<<"-"<<"("<<coef[0][1]<<"*"<<x0[1]<<"))/"<<coef[0][0]<<"="<<x[0]<<endl;
                     cout<<"x2"<<" = "<<"("<<b[1]<<"-"<<"("<<coef[1][0]<<"*"<<x0[0]<<"))/"<<coef[1][1]<<"="<<x[1]<<endl<<endl;
                     break;  
            case 3:  x[0] = (b[0]-(coef[0][1]*x0[1])-(coef[0][2]*x0[2]))/coef[0][0];
                     x[1] = (b[1]-(coef[1][0]*x0[0])-(coef[1][2]*x0[2]))/coef[1][1];
                     x[2] = (b[2]-(coef[2][0]*x0[0])-(coef[2][1]*x0[1]))/coef[2][2];
                     cout<<"x1"<<" = "<<"("<<b[0]<<"-"<<"("<<coef[0][1]<<"*"<<x0[1]<<")-("<<coef[0][2]<<"*"<<x0[2]<<"))/"<<coef[0][0]<<"="<<x[0]<<endl;
                     cout<<"x2"<<" = "<<"("<<b[1]<<"-"<<"("<<coef[1][0]<<"*"<<x0[0]<<")-("<<coef[1][2]<<"*"<<x0[2]<<"))/"<<coef[1][1]<<"="<<x[1]<<endl;
                     cout<<"x3"<<" = "<<"("<<b[2]<<"-"<<"("<<coef[2][0]<<"*"<<x0[0]<<")-("<<coef[2][1]<<"*"<<x0[1]<<"))/"<<coef[2][2]<<"="<<x[2]<<endl<<endl;
                     break; 
            case 4:  x[0] = (b[0]-(coef[0][1]*x0[1])-(coef[0][2]*x0[2])-(coef[0][3]*x0[3]))/coef[0][0];
                     x[1] = (b[1]-(coef[1][0]*x0[0])-(coef[1][2]*x0[2])-(coef[1][3]*x0[3]))/coef[1][1];
                     x[2] = (b[2]-(coef[2][0]*x0[0])-(coef[2][1]*x0[1])-(coef[2][3]*x0[3]))/coef[2][2];
                     x[3] = (b[3]-(coef[3][0]*x0[0])-(coef[3][1]*x0[1])-(coef[3][2]*x0[2]))/coef[3][3];
                     cout<<"x1"<<" = "<<"("<<b[0]<<"-"<<"("<<coef[0][1]<<"*"<<x0[1]<<")-("<<coef[0][2]<<"*"<<x0[2]<<")-("<<coef[0][3]<<"*"<<x0[3]<<"))/"<<coef[0][0]<<"="<<x[0]<<endl;
                     cout<<"x2"<<" = "<<"("<<b[1]<<"-"<<"("<<coef[1][0]<<"*"<<x0[0]<<")-("<<coef[1][2]<<"*"<<x0[2]<<")-("<<coef[1][3]<<"*"<<x0[3]<<"))/"<<coef[1][1]<<"="<<x[1]<<endl;
                     cout<<"x3"<<" = "<<"("<<b[2]<<"-"<<"("<<coef[2][0]<<"*"<<x0[0]<<")-("<<coef[2][1]<<"*"<<x0[1]<<")-("<<coef[2][3]<<"*"<<x0[3]<<"))/"<<coef[2][2]<<"="<<x[2]<<endl;
                     cout<<"x4"<<" = "<<"("<<b[3]<<"-"<<"("<<coef[3][0]<<"*"<<x0[0]<<")-("<<coef[3][1]<<"*"<<x0[1]<<")-("<<coef[3][2]<<"*"<<x0[2]<<"))/"<<coef[3][3]<<"="<<x[3]<<endl<<endl;
                     break;
            case 5:  x[0] = (b[0]-(coef[0][1]*x0[1])-(coef[0][2]*x0[2])-(coef[0][3]*x0[3])-(coef[0][4]*x0[4]))/coef[0][0];
                     x[1] = (b[1]-(coef[1][0]*x0[0])-(coef[1][2]*x0[2])-(coef[1][3]*x0[3])-(coef[1][4]*x0[4]))/coef[1][1];
                     x[2] = (b[2]-(coef[2][0]*x0[0])-(coef[2][1]*x0[1])-(coef[2][3]*x0[3])-(coef[2][4]*x0[4]))/coef[2][2];
                     x[3] = (b[3]-(coef[3][0]*x0[0])-(coef[3][1]*x0[1])-(coef[3][2]*x0[2])-(coef[3][4]*x0[4]))/coef[3][3];
                     x[4] = (b[4]-(coef[4][0]*x0[0])-(coef[4][1]*x0[1])-(coef[4][2]*x0[2])-(coef[4][3]*x0[3]))/coef[4][4];
                     
                     cout<<"x1"<<" = "<<"("<<b[0]<<"-"<<"("<<coef[0][1]<<"*"<<x0[1]<<")-("<<coef[0][2]<<"*"<<x0[2]<<")-("<<coef[0][3]<<"*"<<x0[3]<<")-("<<coef[0][4]<<"*"<<x0[4]<<"))/"<<coef[0][0]<<"="<<x[0]<<endl;
                     cout<<"x2"<<" = "<<"("<<b[1]<<"-"<<"("<<coef[1][0]<<"*"<<x0[0]<<")-("<<coef[1][2]<<"*"<<x0[2]<<")-("<<coef[1][3]<<"*"<<x0[3]<<")-("<<coef[1][4]<<"*"<<x0[4]<<"))/"<<coef[1][1]<<"="<<x[1]<<endl;
                     cout<<"x3"<<" = "<<"("<<b[2]<<"-"<<"("<<coef[2][0]<<"*"<<x0[0]<<")-("<<coef[2][1]<<"*"<<x0[1]<<")-("<<coef[2][3]<<"*"<<x0[3]<<")-("<<coef[2][4]<<"*"<<x0[4]<<"))/"<<coef[2][2]<<"="<<x[2]<<endl;
                     cout<<"x4"<<" = "<<"("<<b[3]<<"-"<<"("<<coef[3][0]<<"*"<<x0[0]<<")-("<<coef[3][1]<<"*"<<x0[1]<<")-("<<coef[3][2]<<"*"<<x0[2]<<")-("<<coef[3][4]<<"*"<<x0[4]<<"))/"<<coef[3][3]<<"="<<x[3]<<endl;
                     cout<<"x5"<<" = "<<"("<<b[4]<<"-"<<"("<<coef[4][0]<<"*"<<x0[0]<<")-("<<coef[4][1]<<"*"<<x0[1]<<")-("<<coef[4][2]<<"*"<<x0[2]<<")-("<<coef[4][3]<<"*"<<x0[3]<<"))/"<<coef[4][4]<<"="<<x[4]<<endl<<endl;
                     break;
                    
         }

          
          //SHOW X's VALUES FOR THIS ITERATION
          cout<<"X VALUES: ";
          for(int i=0; i<n;i++){
              cout<<"x"<<i<<" = "<< x[i]<<"\t";
          }
          
          cout<<endl<<endl;
          
          /* CALCULATE ERROR BETWEEN CURRENT AND NEXT ITERATION X VALUES
          e1 = fabs(x1_0-x1);
          e2 = fabs(x2_0-x2);
          e3 = fabs(x3_0-x3);
          e4 = fabs(x4_0-x4);
          e3 = fabs(x5_0-x5);
            */
          for(int i=0; i<n;i++){
              xe[i]= fabs(x0[i]-x[i]);
              cout<<"Error x"<<i<<" = "<<"| "<<x0[i]<<" - "<<x[i]<<" | ="<<xe[i]<<endl;
          }
          cout<<endl;
          
          step++;
        
          /* Set values for next iteration */
          cout<<endl<<"ON NEXT ITERATIONS Xs VALUES WILL BE:"<<endl;
          for(int i=0; i<n;i++){
              x0[i]=x[i];
              cout<<"x"<<i<<" = "<<x[i]<<endl;
          }
          cout<<endl;
          //check our error for all xs is bigger than the accepted error to continue iterating
          cout<<endl<<"WE COMPARE IF OUR CURRENT ERROR IS BIGGER THAN THE ACCEPTED ONE"<<endl;
          
          for(int i=0; i<n;i++){
              if(xe[i]>e){
                cout<<xe[i]<<">"<<e<<endl;  
              }
              else{
                  cout<<xe[i]<<"<"<<e<<endl;  
                  errorPassed++;
              }
          }
          cout<<endl;
          
     }while(errorPassed != n);
        
     cout<<"Final Solution: ";
     for(int i=0; i<n;i++){
         if(i==0)
          cout<<"x"<<i+1<<" = "<<x[i];
         else
          cout<<", x"<<i+1<<" = "<<x[i];
      }
      cout<<endl;
}

//SOLVE USING GAUSS JACOBI
void GaussJacobiTable(int n, float unknowns[], float c[][5], float b[],float x_0[], float x_e[],int step,float e){

    cout<<endl<<"TABLE SHOWING X's VALUES ON EACH ITERATION"<<endl;
    //COPY ARRAYS INTO NEW VARIABLES
    float x[n];
    for(int i=0; i<n ;i++){
        x[i]= unknowns[i];
    }
    
    float coef[n][5];
    for(int i=0; i<n ;i++){
        for(int j =0;j<n;j++){
            coef[i][j]= c[i][j];
        }
    }
    
    float x0[n];
    for(int i=0; i<n ;i++){
        x0[i]= x_0[i];
    }
    
    float xe[n];
    for(int i=0; i<n ;i++){
        xe[i]= x_e[i];
    }
    
cout<<"Iteration";
    for(int i=0; i<n ;i++){
        cout<<"\t\tx"<<i<<"\t";
    }
    cout<<endl;
    int checkError = 0;
     do
     {
         switch(n){
            case 1:  x[0] = (b[0])/coef[0][0];
                     break; 
            case 2:  x[0] = (b[0]-(coef[0][1]*x0[1]))/coef[0][0];
                     x[1] = (b[1]-(coef[1][0]*x0[0]))/coef[1][1];
                     break;  
            case 3:  x[0] = (b[0]-(coef[0][1]*x0[1])-(coef[0][2]*x0[2]))/coef[0][0];
                     x[1] = (b[1]-(coef[1][0]*x0[0])-(coef[1][2]*x0[2]))/coef[1][1];
                     x[2] = (b[2]-(coef[2][0]*x0[0])-(coef[2][1]*x0[1]))/coef[2][2];
                     break; 
            case 4:  x[0] = (b[0]-(coef[0][1]*x0[1])-(coef[0][2]*x0[2])-(coef[0][3]*x0[3]))/coef[0][0];
                     x[1] = (b[1]-(coef[1][0]*x0[0])-(coef[1][2]*x0[2])-(coef[1][3]*x0[3]))/coef[1][1];
                     x[2] = (b[2]-(coef[2][0]*x0[0])-(coef[2][1]*x0[1])-(coef[2][3]*x0[3]))/coef[2][2];
                     x[3] = (b[3]-(coef[3][0]*x0[0])-(coef[3][1]*x0[1])-(coef[3][2]*x0[2]))/coef[3][3];
                     break;
            case 5:  x[0] = (b[0]-(coef[0][1]*x0[1])-(coef[0][2]*x0[2])-(coef[0][3]*x0[3])-(coef[0][4]*x0[4]))/coef[0][0];
                     x[1] = (b[1]-(coef[1][0]*x0[0])-(coef[1][2]*x0[2])-(coef[1][3]*x0[3])-(coef[1][4]*x0[4]))/coef[1][1];
                     x[2] = (b[2]-(coef[2][0]*x0[0])-(coef[2][1]*x0[1])-(coef[2][3]*x0[3])-(coef[2][4]*x0[4]))/coef[2][2];
                     x[3] = (b[3]-(coef[3][0]*x0[0])-(coef[3][1]*x0[1])-(coef[3][2]*x0[2])-(coef[3][4]*x0[4]))/coef[3][3];
                     x[4] = (b[4]-(coef[4][0]*x0[0])-(coef[4][1]*x0[1])-(coef[4][2]*x0[2])-(coef[4][3]*x0[3]))/coef[4][4];
                     break;
                    
         }

          
          //SHOW X's VALUES FOR THIS ITERATION
          cout<<step<<"\t";
          for(int i=0; i<n;i++){
              cout<<"\t\t"<<x[i];
          }
          
          cout<<endl;
          
          /* Error */
          for(int i=0; i<n;i++){
              xe[i]= fabs(x0[i]-x[i]);
          }
          /*
          e1 = fabs(x1_0-x1);
          e2 = fabs(x2_0-x2);
          e3 = fabs(x3_0-x3);
          e4 = fabs(x4_0-x4);
          e3 = fabs(x5_0-x5);
            */
          step++;
        
          /* Set value for next iteration */
          for(int i=0; i<n;i++){
              x0[i]=x[i];
          }
          
          for(int i=0; i<n;i++){
              if(xe[i]<e){
                  
                  checkError = 1;
              }
              else{
                  checkError=0;
                  break;
              }
          }
     }while(checkError == 0);
      cout<<endl;
}

