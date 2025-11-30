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
#include <iostream>
#include <limits>
#include <cmath>
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

static void	printChar(double num) {
	std::cout << "char: ";
	if (std::isnan(num) || std::isinf(num) || num < 0 || num > 127)
		std::cout << "impossible";
	else if (!std::isprint(static_cast<unsigned char>(num)))
		std::cout << "Non displayable";
	else
		std::cout << "'" << static_cast<char>(num) << "'";
	std::cout << "\n";
}

static void	printFloat(double num) {
	float	f = static_cast<float>(num);
	
	std::cout << "float: ";
	if (std::isnan(static_cast<float>(f)))
		std::cout << "nanf";
	else if (std::isinf(static_cast<float>(f)))
	{
		if (std::signbit(f))
			std::cout << "-inff";
		else
			std::cout << "+inff";
	}
	else
	{
		std::cout << static_cast<float>(f);
		if (f == static_cast<int>(f))
			std::cout << ".0";
		std::cout << "f";
	}
	std::cout << "\n";
}

static void	printInt(double num)
{
	std::cout << "int: ";
	if (std::isnan(num) || std::isinf(num)
			|| num < std::numeric_limits<int>::min()
			|| num > std::numeric_limits<int>::max())
		std::cout << "impossible";
	else
		std::cout << static_cast<int>(num) << "";
	std::cout << "\n";
}

static void	printDouble(double num) {
	std::cout << "double: ";
	if (std::isnan(num))
		std::cout << "nan";
	else if (std::isinf(num))
	{
		if (std::signbit(num))
			std::cout << "-inf";
		else
			std::cout << "+inf";
	}
	else
	{
		std::cout << num;
		if (num == static_cast<int>(num))
			std::cout << ".0";
	}
	std::cout << "\n";
}

static void	printLitteral(double num) {
	printChar(num);
	printInt(num);
	printFloat(num);
	printDouble(num);
}

static bool	isIntLitteral(const std::string &input) {
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
	while (it != input.end() && std::isdigit(static_cast<unsigned char>(*it)))
		++it;
	return (it == input.end());
}

static bool	isFloatLitteral(const std::string& input) {
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

static bool	isDoubleLitteral(const std::string& input) {
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

static bool	isCharLitteral(const std::string& input) { 
	return (input.length() == 3 && input[0] == '\'' && input[2] == '\'');
}

static bool	isPseudoLitteral(const std::string &input) {
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
		long					tmp;

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
	
	if (isPseudoLitteral(inputValue))
		inputType = "pseudo";
	else if (isCharLitteral(inputValue))
		inputType = "char";
	else if (isIntLitteral(inputValue))
		inputType = "int";
	else if (isFloatLitteral(inputValue))
		inputType = "float";
	else if (isDoubleLitteral(inputValue))
		inputType = "double";
	else
		inputType = "invalid";
	if (inputType == "invalid")
	{
		std::cerr << "Error: Invalid type\n";
		return ;
	}
	res = convertType(inputType, inputValue);
	printLitteral(res);
}

ScalarConverter::ScalarConverter(void) {}

ScalarConverter::~ScalarConverter(void) {}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {
	(void)other;
}

ScalarConverter&	ScalarConverter::operator=(const ScalarConverter& other) {
	(void)other;
	return (*this);
}

