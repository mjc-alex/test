#include<stdio.h>
void hello(){
        printf("as");
    }
void test(void (*funcptr)()){
    (*funcptr)();
}
typedef int (*HELLOPTR)();
void test2(HELLOPTR h){
    (*h)();
}
void fun(int x){
    printf("%d",x);
}
int main(){
    void (*helloptr)();
    helloptr = hello;
    void (*intptr)(int) = fun;
    test2(intptr);
    
    return 0;
}