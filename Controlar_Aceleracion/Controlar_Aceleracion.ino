const int sensorPin = 9;
const int puentePin = 8;
int contador = 0;
unsigned long tiempo = 0;
unsigned long  tiempo_anterior = 0;
int ciclos = 0;
int valor_anterior = 0;
int value = 0;
unsigned long TiempoInicioTrabajo = 0;
boolean arranco = false;

void setup()
{
  Serial.begin(9600);
  pinMode(sensorPin, INPUT); 
}

void loop ()
{
  TiempoInicioTrabajo = millis();

  value = digitalRead(sensorPin);

  if(value != valor_anterior)
  {
    contador ++;
    valor_anterior = value;
  }
  
  //uno de estos por cada punto de medicion 
  if(contador > 0 && !arranco)
    PrintTiempo(millis(), "Arranco el motor");
    
  //puntos intermedios  
  if(contador > 50 && contador < 100)  
    PrintTiempo(millis(), "Entre 50 y 100 cambios por segundo");

  //puntos intermedios    
  if(contador > 250 && contador < 300)  
    PrintTiempo(millis(), "Entre 50 y 100 cambios por segundo");

//ponemos un poco menos que la velocidad maxima, vamos a usar 8v y llega a prox 800 cambuios por segundo 70% aprox 600
  if(contador > 600) 
    PrintTiempo(millis(), "Velocidad maxima");    
        
  ReestablecerContador();
   
  delay(1); 
}


 void PrintTiempo(long milisegundos, String mensaje)
 {
   unsigned long tiempoReal = milisegundos - TiempoInicioTrabajo;
   Serial.println(mensaje + " " + tiempoReal);
 }
 
 
 //par medir los cambios de estado cada 50 milisegundo, no mas tiempo poruqe llega muy rapido a la velocidad maxima
void ReestablecerContador()
{
  if(tiempo - tiempo_anterior >= 50)
  {
    tiempo_anterior = tiempo;
    contador = 0;
  }
}
