// by Voinoff
// for art-object

uint8_t firstPinOne = 5;   // Пин, который отправляет сигнал
uint8_t secondPinOne = 4;  // Пин, который принимает сигнал
uint8_t redPinOne = 9; // Красный пин
uint8_t bluePinOne = 10; // Синий пин
uint8_t greenPinOne = 8; // Зеленый пин
uint8_t firstPinTwo = 3;   // Пин, который отправляет сигнал
uint8_t secondPinTwo = 2;  // Пин, который принимает сигнал
uint8_t redPinTwo = 9; // Красный пин
uint8_t bluePinTwo = 10; // Синий пин
uint8_t greenPinTwo = 8;
uint8_t firstPinThree = 7;   // Пин, который отправляет сигнал
uint8_t secondPinThree = 8;  // Пин, который принимает сигнал
uint8_t redPinThree = 9; // Красный пин
uint8_t bluePinThree = 10; // Синий пин
uint8_t greenPinThree = 8;  
int activationOne = 0;
int activationTwo = 0;
int activationThree = 0;
#define COMMON_ANODE

void setup()
{
  pinMode(secondPinOne, OUTPUT);
  pinMode(firstPinOne, INPUT);
  pinMode(redPinOne, OUTPUT);
  pinMode(bluePinOne, OUTPUT);
  pinMode(greenPinOne, OUTPUT);
  pinMode(secondPinTwo, OUTPUT);
  pinMode(firstPinTwo, INPUT);
  pinMode(redPinTwo, OUTPUT);
  pinMode(bluePinTwo, OUTPUT);
  pinMode(greenPinTwo, OUTPUT);
  pinMode(secondPinThree, OUTPUT);
  pinMode(firstPinThree, INPUT);
  pinMode(redPinThree, OUTPUT);
  pinMode(bluePinThree, OUTPUT);
  pinMode(greenPinThree, OUTPUT);
  Serial.begin(9600);
}

int getDeltaTime1()
{

  int time_start1 = 0;
  int time_finish1 = 0;
  int time_delta1 = 0;

  time_start1 = micros(); // Количество микросекунд со старта программы
  digitalWrite(secondPinOne, HIGH); // Отправляем сигнал
  while (digitalRead(firstPinOne) == LOW); // Джем пока дойдет сигнал от одного пина к другому
  time_finish1 = micros(); // Еще раз смотрим сколько прошло микросекунд со старта программы
  time_delta1 = time_finish1 - time_start1; // Высчитываем сколько микросекунд ушло на передачу сигнала между пинами
  digitalWrite(secondPinOne, LOW); // Останавливаем передачу сигнала

  Serial.println(time_delta1);
  return time_delta1;

  digitalWrite(9, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(8, HIGH);
}
int getDeltaTime2()
{

  int time_start2 = 0;
  int time_finish2 = 0;
  int time_delta2 = 0;

  time_start2 = micros(); // Количество микросекунд со старта программы
  digitalWrite(secondPinTwo, HIGH); // Отправляем сигнал
  while (digitalRead(firstPinTwo) == LOW); // Джем пока дойдет сигнал от одного пина к другому
  time_finish2 = micros(); // Еще раз смотрим сколько прошло микросекунд со старта программы
  time_delta2 = time_finish2 - time_start2; // Высчитываем сколько микросекунд ушло на передачу сигнала между пинами
  digitalWrite(secondPinTwo, LOW); // Останавливаем передачу сигнала

  // Serial.println(time_delta2);
  return time_delta2;

  digitalWrite(9, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(8, HIGH);
}

void loop() {
  int ms1 = getDeltaTime1();
  if (ms1 > 50) {
    activation++;
    delay (500);
    if (activation >= 8) {
      activation = 0;
    }
  }

  //Serial.println(activation);
  switch (activation) {

    case 1:
      digitalWrite(9, HIGH);
      digitalWrite(10, HIGH);
      digitalWrite(8, LOW);
      break;
    case 2:
      digitalWrite(9, HIGH);
      digitalWrite(10, LOW);
      digitalWrite(8, LOW);
      break;
    case 3:
      digitalWrite(9, HIGH);
      digitalWrite(10, LOW);
      digitalWrite(8, HIGH);
      break;
    case 4:
      digitalWrite(9, LOW);
      digitalWrite(10, LOW);
      digitalWrite(8, HIGH);
      break;
    case 5:
      digitalWrite(9, LOW);
      digitalWrite(10, HIGH);
      digitalWrite(8, HIGH);
      break;
    case 6:
      digitalWrite(9, LOW);
      digitalWrite(10, HIGH);
      digitalWrite(8, LOW);
      break;
    case 7:
      digitalWrite(9, LOW);
      digitalWrite(10, LOW);
      digitalWrite(8, LOW);
      break;
    case 0:
      digitalWrite(9, HIGH);
      digitalWrite(10, HIGH);
      digitalWrite(8, HIGH);
  }
  int ms2 = getDeltaTime2();
  if (ms2 > 50) {
    activation++;
    delay (500);
    if (activation >= 8) {
      activation = 0;
    }
  

  //Serial.println(activation);
  switch (activation) {

    case 1:
      digitalWrite(9, HIGH);
      digitalWrite(10, HIGH);
      digitalWrite(8, LOW);
      break;
    case 2:
      digitalWrite(9, HIGH);
      digitalWrite(10, LOW);
      digitalWrite(8, LOW);
      break;
    case 3:
      digitalWrite(9, HIGH);
      digitalWrite(10, LOW);
      digitalWrite(8, HIGH);
      break;
    case 4:
      digitalWrite(9, LOW);
      digitalWrite(10, LOW);
      digitalWrite(8, HIGH);
      break;
    case 5:
      digitalWrite(9, LOW);
      digitalWrite(10, HIGH);
      digitalWrite(8, HIGH);
      break;
    case 6:
      digitalWrite(9, LOW);
      digitalWrite(10, HIGH);
      digitalWrite(8, LOW);
      break;
    case 7:
      digitalWrite(9, LOW);
      digitalWrite(10, LOW);
      digitalWrite(8, LOW);
      break;
    case 0:
      digitalWrite(9, HIGH);
      digitalWrite(10, HIGH);
      digitalWrite(8, HIGH);
  }
}
}
