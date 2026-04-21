/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypacileo <ypacileo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 11:01:39 by ypacileo          #+#    #+#             */
/*   Updated: 2026/04/21 15:40:14 by ypacileo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <list>


void	print_separator(const std::string &title)
{
	std::cout << "\n===== " << title << " =====" << std::endl;
}

void	print_mutantstack(MutantStack<int> &mstack, const std::string &name)
{
	MutantStack<int>::iterator	it;
	MutantStack<int>::iterator	ite;

	std::cout << name << " content:" << std::endl;
	it = mstack.begin();
	ite = mstack.end();
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
}

void	print_list(std::list<int> &lst, const std::string &name)
{
	std::list<int>::iterator	it;
	std::list<int>::iterator	ite;

	std::cout << name << " content:" << std::endl;
	it = lst.begin();
	ite = lst.end();
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
}

void	compare_with_list(MutantStack<int> &mstack, std::list<int> &lst)
{
	MutantStack<int>::iterator	ms_it;
	MutantStack<int>::iterator	ms_end;
	std::list<int>::iterator	lst_it;
	std::list<int>::iterator	lst_end;
	bool						same;

	same = true;
	ms_it = mstack.begin();
	ms_end = mstack.end();
	lst_it = lst.begin();
	lst_end = lst.end();
	while (ms_it != ms_end && lst_it != lst_end)
	{
		if (*ms_it != *lst_it)
		{
			same = false;
			break ;
		}
		++ms_it;
		++lst_it;
	}
	if (ms_it != ms_end || lst_it != lst_end)
		same = false;
	if (same)
		std::cout << "OK: MutantStack and list iterate in the same order." << std::endl;
	else
		std::cout << "KO: MutantStack and list do not iterate in the same order." << std::endl;
}

int	main(void)
{
	MutantStack<int>			mstack;
	MutantStack<int>			assign_stack;
	MutantStack<int>::iterator	it;
	MutantStack<int>::iterator	ite;
	std::list<int>				lst;

	print_separator("STACK OPERATIONS");
	mstack.push(5);
	mstack.push(17);
	std::cout << "Top element: " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "Size after pop: " << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	std::cout << "Top element after pushes: " << mstack.top() << std::endl;
	std::cout << "Current size: " << mstack.size() << std::endl;

	print_separator("ITERATOR TEST");
	it = mstack.begin();
	ite = mstack.end();
	if (it != ite)
	{
		std::cout << "First element: " << *it << std::endl;
		++it;
		if (it != ite)
			std::cout << "Second element after ++it: " << *it << std::endl;
		--it;
		std::cout << "Back to first element after --it: " << *it << std::endl;
	}
	print_mutantstack(mstack, "mstack");

	print_separator("COPY CONSTRUCTOR TEST");
	MutantStack<int> copy_stack(mstack);
	print_mutantstack(copy_stack, "copy_stack");
	std::cout << "Pushing 999 into original stack." << std::endl;
	mstack.push(999);
	std::cout << "Original top: " << mstack.top() << std::endl;
	std::cout << "Copied top: " << copy_stack.top() << std::endl;
	if (mstack.top() != copy_stack.top())
		std::cout << "OK: copy constructor created an independent copy." << std::endl;
	else
		std::cout << "KO: copy constructor did not behave as expected." << std::endl;

	print_separator("ASSIGNMENT OPERATOR TEST");
	assign_stack = mstack;
	print_mutantstack(assign_stack, "assign_stack");
	std::cout << "Popping one element from original stack." << std::endl;
	mstack.pop();
	std::cout << "Original top after pop: " << mstack.top() << std::endl;
	std::cout << "Assigned top: " << assign_stack.top() << std::endl;
	if (mstack.top() != assign_stack.top())
		std::cout << "OK: assignment operator created an independent copy." << std::endl;
	else
		std::cout << "KO: assignment operator did not behave as expected." << std::endl;

	print_separator("COMPARISON WITH LIST");
	lst.push_back(5);
	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(737);
	lst.push_back(0);
	lst.push_back(999);
	print_mutantstack(assign_stack, "assign_stack");
	print_list(lst, "list");
	compare_with_list(assign_stack, lst);

	print_separator("STD::STACK CONSTRUCTION TEST");
	std::stack<int>	s(assign_stack);
	std::cout << "std::stack created from MutantStack." << std::endl;
	std::cout << "Top of std::stack: " << s.top() << std::endl;
	std::cout << "Size of std::stack: " << s.size() << std::endl;

	return (0);
}