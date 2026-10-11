/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddi-nico <ddi-nico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 17:13:39 by anjbaiju          #+#    #+#             */
/*   Updated: 2026/06/27 16:04:31 by ddi-nico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

int main(void)
{
    // {
    //     Point a(-7.60495f, 4.5081f);
    //     Point b(6.27556f, 5.2468f);
    //     Point c(-5.50495f, -4.5319f);
    //     Point point(-5.50495f, -4.5319f);
    //     std::cout << "Test 1: Point on vertex C (outside)" << std::endl;
    //     std::cout << std::endl;
    //     bsp(a, b, c, point);
    //     std::cout << std::endl;
    // }

    {
        Point a(0, 0);
        Point b(0, 1);
        Point c(1, 0);
        Point point(0.5f, 0.6f);
        std::cout << "Test 2: Point inside triangle (inside)" << std::endl;
        std::cout << std::endl;
        bsp(a, b, c, point);
        std::cout << std::endl;
    }

    return 0;
}