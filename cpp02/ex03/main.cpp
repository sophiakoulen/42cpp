/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:01:42 by skoulen           #+#    #+#             */
/*   Updated: 2023/04/03 10:03:43 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>

using std::cout;
using std::endl;

bool	bsp(Point const a, Point const b, Point const c, Point const point);

int	main(void)
{
	Point a(0, 2);
	Point b(1, 0);
	Point c(-1, -1);

	Point p0(0, 0);//in the triangle
	cout<<"bsp("<<a<<","<<b<<","<<c<<", "<<p0<<") = "<<bsp(a, b, c, p0)<<endl;

		
	Point p1(0, 1); //in the triangle
	cout<<"bsp("<<a<<","<<b<<","<<c<<", "<<p1<<") = "<<bsp(a, b, c, p1)<<endl;
	
	
	Point p2(2, 3); //outside triangle
	cout<<"bsp("<<a<<","<<b<<","<<c<<", "<<p2<<") = "<<bsp(a, b, c, p2)<<endl;
	
	
	Point p3(0, -0.5); //on the triangle
	cout<<"bsp("<<a<<","<<b<<","<<c<<", "<<p3<<") = "<<bsp(a, b, c, p3)<<endl;


	Point p4(1, 0); //vertex
	cout<<"bsp("<<a<<","<<b<<","<<c<<", "<<p4<<") = "<<bsp(a, b, c, p4)<<endl;

	Point d(3, 0);
	Point e(8, 0);
	Point f(8, 5);

	Point p5(5, 1);//in the triangle
	cout<<"bsp("<<d<<","<<e<<","<<f<<", "<<p5<<") = "<<bsp(d, e, f, p5)<<endl;

		
	Point p6(7, 3); //in the triangle
	cout<<"bsp("<<d<<","<<e<<","<<f<<", "<<p6<<") = "<<bsp(d, e, f, p6)<<endl;
	
	
	Point p7(4, 3); //outside triangle
	cout<<"bsp("<<d<<","<<e<<","<<f<<", "<<p7<<") = "<<bsp(d, e, f, p7)<<endl;
	
	
	Point p8(6, 0); //on the triangle
	cout<<"bsp("<<d<<","<<e<<","<<f<<", "<<p8<<") = "<<bsp(d, e, f, p8)<<endl;


	Point p9(8, 5); //vertex
	cout<<"bsp("<<d<<","<<e<<","<<f<<", "<<p9<<") = "<<bsp(d, e, f, p9)<<endl;
	return (0);
}
