/*
 * This example code has been written by Edwin Fallwell + Matt Neer 
 * for the Monroe County Public Library in Bloomington, IN.
 * 
 * MIT license, check LICENSE for more information */

// This is the TwoWheelRobot library, used to make it easier to work with our little wheeled friends. 
// Let's go over the parts of this library and explain how they all work. 



#ifndef TwoWheelRobot_h // We make this declaration in order to prevent libraries from messing up if they get included more than once. 
#define TwoWheelRobot_h // You gotta wrap the whole thing in this #ifndef then #define (if not defined then define) statement. 


#include "Arduino.h" // While normal .ino sketches don't have to explictly include "Arduino.h", libraries do. 

// I've also included the Adafruit Motor Control library, because its just libraries all the way down. 
#include <Adafruit_MotorShield.h>


// In this section we name all of the variables and functions we want our class to have. 
// We also set up some default values for some of the functions. 
class TwoWheelRobot
{
  private:
    Adafruit_MotorShield _AFMS = Adafruit_MotorShield();;  
    Adafruit_DCMotor *_L_MOTOR = _AFMS.getMotor(3);
    Adafruit_DCMotor *_R_MOTOR = _AFMS.getMotor(4);
    int _l_speed;
    int _r_speed;
    static int _default_segment_length;
    int _default_pause_length;
    int currentMovementMode;
    void _stop();
    void _go(uint8_t l_cmd, uint8_t r_cmd);
  public: 
    TwoWheelRobot();
    void initalize();
    void setMovementMode(int newMovementMode);
    void forward(int segment_length = _default_segment_length);
    void backward(int segment_length = _default_segment_length);
    void left(int segment_length = _default_segment_length);
    void right(int segment_length = _default_segment_length);
    void forwardLeft(int segment_length = _default_segment_length);
    void backwardLeft(int segment_length = _default_segment_length);
    void forwardRight(int segment_length = _default_segment_length);
    void backwardRight(int segment_length = _default_segment_length);
    void stop();
    void speedUp();
    void slowDown();
    void setSpeed(int newSpeed);
};

#endif //this is the end of the "if the classes are not defined then define them" wrapper we put up at the begining. 
