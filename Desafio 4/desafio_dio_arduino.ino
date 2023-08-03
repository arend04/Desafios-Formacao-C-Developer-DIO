const long A=2000;
const int B=35;
const int Rc=10;
const int PinLDR=A0;
const int Direita=7;
const int Esquerda=8;
const int velocidade=10; //Declaramos os nomes de cada pin
const int FCsubir=13;
const int FCbaixar=12;
bool subida = 0, baixada=0;
const int porta_rele1 = 4;
//Armazena o estado do rele - 0 (LOW) ou 1 (HIGH)
const int estadorele1 = 1;
//const int lampada;

void setup()
{
  Serial.begin(9600); //Configuramos puerta serial
  pinMode(porta_rele1, OUTPUT);
}

void loop()
{
  int lux=ler_iluminacao(); //Lê a iluminacao do ambiente
  Serial.println(lux);
  compara_iluminacao(lux); //Verifica se e suficiente para subir ou baixar a persiana			
}
int ler_iluminacao()
{
  int leitura=analogRead(PinLDR);
  int ilum=((long)leitura*A*10)/((long)B*Rc*(1024-leitura));;
  return ilum;
}
void compara_iluminacao(int valor)
{
  if(valor<=250&&baixada==0){
    girar_motor(0,1);
    digitalWrite(porta_rele1, HIGH);
  }else if(valor>=300&&subida==0) {
    girar_motor(1,0);
    digitalWrite(porta_rele1, LOW);
  }else analogWrite(velocidade,0);
    if(digitalRead(FCbaixar)==1)baixada=!baixada; //Comprova que o valor e suficiente para baixar a persiana y la baja
    if(digitalRead(FCsubir)==1) subida=!subida; //Comprova que o valor e suficiente para subir a persiana y la sube
}
void girar_motor(int direita, int esquerda)
{
  analogWrite(velocidade, 255);
  digitalWrite(Direita, direita); //faz girar o motor para direita
  digitalWrite(Esquerda, esquerda); //faz girar o motor para esqeurda
}
