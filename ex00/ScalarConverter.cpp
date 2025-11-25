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

#include <cctype>
#include <cstddef>
#include <ios>
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

bool	ScalarConverter::isIntLitteral(const std::string &input) {
	std::string::const_iterator it = input.begin();
	
	while (it != input.end() && std::isdigit(*it))
		++it;
	if (!input.empty() && it == input.end())
		return (true);
	return (false);
}

bool	ScalarConverter::isFloatLitteral(const std::string& input) {
	size_t	foundDot = input.find('.', 0);
	size_t	foundF = input.find('f', 0);

	return (foundDot != std::string::npos && 
			foundF != std::string::npos &&
			foundF == (input.length() - 1));
}

bool	ScalarConverter::isDoubleLitteral(const std::string& input) {
	size_t	foundDot = input.find('.', 0);

	return (foundDot != std::string::npos);
}

bool	ScalarConverter::isCharLitteral(const std::string& input) { 
	return (input.length() == 3 && input[0] == '\'' && input[2] == '\'');
}

void	ScalarConverter::convert(const std::string& input) {
	std::cout << "ScalarConverter convert method called\n";
	
	if (ScalarConverter::isIntLitteral(input))
		std::cout << "Input is an int litteral\n";
	else if (ScalarConverter::isCharLitteral(input))
		std::cout << "Input is a char litteral\n";
	else if (ScalarConverter::isFloatLitteral(input))
		std::cout << "Input is a float litteral\n";
	else if (ScalarConverter::isDoubleLitteral(input))
		std::cout << "Input is a double litteral\n";
	
	// TODO 
	// detect what is the type of the litteral (char, int, float, double)
	// 
	//
	//
	// convert from string to its type
	//
	//
	// convert from its type to the 3 others scalar type
	//
	//
	// check for overflow or non sens
	//
	//
	// include all headers to handle limits and special values
}
