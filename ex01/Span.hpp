/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchairun <nchairun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 16:52:56 by nchairun          #+#    #+#             */
/*   Updated: 2026/07/23 16:58:14 by nchairun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>
class Span
{
    private:
        unsigned int        maxNumber; // store a maximum of N integers
        std::vector<int>    numbers; 

    public:
        Span();
        Span(unsigned int n);
        Span(const Span& other);
        Span&   operator=(const Span& other);
        ~Span();

	    void	addNumber(int number); //  to add a single number to the Span
};


#endif