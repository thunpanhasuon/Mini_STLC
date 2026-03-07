#include "vector.h"

/* vector for version 2.0 */
Vector* vector_init(size_t element, size_t new_capacity) {
	
	
	Vector* new_vec = malloc(sizeof(Vector));
	if (new_vec == NULL) {
		fprintf(stderr, "Error value %d \n", errno);
		fprintf(stderr, "Error allocating memory %s\n", strerror(errno));	
		new_vec->data = NULL;
		/* sorry no memory */
		return NULL;
	} 

	new_vec->size = 0;
	new_vec->element_size = element;
	new_vec->capacity = new_capacity;

	new_vec->data = malloc(new_vec->capacity * new_vec->element_size);		
	if (new_vec->data == NULL) {
		fprintf(stderr, "Error value %d \n", errno);
		fprintf(stderr, "Error allocating memory %s\n", strerror(errno));	
		new_vec->data = NULL;
		/* sorry no memory */
		return NULL;	
	}
	
	return new_vec; 
}

int vector_push(Vector* vec, const void* element) {
	if (vec->size == vec->capacity)	{
		vec->capacity *= 2;

		void* new_space = realloc(vec->data, vec->capacity * vec->element_size);
		if (new_space == NULL) {
			fprintf(stderr, "Error value %d \n", errno);
			fprintf(stderr, "Error allocating memory %s\n", strerror(errno));	
			new_space = NULL;
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

int vector_pop_back(Vector* vec) {
	/* no poppy play time */	
	if (vec->size == 0) return -1;

	vec->size--;

	return 0;
}

void* vector_get(Vector* vec, size_t index) {
    if (index >= vec->size) return NULL;
    return (char *)vec->data + (index * vec->element_size);
}

void vector_free(Vector* vec) {
	free(vec->data);
	free(vec);
}


