Snake s;
PVector food;
int scl= 20;

void setup() {
  size(800, 600);
  frameRate(10);
  s = new Snake();
  CreateFood();
}
void draw() {
  background(0);

  s.create();
  s.update();





  fill(255, 0, 0);
  rect(food.x, food.y, 20, 20);
}

void keyPressed() {
  if (keyCode == RIGHT) {
    if (s.xspeed != -1) {
      s.dir(1, 0);
    }
  }
  if (keyCode == LEFT) {
    if (s.xspeed != 1){
    s.dir(-1, 0);
    }
  }
  if (keyCode == UP) {
    if (s.yspeed != 1){
    s.dir(0, -1);
    }
  }
  if (keyCode == DOWN) {
    if (s.yspeed != -1){
    s.dir(0, 1);
    }
  }
}
void CreateFood() {
  int cols = floor(width/scl);
  int rows = floor(height/scl);
  food = new PVector(floor(random(cols)), floor(random(rows)));
  food.mult(scl);
}
