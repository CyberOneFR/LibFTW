/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 01:17:39 by ethebaul          #+#    #+#             */
/*   Updated: 2025/12/16 06:09:20 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
//((long)&buffer[10] & ~0xf)
//((long *)((long)&buffer[10] & ~0xf))[1] canary
//((long *)((long)&buffer[10] & ~0xf))[2] RBP
//((long *)((long)&buffer[10] & ~0xf))[3] RIP
int	ft_atoi(const char *nptr)
{
	long	buffer[4];

	buffer[0] = ((long *)((long)&buffer[4] & ~0xf))[1];
	buffer[1] = ((long *)((long)&buffer[4] & ~0xf))[2];
	buffer[2] = ((long *)((long)&buffer[4] & ~0xf))[3];
	buffer[3] = 0xdeadbeef;
	printf("vcanary	%p: %p\n", &buffer[0], (void *)buffer[0]);
	printf("vRBP	%p: %p\n", &buffer[1], (void *)buffer[1]);
	printf("vRIP	%p: %p\n", &buffer[2], (void *)buffer[2]);
	printf("test	%p: %p\n", &buffer[3], (void *)buffer[3]);
	printf("canary	%p: %p\n", &buffer[4], (void *)buffer[4]);
	printf("RBP 	%p: %p\n", &buffer[5], (void *)buffer[5]);
	printf("RIP 	%p: %p\n", &buffer[6], (void *)buffer[6]);
	printf("\n");
	((long *)((long)&buffer[3] & ~0xf))[2] = (long)&buffer[2];
	((long *)((long)&buffer[3] & ~0xf))[3] = (long)ft_atoi;
	return (0);
}

int	main(void)
{
	const char	*str = "42";

	ft_atoi(str);
	printf("%s\n", str);
	return (0);
}
