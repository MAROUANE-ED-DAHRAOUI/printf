#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>

#define BUFF_SIZE 1024
#define BUFF_FLUSH -1

#define NULL_STR "(null)"

#define PARAMS_INIT {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

#define CONV_LOWER 1
#define CONV_UNSIGNED 2

/**
 * struct parameters - parameters struct
 *
 * @unsign: flag if unsigned value
 *
 * @plus_flag: on if + flag specified
 * @space_flag: on if space flag specified
 * @hashtag_flag: on if # flag specified
 * @zero_flag: on if 0 flag specified
 * @minus_flag: on if - flag specified
 *
 * @width: field width specified
 * @precision: field precision specified
 *
 * @h_modifier: on if h modifier is specified
 * @l_modifier: on if l modifier is specified
 *
 */

typedef struct parameters
{
	unsigned int unsign : 1;

	unsigned int plus_flag : 1;
	unsigned int space_flag : 1;
	unsigned int hashtag_flag : 1;
	unsigned int zero_flag : 1;
	unsigned int minus_flag : 1;

	unsigned int width;
	unsigned int precision;

	unsigned int h_modifier : 1;
	unsigned int l_modifier : 1;

} params_t;

/**
 * struct specifier - struct token
 *
 * @specifier: format token
 * @f: the function associated
 */
typedef struct specifier
{
	char *specifier;
	int (*f)(va_list, params_t *);
} specifier_t;
