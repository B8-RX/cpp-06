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
#include <iostream>
#include <string>
#include "ScalarConverter.hpp"

static bool	isPseudoFloatLitteral(const std::string& s) {
	return (s == "nanf" || s == "+inff" || s == "-inff");
}

static bool	isPseudoDoubleLitteral(const std::string& s) {
	return (s == "nan" || s == "+inf" || s == "-inf");
}

static int	hasDigitBeforeDot(const std::string& s, size_t i) {
	int	digit = 0;

	while (i < s.length() && std::isdigit(static_cast<unsigned char>(s[i])))
	{
		digit++;
		i++;
	}
	return (digit);
}

static int	hasDigitAfterDot(const std::string& s, size_t i) {
	int	digit = 0;

	while (i < s.length() && std::isdigit(static_cast<unsigned char>(s[i])))
	{
		digit++;
		i++;
	}
	return (digit);
}

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
	size_t						startIndex = 0;
	std::string::const_iterator	it;
	
	if (input.empty())
		return (false);
	if (input[0] == '-' || input[0] == '+')
	{
		if (input.length() == 1)
			return (false);
		startIndex = 1;
	}
	it = input.begin() + startIndex;
	while (it != input.end() && isdigit(static_cast<unsigned char>(*it)))
		++it;
	return (it == input.end());
}

bool	ScalarConverter::isFloatLitteral(const std::string& input) {
	size_t						startIndex = 0;
	
	if (input.empty())
		return (false);
	if (input[0] == '-' || input[0] == '+') 
		startIndex = 1;
	int							digits = hasDigitBeforeDot(input, startIndex); 
	std::string::const_iterator	it = input.begin() + startIndex + digits;
	if (digits == 0 || it == input.end() || *it != '.')
		return (false);
	else
		++it;
	digits = hasDigitAfterDot(input, startIndex + digits + 1);
	it += digits;
	if (digits == 0 || it == input.end() || *it != 'f')
		return (false);
	it++;
	return (it == input.end());
}

bool	ScalarConverter::isDoubleLitteral(const std::string& input) {
	size_t						startIndex = 0;
	
	if (input.empty())
		return (false);
	if (input[0] == '-' || input[0] == '+') 
		startIndex = 1;
	int							digits = hasDigitBeforeDot(input, startIndex); 
	std::string::const_iterator	it = input.begin() + startIndex + digits;
	if (digits == 0 || it == input.end() || *it != '.')
		return (false);
	else
		++it;
	digits = hasDigitAfterDot(input, startIndex + digits + 1);
	it += digits;
	return (digits > 0 && it == input.end());
}

bool	ScalarConverter::isCharLitteral(const std::string& input) { 
	return (input.length() == 3 && input[0] == '\'' && input[2] == '\'');
}

bool	ScalarConverter::isPseudoLitteral(const std::string &input) {
	return (isPseudoFloatLitteral(input) || isPseudoDoubleLitteral(input));
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
	else if (ScalarConverter::isPseudoLitteral(input))
		std::cout << "Input is a pseudo litteral\n";
	
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
