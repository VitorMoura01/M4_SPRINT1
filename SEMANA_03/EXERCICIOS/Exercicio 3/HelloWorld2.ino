// Programa : Pisque um LED
// Autor : FILIPEFLOP

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

// Notas que devem ser tocadas ordenadamente;
int melodia[] = {
  NOTE_C4,
  NOTE_F4,NOTE_E4,NOTE_F4,NOTE_G4,NOTE_A4,NOTE_G4,NOTE_A4,NOTE_AS4,
  NOTE_B4,NOTE_C5,NOTE_F4,NOTE_C4,
  NOTE_F4,NOTE_E4,NOTE_G4,NOTE_F4,NOTE_A4,NOTE_G4,NOTE_AS4,NOTE_A4,
  NOTE_FS4,NOTE_G4,NO_SOUND,NO_SOUND,NOTE_C4,
  NOTE_G4,NOTE_FS4,NOTE_G4,NOTE_A4,NOTE_AS4,NOTE_A4,NOTE_AS4,NOTE_B4,

  NOTE_CS5,NOTE_D5,NOTE_G4,NOTE_C4,
  NOTE_G4,NOTE_F4,NOTE_A4,NOTE_G4,NOTE_AS4,NOTE_A4,NOTE_B4,NOTE_AS4,
  NOTE_GS4,NOTE_A4,NO_SOUND,NOTE_A4,NOTE_A4,
  NOTE_AS4,NOTE_A4,NO_SOUND,NOTE_A4,NOTE_AS4,NOTE_A4,
  NOTE_A4,NOTE_D5,NOTE_C5,NOTE_AS4,
  NOTE_AS4,NOTE_A4,NOTE_A4,NOTE_G4,NOTE_G4,NOTE_F4,NOTE_F4,NOTE_E4,

  NOTE_E4,NOTE_D4,NO_SOUND,NOTE_G4,NOTE_G4,
  NOTE_A4,NOTE_G4,NO_SOUND,NOTE_G4,NOTE_A4,NOTE_G4,
  NOTE_G4,NOTE_C5,NOTE_B4,NOTE_A4,
  NOTE_A4,NOTE_G4,NOTE_G4,NOTE_F4,NOTE_F4,NOTE_E4,NOTE_E4,NOTE_D4,
  NOTE_D4,NOTE_C4,NO_SOUND,NOTE_C4,NOTE_E4,NOTE_G4,
  NOTE_AS4,NOTE_C4,NOTE_E4,NOTE_G4,NOTE_AS4,NOTE_C4,NOTE_E4,NOTE_G4,

  NOTE_AS4,NOTE_AS4,NOTE_C4,
  NOTE_F4,NOTE_E4,NOTE_F4,NOTE_G4,NOTE_A4,NOTE_G4,NOTE_A4,NOTE_AS4,
  NOTE_B4,NOTE_C5,NOTE_F4,NOTE_C4,
  NOTE_F4,NOTE_E4,NOTE_G4,NOTE_F4,NOTE_A4,NOTE_G4,NOTE_AS4,NOTE_A4,
  NOTE_FS4,NOTE_G4,NO_SOUND,NOTE_C4,
  NOTE_G4,NOTE_FS4,NOTE_G4,NOTE_A4,NOTE_AS4,NOTE_A4,NOTE_AS4,NOTE_B4,

  NOTE_CS5,NOTE_D5,NOTE_G4,NOTE_C4,
  NOTE_G4,NOTE_FS4,NOTE_A4,NOTE_G4,NOTE_AS4,NOTE_A4,NOTE_C5,NOTE_AS4,
  NOTE_GS4,NOTE_A4,NO_SOUND,NO_SOUND,NOTE_F4,
  NOTE_G4,NOTE_F4,NOTE_E4,NOTE_F4,NOTE_E4,NOTE_F4,NOTE_G4,NOTE_F4,
  NOTE_F4,NOTE_AS4,NOTE_AS4,NO_SOUND,NOTE_G4,
  NOTE_A4,NOTE_G4,NOTE_FS4,NOTE_G4,NOTE_FS4,NOTE_G4,NOTE_A4,NOTE_G4,//2ºFS4 
  
  NOTE_G4,NOTE_C5,NOTE_C5,NO_SOUND,NOTE_A4,
  NOTE_AS4,NOTE_A4,NOTE_GS4,NOTE_A4,NOTE_GS4,NOTE_A4,NOTE_AS4,NOTE_A4,//2ºGS4
  NOTE_A4,NOTE_D5,NOTE_C5,NOTE_AS4,NOTE_G4,
  NOTE_G4,NOTE_F4,NO_SOUND,NOTE_E4,NOTE_F4,NOTE_G4,
  NOTE_AS4,NOTE_A4,NOTE_E4,NOTE_F4,NOTE_CS4,NOTE_D4,NOTE_AS4,NOTE_G4,
  NOTE_G4,NOTE_F4,NO_SOUND,NOTE_G4,NOTE_A4,NOTE_AS4,
  
  NOTE_B4,NOTE_C5,NOTE_A4,NOTE_F4,NOTE_D4,NOTE_AS4,
  NOTE_A4,NOTE_F4,NOTE_D4,NOTE_C4,NOTE_D4,NOTE_E4,
  NOTE_F4
  
  
  
  
};

