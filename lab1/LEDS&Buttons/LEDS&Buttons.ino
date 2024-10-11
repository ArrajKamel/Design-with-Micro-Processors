
//b1..b4 buttons variables 
int b1, b2, b3, b4; 
//stat, u can consider it as an array[6] of contain binary values 
//where each element of the array represents a LED (we have six LED)
unsigned char stat = 0; 
//it the number of shifts in the shift operation 
int counter = 0; 
//determines whether we have to decrement of increment the counter variable 
bool mood = false; 
//to save the stat of buttons variables 
bool button_stat[4] ; 
bool blanking_stat = true;

void setup() {
  //configure digital pins as inputs
  pinMode(4 , INPUT_PULLUP);
  pinMode(5 , INPUT_PULLUP);
  pinMode(6 , INPUT_PULLUP);
  pinMode(7 , INPUT_PULLUP);
  
  //activate PORTA, as output,
  DDRA = 0b11111111;
}

void loop() {
  //read BTNs status
  b1 = digitalRead(4);
  b2 = digitalRead(5);
  b3 = digitalRead(6);
  b4 = digitalRead(7);


  if(b1 == 0){
    button_stat[0] = true; 
    button_stat[1] = false;
    button_stat[2] = false;
    button_stat[3] = false;
  }

  if(b2 == 0){
    button_stat[0] = false; 
    button_stat[1] = true;
    button_stat[2] = false;
    button_stat[3] = false;
  }

  if(b3 == 0){
    button_stat[0] = false; 
    button_stat[1] = false;
    button_stat[2] = true;
    button_stat[3] = false;
  }
  if(b4 == 0){
    button_stat[0] = false; 
    button_stat[1] = false;
    button_stat[2] = false;
    button_stat[3] = true;
  }

  //ping_pong
  if(button_stat[0]){
    if(counter == 5)
      mood = true;  
    if(counter == 0)
      mood = false;

    if(mood)
      counter--; 
    if(!mood)
      counter++; 

    stat = (1<<counter); 
    PORTA = stat; 
  }//shift_right
  else if(button_stat[1]){
    if(counter == 5)
      mood = true;  
    if(counter == 0)
      mood = false;

    if(mood)
      counter = 0; 
    if(!mood)
      counter++; 

    stat = (1<<counter); 
    PORTA = stat; 

  }
  else if(button_stat[2]){
    if(counter == 5)
      mood = true;  
    if(counter == 0)
      mood = false;

    if(mood)
      counter--;
    if(!mood)
      counter = 5; 

    stat = (1<<counter); 
    PORTA = stat; 

  }//blanking
  else {
    if(blanking_stat)
      PORTA = 0b111111; 
    else
      PORTA = 0b000000;
    blanking_stat = !blanking_stat; 
  }
  delay(300);

}

