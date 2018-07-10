int sensorPin = 2;  // selecciona el pin de entrada para el sensor de audio
int sensorState;    // variable para guardar el valor del estado del sensor
int i = 0;          // contador de detección de sonido

void setup() {
  // inicializa la comunicación serie a 9600 bits por segundo
  Serial.begin(9600);
  pinMode(sensorPin, INPUT);
  pinMode(13, OUTPUT);
}

void loop() {
  // lee el valor de sensor
  sensorState = digitalRead(sensorPin);
  // en dependencia del threshold que ajustemos con el potenciometro del sensor,
  // devolverá HIGH o LOW, cuando el valor analógico es menor que el ajustado
  // devuelve LOW (sensa sonido al nivel ajustado) y en caso contrario devuelve
  // HIGH (no sensa sonido al nivel ajustado)
  if (sensorState == LOW) {
    Serial.println("Nivel detectado #" + String(i));
    digitalWrite(13, HIGH);
    delay(50);
    i++;
  }
  digitalWrite(13, LOW);
  delay(2);        // demora entre las lecturas para dar estabilidad  
}
