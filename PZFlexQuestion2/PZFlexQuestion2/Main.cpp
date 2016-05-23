#include <iostream>
#include <time.h>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Matrix
{
public:
	Matrix(int rows, int columns);
	void setMatrix();
	vector<vector<int>> getMatrix() { return matrixData; };
	void matrixAddition(int numberToAdd);
	void scalarMultiplication(int multiplier);
	void transposition();
	void sortMatrix();
	void displayMatrix();
	void setRows(int rows) { mRows = rows; };
	void setColumns(int columns) {
		mColumns = columns;
	};
	int getRows() { return mRows; };
	int getColumns() { return mColumns; };
private:
	int mRows;
	int mColumns;
	vector< vector<int> > matrixData;
};

/**Constuctor**/
Matrix::Matrix(int rows, int columns)
{
	mRows = rows;
	mColumns = columns;
	setMatrix();
}

/**
Method which fills the matrix with a series of random numbers**/
void Matrix::setMatrix()
{
	srand(time(NULL));

	matrixData = vector<vector<int>>(mRows, vector<int>(mColumns));

	for (auto row = matrixData.begin(); row != matrixData.end(); row++)
	{
		for (auto col = row->begin(); col != row->end(); col++)
		{
			int randNumber = rand() % 10;
			*col = randNumber;
		}
	}
}
/***
**Method to sort the matrix by column
**/
void Matrix::sortMatrix()
{

	int tempdigit, tempdigit2 = 0;

	for (int i = 0; i < mColumns; i++)
	{
		for (int j = 0; j < mRows - 1; j++)
		{
			tempdigit = matrixData[j][i];
			tempdigit2 = matrixData[j+1][i];
			
			if (tempdigit > tempdigit2)
			{
				matrixData[j+1][i] = tempdigit;
				matrixData[j][i] = tempdigit2;
			}
		}
	}
}

/**Method to multiply the matrix by a scalar factor**/
void Matrix::scalarMultiplication(int multiplier)
{
	for (auto row = matrixData.begin(); row != matrixData.end(); row++)
	{
		for (auto col = row->begin(); col != row->end(); col++)
		{

			*col = *col * multiplier;
		}
	}
}

/**Method to add on a number to each element of the matrix **/
void Matrix::matrixAddition(int numberToAdd)
{
	for (auto row = matrixData.begin(); row != matrixData.end(); row++)
	{
		for (auto col = row->begin(); col != row->end(); col++)
		{

			*col += numberToAdd;
		}
	}
}
/**Method that outputs the transpose of the matrix**/
void Matrix::transposition()
{
	int counter = 0;

	for (auto row = matrixData.begin(); row != matrixData.end(); row++)
	{
		for (auto col = row->begin(); col != row->end(); col++)
		{
			counter++;
			cout << *col << " ";

			if (counter == mRows)
			{
				cout << endl;
				counter = 0;
			}
		}
	}
	
}

/**Method that simply displays the matrix**/
void Matrix::displayMatrix()
{
	for (auto row = matrixData.begin(); row != matrixData.end(); row++)
	{
		for (auto col = row->begin(); col != row->end(); col++)
		{

			cout << *col << " ";
		}
		cout << endl;
	}
}

/**Main method **/
int main()
{
	cout << "Welcome. Please Enter the number of rows and columns your matrix will have.\n\n";
	int rows,columns;
	cout << "Enter the number of rows.";
	cin >> rows;
	cout << "\nEnter the number of columns.";
	cin >> columns;

	Matrix* matrix = new Matrix(rows, columns);
	
	cout << "\nThe matrix randomly generated is: \n";

	matrix->displayMatrix();

	matrix->sortMatrix();

	cout << "\n The reordered matrix is: \n";
	matrix->displayMatrix();

	cout << "\n the transpose is: \n";
	matrix->transposition();

	cout << "\nMultiplying said matrix by 2 gives: \n";
	matrix->scalarMultiplication(2);
	matrix->displayMatrix();

	int in;
	cin >> in;

	return 0;
}