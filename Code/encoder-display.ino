//PRETO = 1
//BRANCO = 0 

/* Inclusão das bibliotecas necessárias para funcionamento do display */
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

/* Definicao das dimensões do display */
#define SCREEN_WIDTH 128 // Largura do display
#define SCREEN_HEIGHT 32 // Altura do display

/* Definicao de parametros do display */
#define SCREEN_ADDRESS 0x3C // Endereço do display (tente trocar por 0x3D se não funcionar)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

//SCL - A5 CLOCK SERIAL
//SDA - A4 DATA SERIAL

/* Definicao das variaveis do programa */
int sensor_raio_maior;
int sensor_raio_medio;
int sensor_raio_menor;
int angulo;

void setup() {

  Serial.begin(9600);

  /* Declaracao do tipo INPUT para os pinos dos sensores infra-vermelhos  */

  pinMode(4, INPUT); //entrada digital fornecida pelo sensor de raio maior
  pinMode(3, INPUT); //entrada digital fornecida pelo sensor de raio medio
  pinMode(2, INPUT); //entrada digital fornecida pelo sensor de raio menor

  /* Inicialização do display */

  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS))
  {
    Serial.println(F("Erro na inicialização!"));
    while(1);
  }
  display.clearDisplay();

}

void loop() {
  
  sensor_raio_maior = digitalRead(4);
  sensor_raio_medio = digitalRead(3);
  sensor_raio_menor = digitalRead(2);    

  /* PARA DEBUG:
  Serial.print(sensor_raio_maior);
  Serial.print(" > ");
  Serial.print(sensor_raio_medio);
  Serial.print(" > ");
  Serial.println(sensor_raio_menor); */

  if (sensor_raio_maior == 0 && sensor_raio_medio == 0 && sensor_raio_menor == 0){
    angulo = 0;
  }
  if (sensor_raio_maior == 1 && sensor_raio_medio == 1 && sensor_raio_menor == 1){
    angulo = 45;
  }
  if (sensor_raio_maior == 0 && sensor_raio_medio == 1 && sensor_raio_menor == 1){
    angulo = 90;
  }
  if (sensor_raio_maior == 1 && sensor_raio_medio == 0 && sensor_raio_menor == 1){
    angulo = 135;
  }
  if (sensor_raio_maior == 0 && sensor_raio_medio == 0 && sensor_raio_menor == 1){
    angulo = 180;
  }
  if (sensor_raio_maior == 1 && sensor_raio_medio == 1 && sensor_raio_menor == 0){
    angulo = 225;
  }
  if (sensor_raio_maior == 0 && sensor_raio_medio == 1 && sensor_raio_menor == 0){
    angulo = 270;
  }
  if (sensor_raio_maior == 1 && sensor_raio_medio == 0 && sensor_raio_menor == 0){
    angulo = 315;
  }

  /* Configurações de exibição do display:  */  

  display.setTextSize(1); // Fonte do texto
  display.setTextColor(WHITE); // Cor do texto
  display.setCursor(15,12); // Posiciona o cursor 
  display.println("Angulo: "); //Imprime a mensagem "Angulo"
  display.setTextSize(1); // Fonte do texto

  display.setCursor(60,12); // Posiciona o cursor
  display.print(angulo); // Imprime a mensagem com o valor da variavel angulo
  display.print(" graus"); // Imprime mensagem " graus"
  display.display(); //Atualiza o display

  delay(2000); // Pausa de 2 segundos
  
  display.clearDisplay(); // Limpa o display
  
}

