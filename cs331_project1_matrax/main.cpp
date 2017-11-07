#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <math.h>
#include<climits>

using namespace std;


int ** matrix_allocate(int size);
void del_allocate(int **matrix, int size);
void print_matrix_arr(int ** matrix, int size);
int ** classical_matrix_multiplication_arr(int **a, int **b, int size);
void print_matrix_arr(int ** matrix, int size);
int ** createMatrix_Arr(int size);
int ** matrix_add(int **a, int **b, int size);
int ** matrix_sub(int **a, int **b, int size);
int ** DQ_rec(int ** A, int ** B, int size);
int GetNumberOfDigits (int i);
vector<vector<int> > emptyMatrix(unsigned int size);
vector<vector<int>> createMatrix(unsigned int size);
void classical_matrix_multiplication_vec(vector<vector<int>>a, vector<vector<int>>b, vector<vector<int>>&matrix);
int ** Strassen(int ** A, int ** B, int size);


vector<vector<int> > emptyMatrix(unsigned int size)
{
        vector<vector<int>> matrix;
        for(unsigned int i =0; i<size; ++i)
        {
             vector<int> inner;
             for(unsigned int j = 0; j<size; ++j)
                     inner.push_back(0);
              matrix.push_back(inner);
       }
        return matrix;
}

vector<vector<int>> createMatrix(unsigned int size)
{
       vector<vector<int>> matrix;
       for(unsigned int i =0; i<size; ++i)
       {
            vector<int> inner;
            for(unsigned int j = 0; j<size; ++j)
            {
                 int random_int= (rand() % 100) +1;
                 inner.push_back(random_int);
            }
            matrix.push_back(inner);
       }
       return matrix;
}

vector<vector<int>> createMatrix2(unsigned int size)
{
       vector<vector<int>> matrix;
       for(unsigned int i =0; i<size; ++i)
       {
            vector<int> inner;
            for(unsigned int j = 0; j<size; ++j)
            {
                 //int random_int= (rand() % 100) +1;
                 inner.push_back(1);
            }
            matrix.push_back(inner);
       }
       return matrix;
}

void classical_matrix_multiplication_vec(vector<vector<int>>a, vector<vector<int>>b, vector<vector<int>>&matrix)
{
    for(unsigned int i =0; i<a.size(); ++i)
         for(unsigned int j = 0; j<a.size(); ++j)
              for(unsigned int k =0; k<a.size(); ++k)
                    matrix[i][j]=matrix[i][j]+(a[i][k]*b[k][j]);
}

int GetNumberOfDigits (int i)
{
    return i > 0 ? (int) log10 ((double) i) + 1 : 1;
}



int ** matrix_allocate(int size)
{
    int** matrix = new int*[size];
    for(int i = 0; i<size; i++)
    {
        matrix[i] = new int [size];
        for(int j=0; j<size; j++)
            matrix[i][j]=0;
    }
    return matrix;
}

void del_allocate(int **matrix, int size)
{
    for(int i=0; i<size; ++i)
     {
        delete [] matrix[i];

      }
      delete[]matrix;
}
void print_matrix_arr(int ** matrix, int size)
{
    int max=0;
    for(int i =0; i<size; ++i)
    {
         for(int j = 0; j<size; ++j)
         {
                int temp = GetNumberOfDigits(matrix[i][j]);
                if(max<temp)
                    max=temp;
         }
    }
    for(int i =0; i<size; ++i)
    {
         cout<<"|";
         for(int j = 0; j<size; ++j)
                cout<<" "<<setw(max)<<matrix[i][j];
         cout<<" ";
         cout<<"|"<<endl;

    }
              cout<<endl<<endl;
}

int ** classical_matrix_multiplication_arr(int **a, int **b, int size)
{
     int ** matrix = matrix_allocate(size);
    for(int i =0; i<size; i++)
         for(int j = 0; j<size; j++)
              for(int k =0; k<size; k++)
                    matrix[i][j]+=(a[i][k]*b[k][j]);
    return matrix;
}

int ** createMatrix_Arr(int size)
{
    int** matrix = new int*[size];
    for(int i = 0; i<size; i++)
    {
        matrix[i] = new int [size];
        for(int j=0; j<size; j++)
        {
            int random_int= (rand() % 100) +1;
            matrix[i][j]=random_int;
            //matrix[i][j]=1;
        }
    }
    return matrix;
}

