#include <stdio.h>
#include <stdlib.h>

//set ค่าตัวแปร 
int globalVariables1, globalVariables2, globalVariables3;
int globalVariables4 = 4, globalVariables5= 5;

//function call memory
void CallMemoryManagement( int level ) {
    //จองพื้นทีของ stack
    int stackVariables = level;

    //malloc จองพื้นทีของ heap
    int *heapVariables = ( int * )malloc( sizeof( int ) );
    *heapVariables = level;

    //print level and address
	//stack
    printf( "Stack level = %d, Stack address = %p\n", level, &stackVariables );
	//heap
    printf( "Heap level = %d, Heap address = %p\n", level, heapVariables );
    printf( "---------------------------------\n" );
    
    if ( level < 3 ) {
        //call function
        CallMemoryManagement( level + 1 );
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
    CallMemoryManagement( 0 );

    //จบการทำงาน
    return 0;
}