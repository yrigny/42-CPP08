/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrigny <yrigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 21:43:25 by yrigny            #+#    #+#             */
/*   Updated: 2024/11/10 20:44:14 by yrigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _n(0) {}

Span::Span(unsigned int n) : _n(n) {}

Span::Span(const Span& src) : _n(src._n), _v(src._v) {}

Span::~Span() {}

Span&	Span::operator=(const Span& rhs)
{
	if (this != &rhs)
	{
		_n = rhs._n;
		_v = rhs._v;
	}
	return *this;
}

void	Span::addNumber(int n)
{
	if (_v.size() < _n)
		_v.push_back(n);
	else
		throw FullException();
}

void	Span::addRange(InputIt start, InputIt end)
{
	if (std::distance(start, end) > static_cast<long>(_n - _v.size()))
		throw BadRangeException();
	_v.insert(_v.end(), start, end);
}

int	Span::shortestSpan()
{
	if (_v.size() < 2)
		throw NoSpanException();
	std::vector<int> v = _v;
	std::sort(v.begin(), v.end());
	std::vector<int>::iterator it;
	int span = v[1] - v[0];
	for (it = v.begin() + 1; it < v.end() - 1; it++)
	{
		if (span == 0)
			break;
		if (span > *(it + 1) - *it)
			span = *(it + 1) - *it;
	}
	return span;
}

int	Span::longestSpan()
{
	if (_v.size() < 2)
		throw NoSpanException();
	int max = *std::max_element(_v.begin(), _v.end());
	int min = *std::min_element(_v.begin(), _v.end());
	return max - min;
}

const std::vector<int>&	Span::getV() const
{
	return _v;
}

const char*	Span::FullException::what() const throw()
{
	return "Container cannot store more elements";
}

const char* Span::NoSpanException::what() const throw()
{
	return "Container does not have enough elements";
}

const char* Span::BadRangeException::what() const throw()
{
	return "Range is too big to fit in the container";
}

std::ostream&	operator<<(std::ostream& o, const Span& span)
{
	const std::vector<int>& v = span.getV();
	std::vector<int>::const_iterator it;
	for (it = v.begin(); it != v.end(); it++)
		o << *it << " ";
	return o;
}
