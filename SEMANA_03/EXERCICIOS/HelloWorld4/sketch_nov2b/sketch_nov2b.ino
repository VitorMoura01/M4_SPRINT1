#define led_vermelho 33
#define led_amarelo 32
#define led_azul 18
#define led_verde 19
#define ldr 14
#define buzzer 27
#define button 5
#define button2 12

void setup() {
  Serial.begin(115200);
  pinMode(led_amarelo, OUTPUT);
  pinMode(led_vermelho, OUTPUT);
  pinMode(led_azul, OUTPUT);
  pinMode(led_verde, OUTPUT);
  pinMode(ldr, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(button, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
}
int static pos = 0;
int static tam = 0;
void loop() {
  
  int  vetor[1000];
  int  ldr_read = analogRead(ldr);
  int resultado = (ldr_read / 273);
  tone(buzzer, 0);
  
  if (digitalRead(button) == LOW) {
    tam += 1;
    if (resultado == 0) {
      tone(buzzer, 100);
      vetor[pos] = 1;
      pos += 1;
      Serial.println(resultado);
      Serial.println(vetor[(pos-1)]);
    }

    if (resultado == 1) {
      tone(buzzer, 200);
      digitalWrite(led_vermelho, HIGH);
      delay(150);
      digitalWrite(led_vermelho, LOW);
      vetor[pos] = 2;
      pos += 1;
      Serial.println(resultado);
      Serial.println(vetor[(pos-1)]);
    }
    if (resultado == 2) {
      tone(buzzer, 300);
      digitalWrite(led_verde, HIGH);
      delay(150);
      digitalWrite(led_verde, LOW);
      vetor[pos] = 3;
      pos += 1;
      Serial.println(resultado);
      Serial.println(vetor[(pos-1)]);
    }
    if (resultado == 3) {
      tone(buzzer, 400);
      digitalWrite(led_vermelho, HIGH);
      digitalWrite(led_verde, HIGH);
      delay(150);
      digitalWrite(led_verde, LOW);
      digitalWrite(led_vermelho, LOW);
      vetor[pos] = 4;
      pos += 1;
      Serial.println(resultado);
      Serial.println(vetor[(pos-1)]);
    }
    if (resultado == 4) {
      tone(buzzer, 500);
      digitalWrite(led_amarelo, HIGH);
      delay(150);
      digitalWrite(led_amarelo, LOW);
      vetor[pos] = 5;
      pos += 1;
      Serial.println(resultado);
      Serial.println(vetor[(pos-1)]);
    }
    if (resultado == 5) {
      tone(buzzer, 600);
      digitalWrite(led_amarelo, HIGH);
      digitalWrite(led_vermelho, HIGH);
      delay(150);
      digitalWrite(led_amarelo, LOW);
      digitalWrite(led_vermelho, LOW);
      vetor[pos] = 6;
      pos += 1;
      Serial.println(resultado);
      Serial.println(vetor[(pos-1)]);
    }
    if (resultado == 6) {
      tone(buzzer, 700);
      digitalWrite(led_amarelo, HIGH);
      digitalWrite(led_verde, HIGH);
      delay(150);
      digitalWrite(led_amarelo, LOW);
      digitalWrite(led_verde, LOW);
      vetor[pos] = 7;
      pos += 1;
      Serial.println(resultado);
      Serial.println(vetor[(pos-1)]);
    }
    if (resultado == 7) {
      tone(buzzer, 800);
      digitalWrite(led_amarelo, HIGH);
      digitalWrite(led_verde, HIGH);
      digitalWrite(led_vermelho, HIGH);
      delay(150);
      digitalWrite(led_amarelo, LOW);
      digitalWrite(led_verde, LOW);
      digitalWrite(led_vermelho, LOW);
      vetor[pos] = 8;
      pos += 1;
      Serial.println(resultado);
      Serial.println(vetor[(pos-1)]);
    }
    if (resultado == 8) {
      tone(buzzer, 900);
      digitalWrite(led_azul, HIGH);
      delay(150);
      digitalWrite(led_azul, LOW);
      vetor[pos] = 9;
      pos += 1;
      Serial.println(resultado);
      Serial.println(vetor[(pos-1)]);
    }
    if (resultado == 9) {
      tone(buzzer, 1000);
      digitalWrite(led_azul, HIGH);
      digitalWrite(led_vermelho, HIGH);
      delay(150);
      digitalWrite(led_azul, LOW);
      digitalWrite(led_vermelho, LOW);
      vetor[pos] = 10;
      pos += 1;
      Serial.println(resultado);
      Serial.println(vetor[(pos-1)]);
    }
    if (resultado == 10) {
      tone(buzzer, 1100);
      digitalWrite(led_azul, HIGH);
      digitalWrite(led_verde, HIGH);
      delay(150);
      digitalWrite(led_azul, LOW);
      digitalWrite(led_verde, LOW);
      vetor[pos] = 11;
      pos += 1;
      Serial.println(resultado);
      Serial.println(vetor[(pos-1)]);
    }
    if (resultado == 11) {
      tone(buzzer, 1200);
      digitalWrite(led_azul, HIGH);
      digitalWrite(led_verde, HIGH);
      digitalWrite(led_vermelho, HIGH);
      delay(150);
      digitalWrite(led_azul, LOW);
      digitalWrite(led_verde, LOW);
      digitalWrite(led_vermelho, LOW);
      vetor[pos] = 12;
      pos += 1;
      Serial.println(resultado);
      Serial.println(vetor[(pos-1)]);
    }
    if (resultado == 12) {
      tone(buzzer, 1300);
      digitalWrite(led_azul, HIGH);
      digitalWrite(led_amarelo, HIGH);
      delay(150);
      digitalWrite(led_azul, LOW);
      digitalWrite(led_amarelo, LOW);
      vetor[pos] = 13;
      pos += 1;
      Serial.println(resultado);
      Serial.println(vetor[(pos-1)]);
    }
    if (resultado == 13) {
      tone(buzzer, 1400);
      digitalWrite(led_azul, HIGH);
      digitalWrite(led_amarelo, HIGH);
      digitalWrite(led_vermelho, HIGH);
      delay(150);
      digitalWrite(led_azul, LOW);
      digitalWrite(led_amarelo, LOW);
      digitalWrite(led_vermelho, LOW);
      vetor[pos] = 14;
      pos += 1;
      Serial.println(resultado);
      Serial.println(vetor[(pos-1)]);
    }
    if (resultado == 14) {
      tone(buzzer, 1500);
      digitalWrite(led_azul, HIGH);
      digitalWrite(led_amarelo, HIGH);
      digitalWrite(led_verde, HIGH);
      delay(150);
      digitalWrite(led_azul, LOW);
      digitalWrite(led_amarelo, LOW);
      digitalWrite(led_verde, LOW);
      vetor[pos] = 15;
      pos += 1;
      Serial.println(resultado);
      Serial.println(vetor[(pos-1)]);
    }
    if (resultado == 15) {
      tone(buzzer, 1600);
      digitalWrite(led_azul, HIGH);
      digitalWrite(led_amarelo, HIGH);
      digitalWrite(led_verde, HIGH);
      digitalWrite(led_vermelho, HIGH);
      delay(150);
      digitalWrite(led_azul, LOW);
      digitalWrite(led_amarelo, LOW);
      digitalWrite(led_verde, LOW);
      digitalWrite(led_vermelho, LOW);
      vetor[pos] = 16;
      pos += 1;
      Serial.println(resultado);
      Serial.println(vetor[(pos-1)]);
    }
  }
  if (digitalRead(button2) == LOW) {
    for (int i = 0; i < tam; i = i + 1) {
     // Serial.println(vetor[i]);
     // vetor[i] = 0;

      if (vetor[i] == 1) {
        tone(buzzer, 100);
        Serial.println(vetor[i]);
        vetor[i] = 0;

      }
      if (vetor[i] == 2) {
        tone(buzzer, 200);
        digitalWrite(led_vermelho, HIGH);
        delay(150);
        digitalWrite(led_vermelho, LOW);
        Serial.println(vetor[i]);
        vetor[i] = 0;

      }
      if (vetor[i] == 3) {
        tone(buzzer, 300);
        digitalWrite(led_verde, HIGH);
        delay(150);
        digitalWrite(led_verde, LOW);
        Serial.println(vetor[i]);
        vetor[i] = 0;

      }
      if (vetor[i] == 4) {
        tone(buzzer, 400);
        digitalWrite(led_vermelho, HIGH);
        digitalWrite(led_verde, HIGH);
        delay(150);
        digitalWrite(led_verde, LOW);
        digitalWrite(led_vermelho, LOW);
        Serial.println(vetor[i]);
        vetor[i] = 0;

      }
      if (vetor[i] == 5) {
        tone(buzzer, 500);
        digitalWrite(led_amarelo, HIGH);
        delay(150);
        digitalWrite(led_amarelo, LOW);
        Serial.println(vetor[i]);
        vetor[i] = 0;
      }
      if (vetor[i] == 6) {
        tone(buzzer, 600);
        digitalWrite(led_amarelo, HIGH);
        digitalWrite(led_vermelho, HIGH);
        delay(150);
        digitalWrite(led_amarelo, LOW);
        digitalWrite(led_vermelho, LOW);
        Serial.println(vetor[i]);
        vetor[i] = 0;

      }
      if (vetor[i] == 7) {
        tone(buzzer, 700);
        digitalWrite(led_amarelo, HIGH);
        digitalWrite(led_verde, HIGH);
        delay(150);
        digitalWrite(led_amarelo, LOW);
        digitalWrite(led_verde, LOW);
        Serial.println(vetor[i]);
        vetor[i] = 0;

      }
      if (vetor[i] == 8) {
        tone(buzzer, 800);
        digitalWrite(led_amarelo, HIGH);
        digitalWrite(led_verde, HIGH);
        digitalWrite(led_vermelho, HIGH);
        delay(150);
        digitalWrite(led_amarelo, LOW);
        digitalWrite(led_verde, LOW);
        digitalWrite(led_vermelho, LOW);
        Serial.println(vetor[i]);
        vetor[i] = 0;

      }
      if (vetor[i] == 9) {
        tone(buzzer, 900);
        digitalWrite(led_azul, HIGH);
        delay(150);
        digitalWrite(led_azul, LOW);
        Serial.println(vetor[i]);
        vetor[i] = 0;

      }
      if (vetor[i] == 10) {
        tone(buzzer, 1000);
        digitalWrite(led_azul, HIGH);
        digitalWrite(led_vermelho, HIGH);
        delay(150);
        digitalWrite(led_azul, LOW);
        digitalWrite(led_vermelho, LOW);
        Serial.println(vetor[i]);
        vetor[i] = 0;

      }
      if (vetor[i] == 11) {
        tone(buzzer, 1100);
        digitalWrite(led_azul, HIGH);
        digitalWrite(led_verde, HIGH);
        delay(150);
        digitalWrite(led_azul, LOW);
        digitalWrite(led_verde, LOW);
        Serial.println(vetor[i]);
        vetor[i] = 0;

      }
      if (vetor[i] == 12) {
        tone(buzzer, 1200);
        digitalWrite(led_azul, HIGH);
        digitalWrite(led_verde, HIGH);
        digitalWrite(led_vermelho, HIGH);
        delay(150);
        digitalWrite(led_azul, LOW);
        digitalWrite(led_verde, LOW);
        digitalWrite(led_vermelho, LOW);
        Serial.println(vetor[i]);
        vetor[i] = 0;

      }
      if (vetor[i] == 13) {
        tone(buzzer, 1300);
        digitalWrite(led_azul, HIGH);
        digitalWrite(led_amarelo, HIGH);
        delay(150);
        digitalWrite(led_azul, LOW);
        digitalWrite(led_amarelo, LOW);
        Serial.println(vetor[i]);
        vetor[i] = 0;

      }
      if (vetor[i] == 14) {
        tone(buzzer, 1400);
        digitalWrite(led_azul, HIGH);
        digitalWrite(led_amarelo, HIGH);
        digitalWrite(led_vermelho, HIGH);
        delay(150);
        digitalWrite(led_azul, LOW);
        digitalWrite(led_amarelo, LOW);
        digitalWrite(led_vermelho, LOW);
        Serial.println(vetor[i]);
        vetor[i] = 0;

      }
      if (vetor[i] == 15) {
        tone(buzzer, 1500);
        digitalWrite(led_azul, HIGH);
        digitalWrite(led_amarelo, HIGH);
        digitalWrite(led_verde, HIGH);
        delay(150);
        digitalWrite(led_azul, LOW);
        digitalWrite(led_amarelo, LOW);
        digitalWrite(led_verde, LOW);
        Serial.println(vetor[i]);
        vetor[i] = 0;

      }
      if (vetor[i] == 16) {
        tone(buzzer, 1600);
        digitalWrite(led_azul, HIGH);
        digitalWrite(led_amarelo, HIGH);
        digitalWrite(led_verde, HIGH);
        digitalWrite(led_vermelho, HIGH);
        delay(150);
        digitalWrite(led_azul, LOW);
        digitalWrite(led_amarelo, LOW);
        digitalWrite(led_verde, LOW);
        digitalWrite(led_vermelho, LOW);
        Serial.println(vetor[i]);
        vetor[i] = 0;

      }

    }
  }
}