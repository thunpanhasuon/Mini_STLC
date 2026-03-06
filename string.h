#ifndef CS67_H
#define CS67_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

/* 
 * str_equal
 * --------------------------
 * Compares two strings for equality.
 * Returns 1 if equal, 0 otherwise
 */
int str_equal(const char *a, const char *b);

/* 
 * str_len
 * --------------------------
 * Returns the length of a null-terminated string (excluding the null character)
 */
int str_len(const char* s);

/* 
 * str_cat
 * --------------------------
 * Concatenates src to the end of dest.
 * dest must have enough space to hold the result.
 * Returns pointer to dest
 */
char *str_cat(char* dest, const char* src);

/* 
 * str_chr
 * --------------------------
 * Returns a pointer to the first occurrence of character uc in str.
 * Returns NULL if character not found
 */
char *str_chr(const char *str, const char uc);

/* 
 * str_copy
 * --------------------------
 * Copies the string src into dest.
 * dest must have enough space.
 * Returns pointer to dest
 */
char *str_copy(char* dest, const char* src);

/* 
 * str_clone
 * --------------------------
 * Allocates memory and creates a copy of the string s.
 * Caller is responsible for freeing the returned string.
 * Returns pointer to the cloned string
 */
char *str_clone(const char *s);


#endif // CS67_H
