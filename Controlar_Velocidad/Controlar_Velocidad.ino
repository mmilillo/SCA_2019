const int sensorPin = 9;
const int puentePin = 8;
int contador = 0;
unsigned long tiempo = 0;
unsigned long  tiempo_anterior = 0;
int ciclos = 0;
int valor_anterior = 0;
int value = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(sensorPin, INPUT); 
}

void loop ()
{
  value = digitalRead(sensorPin);

  if(value != valor_anterior)
  {
    contador ++;
    valor_anterior = value;
  }

  tiempo = millis();

  if(tiempo - tiempo_anterior >= 250)
  {
    tiempo_anterior = tiempo;

    ciclos = contador; //24 rendijas una vuelta, 42 cambios 
    Serial.println(ciclos);


    if(ciclos > 5)
    {
      Serial.println("apagate");
      digitalWrite(puentePin, LOW);
       
    }
    else
    {
      Serial.println("prendete");
      digitalWrite(puentePin, HIGH);
    }
    
    contador = 0;
    
  }
  delay(1); 
}

