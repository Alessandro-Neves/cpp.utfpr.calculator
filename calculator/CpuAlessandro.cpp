#include "Calculator.hpp"
#include "CpuAlessandro.hpp"


int cpuAlessandro::sum(int a, int b){
		a = a + b;
		return a;
}
int cpuAlessandro::sub(int a, int b){
		
		a = a - b;
		return a;
}
int cpuAlessandro::div(int a, int b){
		int aux=0;
		while(a>=b){
			//a=a-b;
			a=this->sub(a, b);
			aux++;
		}
		return aux;
		
}
int cpuAlessandro::mult(int a, int b){
		int aux=0;
		
		while(b>0){
			aux=this->sum(aux, a);
			b--;
		}
		return aux;

}
