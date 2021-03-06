/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenaiss <abenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 15:58:33 by abenaiss          #+#    #+#             */
/*   Updated: 2019/07/24 09:05:42 by abenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void	ft_choose(char *src, t_fract *fract)
{
	if (ft_strcmp(src, "Mandelbrot") == 0)
		fract->choose = 1;
	else if (ft_strcmp(src, "Tricorn") == 0)
		fract->choose = 2;
	else if (ft_strcmp(src, "Julia") == 0)
		fract->choose = 3;
	else if (ft_strcmp(src, "Burning Ship") == 0)
		fract->choose = 4;
	else if (ft_strcmp(src, "Burning Julia") == 0)
		fract->choose = 5;
	else if (ft_strcmp(src, "Julia Cross") == 0)
		fract->choose = 6;
	else if (ft_strcmp(src, "Multibrot") == 0)
		fract->choose = 7;
}

void	ft_draw(t_fract *fract)
{
	if (fract->choose == 1)
		ft_mandelbrot_thread(fract);
	else if (fract->choose == 2)
		ft_tricorn_thread(fract);
	else if (fract->choose == 3)
		ft_julia_thread(fract);
	else if (fract->choose == 4)
		ft_burning_ship_thread(fract);
	else if (fract->choose == 5)
		ft_burning_julia_thread(fract);
	else if (fract->choose == 6)
		ft_julia_cross_thread(fract);
	else if (fract->choose == 7)
		ft_multibrot_thread(fract);
}

double	ft_map(double x, double in_min, double in_max)
{
	double scope;

	scope = 1.0 * (2 - (-2)) / (in_max - in_min);
	return (-2 + scope * (x - in_min));
}

int		main(int argc, char **argv)
{
	t_fract fract;

	fract.choose = 0;
	if (argc == 2)
		ft_choose(argv[1], &fract);
	if (!fract.choose)
	{
		ft_putendl("╔════════════════════════════════════════════════════╗");
		ft_putendl("║                       Fact'ol                      ║");
		ft_putendl("╠════════════════════════════════════════════════════╣");
		ft_putendl("║                   *1- Mandelbrot                   ║");
		ft_putendl("║                   *2- Tricorn                      ║");
		ft_putendl("║                   *3- Julia                        ║");
		ft_putendl("║                   *4- Burning Ship                 ║");
		ft_putendl("║                   *5- Burning Julia                ║");
		ft_putendl("║                   *6- Julia Cross                  ║");
		ft_putendl("║                   *7- Multibrot                    ║");
		ft_putendl("╚════════════════════════════════════════════════════╝");
		exit(0);
	}
	else
		ft_init_win(fract);
	return (0);
}
