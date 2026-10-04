/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddi-nico <ddi-nico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 14:02:59 by anjbaiju          #+#    #+#             */
/*   Updated: 2026/06/27 16:00:41 by ddi-nico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

void printResult(bool inside, Point const &a, Point const &b,
                 Point const &c, Point const &point)
{
    std::cout << "A (" << a.getX() << ", " << a.getY() << ")" << std::endl;
    std::cout << "B (" << b.getX() << ", " << b.getY() << ")" << std::endl;
    std::cout << "C (" << c.getX() << ", " << c.getY() << ")" << std::endl;
    std::cout << "Point(" << point.getX() << ", " << point.getY() << ")" << std::endl;
    std::cout << std::endl;

    if (inside)
        std::cout << "Point is inside." << std::endl;
    else
        std::cout << "Point is outside or on the boundary." << std::endl;
}

static Fixed cross(Point const a, Point const b, Point const p)
{
    Fixed result;

    result = (b.getX() - a.getX()) * (p.getY() - a.getY()) -
             (b.getY() - a.getY()) * (p.getX() - a.getX());

    return result;
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    Fixed d1 = cross(a, b, point); // -
    Fixed d2 = cross(b, c, point); // +
    Fixed d3 = cross(c, a, point); // -

    Fixed zero;
    bool inside = false;

    if (d1 == zero || d2 == zero || d3 == zero)
    {
        printResult(false, a, b, c, point);
        return false;
    }

    inside = (d1 > zero && d2 > zero && d3 > zero) ||
             (d1 < zero && d2 < zero && d3 < zero);

    printResult(inside, a, b, c, point);

    return inside;
}