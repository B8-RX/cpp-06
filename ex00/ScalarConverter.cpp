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
#include <limits>
#include <sstream>
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

ScalarConverter::ScalarConverter(void) {}

ScalarConverter::~ScalarConverter(void) {
}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {
	(void)other;
}

ScalarConverter&	ScalarConverter::operator=(const ScalarConverter& other) {
	(void)other;
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

static double	convertType(const std::string& inputType, const std::string& inputValue) {
	double				res = 0;

	if (inputType == "pseudo")
	{
		if (inputValue == "nanf" || inputValue == "nan")
			res = std::numeric_limits<double>::quiet_NaN();
		else if (inputValue == "+inff" || inputValue == "+inf")
			res = std::numeric_limits<double>::infinity();
		else
			res = -std::numeric_limits<double>::infinity();
	}
	else if (inputType == "char")
		res = static_cast<double>(inputValue[1]);
	else if (inputType == "int")
	{
		std::istringstream	iss(inputValue);
		int					tmp;

		iss >> tmp;
		res = static_cast<double>(tmp);
	}
	else if (inputType == "float")
	{
		std::string			tmpVal = inputValue;

		tmpVal.erase(tmpVal.length() - 1, 1);
		std::istringstream	iss(tmpVal);
		float	tmp;
		
		iss >> tmp;
		res = static_cast<double>(tmp);
	}
	else if (inputType == "double")
	{
		std::istringstream	iss(inputValue);
		
		iss >> res;
	}
	return (res);
}

void	ScalarConverter::convert(const std::string& inputValue) {
	std::string	inputType;
	double		res; 
	
	if (ScalarConverter::isPseudoLitteral(inputValue))
		inputType = "pseudo";
	else if (ScalarConverter::isCharLitteral(inputValue))
		inputType = "char";
	else if (ScalarConverter::isIntLitteral(inputValue))
		inputType = "int";
	else if (ScalarConverter::isFloatLitteral(inputValue))
		inputType = "float";
	else if (ScalarConverter::isDoubleLitteral(inputValue))
		inputType = "double";
	else
		inputType = "invalid";
	if (inputType == "invalid")
	{
		std::cerr << "Error: Invalid type\n";
		return ;
	}
	res = convertType(inputType, inputValue);
}
	// TODO 
	// check for overflow or non sens
	//
	//
	// include all headers to handle limits and special values
