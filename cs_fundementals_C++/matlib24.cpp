// matlib24.cpp : This file contains the 'main' function and others to test matrix routines
//

// matlib24.cpp : A simple matrix library program.
// Template Written by Prof Richard Mitchell    6/12/23
// Adapted by:   << put your name here >>

#include <string>
#include <iostream>
using namespace std;

const int maxM = 16;	// allows for matrices up to size 4*4

struct myMat {			// structure to store a matrix
	int numRows;		// number of rows
	int numCols;		// number of columns
	int data[maxM];		// data are stored in row order
};

myMat zeroMat(int r, int c) { // create a matrix with r rows and c columns, filled with zeros
	// create a matrix with r rows and c columns, filled with zeros
	myMat m;			// define matrix
	m.numRows = r;		// set amount of rows
	m.numCols = c;		// set amount of columns
	for (int ct = 0; ct < maxM && ct < (r * c); ct++) m.data[ct] = 0;	// set elems to 0
	return m;			// return matrix
}

int getIndex(myMat m, int r, int c) { // return index of element in row r, col c of matrix m
	// return index of element in row r, col c of matrix m
	return r * m.numCols + c; // r changes so for first row r is 0 and then c is how many forward in that  row for columns
}

myMat matError(string errstr) { // if this is called, an error has occured for a matrix ... output errstr and return 0 size myMat
	// if this is called, an error has occured ... output errstr and return 0 size myMat
	cout << "Error : " << errstr << "\n";
	return zeroMat(0, 0);
}

int intError(string errstr) { // if this is called, an error has occured for an int ... output errstr and return 0
	// if this is called, an error has occured ... output errstr and return 0 
	cout << "Error : " << errstr << "\n";
	return 0;
}

myMat mFromStr(string s) {
	// create a matrix from string s
	// string of form "1,2;3,4;5,6"   ; separates rows and , separates columns
	if (s.empty()) { //error check
		std::cout << "Error: Empty string\n";
	}
	else {
		int ms;
		if (s.length() > 0) ms = 1; else ms = 0;
		myMat m = zeroMat(ms, ms);						// is s empty create 0*0 matrix, else start with 1*1 matrix
		int mndx = 0;									// used to index into array
		string sub = "";								// sub string - numbers between , or ; set empty
		for (int ct = 0; ct < s.length(); ct++) {		// each char in turn
			if ((s[ct] == ',') || (s[ct] == ';')) {	// if , or ; then sub contains number
				m.data[mndx++] = stoi(sub);				// convert number to integer, put in data array
				sub = "";								// clear sub string
				if (s[ct] == ';') m.numRows++;			// if found ; indicates an extra row
				else if (m.numRows == 1) m.numCols++;	// if , then (if in row 1) increase count of columns
			}
			else sub = sub + s[ct];					// add character to sub string
			std::cout << sub << "\n";
		}
		if (sub.length() > 0) m.data[mndx++] = stoi(sub);// add last sub string
		return m;
	}
}

void printMat(const char* mess, myMat m) { // print matrix m with message mess
	// mess is string to be printed, followed by matrix m
	cout << mess << " = " << "\n";				// print message
	for (int r = 0; r < m.numRows; r++) {		// do each row
		for (int c = 0; c < m.numCols; c++)	{	// do each column
			cout << m.data[getIndex(m, r, c)] << "\t";	// outputing the element then tab
		}
		cout << "\n";							// output new line at end of row
	}
	cout << "\n";								// and end of Matrix
}


myMat mGetRow(myMat m, int row) { // create a matrix from m, having one row
	// create a matrix from m, having one row
	myMat res = zeroMat(1, m.numCols);		// create a matrix of 1 row
	for (int col = 0; col < m.numCols; col++) {		// for each element in row
		res.data[col] = m.data[getIndex(m, row, col)];		// copy col element to res
	}
	return res;
}

myMat mGetCol(myMat m, int col) { // create a matrix from m, having one col
	// create a matrix from m, having one col
	myMat res = zeroMat(m.numRows, 1);	// adjust arguments so column vector
	for (int row = 0; row < m.numRows; row++) {// for each element in col
		res.data[row] = m.data[getIndex(m, row, col)];	// copy row element to res
	}
	return res;
}

