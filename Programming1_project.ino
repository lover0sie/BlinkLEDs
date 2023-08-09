/*defining each the pin of the first decoder and assigning them to a pin number on Arduino*/ 
const int A = 2;
const int B = 3;
const int C = 4;
const int D = 5;

/*defining each pin of the second decoder and assigning them to a pin number on Arduino*/
const int F = 6;
const int G = 7;
const int H = 8;
const int I = 9;

/*defining each pin of Arduino to the each respective components*/
const int LED1 = 11;
const int LED2 = 12;
const int LDR1 = A0;
const int LDR2 = A1; 

/*define the variables and initialize them with specific values*/
int count1 = 0;
int count2 = 0;
int sensor1Value = 0;
int sensor2Value = 0;
unsigned long randInterval;
unsigned long minute = 60000;
unsigned long timerun;

void display_num0_1();
void display_num0_2();

void display_num0_1()
{
  digitalWrite (A, LOW);
  digitalWrite (B, LOW);
  digitalWrite (C, LOW);
  digitalWrite (D, LOW);
}

void display_num0_2()
{
  digitalWrite (F, LOW);
  digitalWrite (G, LOW);
  digitalWrite (H, LOW);
  digitalWrite (I, LOW);
}

void setup() 
{
  
  Serial.begin(9600);
  
  pinMode (LED1 , OUTPUT);

  pinMode (LED2, OUTPUT);

  for (int i = 2 ; i < 6 ; i++)
  {
    pinMode (i, OUTPUT);
  }

  for (int j = 6; j < 10; j++)
  {
    pinMode (j, OUTPUT);
  }

  randomSeed(analogRead(0));
  
}


void loop() 
{
  timerun = 0;

  count1  = 0;

  count2  = 0;

  Serial.print("\nThe time elapsed since the program run OUTSIDE THE LOOP:");
  Serial.println(timerun);
  
  while (timerun < (minute * 1))
  {
      Serial.print("\nThe time elapsed since the program run INSIDE THE FIRST LOOP:");
      Serial.println(timerun);

      randInterval = random(1000,10000); //randomizing the time of interval of each blinking for LEDs

      Serial.print("\nThe random interval:");
      Serial.println(randInterval);
      
     /*numbers displayed on 7 segment display */
       switch (count1)
       {
           case 0:
          digitalWrite (A,LOW);
          digitalWrite (B, LOW);
          digitalWrite (C, LOW);
          digitalWrite (D, LOW);
           break;
         
           case 1:
           digitalWrite (A, HIGH);
           digitalWrite (B, LOW);
           digitalWrite (C, LOW);
           digitalWrite (D, LOW);
           break;
    
           case 2:
           digitalWrite (A, LOW);
           digitalWrite (B, HIGH);
           digitalWrite (C, LOW);
           digitalWrite (D, LOW);
           break;
    
           case 3:
           digitalWrite (A, HIGH);
           digitalWrite (B, HIGH);
           digitalWrite (C, LOW);
           digitalWrite (D, LOW);
           break;
    
           case 4:
           digitalWrite (A, LOW);
           digitalWrite (B, LOW);
           digitalWrite (C, HIGH);
           digitalWrite (D, LOW);
           break;
    
           case 5:
           digitalWrite (A, HIGH);
           digitalWrite (B, LOW);
           digitalWrite (C, HIGH);
           digitalWrite (D, LOW);
           break;
    
           case 6:
           digitalWrite (A, LOW);
           digitalWrite (B, HIGH);
           digitalWrite (C, HIGH);
           digitalWrite (D, LOW);
           break;
    
           case 7:
           digitalWrite (A, HIGH);
           digitalWrite (B, HIGH);
           digitalWrite (C, HIGH);
           digitalWrite (D, LOW);
           break;
    
           case 8:
           digitalWrite (A, LOW);
           digitalWrite (B, LOW);
           digitalWrite (C, LOW);
           digitalWrite (D, HIGH);
           break;
    
           case 9:
           digitalWrite (A, HIGH);
           digitalWrite (B, LOW);
           digitalWrite (C, LOW);
           digitalWrite (D, HIGH);
           break;
           
        }

        delay(randInterval);
        digitalWrite (LED1, HIGH);
        delay(randInterval);
        
        /*reading value from LDR1*/
        sensor1Value = analogRead (LDR1);
        Serial.print("\nThe value of read from the LDR1:");
        Serial.println(sensor1Value);
   
      if (sensor1Value >= 600 && sensor1Value < 700) //if LED lights up, the LDR1 will read the value in these range
      {
        count1++; 
      }

      digitalWrite(LED1, LOW);

      timerun = millis();
      
  } 
   digitalWrite(LED1, LOW);
   
   while (timerun < (minute * 2))
   {
       Serial.print("\nThe time elapsed since the program run INSIDE THE SECOND LOOP:");
       Serial.println(timerun);

       randInterval = random(1000,10000); //randomizing the time of interval of each blinking for LEDs

      Serial.print("\nThe random interval:");
      Serial.println(randInterval);
       
   /*numbers displayed on 7 segment display */
     switch (count2)
     {
         case 0:
         digitalWrite (F, LOW);
         digitalWrite (G, LOW);
         digitalWrite (H, LOW);
         digitalWrite (I, LOW);
         break;
         
         case 1:
         digitalWrite (F, HIGH);
         digitalWrite (G, LOW);
         digitalWrite (H, LOW);
         digitalWrite (I, LOW);
         break;
    
         case 2:
         digitalWrite (F, LOW);
         digitalWrite (G, HIGH);
         digitalWrite (H, LOW);
         digitalWrite (I, LOW);
         break;
    
         case 3:
         digitalWrite (F, HIGH);
         digitalWrite (G, HIGH);
         digitalWrite (H, LOW);
         digitalWrite (I, LOW);
         break;
    
         case 4:
         digitalWrite (F, LOW);
         digitalWrite (G, LOW);
         digitalWrite (H, HIGH);
         digitalWrite (I, LOW);
         break;
    
         case 5:
         digitalWrite (F, HIGH);
         digitalWrite (G, LOW);
         digitalWrite (H, HIGH);
         digitalWrite (I, LOW);
         break;
    
         case 6:
         digitalWrite (F, LOW);
         digitalWrite (G, HIGH);
         digitalWrite (H, HIGH);
         digitalWrite (I, LOW);
         break;
    
         case 7:
         digitalWrite (F, HIGH);
         digitalWrite (G, HIGH);
         digitalWrite (H, HIGH);
         digitalWrite (I, LOW);
         break;
    
         case 8:
         digitalWrite (F, LOW);
         digitalWrite (G, LOW);
         digitalWrite (H, LOW);
         digitalWrite (I, HIGH);
         break;
    
         case 9:
         digitalWrite (F, HIGH);
         digitalWrite (G, LOW);
         digitalWrite (H, LOW);
         digitalWrite (I, HIGH);
         break;
           
      }
    
        delay(randInterval);
        digitalWrite(LED2, HIGH);
        delay(randInterval);
        
        /*reading value from LDR2*/
        sensor2Value = analogRead (LDR2);
        Serial.print("\nThe value of read from the LDR2:");
        Serial.println(sensor2Value);
        
            
      if (sensor2Value >= 680 && sensor2Value < 740)
      {
        count2++;
      }
 
      digitalWrite(LED2, LOW);

      timerun = millis();

   }

   digitalWrite (LED2, LOW);    
}
