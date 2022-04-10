// #include "types.h"
// #include "user.h"

// int main()
// {
//     int *code;
//     code = (int *)4096;
//     int orig = code[0];
//     printf(1, "orig code: %x\n", orig);
//     code[0] = 0;
//     printf(1, "now code: %x\n", code[0]);
//     mprotect(code, 1);
//     printf(1, "after protect: %x\n", code[0]);
//     // if we mod code[0] here, will segfault
//     munprotect(code, 1);
//     code[0] = orig;
//     printf(1, "after unprotect and mod: %x\n", code[0]);
//     exit();
// } 

#include "types.h"
#include "stat.h"
#include "user.h"
#include "mmu.h"
int
main()
{ 
    uint start;
    start = (uint)4096;
    // sbrk(PGSIZE);
    // *start=100;
    mprotect(start, 1) ;
    int child=fork();
    if(child==0){
        printf(1, "protected value = %d\n",start); 
            munprotect(start, 1) ;  
            start=5;
            printf(1, "After unprotecting the value became = %d\n",start); 
            exit();
    }
    else if(child>0){
            wait();
            printf(1, "\nWatch this,I'll trap now\n"); 
            start=5; 
            printf(1, "\nThis statement will not be printed\n");
            exit(); 
} 
  //char arr[]={'1','2','3','4'};
  //arr[0]='a';
  /*printf(1,"\narr[0] = %d\n",arr[0]);
  mprotect((void *)(((uint)arr/PGSIZE)*PGSIZE),1);
  printf(1,"reched here \n");
//  munprotect((void *)(((uint)arr/PGSIZE-1)*PGSIZE),1);
  arr[0]='b';
   printf(1,"\narr[0] = %d\n",arr[0]);
  */ 
 exit();
}