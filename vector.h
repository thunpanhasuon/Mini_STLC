#ifndef VECTOR_H
#define VECTOR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

extern int errno;


typedef struct {
    int status_err;
    void *data;
    size_t element_size;
    size_t size;
    size_t capacity;
} Vector;


/* 
 * vec_init
 * --------------------------
 * Creates and initializes a new dynamic array.
 * element_size: size of each element in bytes (e.g., sizeof(int))
 * capacity: initial number of elements the array can hold
 * Returns a pointer to the allocated array (void* internally)
 */
Vector* vector_init(size_t element, size_t capacity);

 /* 
 * vec_push
 * --------------------------
 * Adds a new element to the end of the array.
 * a: pointer to the Array structure
 * element: pointer to the value to push
 * Returns 0 on success, non-zero on failure (e.g., memory allocation failed)
 */
int vector_push(Vector *vec, const void* element);

/* 
 * vec_get
 * --------------------------
 * Returns a pointer to the element at the given index.
 * a: pointer to the Array
 * index: position of the element (0-based)
 * Note: returned pointer must be cast to the correct type by the caller
 */
void* vector_get(Vector* vec, size_t index);

/* 
 * vec_free
 * --------------------------
 * Frees all memory associated with the array.
 * a: pointer to the Array
 * After calling, the array should not be used again.
 */
void vector_free(Vector *vec);
#endif // VECTOR_H
