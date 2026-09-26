/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjbaiju <anjbaiju@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 17:13:45 by anjbaiju          #+#    #+#             */
/*   Updated: 2026/06/27 14:02:17 by anjbaiju         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
    int _value;
    static const int _bits = 8;

public:
    Fixed();
    Fixed(const int intValue);
    Fixed(const float floatValue);
    Fixed(const Fixed &value);
    Fixed &operator=(const Fixed &value);
    ~Fixed();

    bool operator>(const Fixed &value) const;
    bool operator<(const Fixed &value) const;
    bool operator>=(const Fixed &value) const;
    bool operator<=(const Fixed &value) const;
    bool operator==(const Fixed &value) const;
    bool operator!=(const Fixed &value) const;

    Fixed operator+(const Fixed &value) const;
    Fixed operator-(const Fixed &value) const;
    Fixed operator*(const Fixed &value) const;
    Fixed operator/(const Fixed &value) const;

    Fixed &operator++();
    Fixed operator++(int);
    Fixed &operator--();
    Fixed operator--(int);

    int getRawBits(void) const;
    void setRawBits(int const raw);

    float toFloat(void) const;
    int toInt(void) const;

    static Fixed &min(Fixed &a, Fixed &b);
    static const Fixed &min(const Fixed &a, const Fixed &b);
    static Fixed &max(Fixed &a, Fixed &b);
    static const Fixed &max(const Fixed &a, const Fixed &b);
};

std::ostream &operator<<(std::ostream &out, const Fixed &value);

#endif