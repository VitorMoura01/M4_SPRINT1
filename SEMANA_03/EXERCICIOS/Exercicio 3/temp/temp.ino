#define red 11
#define green 10
#define blue 9

void setup(){
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
}

void loop(){
  setColor(255, 0, 0);
}