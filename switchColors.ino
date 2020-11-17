// by Voinoff
// for art-object

uint8_t firstPin = 3;   // Пин, который отправляет сигнал
uint8_t secondPin = 2;  // Пин, который принимает сигнал
uint8_t ledPin = 13;    // общий анод
uint8_t redPin = 9; // Красный пин
uint8_t bluePin = 10; // Синий пин
uint8_t greenPin = 11; // Зеленый пин
int activation = 0; // Прикосновения

void setup()
{
    pinMode(secondPin, OUTPUT);
    pinMode(firstPin, INPUT);
    pinMode(ledPin, OUTPUT);
    pinMode(redPin,OUTPUT);
    pinMode(bluePin, OUTPUT);
    pinMode(greenPin, OUTPUT);
    Serial.begin(9600);
}

int getDeltaTime()
{

    int time_start=0;
    int time_finish = 0;
    int time_delta = 0;

    time_start = micros(); // Количество микросекунд со старта программы
    digitalWrite(secondPin, HIGH); // Отправляем сигнал
    while(digitalRead(firstPin) == LOW); // ждем пока дойдет сигнал от одного пина к другому
    time_finish = micros(); // Еще раз смотрим сколько прошло микросекунд со старта программы
    time_delta = time_finish - time_start; // Высчитываем сколько микросекунд ушло на передачу сигнала между пинами
    digitalWrite(secondPin, LOW); // Останавливаем передачу сигнала

    //Serial.println(time_delta);
    return time_delta;
}

void loop(){

    int us = getDeltaTime();
    if(us > 100){ // Если нажатие происходит, то переключаем вариант
        activation++;
        delay (250);
        if(activation >=6){
            activation = 0;
        }
    }
    Serial.println(activation);
    switch(activation){
        case 0:
            digitalWrite(redPin, LOW);
            digitalWrite(bluePin, LOW);
            digitalWrite(greenPin, LOW);
            break;
        case 1:
            digitalWrite(redPin, HIGH);
            digitalWrite(bluePin, LOW);
            digitalWrite(greenPin, LOW);
            break;
        case 2:
            digitalWrite(bluePin, HIGH);
            digitalWrite(redPin, LOW);
            digitalWrite(greenPin, LOW);
            break;
        case 3:
            digitalWrite(greenPin, HIGH);
            digitalWrite(redPin, LOW);
            digitalWrite(bluePin, LOW);
            break;
        case 4:
            digitalWrite(greenPin, HIGH);
            digitalWrite(redPin, HIGH);
            digitalWrite(bluePin, LOW);
            break;
        case 5:
            digitalWrite(redPin, HIGH);
            digitalWrite(bluePin, HIGH);
            digitalWrite(greenPin, LOW);
            break;
    }
}
