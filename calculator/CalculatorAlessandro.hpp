#ifndef CALCULATORALESSANDRO_BASE_HPP
#define CALCULATORALESSANDRO_BASE_HPP

#include "Calculator.hpp"

class CalculatorAlessandro: public Calculator{
		Screen* screen;
		Cpu* cpu;
		int flag=0;
		int op1=0, op2=0,equal=0, operador, flagOperator=1, block=0;
		void decompilerScreen(int);
		void multiplexer(void);
	public:
		
		Cpu * getCpu(void);
		void setCpu(Cpu*);
		
		Screen * getScreen(void);
		void setScreen(Screen*);
		//Herdados de CalculatorReceiver
		void receiveClear(void);
		//Herdados de DigitReceiver
		void receiveDigit(Digit);
		//Herdados de OperationReceiver
		void receive(Operation);
		//decompilerScreen
		//void decompilerScreen(int, Screen*, Cpu*);
};

#endif

