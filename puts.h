/** @brief Writes every character from the null-terminated string str and one additional newline character '\n' to the output stream stdout.
 @param [in] str  character string to be written
 @return On success, returns a non-negative value.
On failure, returns EOF and sets the error indicator (see ferror()) on stream.
 @note The puts function appends the newline character to the output, while fputs function does not.
Different implementations return different non-negative numbers: some return the last character written, some return the number of characters written (or INT_MAX if the string was longer than that), some simply return a non-negative constant.
A typical cause of failure for puts is running out of space on the file system, when stdout is redirected to a file.
 */
int puts_( const char* str );
