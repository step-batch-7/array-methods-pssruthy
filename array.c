#include<stdlib.h>
#include "array.h"

Array_ptr move_to_array(int tem_array[], int length){
  Array_ptr array = malloc(sizeof(Array));
  array->array = malloc(sizeof(int) * length);
  array->length = length;

  for (int index = 0; index < length; index++)
  {
    array->array[index] = tem_array[index];
  }
  return array;
}

Array_ptr map(Array_ptr src, Mapper mapper){
  int mapped_array[src->length];

  for (int index = 0; index < src->length; index++)
  {
    mapped_array[index] = (*mapper)(src->array[index]);
  }
  
  return move_to_array(mapped_array, src->length);
}

Array_ptr filter(Array_ptr src, Predicate predicate){
  int filtered_array[src->length];
  int count = 0;
  for (int index = 0; index < src->length; index++)
  {
    if((*predicate)(src->array[index]) == True){
      filtered_array[count] = src->array[index];
      count++;
    }
  }
  return move_to_array(filtered_array, count);
}

int reduce(Array_ptr src, int init, Reducer reducer){
  int context = init;
  for(int index = 0; index < src->length; index++ )
  {
    context =  (*reducer)(src->array[index], context);
  }
  return context;
}
