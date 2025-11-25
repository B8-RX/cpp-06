/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssghioua <ssghioua@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 04:28:12 by ssghioua          #+#    #+#             */
/*   Updated: 2025/11/24 04:28:13 by ssghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

int main(int argc, char **argv) {
	if (argc > 1)
	{
		std::cout << "1st argument: " << argv[1] << "\n";		
		ScalarConverter::convert(argv[1]);

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
	else
		std::cerr << "Error: Need one argument. Usage: [./convert] [arg]";
	return (0);
}
