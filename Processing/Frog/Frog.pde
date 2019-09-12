
PImage frog;

void setup() { 
  size(1280, 720);
  frog = loadImage("frog.jpg");
  frog.loadPixels();
  background(0);
}
void draw() {
  int count = mouseX;
  for (int i=0; i<count; i++) {
    float x = random(width);
    float y = random (height);
    // int index = int(x) + int(y) * width; // The first way
    // color c = frog.pixels[index];
    color c = frog.get(int(x), int (y)); // The second way
    fill(c,180);
    ellipse(x, y, 16, 16);
  }
}
