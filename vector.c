#include "vector.h"

/* vector for version 2.0 */
Vector* vector_init(size_t element, size_t capacity) {
	
	
	Array* new_vec = malloc(sizeof(Vector));
	if (new_vec == NULL) {
		new_vec->status_err = -1;
		fprintf(stderr, "Error value %d \n", errno);
		fprintf(stderr, "Error allocating memory %s\n", strerror(errno));	
		/* sorry no memory */
		return NULL;
	} 
	new_vec->size = 0;
	new_vec->element_size = element;
	new_vec->capacity = capacity;

	new_vec->data = malloc(new_vec->capacity * new_vec->element_size);		
	if (new_array->data == NULL) {
		new_array->status_err = -1;
		fprintf(stderr, "Error value %d \n", errno);
		fprintf(stderr, "Error allocating memory %s\n", strerror(errno));	
		/* sorry no memory */
		return NULL;	
	}
	new_vec->status_err = 0;
	
	return new_array; 
}

/* 
	To push an element, we need size and capacity, 
	To know where it store we use this formula start + (index * size)
*/
int vector_push(Vector* vec, const void* element) {
	if (vec->size == vec->capacity)	{
		vec->capacity *= 2;

		void* new_space = realloc(vec->data, vec->capacity * vec->element_size);
		if (new_space == NULL) {
			/* write to status error */
			vec->status_err = -1;
			fprintf(stderr, "Error value %d \n", errno);
			fprintf(stderr, "Error allocating memory %s\n", strerror(errno));	
			return -1;
		}
		vec->data = new_space;
	}

	/* calculate where the memory will be store */
	void* target = (char*)vec->data + (vec->size * vec->element_size);
	memcpy(target, element, vec->element_size);
	vec->size++;
	return 0;
}

/*
	Just like an array
	Just give it index
	Using our previous formula start + (index * size)
	It will give us the location where it stored 
*/
void* array_get(Vector* vec, size_t index) {
    if (index >= vec->size) return NULL;
    return (char *)vec->data + (index * vec->element_size);
}

void array_free(Vector* vec) {
	free(vec->data);
	free(vec);
}


