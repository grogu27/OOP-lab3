#include <iostream>
#include <stdlib.h>

using namespace std;

class Matrix
{
private:
    int rows;
    int cols;
    int sum = 0;
    int** matrix = NULL;

    void init();
    void freeMatrix();

public:
    void print_matrix();
    void rand_matrix();
    void set(int , int );
    void rand_identity_matrix();
    void product_of_row_and_column();
    void sum_elements();
    void input_elements_in_matrix();

    Matrix(int r, int c);
    Matrix();
    Matrix(int r);
    ~Matrix();

};

Matrix::Matrix(int r, int c)
    {
        rows = r;
        cols = c;
        init();
    }

 Matrix::Matrix(int r)
    {
        rows = r;
        cols = r;
        init();
        rand_identity_matrix();
    }

Matrix::Matrix()
    {
        rows = 0;
        cols = 0;
        init();
    }

Matrix::~Matrix() {
		if(matrix)
			freeMatrix();
	}

void Matrix::freeMatrix() {
	for (int i = 0; i < rows; i++) 
		delete [] matrix[i];
	delete [] matrix;
}
void Matrix::set(int a, int b)
    {
        rows = a;
        cols = b;
    }
void Matrix::init()
{
    matrix = new int* [rows];
    for (size_t i = 0; i < rows; i++)
    {
        matrix[i] = new int[cols];
    }
    
}
void Matrix::print_matrix()
{
    for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) 
				cout << matrix[i][j] << " ";
			
			cout << endl;
		}
		cout << endl;
}
void Matrix::rand_matrix()
{
    srand(time(NULL));
    for (int i = 0; i < rows; i++) 
			for (int j = 0; j < cols; j++) 
                matrix[i][j] = rand() % 10;	
}
void Matrix::rand_identity_matrix()
{
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            matrix[i][j] = (i == j) ? 1 : 0;
}
void Matrix::product_of_row_and_column()
{
    for (int i = 0; i < rows; i++) 
			for (int j = 0; j < cols; j++)
                matrix[i][j] = i * j; 
}
void Matrix::sum_elements()
{
    for (int i = 0; i < rows; i++) 
			for (int j = 0; j < cols; j++)
                sum += matrix[i][j];
    cout << "Sum: " << sum << endl;
}
void Matrix::input_elements_in_matrix()
{
    for (int i = 0; i < rows; i++) 
			for (int j = 0; j < cols; j++){
                cout <<  "[" << i << "|" << j << "]: ";
                cin >> matrix[i][j]; 
            }
                
}

int main()
{
    Matrix M1, M2(3), M3(3, 4), M4(2, 3);
    
    cout << "M2" << endl << endl;
    M2.print_matrix();
    cout << "_________________" << endl;

    cout << "M3" << endl  << endl;
    M3.print_matrix();
    cout << "_________________" << endl;

    cout << "M4" << endl << endl;
    M4.print_matrix();
    cout << "_________________" << endl <<"_________________" << endl;

    M2.product_of_row_and_column();
    cout << "M2" << endl << endl;
    M2.print_matrix();
    cout << "_________________" << endl;

    M3.rand_matrix();
    cout << "M3" << endl  << endl;
    M3.print_matrix();
    cout << "_________________" << endl;

    M4.input_elements_in_matrix();
    cout << "M4" << endl  << endl;
    M4.print_matrix();
    cout << "_________________" << endl;

    M3.sum_elements();

    return 0;
}