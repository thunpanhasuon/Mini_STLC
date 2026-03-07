#ifndef VECTOR_H
#define VECTOR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

typedef struct {
    void *data;
    size_t element_size;
    size_t size;
    size_t capacity;
} Vector;

extern int errno;
/**
 * @file vector.h
 * @brief A generic dynamic array (vector) implementation in C
 */

/**
 * @brief Initializes a new vector
 * 
 * @param element   Size of each element in bytes (use sizeof)
 * @param capacity  Initial capacity of the vector
 * @return          Pointer to the new vector, or NULL on failure
 * 
 * @example
 *   Vector* v = vector_init(sizeof(int), 4);
 */
Vector* vector_init(size_t element, size_t new_capacity);

/**
 * @brief Pushes an element to the end of the vector
 * 
 * @param vec     Pointer to the vector
 * @param element Pointer to the element to push
 * @return        0 on success, -1 on failure
 */
int vector_push(Vector* vec, const void* element);

/**
 * @brief Removes the last element
 * 
 * @param vec Pointer to the vector
 * @return    0 on success, -1 if vector is empty
 */
int vector_pop_back(Vector* vec);

/**
 * @brief Gets element at index
 * 
 * @param vec   Pointer to the vector
 * @param index Zero-based index
 * @return      Pointer to element, or NULL if out of bounds
 */
void* vector_get(Vector* vec, size_t index);

/**
 * @brief Frees all memory associated with the vector
 * 
 * @param vec Pointer to the vector
 */
void vector_free(Vector* vec);

#endif // VECTOR_H 
