#include<stdlib.h>
#include "array_void.h"

ArrayVoid_ptr create_array_void(int length){
  ArrayVoid_ptr void_array = malloc(sizeof(ArrayVoid));
  void_array->array = malloc(sizeof(Object) * length);
  void_array->length = length;
  return void_array;
}

ArrayVoid_ptr map_void(ArrayVoid_ptr src, MapperVoid mapper){
  ArrayVoid_ptr mapped_array = create_array_void(src->length);

  for (int index = 0; index < src->length; index++)
  {
    mapped_array->array[index] = (*mapper)(src->array[index]);
  }
  
  return mapped_array;
}
