#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

//SCL - A5
//SDA - A4

#define SCREEN_WIDTH 128 // Largura do display
#define SCREEN_HEIGHT 32 // Altura do display

#define SCREEN_ADDRESS 0x3C // Endereço do display (tente trocar por 0x3D se não funcionar)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);


void setup()
{
  Serial.begin(9600);

  // Inicializa o display
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS))
  {
    Serial.println(F("Erro na inicialização!"));
    while(1);
  }
   pinMode(A3,INPUT);
  display.clearDisplay();

 
}

void loop()
{ 
  int pot = analogRead(A3);
  display.setTextSize(1); // Fonte do texto
  display.setTextColor(WHITE); // Cor do texto
  display.setCursor(15,12); // Posiciona o cursor
  display.println("Angulo: ");
  display.setTextSize(1); // Fonte do texto
  display.setTextColor(WHITE); // Cor do texto
  display.setCursor(60,12); // Posiciona o cursor
  display.print(pot); // Imprime mensagem
  display.print(" graus"); // Imprime mensagem
  display.display();
  delay(2000); // Pausa de 2 segundos
  display.clearDisplay(); // Limpa o display

}