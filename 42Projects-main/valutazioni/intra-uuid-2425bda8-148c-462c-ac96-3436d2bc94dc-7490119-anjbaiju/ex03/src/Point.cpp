/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjbaiju <anjbaiju@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 14:02:56 by anjbaiju          #+#    #+#             */
/*   Updated: 2026/06/27 14:02:57 by anjbaiju         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(0), _y(0) {}

Point::Point(const float x, const float y) : _x(x), _y(y) {}

Point::Point(const Point &point) : _x(point._x), _y(point._y) {}

Point &Point::operator=(const Point &point)
{
    (void)point;
    return *this;
}

Point::~Point() {}

Fixed Point::getX() const
{
    return this->_x;
}

Fixed Point::getY() const
{
    return this->_y;
}
