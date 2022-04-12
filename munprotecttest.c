#include "types.h"
#include "stat.h"
#include "user.h"
#include "mmu.h"

void
munprotectTest() 
{
    printf(1, "\nStart of munprotect test: \n");

    int *value = (int*) sbrk(sizeof(int));
    *value = 5;
    printf(1, "Created address: %d \n", *value);

    // Make value read only to ensure it is not writable
    mprotect((void*) value, 1);
    // Make value read write
    munprotect((void*) value, 1);
    printf(1, "munprotect called, the address value can now be changed \n");

    printf(1, "Attempting to change address value \n");
    *value = 10;
    printf(1, "Address value changed \nOriginal value: 5 \nUpdated value: %d. \n \n", *value);
}

int
main(int argc, char *argv[])
{
  munprotectTest();
  exit();
}