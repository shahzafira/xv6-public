#include "types.h"
#include "stat.h"
#include "user.h"
#include "mmu.h"

void
mprotectTest() 
{
    printf(1, "\nStart of mprotect test: \n");

    int *value = (int*) sbrk(sizeof(int));
    *value = 5;
    printf(1, "Created address: %d \n", *value);

    // Make value read write to ensure it is writable first
    munprotect((void*) value, 1);
    // Make value read only
    mprotect((void*) value, 1);
    printf(1, "mprotect called, expect a Page Fault \n");

    printf(1, "Attempting to change address value \n");
    *value = 10;
    printf(1, "This should not be seen: the address value has been changed \n \n");
}

int
main(int argc, char *argv[])
{
  mprotectTest();
  exit();
}