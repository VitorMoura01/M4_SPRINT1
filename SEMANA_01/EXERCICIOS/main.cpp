#include <algorithm> // std::sort
#include <iostream>
#include <string>

using namespace std;

/*
1 -  Faça uma função que recebe uma certa medida e ajusta ela percentualmente
entre dois valores mínimo e máximo e retorna esse valor
*/

/*

float converteSensor(int medida, int min, int max){
    float intervalo = max - min;
    float alvo = medida - min;

    float resultado = alvo/intervalo;
  return resultado;
}

/*

// Descomente a função main abaixo para testar o exercício 1
int main(){
  cout << "Teste Ex 1" << endl;
        cout << converteSensor(100,100,400) << endl;
  //valor esperado: 0

        cout << converteSensor(400,100,400) << endl;
  //valor esperado: 1

        cout << converteSensor(250,100,400) << endl;
  //valor esperado: 0.5
}

*/

// ----------------------------------------------------------

/*
2 - Faça uma função que simule a leitura de um sensor lendo o valor do teclado
ao final a função retorna este valor
*/

/*

int leComando(){
    int valor;
    cin >> valor;
  return valor;
}



// Descomente a função main abaixo para testar o exercício 2
int main(){
  cout << "Digite o Comando (0 ou 1):";
        int cmd = leComando();
        cout << "Comando Recebido: " << cmd << endl;
}

*/

// ----------------------------------------------------------

/*
3 - Faça uma função que armazena uma medida inteira qualquer em um vetor
fornecido. Note que como C não possui vetores nativos da linguagem, lembre-se
que você precisa passar o valor máximo do vetor assim como a última posição
preenchida. Evite também que, por acidente, um valor seja escrito em uma área de
memória fora do vetor
*/

/*
static int indice = 0;

void insereVetor(int elemento, int valorMax, int lastPos, int Vetor[]){
  if(valorMax <= indice){
    cout << "Erro:" << valorMax << "indice:" << indice << endl;
  }
  else{
    Vetor[indice] = elemento;
    indice++;
    cout << "indice:" << indice << endl;
  }
}

// Descomente a função main abaixo para testar o exercício 3
int main(){
  int valorMax = 12;
  int lastPos = -1;
  int Numbers[valorMax];

  insereVetor(9, valorMax, lastPos, Numbers);
  lastPos = lastPos + 1;

  insereVetor(8, valorMax, lastPos, Numbers);
  lastPos = lastPos + 1;

  insereVetor(7, valorMax, lastPos, Numbers);
  lastPos = lastPos + 1;

  insereVetor(6, valorMax, lastPos, Numbers);
  lastPos = lastPos + 1;

  insereVetor(5, valorMax, lastPos, Numbers);
  lastPos = lastPos + 1;

  insereVetor(4, valorMax, lastPos, Numbers);
  lastPos = lastPos + 1;

  insereVetor(3, valorMax, lastPos, Numbers);
  lastPos = lastPos + 1;

  insereVetor(2, valorMax, lastPos, Numbers);
  lastPos = lastPos + 1;

  insereVetor(1, valorMax, lastPos, Numbers);
  lastPos = lastPos + 1;

  insereVetor(0, valorMax, lastPos, Numbers);
  lastPos = lastPos + 1;

  insereVetor(100, valorMax, lastPos, Numbers);
  // valor esperado: mensagem de erro "Erro: valorMax: 10, lastPos + 1 (indice):
10"

  cout << Numbers[0] << endl; // valor esperado: 9
  cout << Numbers[1] << endl; // valor esperado: 8
  cout << Numbers[2] << endl; // valor esperado: 7
  cout << Numbers[3] << endl; // valor esperado: 6
  cout << Numbers[4] << endl; // valor esperado: 5
  cout << Numbers[5] << endl; // valor esperado: 4
  cout << Numbers[6] << endl; // valor esperado: 3
  cout << Numbers[7] << endl; // valor esperado: 2
  cout << Numbers[8] << endl; // valor esperado: 1
  cout << Numbers[9] << endl; // valor esperado: 0
}

*/

// ----------------------------------------------------------

/*
4 - Faça duas funções que recebem um vetor com 4 posições que contém o valor da
distância de um pequeno robô até cada um dos seus 4 lados. A primeira função
deve retornar a direção de maior distância ("Direita", "Esquerda", "Frente",
"Tras") e a segunda função deve retornar esta maior distância.
*/

