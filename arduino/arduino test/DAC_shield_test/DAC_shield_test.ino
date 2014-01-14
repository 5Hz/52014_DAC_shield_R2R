
/*
descripcion del codigo
*/

//-----------------------------------------------------------definiciones


//--------------------------------------------------definiciones de pines
const int dato = 8;
const int clock = 4;
const int latch = 7;
const int DACinput = A0;

//-------------------------------------definiciones de variables globales


//------------------------------------------------prototipos de funciones


//----------------------------------------------------------configuracion
void setup()
{
  pinMode(dato, OUTPUT);
  pinMode(clock, OUTPUT);
  pinMode(latch, OUTPUT);
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
    Serial.print("  Dato del ADC:  "); Serial.println(analogRead(DACinput) >> 2);
    delay(100);
  }
}
//##################################################fin del ciclo principal


//-----------------------------------------------------------------funciones

