#include <iostream>
#include<stdlib.h>
#include<conio.h>
#include "Calculator.hpp"
#include "CalculatorAlessandro.hpp"
#include "CalculatorKeyboardAlessandro.hpp"
#include "ScreenAlessandro.hpp"
#include "CpuAlessandro.hpp"



char getKey() //Use ASCII table
{
    if (kbhit())
        return fgetc(stdin);

    return 0; // NENHUMA TECLA FOI PRESSIONADA AINDA
}

void key(CalculatorKeyboard* cka){
	char c = getch();
	//getKey();
    switch (c)
    {
	//Numbers Keys
    case 48:cka->press0();break;
	case 49:cka->press1();break;
	case 50:cka->press2();break;
	case 51:cka->press3();break;
	case 52:cka->press4();break;
	case 53:cka->press5();break;
	case 54:cka->press6();break;
	case 55:cka->press7();break;
	case 56:cka->press8();break;
	case 57:cka->press9();break;
	
	//Exit Program
	case 102:exit(1);

	//Operation Keys
	case 43:cka->pressSum();break;
	case 45:cka->pressSub();break;
	case 42:cka->pressMult();break;
	case 47:cka->pressDiv();break;
	//Equal Key
	case 61:cka->pressEqual();break;
	//Clear Key
	case 32:cka->pressClear();break;
	//default
    default: break;

    }
}

int main(int argc, char * argv[], char *envp[]){



CalculatorKeyboard* cka = new CalculatorKeyboardAlessandro();
Screen* s = new screenAlessandro();
Cpu* cpu = new cpuAlessandro();

Calculator* calculator = new CalculatorAlessandro();

calculator->setScreen(s);
calculator->setCpu(cpu);
cka->setCalculatorReceiver(calculator);

while(true){
	  key(cka);
  }


}