int ** matrix_mult(int **a, int **b, int size)
{
    int ** c = matrix_allocate(size);
    for(int i =0; i<size; ++i)
         for(int j = 0; j<size; ++j)
              for(int k =0; k<size; ++k)
                    c[i][j]+=(a[i][k]*b[k][j]);
    return c;
}

int ** matrix_add(int **a, int **b, int size)
{
    int ** c = matrix_allocate(size);
    for(int i =0; i < size; ++i)
        for(int j = 0; j < size; ++j)
            c[i][j]=a[i][j] + b[i][j];
        del_allocate(a, size);
        del_allocate(b, size);
    return c;
}

int ** matrix_add2(int **a, int **b, int size)
{
    int ** c = matrix_allocate(size);
    for(int i =0; i < size; ++i)
        for(int j = 0; j < size; ++j)
            c[i][j]=a[i][j] + b[i][j];
    return c;
}
int ** matrix_sub(int **a, int **b, int size)
{
    int ** c = matrix_allocate(size);
    for(int i =0; i < size; ++i)
        for(int j = 0; j < size; ++j)
            c[i][j]=a[i][j] - b[i][j];
        del_allocate(a, size);
        del_allocate(b, size);
    return c;
}
int ** matrix_sub2(int **a, int **b, int size)
{
    int ** c = matrix_allocate(size);
    for(int i =0; i < size; ++i)
        for(int j = 0; j < size; ++j)
            c[i][j]=a[i][j] - b[i][j];
    return c;
}


int ** Strassen(int ** A, int ** B, int size)
{
    int ** C = matrix_allocate(size);
    if(size==2)
    {
        C[0][0] = A[0][0] * B[0][0] + A[0][1] * B[1][0];
        C[0][1] = A[0][0] * B[0][1] + A[0][1] * B[1][1];
        C[1][0] = A[1][0] * B[0][0] + A[1][1] * B[1][0];
        C[1][1] = A[1][0] * B[0][1] + A[1][1] * B[1][1];
    }
    else
    {

        int new_size = size/2;

        int ** a11 = matrix_allocate(new_size); //a00
        int ** a12 = matrix_allocate(new_size); //a01
        int ** a21 = matrix_allocate(new_size); //a10
        int ** a22 = matrix_allocate(new_size); //a11

        int ** b11 = matrix_allocate(new_size); //b00
        int ** b12 = matrix_allocate(new_size); //b01
        int ** b21 = matrix_allocate(new_size); //b10
        int ** b22 = matrix_allocate(new_size); //b11

        int ** P = matrix_allocate(new_size);
        int ** Q = matrix_allocate(new_size);
        int ** R = matrix_allocate(new_size);
        int ** S = matrix_allocate(new_size);
        int ** T = matrix_allocate(new_size);
        int ** U = matrix_allocate(new_size);
        int ** V = matrix_allocate(new_size);

        //popoulated all sub matrix
        for(int i = 0; i<new_size; ++i)
            for(int j = 0; j<new_size; ++j)
            {
                a11[i][j]=A[i][j];                                      //a00
                a12[i][j]=A[i][j+new_size];                     //a01
                a21[i][j]=A[i+new_size][j];                     //a10
                a22[i][j]=A[i+new_size][j+new_size];    //a11
                b11[i][j]=B[i][j];                                     //b00
                b12[i][j]=B[i][j+new_size];                    //b01
                b21[i][j]=B[i+new_size][j];                    //b10
                b22[i][j]=B[i+new_size][j+new_size];   //b11
            }





        P = Strassen(matrix_add2(a11, a22, new_size), matrix_add2(b11, b22, new_size), new_size);
        Q = Strassen(matrix_add2(a21, a22, new_size), b11, new_size);
        R = Strassen(a11,                           matrix_sub2(b12, b22, new_size), new_size);
        S = Strassen(a22,                           matrix_sub2(b21, b11, new_size), new_size);
        T = Strassen(matrix_add2(a11, a12, new_size), b22, new_size);
        U = Strassen(matrix_sub2(a21, a11, new_size), matrix_add2(b11, b12, new_size), new_size);
        V = Strassen(matrix_sub2(a12, a22, new_size), matrix_add2(b21, b22, new_size), new_size);


        del_allocate(a11, new_size);
        del_allocate(a12, new_size);
        del_allocate(a22, new_size);
        del_allocate(a21,  new_size);
        del_allocate(b11, new_size);
        del_allocate(b12, new_size);
        del_allocate(b22, new_size);
        del_allocate(b21,  new_size);

         int ** c00 = matrix_add2(matrix_sub2(matrix_add2(P, S, new_size), T, new_size), V, new_size);
         int ** c01 = matrix_add2(R, T, new_size);
         int ** c10 = matrix_add2(Q, S, new_size);
         int ** c11 = matrix_add2(matrix_sub2(matrix_add2(P, R, new_size), Q, new_size), U, new_size);


         del_allocate(P, new_size);
         del_allocate(Q, new_size);
         del_allocate(R, new_size);
         del_allocate(S,  new_size);
         del_allocate(T, new_size);
         del_allocate(U, new_size);
         del_allocate(V, new_size);

        for(int i = 0; i<new_size; ++i)
            for(int j = 0; j<new_size; ++j)
            {
                C[i][j]                     =c00[i][j];
                C[i][j+new_size]            =c01[i][j];
                C[i + new_size][j]          =c10[i][j];
                C[i + new_size][j+new_size] =c11[i][j];

            }

        del_allocate(c00, new_size);
        del_allocate(c01, new_size);
        del_allocate(c10, new_size);
        del_allocate(c11,  new_size);

    }
    return C;
}

