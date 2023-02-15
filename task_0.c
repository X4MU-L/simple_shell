#ifndef HEADER_FILE_H
#define HEADER_FILE_H
/**
 * main - Entry point
 * Return: Always 0 (Success)
 * @printf: Print standard output
 * @add:  which takes num1 and num2
 * @num1: takes an integer 10
 * @num2: takes an integer 20
 * @int add: takes two integer 'num1' and 'num2', and returns their sum
*/
#include <stdio.h>
int add(int num1, int num2)
{
int result;
result = num1 + num2;
return (result);
}
int main(void)
{
int num1 = 10;
int num2 = 20;
int sum;
sum = add(num1, num2);
printf("The sum of %d and %d is %d\n", num1, num2, sum);
return (0);
}
#endif

