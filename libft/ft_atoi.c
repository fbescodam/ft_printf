/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/17 15:17:14 by fbes          #+#    #+#                 */
/*   Updated: 2021/03/03 18:17:34 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

static int	ft_is_whitespace(char c)
{
	if (
		c == ' '
		|| c == '\f'
		|| c == '\n'
		|| c == '\r'
		|| c == '\t'
		|| c == '\v')
	{
		return (1);
	}
	return (0);
}

static int	ft_is_odd_or_even(int n)
{
	if (n == 0 || n % 2 == 0)
		return (1);
	else
		return (-1);
}

int	ft_atoi(const char *str)
{
	int		num;
	int		i;
	int		signs;

	num = 0;
	signs = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (ft_is_whitespace(str[i]) && num == 0 && signs == 0)
			num = 0;
		else if (str[i] >= '0' && str[i] <= '9')
			num = num * 10 + ((int)str[i] - 48);
		else if (str[i] == '-' && signs == 0 && num == 0)
			signs += 1;
		else if (str[i] == '+' && signs == 0 && num == 0)
			signs += 2;
		else
			break ;
		i++;
	}
	return (num * ft_is_odd_or_even(signs));
}
