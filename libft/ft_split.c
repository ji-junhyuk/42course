/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junji <junji@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 13:35:17 by junji             #+#    #+#             */
/*   Updated: 2022/07/04 18:17:10 by junji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_word(const char *str, char c)
{
	int	cnt;

	cnt = 0;
	while (*str)
	{
		while (*str && *str == c)
			++str;
		if (*str && *str != c)
		{
			++cnt;
			while (*str && *str != c)
				++str;
		}
	}
	return (cnt);
}

char	*ft_strlen_dup(const char **str, char c)
{
	int		word_len;
	int		cnt;
	char	*copy;

	word_len = 0;
	while (*(*str) && *(*str) != c)
	{
		++word_len;
		++*str;
	}
	*str -= word_len;
	copy = malloc(sizeof(char) * (word_len + 1));
	if (!copy)
		return (0);
	cnt = 0;
	while (*(*str) && ++cnt <= word_len)
		*copy++ = *(*str)++;
	*copy = '\0';
	copy -= word_len;
	return (copy);
}

char	**free_copy(char **str, int size)
{
	int	index;

	index = -1;
	while (++index < size)
		free(str[index]);
	free(str);
	return (0);
}

char	**ft_split(const char *str, char c)
{
	char	**copy;
	int		words;
	int		index;

	if (!str)
		return (0);
	words = count_word(str, c);
	copy = malloc(sizeof(char *) * (words + 1));
	if (!copy)
		return (0);
	index = -1;
	while (++index < words)
	{
		while (*str && *str == c)
			++str;
		copy[index] = ft_strlen_dup(&str, c);
		if (!copy[index])
			return (free_copy(copy, index));
	}
	copy[index] = 0;
	return (copy);
}
//
//#include <stdio.h>
//int main(void)
//{
//	char **arr;
//	char *str = "hello, jun, nice to meet you";
//	char *str2 = "hello, jun, nice to meet you";
//	char *str3 = "hello";
//	char charset = ' ';
//	char charset2 = '\0';
//	char charset3 = 'h';
//
//	arr = ft_split(str, charset);
//	int index;
//	index = -1;
//	while (++index < 6)
//		printf("%s\n", arr[index]);
//	free(arr);
//	arr = ft_split(str2, charset2);
//	index = -1;
//	while (++index < 1)
//		printf("%s\n", arr[index]);
//	free(arr);
//	arr = ft_split(str3, charset3);
//	if (arr[0] == NULL)
//		printf("hello NULL~!\n");
//	free(arr);
//	return (0);
//}
