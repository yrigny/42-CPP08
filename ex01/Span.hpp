/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrigny <yrigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 21:38:07 by yrigny            #+#    #+#             */
/*   Updated: 2024/11/10 20:56:01 by yrigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP
# include <vector>
# include <algorithm>
# include <iterator>
# include <iostream>

class Span
{
	typedef std::vector<int>::iterator InputIt;
	/*	InputIt is an alias for the type of the iterator of the vector<int> 
		if not declared in public section, it would be private */
	
	public:
		Span();
		Span(unsigned int n);
		Span(const Span& src);
		~Span();
		Span&					operator=(const Span& rhs);

		void					addNumber(int n);
		void					addRange(InputIt start, InputIt end);
		int						shortestSpan();
		int						longestSpan();
		const std::vector<int>&	getV() const;

		class FullException : public std::exception
		{
			public:
				const char* what() const throw();
		};

		class NoSpanException : public std::exception
		{
			public:
				const char* what() const throw();
		};

		class BadRangeException : public std::exception
		{
			public:
				const char* what() const throw();
		};

	private:
		unsigned int		_n;
		std::vector<int>	_v;
};

std::ostream&	operator<<(std::ostream& o, const Span& span);

#endif
