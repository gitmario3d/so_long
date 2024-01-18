/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malena-b <mario3d93@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 12:49:16 by malena-b          #+#    #+#             */
/*   Updated: 2023/12/27 09:30:39 by malena-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_normatoi(int result, int i, int sign, const char	*str)
{
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i + 1] >= '0' && str [i + 1] <= '9')
		{
			if (str[i] == '-')
				sign = -1;
			i++;
		}
		else
			return (0);
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - 48);
		if (str[i + 1] < '0' || str[i + 1] > '9')
			return (result * sign);
		i++;
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	int	result;
	int	i;
	int	sign;

	result = 0;
	sign = 1;
	i = 0;
	result = ft_normatoi(result, i, sign, str);
	return (result);
}

/*int	main(void)
{
	const char	*str = "\t\n\v\f\r -543-01234ab567";

	printf("Original  string: %s\n", str);
	printf("Original result: %d\n", atoi(str));
	printf ("My function result: %d\n", ft_atoi(str));
}*/
