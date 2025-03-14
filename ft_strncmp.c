/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anilchen <anilchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 12:23:44 by anilchen          #+#    #+#             */
/*   Updated: 2024/06/24 16:51:52 by anilchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Функция strncmp в языке программирования C используется для сравнения
// первых n символов двух строк. Она возвращает значение, указывающее на
// лексикографическое отношение между строками.
// Возвращаемое значение:
// 0, если первые n символов строк равны.
// Положительное значение, если первая строка больше второй.
// Отрицательное значение, если первая строка меньше второй.

// #include <ctype.h>
// #include <stdio.h>
// #include <fcntl.h>
// #include <string.h>

int	ft_strncmp(const char *str1, const char *str2, size_t num)
{
	size_t	i;

	i = 0;
	while (i < num && (str1[i] != '\0' || str2[i] != '\0'))
	{
		if (str1[i] != str2[i])
		{
			return ((unsigned char)str1[i] - (unsigned char)str2[i]);
		}
		i++;
	}
	return (0);
}

// #include <stdio.h>

// int	main(void)
// {
// 	const char *str1 = "1111";
// 	const char *str2 = NULL;
// 	unsigned int n = 6;
// 	int res = ft_strncmp(str1, str2, n);
// 	printf("%d\n", res);
// 	return (0);
// }