// Duração das Notas: Colcheia:8; Semínima: 4; Mínima:2; Semibreve:1
int tempoNotas[] = {
  4,
  6,16,6,16,6,16,6,16,
  3,8,4,4,
  6,16,6,16,6,16,6,16,
  4,4,4,16,8,
  6,16,6,16,6,16,6,16,

  3,8,4,4,
  6,16,6,16,6,16,6,16,
  4,4,4,6,16,
  4,4,8,8,6,16,
  4,2,8,8,
  8,8,8,8,8,8,8,8,

  4,4,4,6,16,
  4,4,8,8,6,16,
  4,2,8,8,
  8,8,8,8,8,8,8,8,
  4,4,8,8,8,8,
  8,8,8,8,8,8,8,8,

  2,4,4,
  6,16,6,16,6,16,6,16,
  3,8,4,4,
  6,16,6,16,6,16,6,16,
  4,4,4,4,
  6,16,6,16,6,16,6,16,

  3,8,4,4,
  6,16,6,16,6,16,6,16,
  4,4,4,8,16,
  6,16,6,16,6,16,6,16,
  3,8,4,8,8,
  6,16,6,16,6,16,6,16,
  
  3,8,4,8,8,
  6,16,6,16,6,16,6,16,
  4,3,8,8,8,
  4,4,8,8,8,8,
  8,8,8,8,8,8,8,8,
  4,4,8,8,8,8,
  
  8,8,8,8,4,4,
  4,6,16,4,6,16,
  2
};

const int compasso = 1500; // Altera o compasso da música 

int valorldr = 0;//Declara a variável valorldr como inteiro
int binario[3];

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

  valorldr=analogRead(ldr);//Lê o valor do sensor ldr e armazena na variável valorldr
  Serial.print("Valor lido pelo LDR = ");//Imprime na serial a mensagem Valor lido pelo LDR
  Serial.println(valorldr);//Imprime na serial os dados de valorldr
  
  int resultado = (valorldr/273);
  Serial.print("res: ");
  Serial.println(resultado);


  for(int i=3; i>-1; i--){  
    if(resultado - pow(2, i) >= 0){
      binario[i] = 1;
      resultado -= pow(2,i);
    }else{
      binario[i] = 0;    
    }
    Serial.print("binario:");
    Serial.println(binario[i]);
  }
  
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
  
  
  
  if(digitalRead(button1) == LOW){ // Se o botão for pressionado
    hino();
    //musica();
  }
  

  delay(100);
}
int armazenadas[230];

void hino()
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

void musica()
{
  for (int indice = 0; indice < 230; indice++){
    tone(buzzer, armazenadas[indice]);
  }
}
