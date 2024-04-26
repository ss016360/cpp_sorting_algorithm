
const int maxM = 16; // allows up to size 4*4
struct myMat {
   int numRows;// number of rows
    int numCols;
    int data[maxM];// data stored in row order
    };

int getIndex(myMat m, int r, int c) {
    // return index into data of element at m[r,c]
    // where r is 0..m.numRows-1 etc
    return r*m.numCols + c;
    }
m.data[getIndex(m, r, c)]
m.data[getIndex(m, r, c) = val]

myMat mGetRow(myMat m, int row) {
    // create a matrix from m, having one row
    myMat res = zeroMat(1, m.numCols);		// create a matrix of 1 row
    for (int col = 0; col < m.numCols; col++);		// for each element in row
	    res.data[col] = m.data[getIndex(m, row, col)]; // copy col element to res
    return res;
    }


myMat mGetCol(myMat m, int col) {
// create a matrix from m, having one row
    myMat res = zeroMat(m.numRows, 1);		// create a matrix of 1 row
    for (int row = 0; row < m.numRows; row++)		// for each element in row
        res.data[row] = m.data[getIndex(m, row, col)]; // copy col element to res
    return res;
    }

// dot product of two vectors
int dotProd(myMat v1, myMat v2) {
    int res = 0;
    for (int i = 0; i < v1.numCols; i++)
        res += v1.data[i] * v2.data[i];
    return res;
    }

// matrix transposition
myMat mTranspose(myMat m) {
	// return a matrix which is m transposed myMat res = zeroMat(<what>, <what>);
    myMat res = zeroMat(m.numCols, m.numRows);
    for (int row = 0; row < m.numRows; row++)
        for (int col = 0; col < m.numCols; col++)
            res.data[getIndex(res, col, row)] = m.data[getIndex(m, row, col)];
    return res;
    }

// matrix addition
myMat mAdd (myMat m1, myMat m2) {
	// return a matrix which is m1 + m2
    myMat res = zeroMat(m1.numRows, m1.numCols);
    for (int row = 0; row < m1.numRows; row++)
        for (int col = 0; col < m1.numCols; col++)
            res.data[getIndex(res, row, col)] = m1.data[getIndex(m1, row, col)] + m2.data[getIndex(m2, row, col)];
    return res;
    }

// matrix multiplication
myMat mMult (myMat m1, myMat m2) {
	// return a matrix which is m1 * m2
    myMat res = zeroMat(m1.numRows, m2.numCols);
    for (int row = 0; row < m1.numRows; row++)
        for (int col = 0; col < m2.numCols; col++)
            for (int i = 0; i < m1.numCols; i++)
                res.data[getIndex(res, row, col)] += m1.data[getIndex(m1, row, i)] * m2.data[getIndex(m2, i, col)];
    return res;
    }

