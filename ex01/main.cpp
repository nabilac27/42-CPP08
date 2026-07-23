/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchairun <nchairun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 16:52:33 by nchairun          #+#    #+#             */
/*   Updated: 2026/07/23 18:33:01 by nchairun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>

int main()
{
	// Span sp(3);

	// try
	// {
	// 	sp.addNumber(10);
	// 	sp.addNumber(20);
	// 	sp.addNumber(30);
	// 	sp.addNumber(40);
	// }
	// catch (const std::exception& e)
	// {
	// 	std::cout << e.what() << std::endl;
	// }

		std::cout << "========================================" << std::endl;
	std::cout << "SHORTEST SPAN TEST" << std::endl;
	std::cout << "========================================" << std::endl;

	Span sp(5);

	try
	{
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << "Shortest Span: "
				  << sp.shortestSpan()
				  << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "========================================" << std::endl;
	std::cout << "NOT ENOUGH NUMBERS TEST" << std::endl;
	std::cout << "========================================" << std::endl;

	Span sp2(5);

	try
	{
		sp2.addNumber(42);

		std::cout << "Shortest Span: "
				  << sp2.shortestSpan()
				  << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	return (0);
}