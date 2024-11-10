/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrigny <yrigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 19:07:13 by yrigny            #+#    #+#             */
/*   Updated: 2024/11/10 22:01:08 by yrigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_TPP
# define MUTANTSTACK_TPP
# include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack() {}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack<T>& src) : std::stack<T>(src) {}

template <typename T>
MutantStack<T>::~MutantStack() {}

template <typename T>
MutantStack<T>&	MutantStack<T>::operator=(const MutantStack<T>& rhs)
{
	if (*this != rhs)
		std::stack<T>::operator=(rhs);
	return *this;
}

template <typename T>
typename MutantStack<T>::iterator	MutantStack<T>::begin()
{
	return this->c.begin();
	/* this->c is the container of the stack, which is a deque by default */
}

template <typename T>
typename MutantStack<T>::iterator	MutantStack<T>::end()
{
	return this->c.end();
}

#endif
