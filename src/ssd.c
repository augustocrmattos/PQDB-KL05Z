#include "ssd.h"
#include "so.h"
#include "io.h"

//vetor para armazenar a conversao do display
//ed0cgafb
static const char valor[] = {0xD7, 0x11, 0xCD, 0x5D, 0x1B, 0x5E, 0xDE, 0x15, 0xDF, 0x5F, 0x9F, 0xDA, 0xC6, 0xD9, 0xCE, 0x8E};
//armazena qual e o display disponivel
static char display;
//armazena o valor a ser enviado ao display
static char v0=0, v1=0, v2=0, v3=0;

void ssdDigit(char position, char value){
	if (position == 0){ v0 = value; }
	if (position == 1){ v1 = value; }
	if (position == 2){ v2 = value; }
	if (position == 3){ v3 = value; }
}

void ssdUpdate(void){
	//desliga todos os displays
	digitalWrite(DISP1_PIN,LOW);
	digitalWrite(DISP2_PIN,LOW);
	digitalWrite(DISP3_PIN,LOW);
	digitalWrite(DISP4_PIN,LOW);

	switch(display){ //liga apenas o display da vez
	case 0:
		soWrite(valor[v0]); digitalWrite(DISP1_PIN,HIGH); display = 1;
		break;
	case 1:
		soWrite(valor[v1]); digitalWrite(DISP2_PIN,HIGH); display = 2;
		break;
	case 2:
		soWrite(valor[v2]); digitalWrite(DISP3_PIN,HIGH); display = 3;
		break;
	case 3:
		soWrite(valor[v3]); digitalWrite(DISP4_PIN,HIGH); display = 0;
		break;
	default:
		display = 0;
		break;
	}
}

void ssdInit(void){
	soInit();
	//configurao dos pinos de controle
	pinMode(DISP1_PIN,OUTPUT);
	pinMode(DISP2_PIN,OUTPUT);
	pinMode(DISP3_PIN,OUTPUT);
	pinMode(DISP4_PIN,OUTPUT);
	v0 = 0;
	v1 = 1;
	v2 = 2;
	v3 = 3;
}