int ** DQ_rec(int ** A, int ** B, int size)
{
    int ** C = matrix_allocate(size);
    if(size==2)
    {
        C[0][0] = A[0][0] * B[0][0] + A[0][1] * B[1][0];
        C[0][1] = A[0][0] * B[0][1] + A[0][1] * B[1][1];
        C[1][0] = A[1][0] * B[0][0] + A[1][1] * B[1][0];
        C[1][1] = A[1][0] * B[0][1] + A[1][1] * B[1][1];
    }
    else
    {
        int new_size = size/2;
        int ** a00 = matrix_allocate(new_size);
        int ** a01 = matrix_allocate(new_size);
        int ** a10 = matrix_allocate(new_size);
        int ** a11 = matrix_allocate(new_size);
        int ** b00 = matrix_allocate(new_size);
        int ** b01 = matrix_allocate(new_size);
        int ** b10 = matrix_allocate(new_size);
        int ** b11 = matrix_allocate(new_size);
        //cout<<"pass1"<<endl;
        for(int i = 0; i<new_size; ++i)
            for(int j = 0; j<new_size; ++j)
            {
                a00[i][j]=A[i][j];
                a01[i][j]=A[i][j+new_size];
                a10[i][j]=A[i+new_size][j];
                a11[i][j]=A[i+new_size][j+new_size];
                b00[i][j]=B[i][j];
                b01[i][j]=B[i][j+new_size];
                b10[i][j]=B[i+new_size][j];
                b11[i][j]=B[i+new_size][j+new_size];
            }
        //cout<<"pass2"<<endl;
        int ** c00 = matrix_add(
                DQ_rec(a00, b00, new_size),
                DQ_rec(a01, b10, new_size),
                new_size
                   );
        //cout<<"pass3"<<endl;
        int ** c01 = matrix_add(
                DQ_rec(a00, b01, new_size),
                DQ_rec(a01, b11, new_size),
                new_size);
        //cout<<"pass4"<<endl;
        int ** c10 = matrix_add(
                DQ_rec(a10, b00, new_size),
                DQ_rec(a11, b10, new_size),
                new_size);
        //cout<<"pass5"<<endl;
        int ** c11 = matrix_add(
                DQ_rec(a10, b01, new_size),
                DQ_rec(a11, b11, new_size),
                new_size);
        for(int i = 0; i<new_size; ++i)
            for(int j = 0; j<new_size; ++j)
            {
                C[i][j]                                     =c00[i][j];
                C[i][j+new_size]                    =c01[i][j];
                C[i + new_size][j]                  =c10[i][j];
                C[i + new_size][j+new_size] =c11[i][j];

            }
        //cout<<"pass6"<<endl;
        del_allocate(c00, new_size);
        del_allocate(c01, new_size);
        del_allocate(c10, new_size);
        del_allocate(c11,  new_size);
        //cout<<"pass7"<<endl;
    }
    return C;
}

