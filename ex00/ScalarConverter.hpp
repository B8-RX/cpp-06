/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssghioua <ssghioua@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 05:30:24 by ssghioua          #+#    #+#             */
/*   Updated: 2025/11/24 05:30:25 by ssghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <string>

class	ScalarConverter {
	public:
		ScalarConverter(void);
		virtual ~ScalarConverter(void) = 0;
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter&		operator=(const ScalarConverter& other);

		ScalarConverter(const std::string& input);
		static void				convert(const std::string& input); 
};

#endif // !SCALARCONVERTER_HPP
