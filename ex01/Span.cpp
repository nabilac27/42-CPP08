/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchairun <nchairun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 17:10:35 by nchairun          #+#    #+#             */
/*   Updated: 2026/07/23 18:32:03 by nchairun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

/* ************************************************************************** */
/*	ORTHODOX CANONICAL FORM                                					  */
/* ************************************************************************** */
Span::Span() 
: maxNumber() 
{
}

Span::Span(unsigned int number) 
: maxNumber(number) 
{
}

Span::Span(const Span& other)
{
	*this = other;
}

Span& Span::operator=(const Span& other)
{
	if (this != &other)
	{
		maxNumber = other.maxNumber;
		numbers = other.numbers;
	}
	return (*this);
}

Span::~Span() 
{
}

/* ************************************************************************** */
/*  ADD NUMBER                                                                */
/* ************************************************************************** */
void Span::addNumber(int number)
{
	if (numbers.size() >= maxNumber)
		throw std::runtime_error("Span is full");

	numbers.push_back(number);
}

/* ************************************************************************** */
/*  SHORTEST SPAN                                                             */
/* ************************************************************************** */
/*
    1. Check that at least 2 numbers exist.
    2. Copy the vector.
    3. Sort the copy.
    4. Compare neighboring numbers.
    5. Return the smallest difference.
*/
int Span::shortestSpan() const
{
    if (numbers.size() < 2)
		throw std::runtime_error("Numbers must be at least 2");

    std::vector<int> sortedNumbers = numbers;
	std::sort(sortedNumbers.begin(), sortedNumbers.end());

	int shortest = sortedNumbers[1] - sortedNumbers[0];

    for (size_t i = 1; i < sortedNumbers.size(); i++)
	{
		int diff = sortedNumbers[i] - sortedNumbers[i - 1];

		if (diff < shortest)
			shortest = diff;
	}

	return (shortest);
}
