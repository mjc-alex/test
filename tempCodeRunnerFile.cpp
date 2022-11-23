#include <iostream>

using namespace std;

int main(){

  int ARR_LEN=20;
  int STEP_SIZE=2;
  long SOME_VALUE=100;

  long* arr = new long[ARR_LEN];

  int i;


  for (i=0; i<ARR_LEN; i++){
    arr[i] = 0;
  }

  __asm__ __volatile__
  (
    "loop:"
    "movq %%rdx, (%%rbx);"
    "leaq (%%rbx,%%rcx,4), %%rbx;"
    "cmpq %%rbx, %%rax;"
    "jg loop;"
    : // no output
    : "b" (arr),
      "a" (arr+ARR_LEN),
      "c" (STEP_SIZE),
      "d" (SOME_VALUE)
    : "cc", "memory"
  );

  for (i=0; i<ARR_LEN; i++){
    cout << "element " << i << " is " << arr[i] << endl;
  }

  delete[] arr;

  return 0;

}