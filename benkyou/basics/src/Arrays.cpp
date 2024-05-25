#include "Arrays.h"

using std::cout;
using std::endl;

void arrays()
{
    int A[5] = {};

    A[0] = 1;
    A[1] = 2;
    A[2] = 3;
    A[3] = 4;
    A[4] = 5;

    cout << "Size of int : " << sizeof(int) << endl;
    cout << "Size of int[5] : " << sizeof(A) << endl;

    for (int i = 0; i < 5; i++)
    {
        cout << "Size of A[" << i << "] : " << sizeof(A[1]) << endl;
        cout << "A[" << i << "] : " << A[i] << endl;
    }
}
