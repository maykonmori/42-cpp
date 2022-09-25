#include "Convert.hpp"

/**
 * It takes a string as an argument, parses it, and prints the result to the standard output
 * 
 * @param argc The number of arguments passed to the program.
 * @param argv The argument vector.
 * 
 * @return The return value is the exit status of the program.
 */
int main(int argc, char const **argv)
{

	if (argc != 2)
		return (0);
	
	Convert convert(argv[1]);

	convert.parse();
	return 0;
}
