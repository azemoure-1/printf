#include "main.h"

/**
 * print_c - prints a character
 * @ap: argument pointer
 * @params: the parameters struct
 *
 * Return: bytes printed
 */
int print_c(va_list ap, params_t *params)
{
	char c;

	if (params->l_modifier)
		return (print_wc(va_arg(ap, wint_t), params));
	c = va_arg(ap, int);
	return (print_char(c, params));
}

/**
 * print_s - prints a string
 * @ap: argument pointer
 * @params: the parameters struct
 *
 * Return: bytes printed
 */
int print_s(va_list ap, params_t *params)
{
	char *str;

	if (params->l_modifier)
		return (print_ws(va_arg(ap, wchar_t *), params));
	str = va_arg(ap, char *);
	if (!str)
		str = "(null)";
	return (print_str(str, params));
}

/**
 * print_di - prints decimal and integer numbers
 * @ap: argument pointer
 * @params: the parameters struct
 *
 * Return: bytes printed
 */
int print_di(va_list ap, params_t *params)
{
	long int l;

	if (params->l_modifier)
		l = va_arg(ap, long int);
	else if (params->h_modifier)
		l = (short int)va_arg(ap, int);
	else
		l = va_arg(ap, int);
	return (print_number(convert(l, 10, 0, params), params));
}

/**
 * print_b - prints binary numbers
 * @ap: argument pointer
 * @params: the parameters struct
 *
 * Return: bytes printed
 */
int print_b(va_list ap, params_t *params)
{
	unsigned int l;

	if (params->l_modifier)
		l = va_arg(ap, unsigned long int);
	else if (params->h_modifier)
		l = (unsigned short int)va_arg(ap, unsigned int);
	else
		l = va_arg(ap, unsigned int);
	return (print_number(convert(l, 2, CONVERT_UNSIGNED, params), params));
}

/**
 * print_o - prints octal numbers
 * @ap: argument pointer
 * @params: the parameters struct
 *
 * Return: bytes printed
 */
int print_o(va_list ap, params_t *params)
{
	unsigned long int l;

	if (params->l_modifier)
		l = va_arg(ap, unsigned long int);
	else if (params->h_modifier)
		l = (unsigned short int)va_arg(ap, unsigned int);
	else
		l = va_arg(ap, unsigned int);
	return (print_number(convert(l, 8, CONVERT_UNSIGNED, params), params));
}

/**
 * print_u - prints unsigned decimal numbers
 * @ap: argument pointer
 * @params: the parameters struct
 *
 * Return: bytes printed
 */
int print_u(va_list ap, params_t *params)
{
	unsigned long int l;

	if (params->l_modifier)
		l = va_arg(ap, unsigned long int);
	else if (params->h_modifier)
		l = (unsigned short int)va_arg(ap, unsigned int);
	else
		l = va_arg(ap, unsigned int);
	params->unsign = 1;
	return (print_number(convert(l, 10, CONVERT_UNSIGNED, params), params));
}

/**
 * print_x - prints hexadecimal numbers in lowercase
 * @ap: argument pointer
 * @params: the parameters struct
 *
 * Return: bytes printed
 */
int print_x(va_list ap, params_t *params)
{
	unsigned long int l;

	if (params->l_modifier)
		l = va_arg(ap, unsigned long int);

