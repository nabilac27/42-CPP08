/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchairun <nchairun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 16:52:33 by nchairun          #+#    #+#             */
/*   Updated: 2026/07/23 18:41:35 by nchairun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>

/*
	TO-DO:
		Add a range of iterators
		Tests with at least 10,000 numbers
*/
int main()
{
	std::cout << "========================================" << std::endl;
	std::cout << "LONGEST SPAN TEST" << std::endl;
	std::cout << "========================================" << std::endl;

	Span sp1(5);

	try
	{
		sp1.addNumber(6);
		sp1.addNumber(3);
		sp1.addNumber(17);
		sp1.addNumber(9);
		sp1.addNumber(11);

		std::cout << "Longest Span: "
				  << sp1.longestSpan()
				  << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	// std::cout << std::endl;
	// std::cout << "========================================" << std::endl;
	// std::cout << "NEGATIVE NUMBERS TEST" << std::endl;
	// std::cout << "========================================" << std::endl;

	// Span sp2(4);

	// try
	// {
	// 	sp2.addNumber(-20);
	// 	sp2.addNumber(5);
	// 	sp2.addNumber(30);
	// 	sp2.addNumber(-10);

	// 	std::cout << "Longest Span: "
	// 			  << sp2.longestSpan()
	// 			  << std::endl;
	// }
	// catch (const std::exception& e)
	// {
	// 	std::cout << "Error: " << e.what() << std::endl;
	// }

	std::cout << std::endl;
	std::cout << "========================================" << std::endl;
	std::cout << "NOT ENOUGH NUMBERS TEST" << std::endl;
	std::cout << "========================================" << std::endl;

	Span sp3(5);

	try
	{
		sp3.addNumber(42);

		std::cout << "Longest Span: "
				  << sp3.longestSpan()
				  << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	return (0);
	
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

	// std::cout << std::endl;
	// std::cout << "========================================" << std::endl;
	// std::cout << "NOT ENOUGH NUMBERS TEST" << std::endl;
	// std::cout << "========================================" << std::endl;

	// Span sp2(5);

	// try
	// {
	// 	sp2.addNumber(42);

	// 	std::cout << "Shortest Span: "
	// 			  << sp2.shortestSpan()
	// 			  << std::endl;
	// }
	// catch (const std::exception& e)
	// {
	// 	std::cout << e.what() << std::endl;
	// }

	// return (0);
}