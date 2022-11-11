#include "mytest.h"

int main(){
	// int64_t x = 10, y = 2;
	// asm("addq %1 , %2"
	// 	:"=b"(y)
	// 		:"a"(x),"b"(y)
	// 	 );
	// printf("%ld\t%ld\n",x,y);
	int s = 0, i =0;
	uint64_t x = 0x31;
    // asm(
	// 	// "loop:"
	// 	// "cmpl $0x3, %2;"
	// 	// "jge ret;"
	// 	// "incl %1;"
	// 	// "addl $0x1, %2;"
	// 	// "jmp loop;"
	// 	// "ret:"
	// 	// "retq;"

	//  	// "loop:"
	// 	// "incl %1;"
	// 	// "addl $0x1 , %2;"		
	// 	// "cmpl $0x3,%2;"
	// 	// "jl loop;"
	// 	"cmpl $0x0,%2;"
	// 	"je inflag;"
	// 	"jmp exit;"
	// 	"inflag:incl %1;"
	// 	"exit:"
	// 	:"=b" (s)
	// 	:"b" (s), "a"(i)
	// 	);
	// asm(".loop:"
	//   "cmpl $0, %2;"
	//   "je .cmp;"
    //   "shrq  $1,%3;"
    //   "incl %2;"
	//   ".cmp:"
    //   "cmpq $1,%3;"
    //   "jne .exit"
    //   "incl %1;"
    //   ".exit:"
    //   "cmpl $0x40,%2;"
    //   "jl .loop;"
    //   :"=a" (s)
    //   :"a" (s), "b" (i), "c"(x)
    //   );
	asm(".loop:"
		"cmpl $0, %2;"
		"je .cmp;"
		"shrq $1, %3;"
		".cmp:"
		"incl %2;"
		"testq $1, %3;"
		"jz .exit;"
		"incl %0;"
		".exit:"
		"cmpl $0x40, %2;"
		"jl .loop;"
		:"=a" (s)
		:"a" (s),"b" (i),"c" (x)
		);
	P("%d\n",s);
	return 0;
}
		
