/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrigny <yrigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 00:27:21 by yrigny            #+#    #+#             */
/*   Updated: 2024/11/10 22:09:24 by yrigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP
# include <stack>
# include <deque>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
	
		typedef typename std::stack<T>::container_type::iterator iterator;
		/*	iterator is a type that depends on the template parameter T
			it is accessible from the outside of the class */

		MutantStack();
		MutantStack(const MutantStack &src);
		~MutantStack();
		MutantStack&	operator=(const MutantStack &rhs);

		iterator	begin();
		iterator	end();
};

# include "MutantStack.tpp"

#endif
