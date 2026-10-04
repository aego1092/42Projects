/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjbaiju <anjbaiju@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 17:13:14 by anjbaiju          #+#    #+#             */
/*   Updated: 2026/05/27 17:13:15 by anjbaiju         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
private:
    int _value;
    static const int _bits = 8;

public:
    Fixed();
    Fixed(const Fixed &value);
    Fixed &operator=(const Fixed &value);
    ~Fixed();

    int getRawBits(void) const;
    void setRawBits(int const raw);
};

#endif