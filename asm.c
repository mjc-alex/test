#include "mytest.h"

int main(){
	//int64_t x = 10, y = 2;
	//asm("addq %1 , %2"
	//	:"=b"(y)
	//		:"a"(x),"b"(y)
	//	 );
	//printf("%ld\t%ld\n",x,y);
	int s = 0;
	asm("mov  $0x0, %%eax;"
			 "mov	 $0x3,%%ecx;"
			 ".loop:cmp  %%ecx, %%eax;"
			 "jge  .ret;"
			  "add $0x1 , %1;"
				"add  $0x1, %%eax;"
				"jmp  .loop;"
			".ret:retq"  
			:"=b"(s)
			:"b"(s)
	);
	P("%d\n",s);
	return 0;
}
		
