#include <cstdlib>
#include <cmath>
#include <vector>
#include <iomanip>
#include <iostream>

using namespace std;

void printvec(vector<int> & A) {
  cout << "A: ";
  for (int i = 0; i < A.size(); i++) {
    cout << A[i];
    if (i < A.size() - 1)
      cout << " ";
  }
  cout << endl;
}

void mystery(vector<int> & A) {
    int n = A.size();
    for (int i = 1; i < n; ++i) {
        cout << "i = " << i << ", ";
        printvec(A);
        int j = i;                    // Initialize j.
        while (j > 0) {
            if (A[(j-1)/2] <= A[j])   // Integer division.
                break;                // End the loop early.
            int temp = A[j];          // LINE A.
            A[j] = A[(j-1)/2];        // LINE B.
            A[(j-1)/2] = temp;        // LINE C.
            j = (j-1)/2;
        }
    }
    cout << "i = " << n << ", ";
    printvec(A);
}

int fun(int n) {
    int r;
    int s = 0;
    for (int q = 1; q <= n; q++)
        s = s + q;
    s *= 2;
    for (r = s / 2; r > 2; r--)
        s--;
    return r * s;
}

void csort(vector<int>& A) {
    unsigned int n = A.size();
		
	int* H = new int[11]; // valid indices from 0 to 10
	for (unsigned int i = 0; i <= 10; i++) {    // line 5
	    H[i] = 0;    // line 6
	}
		
	for (unsigned int j = 0; j < n; j++) {    // line 9
	    H[A[j]] += 1;    // line 10
	}    // line 11
	
  cout << "H: ";
  for (unsigned int i = 0; i <= 10; i++) {
    cout << H[i] << " ";
  }
  cout << endl;

	unsigned int a = 0;    // line 13
	for (unsigned int h = 0; h <= 10; h++) {    // line 14
	    int c = H[h];    // line 15
		for (unsigned int k = 0; k < c; k++) {    // line 16
		    A[a+k] = h;    // line 17
		}
		a += c;    // line 19
	}
    
    delete[] H;
}

int main(int argc, char *argv[])
{
    vector<int> A = {7, 0, 6, 3, 2, 5, 0, 1, 0, 0, 9, 0, 4, 3, 0, 7};
    // csort(A);

    vector<int> B = {7, 8, 2, 5, 4};
    mystery(B);


    return EXIT_SUCCESS;
}
