#include <stdio.h>
#include <stdlib.h>
#include "LinkedListAPI.h"

void main(void) {
	
	List* head;
	
	

}



/*
function setup() {
  createCanvas(400, 400);
}

function ellipsePlotPoints(xc, yc, x, y) {
  
  point(xc + x, yc + y);
  point(xc - x, yc + y);
  point(xc + x, yc - y);
  point(xc - x, yc - y);
  
}

function myEllipse(xc, yc, rx, ry) {
  
 rx2 = rx * rx;
 ry2 = ry * ry;
  
 tworx2 = 2 * rx2;
  twory2 = 2 * ry2;
  
  x = 0; 
  y = ry;
  
  px = 0;
  py = tworx2 * y;
  
  ellipsePlotPoints(xc, yc, x, y);

  p = round(ry2 - (rx2 * ry) + (0.25 * rx2));
  while (px < py) {
     x += 1;
    px += twory2;
    if (p < 0) {
      p += ry2 + px;
    } else {
      y -= 1;
      py -= tworx2;
      p += ry2 + px - py;
    }
    ellipsePlotPoints(xc, yc, x, y);
  }
  
  p = round(ry2 * (x+0.5) * (x+0.5) + rx2*(y-1)*(y-1) - rx2*ry2);
  while (y > 0) {
    y -= 1;
    py -= tworx2;
    if (p > 0) {
      p += rx2 - py;
    } else {
      x += 1;
      px += twory2;
      p += rx2 + px - py;
    }
    
    ellipsePlotPoints(xc, yc, x, y);
  }
  
  
}

function draw() {
  background(255);
  stroke('black');
  //ellipse(200, 200, 150, 100);
  
  myEllipse(200, 200, 150, 100);
}

*/