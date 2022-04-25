#ifndef CALCULATOR_BASE_HPP
#define CALCULATOR_BASE_HPP

/* Este enumerador é responsável por agrupar todos os possíveis dígitos */
enum Digit { ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE };

/* Esta classe abstrai o comportamento de um objeto que é capaz de receber um dígito.
Qualquer subclasse desta classe poderá conectar-se a um teclado numérico */
class DigitReceiver {
public:
  virtual void receiveDigit(Digit) = 0;
};

/* O teclado numérico é responsável por manter o contato com o mundo externo da calculadora.
Ele possui 10 teclas numéricas que podem ser "pressionadas". 
Ele transforma um pressionamento externo em um dígito interno e envia o dígito para um DigitReceiver */
class DigitKeyboard {
public:
  virtual DigitReceiver* getDigitReceiver(void) = 0;
  virtual void press0(void) = 0;
  virtual void press1(void) = 0;
  virtual void press2(void) = 0;
  virtual void press3(void) = 0;
  virtual void press4(void) = 0;
  virtual void press5(void) = 0;
  virtual void press6(void) = 0;
  virtual void press7(void) = 0;
  virtual void press8(void) = 0;
  virtual void press9(void) = 0;
};

/* Este enumerador é responsável por agrupar todas as possíveis operações */
enum Operation { SUM, SUB, MULT, DIV, EQUAL };

/* Esta classe abstrai o comportamento de um objeto que é capaz de receber uma operação.
Qualquer subclasse desta classe poderá conectar-se a um teclado de operação */
class OperationReceiver {
public:
  virtual void receive(Operation) = 0;
};

/* O teclado de operações é responsável por manter o contato com o mundo externo da calculadora.
Ele possui 5 teclas que representam as operações.
Ele transforma um pressionamento externo em uma operação interno
e envia o dígito para um OperationReceiver */
class OperationKeyboard {
public:
  virtual OperationReceiver* getOperationReceiver(void) = 0;
  virtual void pressSum(void) = 0;
  virtual void pressSub(void) = 0;
  virtual void pressMult(void) = 0;
  virtual void pressDiv(void) = 0;
  virtual void pressEqual(void) = 0;
};

class CalculatorReceiver: public DigitReceiver,
                          public OperationReceiver{
	public:
  virtual void receiveClear() = 0;
};

/* Esta classe se compõe pra formar um teclado de uma calculadora.
Ela herda os comportamentos de um teclado numérico e de um teclado de operação e adiciona mais um comportamento de um tecla Clear, que na calculadora limpa tudo */
class CalculatorKeyboard : public DigitKeyboard,
                           public OperationKeyboard {
public:
virtual void setCalculatorReceiver(CalculatorReceiver*)=0;
  virtual CalculatorReceiver* getCalculatorReceiver(void) = 0;
  virtual void pressClear() = 0;
};

/* Esta classe abstrai o comportamento de uma tecla simples de calculadora que possui dois comportamentos básicos: limpar e adicionar um dígito após o outro */
class Screen {
public:
  virtual void clear(void) = 0;
  virtual void addDigit(Digit) = 0;
};

/* Esta classe abstrai o comportamento de uma CPU simples capaz que realizar as quatro operações com números inteiros. Ela só faz isto: recebe dois inteiros e devolve um terceiro inteiro */
class Cpu {
public:
  virtual int sum(int, int) = 0;
  virtual int sub(int, int) = 0;
  virtual int div(int, int) = 0;
  virtual int mult(int, int) = 0;
};

/* Esta classe abstrai uma calculadora que recebe dígitos, operações e clear e os transforma em resultados na tela.  */
class Calculator: public CalculatorReceiver {
public:
	virtual void setScreen(Screen*)=0;
	virtual void setCpu(Cpu*)=0;
  virtual Cpu * getCpu() = 0;
  virtual Screen * getScreen() = 0;
  //virtual void decompilerScreen(int, Screen*, Cpu*)=0;
};

#endif