myMat mSetCol(myMat m, int col, myMat v) { // insert v into given col in m
	// insert v into given col in m
	if (m.numRows != v.numRows) {
		return matError("Matrix/Vector should have same number of rows");
	}
	else {
		myMat res = m;
		for (int row = 0; row < m.numRows; row++)
			res.data[getIndex(m, row, col)] = v.data[row];
		return res;
	}
}

int dotProd(myMat v1, myMat v2) { // calculate the dot product of two vectors v1 and v2
	// calculate the dot product of two vectors v1 and v2, each of which could be eitherrow or column vectors
	for (int i = 0; i < v1.numCols; i++) {
		v1.data[i] *= v2.data[i];
	}
	for (int i = 1; i < v1.numCols; i++) {
		v1.data[0] += v1.data[i];
	}
	return v1.data[0];
}


myMat mTranspose(myMat m) { // generate a new matrix which is the transpose of m which is a matrix
	// generate a new matrix which is the transpose of m
	myMat res = zeroMat(m.numCols, m.numRows);		// change arguments 
	// write code to do transpose
	for (int r = 0; r < m.numRows; r++)	{	// for each row
		for (int c = 0; c < m.numCols; c++)	{ // for each column
			res.data[getIndex(res, c, r)] = m.data[getIndex(m, r, c)];
		}
	}
	return res;
}

myMat mAdd(myMat m1, myMat m2) { // create a new matrix whose elements are the sum of the equiv elements in m1 and m2
	// create a new matrix whose elements are the sum of the equiv elements in m1 and m2
	// if time add code to check matrices of right size
	myMat res = zeroMat(m1.numRows, m1.numCols);		// change arguments
	for (int r = 0; r < m1.numRows; r++) {		// for each row
		for (int c = 0; c < m1.numCols; c++) {	// for each column
			res.data[getIndex(res, r, c)] = m1.data[getIndex(m1, r, c)] + m2.data[getIndex(m2, r, c)];
		}
	}
	return res;
}

myMat mScalarMultDiv(myMat m, int s, int isMult) { // multiply or divide all elements in m by s
	// multiply or divide all elements in m by s
	myMat res = zeroMat(m.numRows, m.numCols);		// change arguments
		// write code to do multiply or divide by scalar
	for (int r = 0; r < m.numRows; r++)	{	// for each row
		for (int c = 0; c < m.numCols; c++) { // for each column
			 if (isMult) {
                res.data[getIndex(res, r, c)] = m.data[getIndex(m, r, c)] * s;
            }
			else {
                // Ensure division by zero is handled or avoided
                if (s != 0) {
                    res.data[getIndex(res, r, c)] = m.data[getIndex(m, r, c)] / s;
                } else {
                    return matError("Attempt to divide by zero.");
                }
            }
		}
	}
	return res;
}

myMat mMult(myMat m1, myMat m2) { // generate a matrix which is the product of m1 and m2
	// generate a matrix which is the product of m1 and m2
	// if time add code to check matrices of right size
	myMat res = zeroMat(m1.numRows, m2.numCols);		// change arguments
		// write code to do multiply
	for (int r = 0; r < m1.numRows; r++) {		// for each row
		for (int c = 0; c < m2.numCols; c++) {	// for each column
			for (int k = 0; k < m1.numCols; k++) {	// for each element in row
				res.data[getIndex(res, r, c)] += m1.data[getIndex(m1, r, k)] * m2.data[getIndex(m2, k, c)];
			}
		}
	}
	return res;
}

void testMatOps(myMat m1, myMat m2, myMat m3) { // test matrix operations
	// test matrix operations m1 + m2; m1 + m3 (not poss) m1 + m3'; m1 * m3; m3 * m2
	cout << "Testing Add, Transpose, Multiply routines" << "\n";
	printMat("m1+m2", mAdd(m1, m2));
	printMat("m1 + m3", mAdd(m1, m3));
	printMat("m1 + m3'", mAdd(m1, mTranspose(m3)));
	printMat("m1*m2", mMult(m1, m3));
	printMat("m2*m1", mMult(m3, m1));
	printMat("m1*m3", mMult(m1, m2));
}

