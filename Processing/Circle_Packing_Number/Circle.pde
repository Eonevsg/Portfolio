class Circle{
  float x;
  float y;
  float r = 1;
  
  boolean growing = true;
  
  Circle(float x_, float y_){
     x = x_;
     y = y_;
    
  }
   void show(){
     noFill();
     stroke(255);
     strokeWeight(2);
     ellipse(x,y,r*2,r*2);
   }
  void grow(){
    if (growing)
      r = r + 1;
  }
  
  boolean edges(){
    return (x + r > width || x - r < 0 || y + r > height || y - r < 0);
  }
  
  
}
