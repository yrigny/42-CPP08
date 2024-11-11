/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrigny <yrigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 21:06:31 by yrigny            #+#    #+#             */
/*   Updated: 2024/11/11 12:17:08 by yrigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP
# include <algorithm>
# include <stdexcept>

template <typename T>
int& easyfind(T& container, int n)
{
	typename T::iterator it = std::find(container.begin(), container.end(), n);
	if (it != container.end())
		return *it;
	throw std::out_of_range("Element not found");
}

#endif
