/**
 * To build the program:
 * 	arm-linux-gnueabihf-gcc main.c -o main
 * To run the program
 * 	qemu-arm -L /usr/arm-linux-gnueabihf ./main
 */

#include <stdio.h>

int asm_func1(int a) {
    register int result;
    asm volatile (
        "mov r1, #2\n"
        "add %0, %1, r1"
        : "=r" (result)
        : "r" (a)
    );
    return result;
}

int asm_func2(int a) {
    register int result;
    asm volatile (
        "mov r1, #6\n"
        "sub %0, %1, r1"
        : "=r" (result)
        : "r" (a)
    );
    return result;
}

int asm_func3(int a) {
    register int result;
    asm volatile (
        "mov r1, #2\n"
       
        "mul %0, %1, r1"
        : "=r" (result)
        : "r" (a)
    );
    return result;
}

int main(void) {
    int c = 0x01;
    int a = 0x456;
    int b = a;

    printf("La valeur de a est %d\n", a);
    printf("La valeur de b est %d\n", b);
    printf("La valeur de c est %d\n", c);

    b = asm_func1(a);   // - asm_func1 that returns a+2
    printf("%d\n", b);

    b = asm_func2(a);   // - asm_func2 that returns a - 6
    printf("%d\n", b);

    c = asm_func3(c);    // - asm_func3 that returns c*2
    printf("%d\n", c);

    return 0;
}
