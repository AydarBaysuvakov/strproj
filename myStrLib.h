#ifndef __STRLIB__
#define __STRLIB__

#include <stdio.h>
#include <stdlib.h>

/// @brief Writes every character from the null-terminated string str and one additional newline character '\n' to the output stream stdout.
/// @param [in] str  character string to be written
/// @return On success, returns a non-negative value. On failure, returns EOF and sets the error indicator (see ferror()) on stream.
/// @note The puts function appends the newline character to the output, while fputs function does not. Different implementations return different non-negative numbers: some return the last character written, some return the number of characters written (or INT_MAX if the string was longer than that), some simply return a non-negative constant. A typical cause of failure for puts is running out of space on the file system, when stdout is redirected to a file.
int puts_( const char* str );

/// @brief Finds the first occurrence of ch in the null-terminated byte string pointed to by str.
/// @param str pointer to the null-terminated byte string to be analyzed.
/// @param ch character to search for.
/// @return Pointer to the found character in str, or null pointer if no such character is found.
char *strchr_( const char *str, int ch );

/// @brief Returns the length of the given null-terminated byte string, that is, the number of characters in a character array whose first element is pointed to by str up to and not including the first null character.
/// @param str pointer to the null-terminated byte string to be examined
/// @return The length of the null-terminated byte string str.
int strlen_( const char *str );

/// @brief Copies the null-terminated byte string pointed to by src, including the null terminator, to the character array whose first element is pointed to by dest.
/// @param dest pointer to the character array to write to
/// @param src pointer to the null-terminated byte string to copy from
/// @return a copy of dest
char *strcpy_( char *dest, const char *src );

/// @brief Copies at most count characters of the character array pointed to by src (including the terminating null character, but not any of the characters that follow the null character) to character array pointed to by dest.
/// @param dest pointer to the character array to copy to
/// @param src pointer to the character array to copy from
/// @param count maximum number of characters to copy
/// @return a copy of dest
char *strncpy_( char *dest, const char *src, size_t count );

/// @brief Appends a copy of the null-terminated byte string pointed to by src to the end of the null-terminated byte string pointed to by dest. The character src[0] replaces the null terminator at the end of dest. The resulting byte string is null-terminated.
/// @param dest pointer to the null-terminated byte string to append to.
/// @param src pointer to the null-terminated byte string to copy from
/// @return a copy of dest
char *strcat_( char *dest, const char *src );

/// @brief Appends at most count characters from the character array pointed to by src, stopping if the null character is found, to the end of the null-terminated byte string pointed to by dest. The character src[0] replaces the null terminator at the end of dest. The terminating null character is always appended in the end (so the maximum number of bytes the function may write is count+1).
/// @param dest pointer to the null-terminated byte string to append to.
/// @param src pointer to the character array to copy from.
/// @param count maximum number of characters to copy.
/// @return a copy of dest
char *strncat_( char *dest, const char *src, size_t count );

/// @brief Reads at most count - 1 characters from the given file stream and stores them in the character array pointed to by str. Parsing stops if a newline character is found, in which case str will contain that newline character, or if end-of-file occurs. If bytes are read and no errors occur, writes a null character at the position immediately after the last character written to str.
/// @param str pointer to an element of a char array
/// @param count maximum number of characters to write (typically the length of str)
/// @param stream file stream to read the data from
/// @return str
char *fgets_( char *str, int count, FILE *stream );

/// @brief Returns a pointer to a null-terminated byte string, which is a duplicate of the string pointed to by src. The space for the new string is obtained as if the malloc was invoked. The returned pointer must be passed to free to avoid a memory leak.
/// @param src pointer to the null-terminated byte string to duplicate.
/// @return A pointer to the newly allocated string, or a null pointer if an error occurred.
char *strdup_( const char *src );

#endif //__STRLIB__
