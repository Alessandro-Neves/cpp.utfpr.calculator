#include "Calculator.hpp"
#include "CalculatorAlessandro.hpp"


void CalculatorAlessandro::receiveDigit(Digit digito){
	if(block==0){
		if(flag==0){
			switch(digito){
			case ZERO:
				this->op1=this->cpu->sum(this->cpu->mult(op1, 10), 0);

			break;
			case ONE:
				this->op1=this->cpu->sum(this->cpu->mult(op1, 10), 1);

			break;
			case TWO:
				this->op1=this->cpu->sum(this->cpu->mult(op1, 10), 2);
			break;
			case THREE:
				this->op1=this->cpu->sum(this->cpu->mult(op1, 10), 3);
			break;
			case FOUR:
				this->op1=this->cpu->sum(this->cpu->mult(op1, 10), 4);
			break;
			case FIVE:
				this->op1=this->cpu->sum(this->cpu->mult(op1, 10), 5);
			break;
			case SIX:
				this->op1=this->cpu->sum(this->cpu->mult(op1, 10), 6);
			break;
			case SEVEN:
				this->op1=this->cpu->sum(this->cpu->mult(op1, 10), 7);
			break;
			case EIGHT:
				this->op1=this->cpu->sum(this->cpu->mult(op1, 10), 8);
			break;
			case NINE:
				this->op1=this->cpu->sum(this->cpu->mult(op1, 10), 9);
			break;
			
		}
			if(this->flagOperator==1){
				this->screen->clear();
				this->flagOperator=0;
				this->screen->addDigit(digito);
			}else{
				this->screen->addDigit(digito);
			}
		}else{
			switch(digito){
			case ZERO:
				this->op2=this->cpu->sum(this->cpu->mult(op2, 10), 0);
			break;
			case ONE:
				this->op2=this->cpu->sum(this->cpu->mult(op2, 10), 1);
			break;
			case TWO:
				this->op2=this->cpu->sum(this->cpu->mult(op2, 10), 2);
			break;
			case THREE:
				this->op2=this->cpu->sum(this->cpu->mult(op2, 10), 3);
			break;
			case FOUR:
				this->op2=this->cpu->sum(this->cpu->mult(op2, 10), 4);
			break;
			case FIVE:
				this->op2=this->cpu->sum(this->cpu->mult(op2, 10), 5);
			break;
			case SIX:
				this->op2=this->cpu->sum(this->cpu->mult(op2, 10), 6);
			break;
			case SEVEN:
				this->op2=this->cpu->sum(this->cpu->mult(op2, 10), 7);
			break;
			case EIGHT:
				this->op2=this->cpu->sum(this->cpu->mult(op2, 10), 8);
			break;
			case NINE:
				this->op2=this->cpu->sum(this->cpu->mult(op2, 10), 9);
			break;
			
		}
			if(this->flagOperator==1){
				this->screen->clear();
				this->flagOperator=0;
				this->screen->addDigit(digito);
			}else{
				this->screen->addDigit(digito);
			}
		}
	}
}

Cpu* CalculatorAlessandro::getCpu(void){
	return this->cpu;
}
//getScreen
Screen* CalculatorAlessandro::getScreen(void){
	return this->screen;
}
//setScreen
void CalculatorAlessandro::setScreen(Screen* screen){
	this->screen=screen;
}
//setCpu
void CalculatorAlessandro::setCpu(Cpu* cpu){
	this->cpu=cpu;
}
//receiveClear
void CalculatorAlessandro::receiveClear(void){
	this->flag=0;
	this->operador=0;
	this->flagOperator=1;
	this->op1=0;
	this->op2=0;
	this->block=0;
	screen->clear();
}

void CalculatorAlessandro::receive(Operation operation){
	if(this->block==0){
		switch (operation){
			case SUM:
				if(this->flag==0){
					this->flag = 1;
					this->flagOperator=1;
					this->operador=0;
					screen->clear();
					break;
				}else{
					if(this->equal==0){
						this->multiplexer();
						if(block==1){break;}
					}
					this->flagOperator=1;
					this->equal=0;
					this->operador=0;
					this->op2=0;
					screen->clear();
					if(this->op1==0){
						screen->addDigit(ZERO); break;
					}
					this->decompilerScreen(op1);
					break;
				}
			case SUB:
				if(this->flag==0){
					this->flag = 1;
					this->flagOperator=1;
					this->operador=1;
					screen->clear();
					break;
				}else{
					if(this->equal==0){
						this->multiplexer();
						if(block==1){break;}
					}
					this->flagOperator=1;
					this->equal=0;
					this->operador=1;
					this->op2=0;
					screen->clear();
					if(this->op1==0){
						screen->addDigit(ZERO); break;
					}
					this->decompilerScreen(op1);
					break;
				}
			case MULT:
				if(this->flag==0){
					this->flag = 1;
					this->flagOperator=1;
					this->operador=2;
					screen->clear();
					break;
				}else{
					if(this->equal==0){
						this->multiplexer();
						if(block==1){break;}
					}
					this->flagOperator=1;
					this->equal=0;
					this->operador=2;
					this->op2=0;
					screen->clear();
					if(this->op1==0){
						screen->addDigit(ZERO); break;
					}
					this->decompilerScreen(op1);
					break;
				}
			case DIV:
				if(this->flag==0){
					this->flag = 1;
					this->flagOperator=1;
					this->operador=3;
					screen->clear();
					break;
				}else{
					if(this->equal==0){
						this->multiplexer();
						if(block==1){break;}
					}
					this->flagOperator=1;
					this->equal=0;
					this->operador=3;
					this->op2=0;
					screen->clear();
					if(this->op1==0){
						screen->addDigit(ZERO); break;
					}
					this->decompilerScreen(op1);
					break;
				}
			case EQUAL:
			this->flag=1;
				this->equal=1;
				this->multiplexer();
				if(block==1){break;}
				screen->clear();
				if(this->op1==0){	screen->addDigit(ZERO);	 break;	}
				this->decompilerScreen(op1);
		}
	}
}

void CalculatorAlessandro::decompilerScreen(int n){
	int aux;
	if(n==0){
		return;
	}
	if(n>0){
		aux=n;
		n=cpu->div(n, 10);
		aux=cpu->sub(aux, cpu->mult(n, 10));
		decompilerScreen(n);
		switch(aux){
			case 0:
				screen->addDigit(ZERO);
				break;
			case 1:
				screen->addDigit(ONE);
				break;
			case 2:
				screen->addDigit(TWO);
				break;
			case 3:
				screen->addDigit(THREE);
				break;
			case 4:
				screen->addDigit(FOUR);
				break;
			case 5:
				screen->addDigit(FIVE);
				break;
			case 6:
				screen->addDigit(SIX);
				break;
			case 7:
				screen->addDigit(SEVEN);
				break;
			case 8:
				screen->addDigit(EIGHT);
				break;
			case 9:
				screen->addDigit(NINE);
				break;
		}
		return;
	}
}
void CalculatorAlessandro::multiplexer(void){
	switch(this->operador){
		case 0:
			this->op1=this->cpu->sum(op1, op2);
			break;
		case 1:
			this->op1=this->cpu->sub(op1, op2);
			break;
		case 2:
			this->op1=this->cpu->mult(op1, op2);
			break;
		case 3:
			if(this->op2==0){
				this->block=1;
				screen->clear();
				decompilerScreen(999999999); break;
			}
			this->op1 = op1=cpu->div(op1, op2);
			break;
	}
}