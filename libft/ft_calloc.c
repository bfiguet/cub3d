/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 04:51:55 by bfiguet           #+#    #+#             */
/*   Updated: 2023/10/06 11:53:37 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t	count, size_t	size)
{
	void	*dst;

	if (count == 0 || size == 0)
	{
		count = 1;
		size = 1;
	}
	dst = malloc(size * count);
	if (!dst)
		return (NULL);
	ft_bzero(dst, count * size);
	return (dst);
}
/*
#include<stdio.h>
int	main()
{
	float *ptr = NULL;
	float *ptr2 = NULL;
	int	n;
	int	i;

	n= 5;
	i = 0;
	ptr = calloc(n, sizeof(char));
	ptr2 = ft_calloc(n, sizeof(char));
	while (i < n)
	{
		printf("ptr[%d]= %f :ptr2[%d]= %f\n", i, ptr[i], i, ptr2[i]);
		i++;
	}
	return (0);
}*/
