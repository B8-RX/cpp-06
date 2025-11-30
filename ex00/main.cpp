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
		ScalarConverter::convert(argv[1]);
	else
		std::cerr << "Error: Need one argument. Usage: [./convert] [arg]";
	return (0);
}
