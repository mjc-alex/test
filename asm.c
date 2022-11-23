#include "mytest.h"

int main(){
	// int64_t x = 10, y = 2;
	// asm("addq %1 , %2"
	// 	:"=b"(y)
	// 		:"a"(x),"b"(y)
	// 	 );
	// printf("%ld\t%ld\n",x,y);
	int s = 0;
	size_t n = 8,i = 0;
	int src[50],dest[50];
	for (i = 0; i<n; i++){
    	src[i] = i;
  	}
	i = 0;
	asm(".loop:"
      "cmpq $0 , %0;"
      "je .exit;"
      "leaq (%2,%1,4), %2;"
      "leaq (%3,%1,4), %3;"
	  "movl (%3), %%ecx;"
      "movl %%ecx, (%2);"
      "incq %1;"
      ".exit:"
      "cmpq %0,%1;"
      "jl .loop;"
      :
      :"a"(n), "b"(i), "S"(dest), "D"(src)
      :"memory","cc","%ecx"
      );
	//memcpy(dest,src,strlen(src));
	for (i = 0;i < n; i++){
		P("%d\n",dest[i]);
	}
	return 0;
}
// asm(".loop:"
// 		"cmpl $0, %2;"
// 		"je .cmp;"
// 		"shrq $1, %3;"
// 		".cmp:"
// 		"incl %2;"
// 		"testq $1, %3;"
// 		"jz .exit;"
// 		"incl %0;"
// 		".exit:"
// 		"cmpl $0x40, %2;"
// 		"jl .loop;"
// 		:"=a" (s)
// 		:"a" (s),"b" (i),"c" (x)
// 		);	
