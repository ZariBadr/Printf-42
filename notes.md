## the variadic function 
	we will use the **#include <stdarg.h> library**
	
	**va_list** : is an object type that will holds all the infos by the macros <va_start,va_arg,va_copy,va_end>
	**va_start**: its purpose it to initialize everything before starting
	its written like the following:
	> va_start( va_list var, parameterN );
	*for exemple*
	va_start(args, format); the parameterN is the mandatory argument
	**va_arg** : its me made to access the arguments
	*for exemple*
	va_arg( va_list var,type_of_the_variable)
		printf("name : %s, age : %d","badr",22);
		va_arg( args, char *) -> "laura"
		va_arg( args, int ) -> 22
	**va_end** : once you finish your program it will clean up the object for you
	*for exemple*
	va_end(args) it will free the allocated memory
	
	
## details:
	**allowed functions** : malloc,free,write,va_start,va_arg,va_copy,va_end
	**make file** : NAME, all, clean, fclean, re
	**libft-authorized** : yes
# 1 :
	The printf function will write each character of the intial string, one by one, until it finds a %
# 2 : 
	When it finds a %, it will look at the element in the next index/position. It will find the character that will define the type of the first variable argument.
# 3 :
	Depending on what it finds, it will call a method that will display the argument of the particular type at output.
	-> if there is a "s" after the %, then you will need a function that displays strings.
	-> if there is a "d" after the %, then you will need a function that displays numbers. etc.
# 4 :
	Once the first variable argument has been written, you go back to step 1, until the string is finished (aka, until you find a null character (\0)).
	
