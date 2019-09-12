
ArrayList<Circle> circles;
PImage img;

void setup() {
  size(1280, 720);
  circles = new ArrayList<Circle>();
  img = loadImage("frog.jpg");
  img.loadPixels();
 
}

void draw() {
  
  background(0);
  //frameRate(5);
  int total=100;
  int count=0;
  int attempts=0;
  while (count < total) {

    Circle newC = newCircle();
    if (newC != null) {
      circles.add(newC);
      count++;
    }
    attempts++;
    if (attempts > 1000)
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
  
  float x = random(width);
  float y = random(height);

  boolean validCircle = true;
  for (Circle c : circles) {
    float d = dist(x, y, c.x, c.y);
    if (d < c.r + 2) {
      validCircle = false;
      break;
    }
  }
  if (validCircle) {
    int index = int(x) + int(y)*width;
    color col = img.pixels[index];
    return new Circle(x, y, col);
  } else 
  return null;
}
