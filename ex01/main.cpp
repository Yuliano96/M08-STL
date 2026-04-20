/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuliano <yuliano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 12:51:28 by yuliano           #+#    #+#             */
/*   Updated: 2026/04/20 20:38:24 by yuliano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <list>
	
int main()
{
	std::cout<<"====TEST ONE=======\n";
	std::list<int> list;
	Span p(5);
	
	list.push_back(4);
	list.push_back(7);
	list.push_back(12);

	p.addNumber(list.begin(), list.end());
	for (int i = 0; i < 3; i++)
		std::cout<<p.getNumber(i)<<" ";
		
	std::cout<<"\n========TEST TWO =======\n";
	{
		int miArray[] = {10, 20, 30, 40, 50};
    
    	int n = sizeof(miArray) / sizeof(miArray[0]);
	
    	Span sp(10);

    	sp.addNumber(miArray, miArray + n);

		for (int i = 0; i < n; i++)
			std::cout<<sp.getNumber(i)<<" ";
	
    	std::cout << "\nShortest Span: " << sp.shortestSpan() << std::endl;
		std::cout << "longest Span : " << sp.longestSpan() << std::endl; 
	
	}
    
	std::cout<<"\n======TEST THREE ====\n";
	Span vec(5);
	try
	{
		for(int i = 0; i < 10; i++)
			vec.addNumber(i + 2);
			
	}
	catch(std::exception &e)
	{
		std::cerr<<e.what()<<std::endl;
	}

	std::cout<< "\n======TEST FOUR=======\n";
	Span len(10000);
	for(int i = 0; i < 10000; i++)
			len.addNumber(i + 5);

	std::cout << "Shortest Span: " << len.shortestSpan() << std::endl;
	std::cout << "longest Span : " << len.longestSpan() << std::endl;
	
	std::cout<<"\n=======TEST FIVE ========\n";

	Span empty;

	try
	{
		std::cout << "Shortest Span: " << empty.shortestSpan() << std::endl;
		std::cout << "longest Span : " << empty.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout<<"\n=======TEST SIX========\n";

	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	
	return (0);
}