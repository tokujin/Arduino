/*
*  pa_Ultrasound
*  
*  Reads values of a ping ultrasound sensor from the serial port
*  and draws a graphical representation of the sensor's state.
* 
*  This file is part of the Arduino meets Processing Project.
*  For more information visit http://www.arduino.cc.
*
*  copyleft 2005 by Anders Gran and Jacob Holst for Malmö University
*
*/

import processing.serial.*;

  DisplayItems di;  // backgroundcolor, grid, etc. are controlled in the DisplayItems object
  // width and height should be set here
  int xWidth = 600;
  int yHeight = 600;

  // set framerate
  int fr = 24;
  
  // set up the display items you want by choosing true
  boolean bck = true;
  boolean grid = true;
  boolean g_vert = true;
  boolean g_horiz = true;
  boolean g_values = true;
  boolean output = true;
  
  // these variables are for the serial port connection object
  Serial port;
//  String portname = "/dev/cu.usbmodemfd121";  // find the name of your serial port in your system setup!
  int baudrate = 9600;  //  set baudrate here
  int value;  // variables used to store value from serial port
  String buf=""; // String buffer to store serial values
  int value1;  // value1 is the read value


// pressing these keys you can toogle on/off display items
void keyPressed(){
      if (key == 'b' || key == 'B') bck=!bck; 
      if (key == 'g' || key == 'G') grid=!grid; 
      if (key == 'v' || key == 'V') g_values=!g_values; 
      if (key == 'o' || key == 'O') output=!output; 
}

// the serial event function takes the value of the event and store it in the corresponding variable
void serialEvent(int serial){

    if(serial!=10) {        
          buf += char(serial);          
          } else {
          //extract the value from the string 'buf'
          buf = buf.substring(1,buf.length());
          //cast the value to an integer
          value1 = int(buf);
          buf="";
      }
     }
// setup initializes displayItems and serial port objects
void setup(){
  
      size(xWidth, yHeight);
      frameRate(fr);

      di = new DisplayItems();

      port = new Serial(this, "/dev/cu.usbmodemfd121", 9600);
      println(port);
}
void createCircle(){

   
   //Adding constraints to keep the circle within the framesize
   if(value1 > width){
       value1 = width;
   }
     //Draw the circle
     ellipse(width/2, height/2, value1, value1);
 
       
}

// draw listens to serial port, draw 
void draw(){
  
  while(port.available() > 0){
        value = port.read();
        serialEvent(value);
    }

    di.drawBack();

    noStroke();
    fill(0, 0, 255);
    
    createCircle();
    
    di.drawItems();  
    
    
    if(output) println("Distance: "+value1);
    delay(100);
}

