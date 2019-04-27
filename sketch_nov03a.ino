// ***** MUHAMMED ALİ ÖZEN *****
 
char dataIn = 'S'; // Durma fonksiyonu için karakter
int pinileri = 2; //**
int pingeri = 3;  //**
int pinsol = 4;   //**ARACIN İLERİ ,GERİ, SAĞ ,SOL KOMUT ÇIKIŞ PİNLERİ**
int pinsag = 5;   //**
int pinonla = 6;//ön lamba 
int pinarkala = 7;//arka lamba 
int pinkorna = 8;//korna 
int pindortlu = 9;//DÖRTLÜ 
char determinant; //Program döngüsü için karakter
char det; //Program döngüsü için karakter
 
void setup()
{
Serial.begin(9600); //HC-06 bluetooth modülü için btu 9600
pinMode(pinileri, OUTPUT); // Çıkış pinlerini belirliyoruz.
pinMode(pingeri, OUTPUT);
pinMode(pinsol, OUTPUT);
pinMode(pinsag, OUTPUT);
pinMode(pinonla, OUTPUT);
pinMode(pinarkala, OUTPUT);
pinMode(pindortlu, OUTPUT);
pinMode(pinkorna, OUTPUT);
}
 
void loop()
{
det = check(); // determinantı kontrol et
while (det == 'F') //İLERİ
{
digitalWrite(pinileri, HIGH);
digitalWrite(pinsol, HIGH);
det = check();
}
while (det == 'B') //GERİ
{
digitalWrite(pingeri, HIGH);
digitalWrite(pinsag, HIGH);
det = check();
}
 
while (det == 'L') //SOL
{
digitalWrite(pinileri, HIGH);
digitalWrite(pinsag, HIGH);
det = check();
}
while (det == 'R') //SAĞ
{
digitalWrite(pingeri, HIGH);
digitalWrite(pinsol, HIGH);
det = check();
}
while (det == 'G') //İLERİ SOL
{
digitalWrite(pinileri, HIGH);
digitalWrite(pinsol, HIGH);
det = check();
}
while (det == 'I') //İLERİ SAĞ
{
digitalWrite(pinileri, HIGH);
digitalWrite(pinsag, HIGH);
det = check();
}
while (det == 'H') //GERİ SOL
{
digitalWrite(pingeri, HIGH);
digitalWrite(pinsol, HIGH);
det = check();
}
while (det == 'J') //GERİ SAĞ
{
digitalWrite(pingeri, HIGH);
digitalWrite(pinsag, HIGH);
det = check();
}
while (det == 'W')// ÖN LAMBA YAKMA 
{
digitalWrite(pinonla, HIGH);
det = check();
}
while (det == 'w') // ÖN LAMBA  SÖNDÜRME  
{
digitalWrite(pinonla, LOW);
det = check();
}
while (det == 'U') //ARKA IŞIK YAKMA 
{
digitalWrite(pinarkala, HIGH);
det = check();
}
while (det == 'u') //ARKA LAMBA SÖNDÜRME  
{
digitalWrite(pinarkala,LOW);
det = check();
}
while (det == 'V')// KORNA  ÇALMA   
{
digitalWrite(pinkorna, HIGH);
delay(100);
digitalWrite(pinkorna, LOW);
delay(100);
det = check();
}
while (det == 'v')//KORNA  SUSTURMA   
{
digitalWrite(pinkorna, LOW);
det = check();
}
while (det == 'X')// DÖRTLÜ YAKMA  
{
digitalWrite(pindortlu, HIGH);
delay(250);
digitalWrite(pindortlu, LOW);
delay(250);
det = check();
}
while (det == 'x')//DÖRTLÜ SÖNDÜRME   
{
digitalWrite(pindortlu, LOW);
det = check();
}
while (det == 'S') //Telefondaki programda atanmış olan durma fonksiyonun harf eşdeğeri
{
digitalWrite(pinileri, LOW);
digitalWrite(pingeri, LOW);
digitalWrite(pinsol, LOW);
digitalWrite(pinsag, LOW);
digitalWrite(pinkorna, LOW);
det = check();
}
 
}
 
int check()
{
if (Serial.available() > 0) //Serial portun kontrollü
{
dataIn = Serial.read(); //Telefondan gelen verilerin kontrollü
if (dataIn == 'F')
{
determinant = 'F';
}
else if (dataIn == 'B')
{
determinant = 'B';
}
else if (dataIn == 'L')
{
determinant = 'L';
}
else if (dataIn == 'R')
{
determinant = 'R';
}
else if (dataIn == 'G')
{
determinant = 'G';
}
else if (dataIn == 'I')
{
determinant = 'I';
}
else if (dataIn == 'H')
{
determinant = 'H';
}
else if (dataIn == 'J')
{
determinant = 'J';
}
else if (dataIn == 'W')
{
determinant = 'W';
}
else if (dataIn == 'w')
{
determinant = 'w';
}
else if (dataIn == 'U')
{
determinant = 'U';
}
else if (dataIn == 'u')
{
determinant = 'u';
}
else if (dataIn == 'V')
{
determinant = 'V';
}
else if (dataIn == 'v')
{
determinant = 'v';
}
else if (dataIn == 'X')
{
determinant = 'X';
}
else if (dataIn == 'x')
{
determinant = 'x';
}
else if (dataIn == 'S')
{
determinant = 'S';
}
 
}
return determinant;
}
