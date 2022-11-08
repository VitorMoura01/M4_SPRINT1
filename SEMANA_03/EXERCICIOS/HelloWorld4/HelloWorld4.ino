#include "pitches.h"
#define NO_SOUND 0

#define green 16
#define yellow 7
#define blue 5
#define white 18

#define button1 46
#define button2 10
#define buzzer 48
#define ldr 1

const int compasso = 1500; // Altera o compasso da música 

int valorldr = 0;//Declara a variável valorldr como inteiro
int binario[3];
int armazenaNota[100];
int trava = 0;
static int indice =0;

void setup()
{
  //Define a porta do led como saida
  pinMode(green, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(white, OUTPUT);

  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);

  pinMode(ldr, INPUT);//Define ldr (pino analógico A0) como saída
  Serial.begin(9600);//Inicialização da comunicação serial, com taxa de transferência em bits por segundo de 9600
}
  
void loop()
{
  int value = readLight();
  sound(value);
  convertBinary(value);
  
  if(binario[3] == 1){
    digitalWrite(green, 1);
  }else{digitalWrite(green, 0);}
  if(binario[2] == 1){
    digitalWrite(yellow, 1);
  }else{digitalWrite(yellow, 0);}
  if(binario[1] == 1){
    digitalWrite(blue, 1);
  }else{digitalWrite(blue, 0);}
  if(binario[0] == 1){
    digitalWrite(white, 1);
  }else{digitalWrite(white, 0);}
  

  delay(100);
}

void convertBinary(int resultado)
{
  for(int i=3; i>-1; i--){  
    if(resultado - pow(2, i) >= 0){
      binario[i] = 1;
      resultado -= pow(2,i);
    }else{
      binario[i] = 0;    
    }
    //Serial.print("binario:");
    //Serial.println(binario[i]);
  }
}

int readLight()
{
  valorldr=analogRead(ldr);//Lê o valor do sensor ldr e armazena na variável valorldr

  //Serial.print("Valor lido pelo LDR = ");//Imprime na serial a mensagem Valor lido pelo LDR
  //Serial.println(valorldr);//Imprime na serial os dados de valorldr

  int resultado = (valorldr/273);//Converte o valorldr para um intervalo de 15 valores.
  //Serial.print("res: ");
  //Serial.println(resultado);

  return resultado;
}

void sound(int valor){
  //Toca no buzzer as notas de acordo com o valor de 0 a 15 recebido pelo LDR
  int notes[15] = {NOTE_B0, NOTE_B1, NOTE_B2, NOTE_B3, NOTE_B4, NOTE_B5, NOTE_B6, NOTE_B7, NOTE_C1, NOTE_CS1, NOTE_C2 , NOTE_CS2, NOTE_C3 , NOTE_CS3, NOTE_C4};
  tone(buzzer, notes[valor]);

  //Armazena as notas que estão sendo tocadas no vetor
  if(digitalRead(button2) == LOW){
    armazenaNota[indice] = notes[valor];
    
    Serial.print(indice);
    Serial.print(": ");
    Serial.println(armazenaNota[indice]);
    indice++;
  }

  if(digitalRead(button1) == LOW){ // Se o botão for pressionado
    for(int i=0; i<100; i++){
      tone(buzzer, armazenaNota[i]);
      delay(100);
      Serial.print("tocando ");
      Serial.println(armazenaNota[i]);
    }
  }

  delay(100);
  noTone(buzzer);
}

/*
void anthem()
{
  int indice = 0;
  for (int Nota = 0; Nota < 230; Nota++) {//o número 80 indica quantas notas tem a nossa matriz.
    int tempo = compasso/tempoNotas[Nota]; //Tempo = compasso dividido pela indicação da matriz tempoNotas.
    tone(buzzer, melodia[Nota],tempo); //Toca a nota indicada pela matriz melodia durante o tempo.
    if(digitalRead(button2) == LOW){
      int notaArmazenada = melodia[Nota];
      Serial.println(notaArmazenada);
      armazenadas[indice] = notaArmazenada;
    }
    indice++;
    // Para distinguir as notas adicionamos um tempo entre elas (tempo da nota + 20%).
    delay(tempo*1.2);
  }
}

*/


