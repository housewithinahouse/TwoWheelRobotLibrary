

/*
 * This example code has been written by Edwin Fallwell + Matt Neer 
 * for the Monroe County Public Library in Bloomington, IN.
 * 
 * MIT license, check LICENSE for more information */
 
// we include our TwoWheeledRobot libary, which has all of our motor control functions 
#include <TwoWheelRobot.h>

// create a TwoWheelRobot object, which we will address
// when we want to issue commands to our example robot
TwoWheelRobot examply = TwoWheelRobot();

void setup() {
  /* The setup section of your code runs once, when the 
  *  board first boots forward. We only need to acomplish one 
  *  thing in our setforward here, which is to start forward examply. */

  // start up the two wheel robot library
  examply.initalize();

  
  // and tell the robot to hold on for a little bit
  // (so it doesn't run away as soon as its code is uploaded.) 
  delay(500);
}

void loop() {
  /* The loop section of your code will be run through 
   * continuously, from top to bottom. In this example,    
   * we give a bunch of examples of what it can do. */
  
  // these are all of the moves that our TwoWheelRobot object can do:
  examply.forward();
  examply.backward();
  examply.left();
  examply.right();
  examply.forwardLeft();
  examply.backwardLeft();
  examply.forwardRight();
  examply.backwardRight();

  //  you can specifiy how long each command runs: 
  examply.forward(1);
  examply.left(300);

  // the speed of the robot can be adjusted:
  examply.speedUp();
  examply.slowDown();

  // or be set directly
  examply.setSpeed(60);

  //there are 2 different movement modes for our Two Wheel Robot object: 
  examply.setMovementMode(2); //continous
  examply.setMovementMode(1); //discrete

  
  // in continous mode, stop commands must be explicitly made:
  examply.setMovementMode(2);
  examply.forward();
  delay(100);
  examply.backward();
  delay(100);
  examply.stop(); 

  // in discrete mode, stop commands implicitly are added after each movment c:
  examply.setMovementMode(1);
  examply.forward(50);
               //stops
  examply.backward(50);
               //stops

 
}  

void moveForwardUntilSwitchHitThenCircleBackAndStartAllOver(){
  // the name of the function is pretty self explanatory, but
  // yeah, lets use our TwoWheelRobot library to do just that 
  // (this is the core of the first flashligh robot. 
  examply.setMovementMode(2);//have it move until being told to stop
 
  // create a var to hold our "have I hit something?" state
  bool hasHitSomething = false;

  // and run a loop that will drive forward, looking for something
  // this while loop will continue to run forever
  while(!hasHitSomething){
    examply.forward();

    // unless it hits something...
    if(hitSomething()){
      hasHitSomething = true;
    }
  }
  
  // then it will back up for a bit and start over again
  examply.backwardLeft();
  delay(300);  
}

// this is how we check if we hit something:
bool hitSomething(){
  // hook up a switch to a digital pin and +v
  int bumpSensor = 19; //or whatever
  //turn it to input
  pinMode(bumpSensor, INPUT);
  
  // if it ever goes high (cuz it bumped something)
  if (digitalRead(bumpSensor) == HIGH){
    return true;
  }
  else{
    return false;
  }
}

// ***********- BUILD A BOT III -*******************// 
// for our Build a Bot III, we'll use the 
// "check to see if something has hit it" 
// bits, but also reuse some of our line detection


bool leftSensorSeesLine = false;
bool rightSensorSeesLine = false;
bool foundALine = false;
int leftSensorPin = A0;
int rightSensorPin = A1; 
int leftBumperPin = 20;
int rightBumperPin = 21;
int lineThreshold = 600; // number derived from testing

void lookForLinesifFoundStayThereAndWaitForSomethingToBumpYou(){ 
  // check the sensors, if either sensor sees a line, try to get the other sensor
  // also be over that line. If no lines found,  
  checkEachSensor();
  
  if(leftSensorSeesLine && rightSensorSeesLine){
    examply.stop();
    foundALine = true;
  }      
  else if(rightSensorSeesLine){
    examply.right();
  }
  else if(leftSensorSeesLine){
    examply.left();
  }
  else if(foundALine){
    examply.stop();
  }
  else{
    wanderRandomly();
  }

  if(somethingBumpsYou()){
    freakOut();
    foundALine = false;
  }  
}

void checkEachSensor(){
  // updates the vars: leftSensorSeesLine + rightSensorSeesLine
    
  if((analogRead(leftSensorPin)) > lineThreshold){
    leftSensorSeesLine = true;
  }
  else{
    leftSensorSeesLine = false;
  }
  
  if((analogRead(rightSensorPin)) > lineThreshold){
    rightSensorSeesLine = true;
  }
  else{
    rightSensorSeesLine = false;
  }
}

void wanderRandomly(){
  // issues a series of random commands to our robot
    
  examply.forward(); //TODO: replace with actually random movement
}

bool somethingBumpsYou(){
  // returns true if either bumper is hit

  // turn the pins into inputs
  pinMode(leftBumperPin, INPUT);
  pinMode(rightBumperPin, INPUT);

  // check to see if either one goes high  
  if((digitalRead(leftBumperPin) == HIGH)||(digitalRead(rightBumperPin)) == HIGH){
    return true;
  }
  else{
    return false;
  }
}

void freakOut(){
  // preforms a crazy chaotic series of moves
    
  examply.left(300); //TODO: replace with more interesting actions
}





