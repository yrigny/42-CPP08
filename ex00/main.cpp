/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrigny <yrigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 21:05:21 by yrigny            #+#    #+#             */
/*   Updated: 2024/11/10 01:18:36 by yrigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <array>
#define MAX_SIZE 10
#define CLR "\e[33m"
#define BOLD "\e[1m"
#define NONE "\e[0m"

int main()
{
	std::cout << CLR BOLD "Test 1: vector container" NONE << std::endl;
	std::vector<int> v;
	for (int i = 0; i < MAX_SIZE; i++)
		v.push_back(i);
	std::cout << "Vector: [ ";
	for (size_t i = 0; i < v.size(); i++)
		std::cout << v[i] << " ";
	std::cout << "]" << std::endl;

	std::cout << "find 3 in vector: ";
	try
	{
		std::cout << easyfind(v, 3) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Not found" << std::endl;
	}
	std::cout << "find 6 in vector: ";
	try
	{
		std::cout << easyfind(v, 6) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Not found" << std::endl;
	}
	std::cout << "find 10 in vector: ";
	try
	{
		std::cout << easyfind(v, 10) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Not found" << std::endl;
	}
	std::cout << "Empty the vector container" << std::endl;
	v.clear();
	std::cout << "Vector: [ ";
	for (size_t i = 0; i < v.size(); i++)
		std::cout << v[i] << " ";
	std::cout << "]" << std::endl;
	std::cout << "find 3 in empty vector: ";
	try
	{
		std::cout << easyfind(v, 3) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Not found" << std::endl;
	}

	std::cout << CLR BOLD "Test 2: list container" NONE << std::endl;
	std::list<int> l;
	std::cout << "Assign 42 to 5 elements in the list" << std::endl;
	l.assign(5, 42);
	std::cout << "Push 3 to the list" << std::endl;
	l.push_back(3);
	std::cout << "List: [ ";
	for (std::list<int>::iterator it = l.begin(); it != l.end(); it++)
		std::cout << *it << " ";
	std::cout << "]" << std::endl;
	std::cout << "find 3 in list: ";
	try
	{
		std::cout << easyfind(l, 3) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Not found" << std::endl;
	}
	std::cout << "Empty the list" << std::endl;
	l.clear();
	std::cout << "List: [ ";
	for (std::list<int>::iterator it = l.begin(); it != l.end(); it++)
		std::cout << *it << " ";
	std::cout << "]" << std::endl;
	std::cout << "find 3 in empty list: ";
	try
	{
		std::cout << easyfind(l, 3) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Not found" << std::endl;
	}
	
	std::cout << CLR BOLD "Test 3: array container" NONE << std::endl;
	std::array<int, MAX_SIZE> arr;
	arr.fill(-1);
	std::cout << "Array: [ ";
	for (int i = 0; i < MAX_SIZE; i++)
		std::cout << arr[i] << " ";
	std::cout << "]" << std::endl;
	std::cout << "find 3 in array: ";
	try
	{
		std::cout << easyfind(arr, 3) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Not found" << std::endl;
	}
	std::cout << "Place 3 in the array" << std::endl;
	arr[3] = 3;
	std::cout << "Array: [ ";
	for (int i = 0; i < MAX_SIZE; i++)
		std::cout << arr[i] << " ";
	std::cout << "]" << std::endl;
	std::cout << "find 3 in array: ";
	try
	{
		std::cout << easyfind(arr, 3) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Not found" << std::endl;
	}
	
	return 0;
}