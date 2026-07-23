/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchairun <nchairun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 16:52:33 by nchairun          #+#    #+#             */
/*   Updated: 2026/07/23 23:23:22 by nchairun         ###   ########.fr       */
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
	/* ************************************************************************** */
	/*  ADD RANGE TEST                                                            */
	/* ************************************************************************** */

	std::cout << "========================================" << std::endl;
	std::cout << "ADD RANGE TEST" << std::endl;
	std::cout << "========================================" << std::endl;

	try
	{
		std::vector<int> values;

		values.push_back(6);
		values.push_back(3);
		values.push_back(17);
		values.push_back(9);
		values.push_back(11);

		Span sp(5);

		sp.addRange(values.begin(), values.end());

		std::cout << "Shortest span: "
				  << sp.shortestSpan() << std::endl;

		std::cout << "Longest span : "
				  << sp.longestSpan() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	/* ************************************************************************** */
	/*  10,000 NUMBERS TEST                                                       */
	/* ************************************************************************** */

	std::cout << std::endl;
	std::cout << "========================================" << std::endl;
	std::cout << "10,000 NUMBERS TEST" << std::endl;
	std::cout << "========================================" << std::endl;

	try
	{
		std::vector<int> values;

		for (int i = 0; i < 10000; ++i)
			values.push_back(i);

		Span largeSpan(10000);

		largeSpan.addRange(values.begin(), values.end());

		std::cout << "Shortest span: "
				  << largeSpan.shortestSpan() << std::endl;

		std::cout << "Longest span : "
				  << largeSpan.longestSpan() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	/* ************************************************************************** */
	/*  RANGE OVERFLOW TEST                                                       */
	/* ************************************************************************** */

	std::cout << std::endl;
	std::cout << "========================================" << std::endl;
	std::cout << "RANGE OVERFLOW TEST" << std::endl;
	std::cout << "========================================" << std::endl;

	try
	{
		std::vector<int> values;

		values.push_back(10);
		values.push_back(20);
		values.push_back(30);
		values.push_back(40);

		Span smallSpan(3);

		smallSpan.addRange(values.begin(), values.end());
	}
	catch (const std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

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