/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuliano <yuliano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 17:51:39 by yuliano           #+#    #+#             */
/*   Updated: 2026/04/18 21:39:45 by yuliano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASY_FIND_HPP
#define EASY_FIND_HPP

#include <exception>
#include <algorithm>

class Error:public std::exception
{
	public:
	const char *what() const throw()
	{
		return "value not found\n";
	}	
};

/*
-T::iterator depende de T
-typename le dice al compilador que iterator es un tipo interno
*/
template<typename T>
typename T::iterator easyfind(T &v, int value)
{
	
	typename T::iterator it;
	it = std::find(v.begin(), v.end(), value);

	if (it != v.end())
		return it;
	else
	{
		throw Error();
	}
}

template <typename T>
typename T::const_iterator easyfind(const T &v, int value)
{
	typename T::const_iterator it;
	it = std::find(v.begin(), v.end(), value);

	if (it != v.end())
		return it;
	else
	{
		throw Error();
	}
}

#endif