/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostrik <akostrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 13:46:18 by akostrik          #+#    #+#             */
/*   Updated: 2022/11/28 19:05:42 by akostrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Une bibliothèque qui contient ft_printf(), imitant printf() originale
// Contrairement à printf(), ne pas gérer de buffer
// %c caractère
// %s chaîne (telle que définie par la convention C)
// %p L’argument de pointeur void * doit être affiché en hexadécimal
// %d nombre décimal (base 10)
// %i entier en base 10
// %u nombre décimal non signé (base 10)
// %x nombre en hexadécimal (base 16) avec des lettres minuscules
// %X nombre en hexadécimal (base 16) avec des lettres majuscules
// %% %
// rendu : Makefile, *.h, */*.h, *.c, */*.c
// malloc free write libft
// обязательный аргумент – первое переданное число, если его не передавать, то
// не сможем найти адрес, по которому размещаются переменные в стеке

// a pointer to any object type may be converted to void*
// void* is useful in function parameters to allow passing values of any type
// void* can't be dereferenced (it would give a value of type void)
// void* : pointer arithmetic is not possible

// 0x 56 12 21 0d a0 08

/*static char	hex_digit_n_to_char(int n, void *p)
{

}*/

static char	*pointer_to_str(void *p)
{
	char	*str;

	printf("\np          = %p = %c\n",p,*(char*)p);
	printf("sizeof( p) = sizeof(%p) = %zu\n",p,sizeof(p));
	str = ft_calloc(14,1); // 16 ?
	if (str == NULL)
		return (NULL);
	str[0] = '0';
	str[1] = 'x';
	str[2] = ft_itoa(((unsigned long)p & 0x00000000000f))[0];
	str[3] = ft_itoa(((unsigned long)p & 0x0000000000f0) >> 4)[0];
	str[4] = ft_itoa(((unsigned long)p & 0x000000000f00) >> 8)[0];
	str[5] = ft_itoa(((unsigned long)p & 0x00000000f000) >> 12)[0];
	str[6] = ft_itoa(((unsigned long)p & 0x0000000f0000) >> 16)[0];
	str[7] = ft_itoa(((unsigned long)p & 0x000000f00000) >> 20)[0];
	str[8] = ft_itoa(((unsigned long)p & 0x00000f000000) >> 24)[0];
	str[9] = ft_itoa(((unsigned long)p & 0x0000f0000000) >> 28)[0];
	//ft_memcpy(str+2, (char*)p, 12);
	printf("\npointer_to_str returns %s\n",str);
	return (str);
}

static void	ft_putpointer_fd(void *p, int fd)
{
	//if ( == NULL)
	ft_putstr_fd(pointer_to_str(p), fd);
}

int	ft_printf(const char *s, ...)
{
	va_list list_args;
	size_t	i;

	va_start(list_args, s);
	i = 0;
	while (i < ft_strlen((char *)s))
	{
		if (ft_strncmp(&s[i],"%s",2) == 0)
			ft_putstr_fd(va_arg(list_args, char*), 1);
		else if (ft_strncmp(&s[i],"%c",2) == 0)
			ft_putchar_fd(va_arg(list_args, int), 1);
		else if (ft_strncmp(&s[i],"%d",2) == 0)
			ft_putnbr_fd(va_arg(list_args, int), 1);
		else if (ft_strncmp(&s[i],"%p",2) == 0)
			ft_putpointer_fd(va_arg(list_args, void*), 1);
		else
		{
			ft_putchar_fd(s[i], 1);
			i--;
		}
		i += 2;
	}
	va_end(list_args);
	// free
	return (1);
}
