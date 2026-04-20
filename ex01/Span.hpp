/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuliano <yuliano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 12:19:52 by yuliano           #+#    #+#             */
/*   Updated: 2026/04/20 20:30:58 by yuliano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include<vector>
#include<algorithm>
#include <stdexcept>
#include <climits>

class Span
{
	private:

	unsigned int N;
	std::vector<int> vec;
	
	public:
	
	Span();
	Span(unsigned int n);
	Span(const Span &other);
	Span &operator=(const Span &other);
	~Span();
	void addNumber(int value);
	int shortestSpan() const;
	int longestSpan() const;
	const int &getNumber(unsigned int _index) const;
	template <typename T>
	void addNumber(T it_begin, T it_end) 
	{
    	size_t len = std::distance(it_begin, it_end);

    	if(vec.size() + len > N)
        		throw std::out_of_range("Limit exceeded");
    
    	vec.insert(vec.end(), it_begin, it_end);
	}
	
};

#endif