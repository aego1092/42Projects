/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpuscedd <gpuscedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 15:30:25 by gpuscedd          #+#    #+#             */
/*   Updated: 2026/05/31 16:06:29 by gpuscedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// =============================================================================
// COSTRUTTORI E DISTRUTTORE
// =============================================================================

Fixed::Fixed() : _fixedPointValue(0) {
}

Fixed::Fixed(const int n) : _fixedPointValue(n << _fractionalBits) {
}

Fixed::Fixed(const float n) : _fixedPointValue(roundf(n * (1 << _fractionalBits))) {
}

Fixed::Fixed(const Fixed& src) {
    *this = src;
}

Fixed::~Fixed() {
}

// =============================================================================
// ASSEGNAZIONE E CONVERSIONI
// =============================================================================

Fixed& Fixed::operator=(const Fixed& obj) {
    if (this != &obj)
        this->_fixedPointValue = obj.getRawBits();
    return *this;
}

float Fixed::toFloat(void) const {
    return (float)this->_fixedPointValue / (float)(1 << _fractionalBits);
}

int Fixed::toInt(void) const {
    return this->_fixedPointValue >> _fractionalBits;
}

int Fixed::getRawBits(void) const {
    return this->_fixedPointValue;
}

void Fixed::setRawBits(int const raw) {
    this->_fixedPointValue = raw;
}

// =============================================================================
// OPERATORI DI COMPARAZIONE
// =============================================================================

bool Fixed::operator>(const Fixed& obj) const {
    return this->getRawBits() > obj.getRawBits();
}

bool Fixed::operator<(const Fixed& obj) const {
    return this->getRawBits() < obj.getRawBits();
}

bool Fixed::operator>=(const Fixed& obj) const {
    return this->getRawBits() >= obj.getRawBits();
}

bool Fixed::operator<=(const Fixed& obj) const {
    return this->getRawBits() <= obj.getRawBits();
}

bool Fixed::operator==(const Fixed& obj) const {
    return this->getRawBits() == obj.getRawBits();
}

bool Fixed::operator!=(const Fixed& obj) const {
    return this->getRawBits() != obj.getRawBits();
}

// =============================================================================
// OPERATORI ARITMETICI
// =============================================================================

Fixed Fixed::operator+(const Fixed& obj) const {
    return Fixed(this->toFloat() + obj.toFloat());
}

Fixed Fixed::operator-(const Fixed& obj) const {
    return Fixed(this->toFloat() - obj.toFloat());
}

Fixed Fixed::operator*(const Fixed& obj) const {
    return Fixed(this->toFloat() * obj.toFloat());
}

Fixed Fixed::operator/(const Fixed& obj) const {
    return Fixed(this->toFloat() / obj.toFloat());
}

// =============================================================================
// OPERATORI DI INCREMENTO / DECREMENTO
// =============================================================================

// Pre-incremento (++a)
Fixed& Fixed::operator++(void) {
    this->_fixedPointValue++;
    return *this;
}

// Post-incremento (a++)
Fixed Fixed::operator++(int) {
    Fixed tmp(*this);
    this->_fixedPointValue++;
    return tmp;
}

// Pre-decremento (--a)
Fixed& Fixed::operator--(void) {
    this->_fixedPointValue--;
    return *this;
}

// Post-decremento (a--)
Fixed Fixed::operator--(int) {
    Fixed tmp(*this);
    this->_fixedPointValue--;
    return tmp;
}

// =============================================================================
// FUNZIONI MIN E MAX (STATICHE)
// =============================================================================

Fixed& Fixed::min(Fixed& a, Fixed& b) {
    if (a < b)
        return a;
    return b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
    if (a < b)
        return a;
    return b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
    if (a > b)
        return a;
    return b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
    if (a > b)
        return a;
    return b;
}

// =============================================================================
// OVERLOAD DELL'OPERATORE DI INSERIMENTO (GLOBALE)
// =============================================================================

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    os << fixed.toFloat();
    return os;
}