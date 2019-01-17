/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 16:55:11 by pscott            #+#    #+#             */
/*   Updated: 2019/01/17 17:34:27 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	add(int a, int b)
{
	printf("%d, %d\n", a, b);
	printf("AH\n");
}

void	substract(int a, int b)
{
	printf("%d, %d\n", a, b);
	printf("BEH\n");
}

void	multiply(int a, int b)
{
	printf("%d, %d\n", a, b);
	printf("CEH\n");
}

int		main(void)
{
	void	(*fun_ptr[3]) (int, int);
	int		a;
	int		b;
	int		ch;

	a = 15;
	b = 20;
	ch = 2;
	fun_ptr[0] = add;
	fun_ptr[1] = substract;
	fun_ptr[2] = multiply;
	(*fun_ptr[ch])(a, b);
	return (1);
}
