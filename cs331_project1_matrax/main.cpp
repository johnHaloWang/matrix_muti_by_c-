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
void classical_matrix_multiplication_arr(int **a, int **b, int **matrix, int size);
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
void classical_matrix_multiplication_vec(vector<vector<int>>a, vector<vector<int>>b, vector<vector<int>>&matrix)
{

    for(unsigned int i =0; i<a.size(); ++i)
         for(unsigned int j = 0; j<a.size(); ++j)
              for(unsigned int k =0; k<a.size(); ++k)
                    matrix[i][j]=matrix[i][j]+(a[i][k]*b[k][j]);
   // return matrix;

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
    //delete matrix;
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

void classical_matrix_multiplication_arr(int **a, int **b, int **matrix, int size)
{
    for(int i =0; i<size; ++i)
         for(int j = 0; j<size; ++j)
              for(int k =0; k<size; ++k)
                    matrix[i][j]+=(a[i][k]*b[k][j]);
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
        //del_allocate(a, size);
        //del_allocate(b, size);
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
//        del_allocate(a, size);
//        del_allocate(b, size);
    return c;
}


int ** Strassen(int ** A, int ** B, int size)
{
    int ** C = matrix_allocate(size);
    if(size==1)
    {

        C[0][0] = A[0][0] * B[0][0];
        //cout<<C[0][0]<<" = "<<A[0][0]<<" * "<<B[0][0]<<endl;

    }
    else
    {

        int new_size = size/2;
        int ** a = matrix_allocate(new_size); //a00
        int ** b = matrix_allocate(new_size); //a01
        int ** c = matrix_allocate(new_size); //a10
        int ** d = matrix_allocate(new_size); //a11

        /*
         *
         *  a00    a01
         *  a10    a11
         *
         *  a        b
         *  c        d
         *
         *  b00    b01
         *  b10    b11
         *
         *  e        f
         *  g       h
         *
         *  c00    c01
         *  c10    c11
         */

        int ** e = matrix_allocate(new_size); //b00
        int ** f = matrix_allocate(new_size); //b01
        int ** g = matrix_allocate(new_size); //b10
        int ** h = matrix_allocate(new_size); //b11

        int ** p1 = matrix_allocate(new_size);
        int ** p2 = matrix_allocate(new_size);
        int ** p3 = matrix_allocate(new_size);
        int ** p4 = matrix_allocate(new_size);
        int ** p5 = matrix_allocate(new_size);
        int ** p6 = matrix_allocate(new_size);
        int ** p7 = matrix_allocate(new_size);

        //popoulated all sub matrix
        for(int i = 0; i<new_size; ++i)
            for(int j = 0; j<new_size; ++j)
            {
                a[i][j]=A[i][j];                                      //a00
                b[i][j]=A[i][j+new_size];                     //a01
                c[i][j]=A[i+new_size][j];                     //a10
                d[i][j]=A[i+new_size][j+new_size];    //a11
                e[i][j]=B[i][j];                                     //b00
                f[i][j]=B[i][j+new_size];                    //b01
                g[i][j]=B[i+new_size][j];                    //b10
                h[i][j]=B[i+new_size][j+new_size];   //b11
            }

        p1 = matrix_mult(a, matrix_sub2(f, h, new_size), new_size);
        p2 = matrix_mult(matrix_add2(a, b, new_size), h, new_size);
        p3 = matrix_mult(matrix_add2(c, d, new_size), e, new_size);
        p4 = matrix_mult(d, matrix_sub2(g, e, new_size), new_size);
        p5 = matrix_mult(matrix_add2(a, d, new_size), matrix_add2(e, h, new_size), new_size);
        p6 = matrix_mult(matrix_sub2(b, d, new_size), matrix_add2(g, h, new_size), new_size);
        p7 = matrix_mult(matrix_sub2(a, c, new_size), matrix_add2(e, f, new_size), new_size);

        del_allocate(a, new_size);
        del_allocate(b, new_size);
        del_allocate(c, new_size);
        del_allocate(d,  new_size);
        del_allocate(e, new_size);
        del_allocate(f, new_size);
        del_allocate(g, new_size);
        del_allocate(h,  new_size);

         int ** c00 = matrix_add2(matrix_sub2(matrix_add2(p5, p4, new_size), p2, new_size), p6, new_size);
         int ** c01 = matrix_add2(p1, p2, new_size);
         int ** c10 = matrix_add2(p3, p4, new_size);
         int ** c11 = matrix_sub2(matrix_sub2(matrix_add2(p1, p5, new_size), p3, new_size), p7, new_size);


         del_allocate(p1, new_size);
         del_allocate(p2, new_size);
         del_allocate(p3, new_size);
         del_allocate(p4,  new_size);
         del_allocate(p5, new_size);
         del_allocate(p6, new_size);
         del_allocate(p7, new_size);

        for(int i = 0; i<new_size; ++i)
            for(int j = 0; j<new_size; ++j)
            {
                C[i][j]                                     =c00[i][j];
                C[i][j+new_size]                    =c01[i][j];
                C[i + new_size][j]                  =c10[i][j];
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
    if(size==1)
    {

        C[0][0] = A[0][0] * B[0][0];
        //cout<<C[0][0]<<" = "<<A[0][0]<<" * "<<B[0][0]<<endl;

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




void driver()
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
        //int ** c = matrix_allocate(size);

        //classical_matrix_multiplication_arr(a,b, c, size);

       // print_matrix_arr(a, size);
       //cout<<endl<<"-"<<endl;
       // print_matrix_arr(b, size);
       //cout<<"pass classic : ="<<endl;
       // print_matrix_arr(c, size);

        //int ** d = DQ_rec(a, b, size);
       //cout<<"pass Divid and Conqure: ="<<endl;
        //print_matrix_arr(d, size);

        int  start_s = clock();
        int ** e = Strassen(a, b, size);
        cout<<"pass Strassen: ="<<endl;
        int stop_s=clock();
        cout << "time: " << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << endl;
        //print_matrix_arr(e, size);


         del_allocate(a, size);
         del_allocate(b, size);
//         del_allocate(c, size);
//         del_allocate(d, size);
         del_allocate(e, size);

        size*=2;
        counter++;
     }
    cout<<"finish....."<<endl;


}

int main(int argc, char *argv[])
{
    driver();
    return 0;
}
