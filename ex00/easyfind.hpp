/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchairun <nchairun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 21:30:40 by nchairun          #+#    #+#             */
/*   Updated: 2026/07/23 16:49:07 by nchairun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <stdexcept>

template<typename T>
typename T::iterator easyfind(T& container, int value)
{
    typename T::iterator result;

    result = std::find(container.begin(), container.end(), value);
    
    if (result == container.end())
        throw std::runtime_error("Value not found");
    return (result);
}

#endif

/*
    https://www.geeksforgeeks.org/cpp/std-find-in-cpp/
*/