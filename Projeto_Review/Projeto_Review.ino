#include <Servo.h>

int ledSinalizacao = 9;
int ledLampada = 8;

int pinoVermelho = A3;
int pinoVerde = A2;
int pinoAzul = A1;

int botaoPortao = 6;
int botaoLampada = 7;

int estadoBotao = 0;
int estadoLampada = 0;
int estadoPortao = 0;

Servo portao;

void setup() 
{
  pinMode(ledSinalizacao, OUTPUT);
  pinMode(ledLampada, OUTPUT);

  pinMode(pinoVermelho, OUTPUT);
  pinMode(pinoVerde, OUTPUT);
  pinMode(pinoAzul, OUTPUT);
  
  pinMode(botaoPortao, INPUT);
  pinMode(botaoLampada, INPUT);  
  
  portao.attach(3);
  portao.write(30);
  
  Serial.begin(9600);
}

void loop() 
{
    int leituraBotaoLampada = digitalRead(botaoLampada);
    int leituraBotaoPortao = digitalRead(botaoPortao);
    
    if (leituraBotaoLampada == HIGH)
    {
        acendeApagaLampada();
        delay(500);
    }

    if (leituraBotaoPortao == HIGH)
    {
      abreFechaPortao();
      delay(500);
    }
}

// Funções //

void abreFechaPortao()
{
    if (estadoPortao == 0)
    {
        long tempo = millis();
        
        digitalWrite(ledLampada, HIGH);
        for (int pos = 30; pos <= 120; pos += 3) 
        { 
            portao.write(pos); 
            delay(100);
            digitalWrite(ledSinalizacao, HIGH);
            delay(100);
            digitalWrite(ledSinalizacao, LOW);
        }   
        estadoPortao = 1;
    }
    else 
    {
        for (int pos = 120; pos >= 30; pos -= 1) 
        {
            portao.write(pos);              
            delay(15);
            digitalWrite(ledSinalizacao, HIGH);
            delay(15);
            digitalWrite(ledSinalizacao, LOW);
        }
        estadoPortao = 0;
    }
}

void acendeApagaLampada()
{
    if (estadoLampada == 0)
    {
        digitalWrite(ledLampada, HIGH);
        estadoLampada = 1;
    }
    else
    {
        digitalWrite(ledLampada, LOW);
        estadoLampada = 0;
    }
}
// Alteração
