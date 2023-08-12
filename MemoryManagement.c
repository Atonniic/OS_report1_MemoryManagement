#include <stdio.h>
#include <stdlib.h>

//set ค่าตัวแปร
int globalVariables1, globalVariables2, globalVariables3, globalVariables4, globalVariables5;

//function call stack
void CallStackFunc( int level ) {
    //set ค่าตัวแปร
    int stackVariables = 0;

    //malloc จองพื้นที่ใน memory
    int *heapVariables = ( int * )malloc( sizeof( int ) );
    *heapVariables = 0;

    //print level stack และ heap
    printf( "Stack level = %d, Stack address = %p\n", level, &stackVariables );
    printf( "Heap level = %d, Heap address = %p\n", level, heapVariables );
    printf( "---------------------------------\n" );
    
    if ( level < 5 ) {
        //call function
        CallStackFunc( level + 1 );
    }

    //free *คืนพื้นที่ที่จองไว้ 
    free(heapVariables);
}

int main() {
    //print address ของตัวแปรแต่ละตัว
    printf("address of globalVariables1 = %p\n", &globalVariables1);
    printf("address of globalVariables2 = %p\n", &globalVariables2);
    printf("address of globalVariables3 = %p\n", &globalVariables3);
    printf("address of globalVariables4 = %p\n", &globalVariables4);
    printf("address of globalVariables5 = %p\n", &globalVariables5);

    //call function
    CallStackFunc( 1 );

    //จบการทำงาน
    return 0;
}
