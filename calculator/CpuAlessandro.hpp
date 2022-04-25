#ifndef CPUALESSANDRO_BASE_HPP
#define CPUALESSANDRO_BASE_HPP

#include "Calculator.hpp"
#include <cstddef>

class cpuAlessandro: public Cpu{
	public:
		int sum(int, int);
		int sub(int, int);
		int div(int, int);
		int mult(int, int);
};

#endif