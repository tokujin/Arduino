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
import ddf.minim.*;
import ddf.minim.signals.*;
import ddf.minim.analysis.*;
import ddf.minim.effects.*;

Minim minim;
AudioPlayer song;


  DisplayItems di;  // backgroundcolor, grid, etc. are controlled in the DisplayItems object
  // width and height should be set here
  int xWidth = 900;
  int yHeight = 900;
  
  // set framerate
  int fr = 40;
  
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
      colorMode(HSB,100);
      di = new DisplayItems();
      smooth();
      port = new Serial(this, "/dev/cu.usbmodemfd121", 9600);
      println(port);
      
      minim = new Minim(this);
// this loads mysong.wav from the data folder
song = minim.loadFile("waterdrops2.mp3");
song.play();
      
}
void createCircle(){

   
   //Adding constraints to keep the circle within the framesize
   if(value1 > width){
       value1 = width;
   }
     //Draw the circle
     ellipse(random(width/2 - 200,width/2 + 200), random(height/2 - 200,height/2 + 200) , random(value1 / 3, value1), random(value1 / 3, value1));
 
       
}

// draw listens to serial port, draw 
void draw(){
  
  while(port.available() > 0){
        value = port.read();
        serialEvent(value);
    }

    di.drawBack();

    noStroke();
    //fill(random(255),random(255),random(255),random(50,80));
    fill(random(100),60,99,50);
    
    
    createCircle();
    
    di.drawItems();  
    
    
    if(output) println("Distance: "+value1);
    delay(900);
}

