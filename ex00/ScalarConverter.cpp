/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssghioua <ssghioua@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 05:57:10 by ssghioua          #+#    #+#             */
/*   Updated: 2025/11/24 05:57:11 by ssghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void) {
	std::cout << "ScalarConverter Default constructor called\n";
}

ScalarConverter::~ScalarConverter(void) {
}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {
	(void)other;
	std::cout << "ScalarConverter Copy constructor called\n";
}

ScalarConverter&	ScalarConverter::operator=(const ScalarConverter& other) {
	(void)other;
	std::cout << "ScalarConverter Copy assignment operator called\n";
	return (*this);
}

ScalarConverter::ScalarConverter(const std::string& input)
{
	(void)input;
	std::cout << "ScalarConverter String constructor called\n";
}

void	ScalarConverter::convert(const std::string& input) {
	(void)input;
	std::cout << "ScalarConverter convert method called\n";
}
