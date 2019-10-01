const int sensorPin = 9;
const int puentePin = 8;
int contador = 0;
unsigned long tiempo = 0;
unsigned long  tiempo_anterior = 0;
int ciclos = 0;
int valor_anterior = 0;
int value = 0;
boolean midio = false;

void setup()
{
  Serial.begin(9600);
  pinMode(sensorPin, INPUT); 
  pinMode(puentePin, OUTPUT);
}

void loop ()
{
  digitalWrite(puentePin, HIGH);
  value = digitalRead(sensorPin);

  if(value != valor_anterior)
  {
    contador ++;
    valor_anterior = value;
  }

  tiempo = millis();

  if(tiempo - tiempo_anterior >= 100 && !midio)
  {
    tiempo_anterior = tiempo;

    ciclos = contador; //24 rendijas una vuelta, 42 cambios 

    if(ciclos > 12)
    {
      Serial.println("tiempo hasta el 99");
      Serial.print(tiempo_anterior);
       midio = true;
    }
    
    contador = 0;
    
  }
  delay(1); 
}

