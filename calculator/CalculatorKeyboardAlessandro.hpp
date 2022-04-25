#ifndef CALCULATORKEYBOARDALESSANDRO_BASE_HPP
#define CALCULATORKEYBOARDALESSANDRO_BASE_HPP

#include "Calculator.hpp"
#include<stdio.h>

class CalculatorKeyboardAlessandro: public CalculatorKeyboard{
		CalculatorReceiver* calculatorReceiver;
		DigitReceiver* digitReceiver;
		OperationReceiver* operationReceiver;
	public:
		void setCalculatorReceiver(CalculatorReceiver*);
	
		//Herdados de CalculatorKeyboard
		CalculatorReceiver* getCalculatorReceiver(void);
		void pressClear(void);	
		//Herdados de DigitKeyboard
		DigitReceiver* getDigitReceiver(void);
		void press0(void);  //Implement
		void press1(void);	//Implement
		void press2(void);	//Implement
		void press3(void);	//Implement
		void press4(void);	//Implement
		void press5(void);	//Implement
		void press6(void);	//Implement
		void press7(void);	//Implement
		void press8(void);	//Implement
		void press9(void);	//Implement
		//Herdados de OperationKeyboard
		OperationReceiver* getOperationReceiver(void);
		void pressSum(void);	//Implement
		void pressSub(void);	//Implement
		void pressMult(void);	//Implement
		void pressDiv(void);	//Implement
		void pressEqual(void);	//Implement
		
};




#endif