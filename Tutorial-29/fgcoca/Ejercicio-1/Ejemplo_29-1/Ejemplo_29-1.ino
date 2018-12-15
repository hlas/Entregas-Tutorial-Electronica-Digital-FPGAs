const int LED = 13;  //-- LED de Arduino
const int CLK = 12;  //-- Pin de reloj
const int DAT = 11;  //-- Pin de Datos
const int CTRL = 10; //-- Pin de control

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(CLK, OUTPUT);
  pinMode(DAT, OUTPUT);
  pinMode(CTRL, OUTPUT);
  digitalWrite(CTRL, LOW);
  digitalWrite(LED, LOW);
}

void fpga_write(int value); //definimos fpga_write

void loop() {
   fpga_write(0x0F);
   delay(500);
   fpga_write(0x1A);
   delay(500);
}
// Implementamos fpga_write
void fpga_write(int value) {
 shiftOut(DAT, CLK, MSBFIRST, value);
 digitalWrite(CTRL, HIGH);
 digitalWrite(CTRL, LOW);
}
