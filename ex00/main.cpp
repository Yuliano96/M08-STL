/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuliano <yuliano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 12:00:52 by yuliano           #+#    #+#             */
/*   Updated: 2026/04/18 20:17:43 by yuliano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

int main(void)
{
	std::vector<int>	v;
	std::list<int>		l;
	std::vector<int>::iterator	it_v;
	std::list<int>::iterator	it_l;
	int	i;

	i = 0;
	while (i < 5)
	{
		v.push_back(i * 10);
		i++;
	}

	i = 0;
	while (i < 5)
	{
		l.push_back(i + 1);
		i++;
	}

	std::cout << "=== VECTOR TEST (FOUND) ===" << std::endl;
	try
	{
		it_v = easyfind(v, 20);
		std::cout << "Found in vector: " << *it_v << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n=== VECTOR TEST (NOT FOUND) ===" << std::endl;
	try
	{
		it_v = easyfind(v, 99);
		std::cout << "Found in vector: " << *it_v << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n=== LIST TEST (FOUND) ===" << std::endl;
	try
	{
		it_l = easyfind(l, 3);
		std::cout << "Found in list: " << *it_l << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n=== LIST TEST (NOT FOUND) ===" << std::endl;
	try
	{
		it_l = easyfind(l, 42);
		std::cout << "Found in list: " << *it_l << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return (0);
}