
int trigPin = 4; // Ultrasonik Sensör Trig Pininin Bağlı Olduğu Yer
int echoPin = 3;  // Ultrasonik Sensör Echo Pininin Bağlı Olduğu Yer
int buzzer = 2; //  Buzzerin Bağlı Olduğu Pin

long zaman;
long mesafe;
long ilk;
int calmasuresi;
 
void setup(){
  
  pinMode(trigPin, OUTPUT); 
  pinMode(buzzer, OUTPUT); 
  pinMode(echoPin,INPUT); 
  Serial.begin(9600); // Seri Haberleşme Başlattık
  /* Kalibrasyon İçin İlk Ölçüm Yapıldı */
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);  
  zaman = pulseIn(echoPin, HIGH);
  ilk= (zaman /29.1)/2; // Ölçülen Süreyi Ses Hızından Yararlanarak Saniyeye Çevirdik
  ilk = ilk - 10; // Ufak çaplı sapmalar için 10cm lik bir pay oluşturduk

  calmasuresi = 3000; // Buzzerin kaç saniye çalacağını gösterir. 1 saniye = 1000 olacak şekilde ayarlanabilir.
}
void loop()
{
  /* Döngü Ölçümleri */
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);  
  zaman = pulseIn(echoPin, HIGH);
  mesafe= (zaman /29.1)/2;    
  Serial.print("Uzaklik ");  
  Serial.print(mesafe);
  Serial.println(" cm");  
    if (ilk > mesafe) {digitalWrite(buzzer, HIGH); delay(calmasuresi); digitalWrite(buzzer, LOW);} // Eğer kalibrasyonun hata toleransı aşılırsa zili çalma süresi boyunca çal

  delay(50);
}
