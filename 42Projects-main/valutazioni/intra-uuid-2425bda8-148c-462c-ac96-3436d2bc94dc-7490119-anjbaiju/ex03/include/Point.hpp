/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjbaiju <anjbaiju@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 14:02:52 by anjbaiju          #+#    #+#             */
/*   Updated: 2026/06/27 14:02:53 by anjbaiju         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"
#include <cmath>

class Point
{
private:
    Fixed const _x;
    Fixed const _y;

public:
    Point();
    Point(const float x, const float y);
    Point(const Point &point);
    Point &operator=(const Point &point);
    ~Point();

    Fixed getX() const;
    Fixed getY() const;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);
void printResult(bool inside, Point const &a, Point const &b,
                 Point const &c, Point const &point);

#endif