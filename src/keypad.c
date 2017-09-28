#include "keypad.h"
#include "so.h"
#include "io.h"

static unsigned int keys;

//vetor com o "nome" dos botões
//U -> up, L -> left, D -> down, R -> right
//S -> start, s -> select
//a ordem é referente a posição dos botões
static const char charKey[] = {'U','L','D','R','S','s','Y','B','A','X'};

unsigned int kpRead(void) {
    return keys;
}
char kpReadKey(void){
	int i;
	for(i=0;i<10;i++){
		if (bitTst(keys,0)){
			return charKey[i];
		}
	}
	//nenhuma tecla pressionada
	return 0;
}
void kpDebounce(void) {
    int i;
    static unsigned char tempo;
    static unsigned int newRead;
    static unsigned int oldRead;
    newRead = 0;
    for(i = 0; i<5; i++){
      soWrite(1<<(i+3));
      if(digitalRead(13)){
        bitSet(newRead,i);
      }
      if(digitalRead(12)){
        bitSet(newRead,(i+5));
      }
    }
    if (oldRead == newRead) {
        tempo--;
    } else {
        tempo = 4;
        oldRead = newRead;
    }
    if (tempo == 0) {
        keys = oldRead;
    }
}
void kpInit(void) {
  soInit();
  pinMode(12, INPUT);
  pinMode(13, INPUT);
}
