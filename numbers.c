#include<stdio.h>
#include<stdlib.h>
#include "array.h"
#include "array_void.h"

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
  printf("\n");
}

//-----Object related functions ------

Object square_void(Object object){
  long int number = (long int )object;
  Object result = (Object)(number * number);
  return result;
}

Bool is_even_void(Object object){
  int number = (long int) object;
  if (number % 2 == 0) return True;
  return False;
}

Object add_void(Object object1, Object object2 ){
  long int number1 = (long int) object1;
  long int number2 = (long int) object2;
  Object result = (Object)(number1 + number2);
  return result;
}

void display_number_array_void(ArrayVoid_ptr array){
  for (int index = 0; index < array->length; index++)
  {
    printf("%d ", (int) array->array[index]);
  } 
  printf("\n");
}

int main(void){
  int tem_array[] = {1, 2, 3, 4, 5, 6};
  int length = sizeof(tem_array) / sizeof(int);
  Array_ptr array = move_to_array(tem_array, length);

  printf("List :\n");
  display_array(array); 

  printf("Result from mapping(square) : \n");
  display_array(map( array, &square)); 

  printf("Result from filter(is_even) : \n");
  display_array(filter(array, &is_even)); 

  printf("Result from reducer(add) : \n");
  printf("%d", reduce(array, 0, &add));

  printf("\n\n---------void---------\n");

  ArrayVoid_ptr array_void = create_array_void(5);
  array_void->array[0] = (Object) + 1;
  array_void->array[1] = (Object) + 2;
  array_void->array[2] = (Object) + 3;
  array_void->array[3] = (Object) + 4;
  array_void->array[4] = (Object) + 5;

  display_number_array_void(array_void);
  printf("Result from mapping(square) : \n");
  display_number_array_void(map_void( array_void, &square_void)); 

  return 0;
}