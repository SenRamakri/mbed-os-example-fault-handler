#include "mbed.h"

//Prototypes
void generate_zero_div_fault(void);

// main() runs in its own thread in the OS
int main() {
  
    printf("\nMbed-OS fault handler test\n");
    while (true) {
        printf("\nForcing div-by-zero exception\n");
        generate_zero_div_fault();
    }
}

void generate_zero_div_fault()
{
  SCB->CCR |= SCB_CCR_DIV_0_TRP_Msk;
  int x = 1;
  int y = 0;
  int s = x / y;
  printf("SOMETHING WRONG!!! We shouldn't be here...");
  return;
}




