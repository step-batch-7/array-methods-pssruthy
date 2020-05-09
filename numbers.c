#include<stdio.h>
#include<stdlib.h>
#include "array.h"

int square(int number){
  return number * number;
}

Bool is_even(int number){
  if (number % 2 == 0) return True;
  return False;
}

int add(int num1, int num2 ){
  return num1 + num2;
}

void display_array(Array_ptr array){
  for (int index = 0; index < array->length; index++)
  {
    printf("%d ", array->array[index]);
  }
  
}

int main(void){
  int tem_array[] = {1, 2, 3, 4, 5, 6};
  int length = sizeof(tem_array) / sizeof(int);
  Array_ptr array = move_to_array(tem_array, length);

  printf("List :\n");
  display_array(array); 

  Array_ptr result = map( array, &square);
  printf("\nResult from mapping(square) : \n");
  display_array(result); 

  result = filter(array, &is_even);
  printf("\nResult from filter(is_even) : \n");
  display_array(result); 

  printf("\nResult from reducer(add) : \n");
  printf("%d", reduce(array, 0, &add));

  return 0;
}