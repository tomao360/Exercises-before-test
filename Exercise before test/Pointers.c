#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable : 4996)


//-----------pointers-----------
void reverse(char* str)
{
	char a;
	int len = strlen(str) - 1;

	for (int i = 0; i <= len / 2; i++)
	{
		a = *(str + i);
		*(str + i) = *(str + len - i);
		*(str + len - i) = a;
	}

	printf("%s", str);
}

void PointerMathOps()
{
    float num1, num2;    // Normal variables to contain Data
    float* ptr1, * ptr2;  // Pointer variables 

    float sum, diff, mult, div;

    ptr1 = &num1; // ptr1 stores the address of num1
    ptr2 = &num2; // ptr2 stores the address of num2

    /* User input to Pointers */
    printf("Enter any two real numbers: ");
    scanf("%f%f", ptr1, ptr2);

    /* Perform arithmetic operation */
    sum = (*ptr1) + (*ptr2);
    diff = (*ptr1) - (*ptr2);
    mult = (*ptr1) * (*ptr2);
    div = (*ptr1) / (*ptr2);

    /* Print the results */
    printf("Sum = %.2f\n", sum);
    printf("Difference = %.2f\n", diff);
    printf("Product = %.2f\n", mult);
    printf("Div Result = %.2f\n", div);
}


/**
 * Function to swap two numbers
 */
void swap(int* num1, int* num2)
{
    int temp;

    // Copy the value of num1 to some temp variable
    temp = *num1;

    // Copy the value of num2 to num1
    *num1 = *num2;

    // Copy the value of num1 stored in temp to num2
    *num2 = temp;

    printf("After swapping in swap function n");
    printf("Value of num1 = %d \n", *num1);
    printf("Value of num2 = %d \n\n", *num2);
}


int main_2()
{
	char arr[10] = "targil";
	reverse(arr);
    PointerMathOps();

    int num1, num2;

    /* Input numbers */
    printf("Enter two numbers: ");
    scanf("%d%d", &num1, &num2);

    /* Print original values of num1 and num2 */
    printf("Before swapping in main n");
    printf("Value of num1 = %d \n", num1);
    printf("Value of num2 = %d \n\n", num2);

    /* Pass the addresses of num1 and num2 */
    swap(&num1, &num2);

    /* Print the swapped values of num1 and num2 */
    printf("After swapping in main n");
    printf("Value of num1 = %d \n", num1);
    printf("Value of num2 = %d \n\n", num2);

	return 0;
}
