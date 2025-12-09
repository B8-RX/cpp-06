
#ifndef DATA_HPP
# define DATA_HPP

#include <string>

class Data {
	private:
		std::string	_name;
	public:
		Data(void);
		~Data(void);
		Data(const std::string& name);
		Data(const Data& other);
		Data&				operator=(const Data& other);
		const std::string&	getName(void) const;
};

#endif // !DATA_HPP
