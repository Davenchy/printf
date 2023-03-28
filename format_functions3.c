#include "main.h"
#include <ctype.h>
#include <stdarg.h>

/**
 * case_address - function to handle pointer address format
 * @ap: the variadic list pointer
 * Return: number of characters had been printed
 */
int case_address(va_list ap)
{
	unsigned long value = va_arg(ap, unsigned long);
	char str[19];

	if (!value)
		return pstr("(nil)");

	str[0] = '0';
	str[1] = 'x';
	if (!number_converter(str + 2, value, 16))
		return (0);
	return (pstr(str));
}

/**
* case_R13 - convert normal string to rot13 string
* @ap: the variadic list pointer
* Return: number of characters had been printed
*/
int case_R13(va_list ap)
{
        int counter = 0;
	char *str = va_arg(ap, char *);
        
        if (!str)
                return (0);

        for(; *str; str++)
        {
                if ( *str >= 65 && *str <= 90)
        {
                counter += pchar(((90 - *str) >= 13) ? *str + 13 : *str - 13);
                continue;
        }

        else if ( *str >= 97 && *str <= 122)
        {
                counter += pchar(((122 - *str) >= 13) ? *str + 13 : *str - 13);
                continue;
        }
        counter += pchar(*str);
        }
        return (counter);
}


int case_S(va_list ap)
{
        int counter = 0;
        char *str = va_arg(ap, char *); 

        for (; *str; str++)
        {
                char str_2[5];


                str_2[0] = '\\';
                str_2[1] = 'x';
                str_2[2] = '0';

                if (isprint(*str))
                {
                        counter += pchar(*str);
                        continue;
                }
                number_converter(str_2 + 3, *str, 16);
                str_2[3] = toupper(str_2[3]);
                str_2[4] = toupper(str_2[4]);
                counter += pstr(str_2);
        }
        return (counter);
}



















