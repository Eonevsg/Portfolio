
ArrayList<Circle> circles;
PImage img;
ArrayList<PVector> spots;

void setup() {
  size(1329, 674);
  circles = new ArrayList<Circle>();
  spots = new ArrayList<PVector>();
  img = loadImage("2017.png");
  img.loadPixels();
  

  for (int x = 0; x < img.width; x++)
    for (int y = 0; y < img.height; y++)
    {
      int index = x + y * width;
      color c = img.pixels[index];
      float b = brightness(c);
      if (b>1)
      {
        spots.add(new PVector(x, y));
      }
    }
}

void draw() {
  background(0);
  //frameRate(5);
  int total=10;
  int count=0;
  int attempts=0;
while(count < total){
  
  Circle newC = newCircle();
  if (newC != null) {
    circles.add(newC);
    count++;
  }
  attempts++;
  if(attempts>500)
  {
    noLoop();
    println("Done!");
    break;
  }
}
  for (Circle c : circles) {
    if (c.growing) {
      if (c.edges()) {
        c.growing = false;
      } else {
        for (Circle other : circles) {
          if (c != other) {
            float d = dist(c.x, c.y, other.x, other.y);
            if (d - 2 < c.r + other.r) {
              c.growing = false;
              break;
            }
          }
        }
      }
    }
    c.show();
    c.grow();
  }
 // println(spots.size());
}



Circle newCircle() {
  int r = int (random(0, spots.size()));
  PVector spot = spots.get(r);
  float x = spot.x;
  float y = spot.y;

  boolean validCircle = true;
  for (Circle c : circles) {
    float d = dist(x, y, c.x, c.y);
    if (d < c.r + 2) {
      validCircle = false;
      break;
    }
  }
  if (validCircle) {
    return new Circle(x, y);
  } else 
  return null;
}
