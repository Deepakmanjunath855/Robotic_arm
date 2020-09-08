/* Four Servos of the Robotic Arm are connected to 4 PWM Pins of Arduino 
and these 4 servos are named a, b, c and d. 
If you want to control servo a, then type "90a/", 
where "90" is the PWM value (range is 0 - 255), 
"a" means servo a and "/" is string parse delimiter.
*/

String readString;
int x=90, y=90, z=90, p=90; 
#include <Servo.h> 
Servo servoa, servob, servoc, servod;

void setup() 
{
  Serial.begin(9600);


  servoa.attach(3); 
  servob.attach(5); 
  servoc.attach(6);
  servod.attach(9); 
  servoa.write(x);
  servob.write(y);
  servoc.write(z);
  servod.write(p);
}

void loop() 
{
  if (Serial.available())  
  {
    char m = Serial.read();
    if (m == '/') 
    {
      if (readString.length() >1) 
      {
        Serial.println(readString);

        int temp = readString.toInt();
        
          Serial.print("writing Angle: ");
          Serial.println(temp);
          if(readString.indexOf('a') >=0)
          {
            if (temp>x)
            {
              for (int i=x; i<temp; i++)
              {
                servoa.write(i);
                delay(10);
              }
              x=temp;
            }
            else 
            {
            for (int i=x; i>temp; i--)
              {
                servoa.write(i);
                delay(10);
              }
            }
            x=temp;
         }
         Serial.print("done");
//////////////////////////////////////////////////////////////////////////////         
          if(readString.indexOf('b') >=0)
          {
            if (temp>y)
            {
              for (int i=y; i<temp; i++)
             { servob.write(i);
               delay(10);
             }
              y=temp;
            }
            else 
            {
            for (int i=y; i>temp; i--)
             { 
               servob.write(i);
               delay(10);
             }
              y=temp;
          }
         }
///////////////////////////////////////////////////////////////////////
          if(readString.indexOf('c') >=0) //myservoc.write(n);
          {
            if (temp>z)
            {
              for (int i=z; i<temp; i++)
              {
                servoc.write(i);
                delay(10);
              }
              z=temp;
            }
            else 
            {
            for (int i=z; i>temp; i--)
             { 
               servoc.write(i);
               delay(10);
              }
              z=temp;
            }
         }
/////////////////////////////////////////////////////
         if(readString.indexOf('d') >=0)
          {
            if (temp>p)
            {
              for (int i=p; i<temp; i++)
              {
                servod.write(i);
                delay(10);
              }
              p=temp;
            }
            else 
            {
            for (int i=p; i>temp; i--)
              {
                servod.write(i);
                delay(30);
              }
            }
            p=temp;
         }

       readString="";
      }
    }  
    else 
    {     
      readString += m;
    }
  }
}