string dirMaiorDist(int Vetor[]) {

  int direita = Vetor[0];
  int esquerda = Vetor[1];
  int frente = Vetor[2];
  int tras = Vetor[3];

  sort(Vetor, Vetor + 4);
  int maior = Vetor[3];

  if (maior == direita) {
    return "Direita";
  } else if (maior == esquerda) {
    return "Esquerda";
  } else if (maior == frente) {
    return "Frente";
  } else {
    return "Tras";
  }
}

int maiorDist(int Vetor[]) {
  sort(Vetor, Vetor + 4);
  int maior = Vetor[3];
  return maior;
}

/*
// Descomente a função main abaixo para testar o exercício 3
int main(){

//Considere que os valores sempre serão distintos
//Considere valores de distância inteiros entre 0 e 100

// "Direita", "Esquerda", "Frente", "Tras"
int posicoes [4] = {0, 20, 100, 50};

cout << dirMaiorDist(posicoes) << endl;
//valor esperado: Frente

cout << maiorDist(posicoes) << endl;
//valor esperado: 100


// "Direita", "Esquerda", "Frente", "Tras"
int posicoes2 [4] = {95, 70, 80, 50};

cout << dirMaiorDist(posicoes2) << endl;
//valor esperado: Direita

cout << maiorDist(posicoes2) << endl;
//valor esperado: 95


// "Direita", "Esquerda", "Frente", "Tras"
int posicoes3 [4] = {10, 0, 50, 60};

cout << dirMaiorDist(posicoes3) << endl;
//valor esperado: Tras

cout << maiorDist(posicoes3) << endl;
//valor esperado: 60


// "Direita", "Esquerda", "Frente", "Tras"
int posicoes4 [4] = {54, 55, 30, 0};

cout << dirMaiorDist(posicoes4) << endl;
//valor esperado: Esquerda

cout << maiorDist(posicoes4) << endl;
//valor esperado: 55
}
*/

// ----------------------------------------------------------

// 5 - Faça uma função que pergunta ao usuário se ele deseja continuar o
// mapeamento e retorna verdadeiro ou falso

/*
int continuar() {
  int tecla = 0;
  cout << "Insira uma tecla:" << endl;
  cin >> tecla;
  if (tecla == 1) {
    return 1;
  } else {
    return 0;
  }
}

// Descomente a função main abaixo para testar o exercício 5

int main() {
  int parar = 0;

  while (parar == 0) {
    parar = continuar();
  }
  // A função deve perguntar: "Digite 1 para parar o mapeamento!"
  // Se o usuário digitar 1, deve sair do loop while declarado acima
  // Em caso contrário, continua no loop acima e pergunta novamente

  return 1;
}
*/
// ----------------------------------------------------------

/*
6 - Escreva uma função que vai "dirigindo" virtualmente um robô e através de 4
sensores em cada um dos 4 pontos do robo ("Direita", "Esquerda", "Frente",
"Tras"). A cada passo, ele verifica as distâncias aos objetos e vai mapeando o
terreno para uma movimentação futura. Ele vai armazenando estas distancias em um
vetor fornecido como parâmetro e retorna a ultima posicao preenchida do vetor.
Esta função deve ir lendo os 4 sensores até que um comando de pare seja enviado.
Para simular os sensores e os comandos de pare, use as funções já construídas
nos ítens anteriores e em um looping contínuo até que um pedido de parada seja
enviado pelo usuário. A função final deve utilizar as funções declaradas acima
para ler os sensores e o movimento do robô e no final percorrer o vetor e
mostrar o movimento a cada direção na maior distância a cada movimento.
*/

// Defina as funções aqui

// Descomente a função main abaixo para testar o exercício 4
int main() {
  int direita;
  int esquerda;
  int frente;
  int tras;

  cout << "Insira o valor da direita";
  cin >> direita;
  cout << "Insira o valor da esquerda";
  cin >> esquerda;
  cout << "Insira o valor da frente";
  cin >> frente;
  cout << "Insira o valor de tras";
  cin >> tras;
  return 0;

  int posicoes[4] = {direita, esquerda, frente, tras};

  cout << dirMaiorDist(posicoes) << endl;
}
