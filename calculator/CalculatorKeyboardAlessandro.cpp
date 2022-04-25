#include "Calculator.hpp"
#include "CalculatorKeyboardAlessandro.hpp"

void CalculatorKeyboardAlessandro::setCalculatorReceiver(CalculatorReceiver* Calculator){
	this->calculatorReceiver=Calculator;
}

CalculatorReceiver* CalculatorKeyboardAlessandro::getCalculatorReceiver(void){
	return this->calculatorReceiver;
}

DigitReceiver* CalculatorKeyboardAlessandro::getDigitReceiver(void){
	return this->digitReceiver;
}
OperationReceiver* CalculatorKeyboardAlessandro::getOperationReceiver(void){
	return this->operationReceiver;
}

//Number Keys
void CalculatorKeyboardAlessandro::press0(void){
	this->calculatorReceiver->receiveDigit(ZERO);
}
void CalculatorKeyboardAlessandro::press1(void){
	this->calculatorReceiver->receiveDigit(ONE);
}
void CalculatorKeyboardAlessandro::press2(void){
	this->calculatorReceiver->receiveDigit(TWO);
}
void CalculatorKeyboardAlessandro::press3(void){
	this->calculatorReceiver->receiveDigit(THREE);
}
void CalculatorKeyboardAlessandro::press4(void){
	this->calculatorReceiver->receiveDigit(FOUR);
}
void CalculatorKeyboardAlessandro::press5(void){
	this->calculatorReceiver->receiveDigit(FIVE);
}
void CalculatorKeyboardAlessandro::press6(void){
	this->calculatorReceiver->receiveDigit(SIX);
}
void CalculatorKeyboardAlessandro::press7(void){
	this->calculatorReceiver->receiveDigit(SEVEN);
}
void CalculatorKeyboardAlessandro::press8(void){
	this->calculatorReceiver->receiveDigit(EIGHT);
}
void CalculatorKeyboardAlessandro::press9(void){
	this->calculatorReceiver->receiveDigit(NINE);
}
//Operation Keys
void CalculatorKeyboardAlessandro::pressSum(void){
	this->calculatorReceiver->receive(SUM);
}
void CalculatorKeyboardAlessandro::pressSub(void){
	this->calculatorReceiver->receive(SUB);
}
void CalculatorKeyboardAlessandro::pressDiv(void){
	this->calculatorReceiver->receive(DIV);
}
void CalculatorKeyboardAlessandro::pressMult(void){
	this->calculatorReceiver->receive(MULT);
}
void CalculatorKeyboardAlessandro::pressEqual(void){
	this->calculatorReceiver->receive(EQUAL);
}
//Clear Key
void CalculatorKeyboardAlessandro::pressClear(void){
	this->calculatorReceiver->receiveClear();
}

