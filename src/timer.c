#include "derivative.h"
#include "timer.h"

void timerStart(unsigned int count_val){
	// desliga timer para mudar a configuração de tempo e resetar contador
	LPTMR0_CSR=0;
	// Configura o tempo de contagem, como o timer usa um clock de 1KHz, cada unidade equivale 1ms
	// Subtrai duas unidades, descontando o overflow e a reinicialização
	LPTMR0_CMR = count_val-2;
	//Liga o timer
	LPTMR0_CSR |= 1;
	return;
}
unsigned int timerRead(void){
	return LPTMR0_CNR;
}
void timerWait(void){
	//Aguarda final da contagem
	while (!(LPTMR0_CSR & LPTMR_CSR_TCF_MASK));
	//Desliga o contador
	LPTMR0_CSR &= ~LPTMR_CSR_TEN_MASK;
}
int timerFinished(void){
	//Verifica se terminou de contar
	if (LPTMR0_CSR & LPTMR_CSR_TCF_MASK){
		//Se terminou desliga o contador
		LPTMR0_CSR &= ~LPTMR_CSR_TEN_MASK;
		return 1;
	}else{
		return 0;
	}
}
//gera um atraso de (time) milissegundos
void timerDelay(unsigned int time){
	timerStart(time);
	while(!timerFinished());
}
void timerInit(void){
	//Liga sistema de clock do timer
    SIM_SCGC5 |= SIM_SCGC5_LPTMR_MASK;
    //Utiliza oscilador de 1kHz sem prescaller
    LPTMR0_PSR = LPTMR_PSR_PCS(1)|LPTMR_PSR_PBYP_MASK;
}
