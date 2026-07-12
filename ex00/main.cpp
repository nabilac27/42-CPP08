/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchairun <nchairun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 21:50:04 by nchairun          #+#    #+#             */
/*   Updated: 2026/07/12 21:53:19 by nchairun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

#include <iostream>
#include <vector>
#include <list>

/* ************************************************************************** */
/*                                    MAIN                                    */
/* ************************************************************************** */

int	main(void)
{
	std::vector<int>	numbers;
	std::list<int>		values;

	numbers.push_back(10);
	numbers.push_back(20);
	numbers.push_back(30);
	numbers.push_back(40);

	values.push_back(5);
	values.push_back(15);
	values.push_back(25);

	/* **************************** VECTOR TEST ******************************* */

	try
	{
		std::vector<int>::iterator	it;

		it = easyfind(numbers, 30);
		std::cout << "Found in vector: " << *it << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	/* *************************** NOT FOUND TEST ***************************** */

	try
	{
		easyfind(numbers, 100);
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	/* ***************************** LIST TEST ******************************* */

	try
	{
		std::list<int>::iterator	it;

		it = easyfind(values, 15);
		std::cout << "Found in list: " << *it << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return (0);
}