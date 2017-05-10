/* 
 * rosserial Subscriber Example
 * Blinks an LED on callback
 */

#include <ros.h>
#include <std_msgs/Empty.h>
#include <std_msgs/String.h>
#include <std_msgs/Int8.h> 

int LED1 = 12;
int LED2 = 11;
int LED3 = 10;

ros::NodeHandle  nh;

void messageCb( const std_msgs::Empty& toggle_msg){
  digitalWrite(11, HIGH-digitalRead(11));   // blink the led
}


void changeSentiment( const std_msgs::Int8& toggle_msg){
  if(toggle_msg.data > 0){
    if(digitalRead(LED1) == 0) {
       digitalWrite(LED1, HIGH);   // blink the led
    }
    digitalWrite(LED2, LOW);   // Turn led low
    digitalWrite(LED3, LOW);   // Turn led low
  }
  else if ( toggle_msg.data < 0){
    if(digitalRead(LED2) == LOW){
        digitalWrite(LED2, HIGH);   // blink the led
    }
    digitalWrite(LED1, LOW);   // Turn led low
    digitalWrite(LED3, LOW);   // Turn led low

  }  else {

    if(digitalRead(LED3) == LOW){
      digitalWrite(LED3, HIGH);  // blink the led
    }
    digitalWrite(LED1, LOW);   // blink the led
   digitalWrite(LED2, LOW);   // blink the led

     
  }
  
}
//ros::Subscriber<std_msgs::Empty> sub("toggle_led", &messageCb );
//ros::Subscriber<std_msgs::String> sub("voice_chatter", &messageCb );
ros::Subscriber<std_msgs::Int8> sub("score", &changeSentiment );

void setup()
{ 
  
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  
  nh.initNode();
  nh.subscribe(sub);
}

void loop()
{  
  nh.spinOnce();
  delay(1);
}

