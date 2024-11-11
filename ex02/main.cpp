/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrigny <yrigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 00:25:01 by yrigny            #+#    #+#             */
/*   Updated: 2024/11/11 13:43:34 by yrigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <list>
#include <algorithm>
#define TITLE "\e[1;33m"
#define NONE "\e[0m"

std::ostream&	operator<<(std::ostream &o, const std::stack<int> &s)
{
	std::stack<int> tmp = s;
	o << "[ ";
	while (!tmp.empty())
	{
		o << tmp.top() << " ";
		tmp.pop();
	}
	o << "]" << std::endl;
	return o;
}

int main()
{
	std::cout << TITLE << "Test 1: example test from subject" << NONE << std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	std::cout << TITLE << "Test 2: compare with list container" << NONE << std::endl;
	std::list<int> list;
	list.push_back(5);
	list.push_back(17);
	std::cout << list.back() << std::endl;
	list.pop_back();
	std::cout << list.size() << std::endl;
	list.push_back(3);
	list.push_back(5);
	list.push_back(737);
	list.push_back(0);
	std::list<int>::iterator it2 = list.begin();
	std::list<int>::iterator ite2 = list.end();
	++it2;
	--it2;
	while (it2 != ite2)
	{
		std::cout << *it2 << std::endl;
		++it2;
	}

	std::cout << TITLE << "Test 3: use member functions of std::stack" << NONE << std::endl;
	std::cout << "mstack:" << std::endl;
	std::cout << mstack;
	std::cout << "copy from mstack to construct mstack2:" << std::endl;
	MutantStack<int> mstack2(mstack);
	std::cout << mstack2;
	std::cout << "mstack2.empty() - Returns whether the stack is empty:"
	<< std::endl << mstack2.empty() << std::endl;
	std::cout << "mstack2.size() - Returns the size of the stack:"
	<< std::endl << mstack2.size() << std::endl;
	std::cout << "mstack2.top() - Returns a reference to the top most element of the stack:"
	<< std::endl << mstack2.top() << std::endl;
	std::cout << "mstack2.push(42) - Adds the element '42' at the top of the stack:" << std::endl;
	mstack2.push(42);
	std::cout << mstack2;
	std::cout << "mstack2.push(2024) - Adds the element '2024' at the top of the stack:" << std::endl;
	mstack2.push(2024);
	std::cout << mstack2;
	std::cout << "mstack2.pop() - Deletes the most recent entered element of the stack:" << std::endl;
	mstack2.pop();
	std::cout << mstack2;
	std::cout << "use copy assignment to let mstack2 = mstack:" << std::endl;
	mstack2 = mstack;
	std::cout << mstack2;

	std::cout << TITLE << "Test 4: use iterator feature of MutantStack" << NONE << std::endl;
	std::cout << "use iterator to print elements from oldest to newest" << std::endl;
	for (MutantStack<int>::iterator it = mstack2.begin(); it != mstack2.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "use iterator to find element 737" << std::endl;
	MutantStack<int>::iterator find = std::find(mstack2.begin(), mstack2.end(), 737);
	if (find != mstack2.end())
		std::cout << "Element found: " << *find << std::endl;
	else
		std::cout << "Element not found" << std::endl;

	return 0;
}
