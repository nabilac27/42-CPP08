/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchairun <nchairun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 17:10:35 by nchairun          #+#    #+#             */
/*   Updated: 2026/07/23 17:17:34 by nchairun         ###   ########.fr       */
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
/*	                              					  */
/* ************************************************************************** */
void Span::addNumber(int number)
{
	if (numbers.size() >= maxNumber)
		throw std::runtime_error("Span is full");

	numbers.push_back(number);
}