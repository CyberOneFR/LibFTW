/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 01:17:39 by ethebaul          #+#    #+#             */
/*   Updated: 2025/12/16 09:32:59 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
//((long)&buffer[10] & ~0xf)
//((long *)((long)&buffer[4] & ~0xf))[11] canary
//((long *)((long)&buffer[4] & ~0xf))[12] RBP
//((long *)((long)&buffer[4] & ~0xf))[13] RIP

int	function(void)
{
	unsigned long	buffer[10];

	buffer[13] = (unsigned long)function + 0x58;
	buffer[12] = (unsigned long)&buffer[1];
	buffer[2] = (unsigned long)function + 0x58;
	buffer[1] = (unsigned long)&buffer[1];
	buffer[0] = buffer[11];
	printf("start\n");
	printf("next\n");
	return (0);
}

int	function2(void)
{
	unsigned long	buffer[10];

	buffer[13] = (unsigned long)function2;
	buffer[12] = (unsigned long)&buffer[12];
	printf("loop %p\n", buffer[12]);
	return (0);
}

int	main(void)
{
	function2();
	return (0);
}
