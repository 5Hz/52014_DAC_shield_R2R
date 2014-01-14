
/******************************************************************
** Código creado en Electrónica 5Hz                              **
** www.5hz-electronica.com                                       **
** Por:                                                          **
** Basado en el código de:                                       **
** Descripción del código:                                       **
**                                                               **
** Ejemplo para el Shield convertidor Digital-Analógico          **
** genera una señal analogica, es leida por el pin A0 y          **
** varia la intensidad de un led externo                         **
** conectado al pin 9 segun el valor leido.                      **
*******************************************************************
Conexiones:
UNO  <-> DAC shield
4     -  Clock
7     -  Latch
8     -  Dato
9     -  led
A0    -  DAC Output
GND   -  GND
5V    -  VCC
*/

//--------------------------------------------------definiciones de pines
int dato = 8;
int clock = 4;
int latch = 7;
int led = 9;
int DACinput = A0;

//----------------------------------------------------------configuracion
void setup()
{
  pinMode(dato, OUTPUT);
  pinMode(clock, OUTPUT);
  pinMode(latch, OUTPUT);
  pinMode(led, OUTPUT);
  pinMode(DACinput, INPUT);
  Serial.begin(9600);
}

//#########################################################ciclo principal
void loop()
{
  for(int x = 0; x <= 255; x = x+5)
  {
    digitalWrite(latch, LOW);
    shiftOut(dato, clock, MSBFIRST, x);
    digitalWrite(latch, HIGH);
    Serial.print("Salida DAC:  "); Serial.print(x);
    int dato_DAC = analogRead(DACinput) >> 2;
    analogWrite(led, dato_DAC);
    Serial.print("  Dato del ADC:  "); Serial.println(dato_DAC);
    delay(100);
  }
  for(int x = 255; x >= 0; x = x-5)
  {
    digitalWrite(latch, LOW);
    shiftOut(dato, clock, MSBFIRST, x);
    digitalWrite(latch, HIGH);
    Serial.print("Salida DAC:  "); Serial.print(x);
    int dato_DAC = analogRead(DACinput) >> 2;
    analogWrite(led, dato_DAC);
    Serial.print("  Dato del ADC:  "); Serial.println(dato_DAC);
    delay(100);
  }
}
//##################################################fin del ciclo principal
