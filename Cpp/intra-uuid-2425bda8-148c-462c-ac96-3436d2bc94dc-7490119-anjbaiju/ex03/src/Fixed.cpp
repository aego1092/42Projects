/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjbaiju <anjbaiju@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 17:13:42 by anjbaiju          #+#    #+#             */
/*   Updated: 2026/06/27 11:11:24 by anjbaiju         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
    // std::cout << "Default constructor called" << std::endl;
    this->_value = 0;
}

Fixed::Fixed(const int intValue)
{
    // std::cout << "Int constructor called" << std::endl;
    this->_value = intValue << this->_bits;
}

Fixed::Fixed(const float floatValue)
{
    // std::cout << "Float constructor called" << std::endl;
    this->_value = roundf(floatValue * (1 << this->_bits));
}

Fixed::Fixed(const Fixed &value)
{
    // std::cout << "Copy constructor called" << std::endl;
    this->_value = value._value;
}

Fixed &Fixed::operator=(const Fixed &value)
{
    // std::cout << "Copy assignment operator called" << std::endl;
    if (this != &value)
        this->_value = value._value;
    return (*this);
}

Fixed::~Fixed()
{
    // std::cout << "Destructor called" << std::endl;
}

float Fixed::toFloat(void) const
{
    return ((float)this->_value / (1 << this->_bits));
}

int Fixed::toInt(void) const
{
    return (this->_value / (1 << this->_bits));
}

bool Fixed::operator>(const Fixed &value) const
{
    return (this->_value > value._value);
}

bool Fixed::operator<(const Fixed &value) const
{
    return (this->_value < value._value);
}

bool Fixed::operator>=(const Fixed &value) const
{
    return (this->_value >= value._value);
}

bool Fixed::operator<=(const Fixed &value) const
{
    return (this->_value <= value._value);
}

bool Fixed::operator==(const Fixed &value) const
{
    return (this->_value == value._value);
}

bool Fixed::operator!=(const Fixed &value) const
{
    return (this->_value != value._value);
}

Fixed Fixed::operator+(const Fixed &value) const
{
    Fixed result;
    result.setRawBits(this->_value + value._value);
    return result;
}

Fixed Fixed::operator-(const Fixed &value) const
{
    Fixed result;
    result.setRawBits(this->_value - value._value);
    return result;
}

Fixed Fixed::operator*(const Fixed &value) const
{
    Fixed result;
    result.setRawBits((this->_value * value._value) >> this->_bits);
    return result;
}

Fixed Fixed::operator/(const Fixed &value) const
{
    Fixed result;
    result.setRawBits((this->_value << this->_bits) / value._value);
    return result;
}

Fixed &Fixed::operator++()
{
    this->_value += 1;
    return (*this);
}

Fixed Fixed::operator++(int)
{
    Fixed tmp(*this);
    this->_value += 1;
    return (tmp);
}

Fixed &Fixed::operator--()
{
    this->_value -= 1;
    return (*this);
}

Fixed Fixed::operator--(int)
{
    Fixed tmp(*this);
    this->_value -= 1;
    return tmp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    if (a < b)
        return a;
    return b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    if (a < b)
        return a;
    return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    if (a > b)
        return a;
    return b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    if (a > b)
        return a;
    return b;
}

void Fixed::setRawBits(int const raw)
{
    // std::cout << "setRawBits member function called" << std::endl;
    this->_value = raw;
}

int Fixed::getRawBits(void) const
{
    // std::cout << "getRawBits member function called" << std::endl;
    return this->_value;
}

std::ostream &operator<<(std::ostream &out, const Fixed &value)
{
    out << value.toFloat();
    return out;
}