#ifndef SCREENALESSANDRO_BASE_HPP
#define SCREENALESSANDRO_BASE_HPP

#include "Calculator.hpp"



class screenAlessandro: public Screen {
	public:
		void clear(void);
		void addDigit(Digit);
};


#endif