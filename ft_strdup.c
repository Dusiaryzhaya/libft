/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anilchen <anilchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 13:14:42 by anilchen          #+#    #+#             */
/*   Updated: 2024/06/24 17:08:06 by anilchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Функция strdup в языке программирования C используется для дублирования
// строки. Она выделяет память и копирует в неё содержимое указанной строки,
// включая завершающий нулевой символ.
// Аргументы:
// str: указатель на строку, которую нужно дублировать.
// Возвращаемое значение:
// Указатель на вновь выделенную память, содержащую дублированную строку.
// Если выделение памяти не удалось, возвращает NULL.

char	*ft_strdup(const char *str)
{
	int		size;
	int		i;
	char	*arr;

	i = 0;
	size = 0;
	while (str[size])
		size++;
	arr = (char *)malloc((size + 1) * sizeof(char));
	if (arr == NULL)
		return (NULL);
	else
	{
		while (i < size)
		{
			arr[i] = str[i];
			i++;
		}
		arr[i] = '\0';
	}
	return (arr);
}

// int	main(void)
// {
// 	const char *str = "Hello!";
// 	char *res = ft_strdup(str);
// 	if (*res != NULL)
// 	{
// 		printf("%s", res);
// 	}
// 	return (0);
// }