#include "Arrays.h"

int main(int argc, char** argv)
{
  int A[5] = {};

  A[0] = 1;
  A[1] = 2;
  A[2] = 3;
  A[3] = 4;
  A[4] = 5;

  std::cout << "Size of int : " << sizeof(int) << std::endl;
  std::cout << "Size of int[5] : " << sizeof(A) << std::endl;


  for (int i = 0; i < 5; i++)
  {
    std::cout << "Size of A[" << i << "] : " << sizeof(A[1]) << std::endl;
    std::cout << "A[" << i << "] : " << A[i] << std::endl;
  }

  return 0;
}
