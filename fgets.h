/// @brief Reads at most count - 1 characters from the given file stream and stores them in the character array pointed to by str. Parsing stops if a newline character is found, in which case str will contain that newline character, or if end-of-file occurs. If bytes are read and no errors occur, writes a null character at the position immediately after the last character written to str.
/// @param str pointer to an element of a char array
/// @param count maximum number of characters to write (typically the length of str)
/// @param stream file stream to read the data from
/// @return str
char *fgets_( char *str, int count, FILE *stream );