void testVecs(myMat m1, myMat m3) { // test vector routines
	// test vector routines ... get row from m1, col from m3, do dot product of these
	cout << "Testing Vector routines" << "\n";
	printMat("m1 row 0", mGetRow(m1, 0));	// display row 0 of m1
	printMat("m3 col 1", mGetCol(m3, 1));	// display col 1 of m2
	cout << "Dot prod of these is " << dotProd(mGetRow(m1, 0), mGetCol(m3, 1)) << "\n\n";
	cout << "Dot prod of m1 row 1 and m3 row 1 " << dotProd(mGetRow(m1, 0), mGetRow(m3, 1)) << "\n\n";
}

//commented out code you will do as part of Summative Assessment later in term 

myMat mSubMat(myMat m, int row, int col) {
	// return matrix m but omitting specified row and column
	// if time add code to check matrices of right size
	// write code to do sub mat
	myMat res = zeroMat(m.numRows - 1, m.numCols - 1);
	int r = 0;
	for (int i = 0; i < m.numRows; i++) {
		if (i == row) continue;
		int c = 0;
		for (int j = 0; j < m.numCols; j++) {
			if (j == col) continue;
			res.data[getIndex(res, r, c)] = m.data[getIndex(m, i, j)];
			c++;
		}
		r++;
	}

	return res;
}

int mDet(myMat m) {
	// compute determinant of matrix m for 1*1 and 2*2
	if (m.numRows == 1) return m.data[0];
	if (m.numRows == 2) return m.data[0] * m.data[3] - m.data[1] * m.data[2];
	
	// change this ... initially handcode for 1*1 and 2*2 ... if brave do 3*3 or 4*4 recursively
}

myMat mAdj(myMat m) {
	// return adjoint of matrix m     assume 2*2 initially
	// if time add code to check matrices of right size
	// return the adjoint of m which is a 2*2 matrix
	if (m.numRows != 2 || m.numCols != 2) {
        return matError("mAdj requires a 2x2 matrix.");
    }

	myMat res = zeroMat(2, 2);		// change arguments
		// write code to do adjoint initially handcode for 1*1 and 2*2 ... if brave do 3*3 or 4*4 recursivel
	res.data[getIndex(res, 0, 0)] = m.data[getIndex(m, 1, 1)];  // d
    res.data[getIndex(res, 0, 1)] = -m.data[getIndex(m, 0, 1)]; // -b
    res.data[getIndex(res, 1, 0)] = -m.data[getIndex(m, 1, 0)]; // -c
    res.data[getIndex(res, 1, 1)] = m.data[getIndex(m, 0, 0)];  // a
	
	return res;
}

void testMatEqn(myMat A, myMat b) {
    int detA = mDet(A);
    myMat adjA = mAdj(A);

    myMat m = mScalarMultDiv(adjA, 1, 0); // divide adjA by detA
    for (int i = 0; i < maxM; i++) m.data[i] /= detA; // divide adjA by detA
    // Multiply A inverse by b to get x
    myMat x = mMult(m, b);
    
    printMat("Solution x", x);
}


int main()
{
	
	cout << "Ric's Matrix Example Program\n";	// change to your student number
	myMat m1, m2, m3, rowM1, colM2;					// create  matrices

	m1 = mFromStr("1,2,3;4,-5,6");			// change numbers to those in A from Q1 on web page, as specified on the sheet
	m2 = mFromStr("2,-5,3;7,1,4");			// ditto but B
	m3 = mFromStr("2,-5;3,7;1,4");			// ditto  but C
	rowM1 = mGetRow(m1, 0);
	colM2 = mGetCol(m2, 1);
	printMat("m1", m1);						// display m1
	printMat("m2", m2);						// display m2
	printMat("m3", m3);						// display m3
	printMat("m1 row 0", rowM1);				// display row 0 of m1
	printMat("m2 col 1", colM2);				// display col 1 of m2

	testVecs(m1, m3);						// test the vector routines

	//equation for 3201630 student number for Ax = b
	myMat A = mFromStr("8,10;4,4");
	myMat b = mFromStr("164;72");
	testMatEqn(A, b);

	myMat C = mFromStr("9,7;10,4");
	myMat D = mFromStr("118;116");
	testMatEqn(C, D);

	myMat E = mFromStr("4,4,7;9,8,10;4,10,7");
	myMat F = mFromStr("120;217;162");
	testMatEqn(E, F);

	//	testMatOps(m1, m2, m3);					// test the add, transpose and multiply
	return 0;
}