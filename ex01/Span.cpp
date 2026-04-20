/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuliano <yuliano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 12:29:53 by yuliano           #+#    #+#             */
/*   Updated: 2026/04/20 20:31:38 by yuliano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span():N(0) {}

Span::Span(unsigned int n) : N(n)
{   
    vec.reserve(N);
}

Span::Span(const Span &other) : N(other.N) 
{
    this->vec = other.vec; // El operador = de std::vector hace copia profunda
}

Span &Span::operator=(const Span &other) 
{
    if (this != &other) 
	{
        this->N = other.N;
        this->vec = other.vec; // Copiamos los datos reales, no solo el espacio
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int value) 
{
    if (vec.size() >= N)
        throw std::out_of_range("Insufficient space");
    vec.push_back(value);
}

int Span::shortestSpan() const
{
    if (vec.size() < 2)
        throw std::logic_error("Not enough elements to find a span");

    std::vector<int> sortedVec = vec;
    std::sort(sortedVec.begin(), sortedVec.end());

    int min = INT_MAX;
    for (size_t i = 0; i < sortedVec.size() - 1; i++)
    {
        int diff = sortedVec[i + 1] - sortedVec[i];
        if (diff < min)
            min = diff;
    }
    return min;
}

int Span::longestSpan() const
{
	
	if(vec.size() < 2)
        throw std::logic_error("Not enough elements to find a span");
	
	return (*std::max_element(vec.begin(), vec.end()) - *std::min_element(vec.begin(), vec.end()));

}

const int &Span::getNumber(unsigned int _index) const 
{
    // .at() lanza out_of_range si el índice es inválido
    return vec.at(_index);      
}


