#include "serial.h"
#include "io.h"
#include "derivative.h"

void serialSend(char c) {
	while (!(UART0_S1_REG(UART0_BASE_PTR) & UART0_S1_TDRE_MASK));
	UART0_D_REG(UART0_BASE_PTR) = c;
}
char serialRead(void) {
	//Verificar se há algo disponível
	if ((UART0_S1_REG(UART0_BASE_PTR) & UART0_S1_RDRF_MASK)) {
		//Lê o registro da serial
		return UART0_D_REG(UART0_BASE_PTR) ;
	} else {
		//Código para "não há caracter disponível"
		return 0xff;
	}
}

void serialInit(void) {
	unsigned int sbr_val;
	//Configura os terminais D0 e D1
	PORTB_PCR1 = PORT_PCR_MUX(0x2);
	PORTB_PCR2 = PORT_PCR_MUX(0x2); 
	//Seleciona o clock da serial a partir do clock principal da CPU 
	SIM_SOPT2 |= SIM_SOPT2_UART0SRC(1);
	//habilita o clock para o periférico da UART
	SIM_SCGC4 |= SIM_SCGC4_UART0_MASK;
	// Desliga a UART antes de configurá-lo
	UART0_C2 &= ~(UART0_C2_TE_MASK | UART0_C2_RE_MASK);
	//A velocidade de transmissão é dada por: baudrate = sys_clock/(OSR * sbr)
	// Configurando OSR para 10x
	UART0_C4 = (10-1);//sempre 1 unidade a menos
	//escolhendo o valor de sbr para um baudrate de 115200
	//sbr_val = (sys_clock) / (baudrate * OSR));
	sbr_val = (unsigned int) (24000000 / (115200 * 10));
	//o valor de sbr tem que ser armazenado em dois registros diferentes
	//os 5 bits mais altos vão para o UART0_BDH
	UART0_BDH = ((sbr_val & 0x1F00) >> 8);
	//os 8 mais baixos vão para UART0_BDL
	UART0_BDL = sbr_val & 0x00FF;
	//Liga o transmissor e o receptor
	UART0_C2 |= (UART0_C2_TE_MASK | UART0_C2_RE_MASK);
}
