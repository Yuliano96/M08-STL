/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypacileo <ypacileo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 10:54:38 by ypacileo          #+#    #+#             */
/*   Updated: 2026/04/21 15:14:35 by ypacileo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef MUTANT_STACK_HPP
# define MUTANT_STACK_HPP

#include <stack>

template<class T>
class MutantStack:public std::stack<T>
{
	
	public:
	typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;
	MutantStack() {}
	MutantStack(const MutantStack &other):std::stack<T>(other) {}
	MutantStack &operator=(const MutantStack &other)
	{
		if (this != &other)
		{
			std::stack<T>::operator=(other);
		}
		return *this;
	}
	~MutantStack() {}
	
	iterator begin() { return this->c.begin(); }
	iterator end() { return this->c.end();}
	const_iterator begin() const { return this->c.begin(); }
	const_iterator end() const { return this->c.end();}
	
	
};

#endif