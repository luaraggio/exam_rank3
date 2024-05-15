/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:51:16 by lraggio           #+#    #+#             */
/*   Updated: 2024/05/15 18:03:24 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

void	put_str(char *str, int bytes)
{
	int		i;

	i = 0;
	if (!str)
		write(1,"(null)", 6);
	while (str[i])
		bytes += write(1, &str[i++], 1);
}

void	put_nbr(int nbr, int bytes)
{
	char	*dec;

	dec = "0123456789";
	if (nbr < 0)
	{
		nbr *= -1;
		bytes = write(1, "-", 1);
	}
	if (nbr >= 10)
		put_nbr((nbr / 10), bytes);
	bytes = write(1, &dec[nbr % 10], 1);
}

void	put_hex(int nbr, int bytes)
{
	char	*hex;
	
	hex = "0123456789abcdef";	
	if (nbr >= 16)
		put_hex((nbr / 16), bytes);
	bytes = write(1, &hex[nbr % 16], 1);
}

int	ft_printf(const char *s, ...)
{
	int	bytes;
	int	i;
	va_list	args;

	i = 0;
	bytes = 0;
	va_start(args, s);
	while (s[i])
	{
		if (s[i] == '%' && ((s[i + 1] == 's') || (s[i + 1] == 'd' || s[i + 1] == 'x')))
		{
			i++;
			if (s[i] == 's')
			       put_str(va_arg(args, char *), bytes);
			else if (s[i] == 'd')
				put_nbr(va_arg(args, int), bytes);
			else if (s[i] == 'x')
				put_hex(va_arg(args, unsigned int), bytes);
		}
		else
			bytes += write(1, &s[i], 1);
		i++;
	}
	va_end(args);
	return (bytes);
}

/*int	main(void)
{
	ft_printf("%s\n", "toto");
	ft_printf("Magic %s is %d\n", "number", 42);
	ft_printf("Hexadecimal for %d is %x\n", 42, 42);
}*/
