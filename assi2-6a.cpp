#include <iostream>
#include <vector>
using namespace std;

struct Triplet {
    int row, col, value;
};

class SparseMatrix {
public:
    int rows, cols, terms;
    vector<Triplet> data;

    SparseMatrix(int r = 0, int c = 0, int t = 0) {
        rows = r;
        cols = c;
        terms = t;
    }

    void read() {
        cout << "Enter number of rows, columns, and non-zero elements: ";
        cin >> rows >> cols >> terms;
        data.resize(terms);
        cout << "Enter triplets (row, col, value):\n";
        for (int i = 0; i < terms; i++) {
            cin >> data[i].row >> data[i].col >> data[i].value;
        }
    }

    void display() {
        cout << "Sparse Matrix in triplet form:\n";
        cout << "Row Col Value\n";
        for (int i = 0; i < terms; i++) {
            cout << data[i].row << "   " << data[i].col << "   " << data[i].value << "\n";
        }
    }

    // (a) Transpose
    SparseMatrix transpose() {
        SparseMatrix result(cols, rows, terms);
        int idx = 0;
        for (int col = 0; col < cols; col++) {
            for (int i = 0; i < terms; i++) {
                if (data[i].col == col) {
                    result.data.push_back({data[i].col, data[i].row, data[i].value});
                    idx++;
                }
            }
        }
        result.terms = idx;
        return result;
    }

    // (b) Addition
    SparseMatrix add(const SparseMatrix &other) {
        if (rows != other.rows || cols != other.cols) {
            throw invalid_argument("Matrix dimensions must match for addition.");
        }

        SparseMatrix result(rows, cols);
        int i = 0, j = 0;

        while (i < terms && j < other.terms) {
            if (data[i].row < other.data[j].row ||
               (data[i].row == other.data[j].row && data[i].col < other.data[j].col)) {
                result.data.push_back(data[i++]);
            } else if (data[i].row > other.data[j].row ||
                      (data[i].row == other.data[j].row && data[i].col > other.data[j].col)) {
                result.data.push_back(other.data[j++]);
            } else {
                int summed = data[i].value + other.data[j].value;
                if (summed != 0) {
                    result.data.push_back({data[i].row, data[i].col, summed});
                }
                i++; j++;
            }
        }

        // Add remaining elements
        while (i < terms) result.data.push_back(data[i++]);
        while (j < other.terms) result.data.push_back(other.data[j++]);

        result.terms = result.data.size();
        return result;
    }

    // (c) Multiplication
    SparseMatrix multiply(const SparseMatrix &other) {
        if (cols != other.rows) {
            throw invalid_argument("Invalid dimensions for multiplication.");
        }

        SparseMatrix result(rows, other.cols);
        SparseMatrix otherT = other.transpose();

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < other.cols; j++) {
                int sum = 0;
                for (int a = 0; a < terms; a++) {
                    if (data[a].row == i) {
                        for (int b = 0; b < otherT.terms; b++) {
                            if (otherT.data[b].row == j && data[a].col == otherT.data[b].col) {
                                sum += data[a].value * otherT.data[b].value;
                            }
                        }
                    }
                }
                if (sum != 0) {
                    result.data.push_back({i, j, sum});
                }
            }
        }

        result.terms = result.data.size();
        return result;
    }
};