void driver3()
{
    int size=2;
    srand((unsigned)time(0));
    cout<<"start"<<endl;
    int counter = 0;
    while(size<=INT_MAX)
    {
        cout<<counter<<endl;
        cout<<size<<" x "<<size<<endl;

        int ** a = createMatrix_Arr(size);
        int ** b = createMatrix_Arr(size);

        int  start_s = clock();
        cout<<"start time: "<<start_s<<endl;
        int ** d = Strassen(a, b, size);
        cout<<"pass Strass: ="<<endl;
        int stop_s=clock();
        cout << "time: " << ((stop_s-start_s)/double(CLOCKS_PER_SEC))*1000 << endl;
        cout<<"end time: "<<stop_s<<endl;
        del_allocate(a, size);
        del_allocate(b, size);
        del_allocate(d, size);
        size*=2;
        counter++;
     }
    cout<<"finish....."<<endl;
}

void driver2()
{
    int size=2;
    srand((unsigned)time(0));
    cout<<"start"<<endl;
    int counter = 0;
    while(size<=INT_MAX)
    {
        cout<<counter<<endl;
        cout<<size<<" x "<<size<<endl;

        int ** a = createMatrix_Arr(size);
        int ** b = createMatrix_Arr(size);

        int  start_s = clock();
        cout<<"start time: "<<start_s<<endl;
        int ** d = DQ_rec(a, b, size);
        cout<<"pass Div and Conq: ="<<endl;
        int stop_s=clock();
        cout << "time: " << ((stop_s-start_s)/double(CLOCKS_PER_SEC))* 1000<< endl;
        cout<<"end time: "<<stop_s<<endl;
        del_allocate(a, size);
        del_allocate(b, size);
        del_allocate(d, size);
        size*=2;
        counter++;
     }
    cout<<"finish....."<<endl;
}

void driver1()
{

    int size=2;
    srand((unsigned)time(0));
    cout<<"start"<<endl;
    int counter = 0;
    while(size<=256)
    {
        cout<<counter<<endl;
        cout<<size<<" x "<<size<<endl;

        int ** a = createMatrix_Arr(size);
        int ** b = createMatrix_Arr(size);
        int  start_s = clock();
        cout<<"start time: "<<start_s<<endl;
        int ** c = classical_matrix_multiplication_arr(a,b, size);
        cout<<"pass classic: ="<<endl;
        int stop_s=clock();
        cout << "time: " << ((stop_s-start_s)/double(CLOCKS_PER_SEC)) * 1000 << endl;
        cout<<"end time: "<<stop_s<<endl;
         del_allocate(a, size);
         del_allocate(b, size);
         del_allocate(c, size);
        size*=2;
        counter++;
     }
    cout<<"finish....."<<endl;


}
void driver4()
{
    int size=2;
    srand((unsigned)time(0));
    cout<<"start"<<endl;
    int counter = 0;
    while(size<=16)
    {
        cout<<counter<<endl;
        cout<<size<<" x "<<size<<endl;

        int ** a = createMatrix_Arr(size);
        int ** b = createMatrix_Arr(size);


        print_matrix_arr(a, size);
        print_matrix_arr(b, size);
        //int ** c = createMatrix_Arr(size);
        int  start_s = clock();
        cout<<"start time: "<<start_s<<endl;
        int ** c = classical_matrix_multiplication_arr(a, b, size);
        print_matrix_arr(c, size);
        int ** d = DQ_rec(a, b, size);
        print_matrix_arr(d, size);
        int ** e = Strassen(a, b, size);
        print_matrix_arr(e, size);
        //int stop_s=clock();
        //cout << "time: " << ((stop_s-start_s)/double(CLOCKS_PER_SEC))*1000 << endl;
        //cout<<"end time: "<<stop_s<<endl;
        del_allocate(a, size);
        del_allocate(b, size);
        del_allocate(c, size);
        del_allocate(d, size);
        del_allocate(e, size);
        size*=2;
        counter++;
     }
    cout<<"finish....."<<endl;

}

int main(int argc, char *argv[])
{
    driver4();
    return 0;
}
