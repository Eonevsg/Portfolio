class Snake {

  int x=0;
  int y=0;
  float xspeed;
  float yspeed;
  ArrayList<PVector> tail= new ArrayList<PVector>(); 


  Snake(int x_, int y_)
  {
    x=x_;
    y=y_;
  }
  Snake() {
    xspeed=1;
  }

  boolean edges() {
    if (x > width || x < 0 || y > height || y < 0) return true;
    else return false;
  }
  void controlEdges(int  x, int y) {
    if (x > width) {
      rect(x - width, y, 20, 20);
    } else if (x < 0) {
      rect(x + width, y, 20, 20);
    } else if (y > height) {
      rect(x, y - height, 20, 20);
    } else if (y < 0) {
      rect(x, y + height, 20, 20);
    }
  }
  void resetEdges() {
    if (x > width) {
      x = 0;
    } else if (x < 0) {
      x = width-scl;
    } else if (y > height) {
      y = 0;
    } else if (y < 0) {
      y = height - scl;
    }
  }
  boolean isDead() {
    boolean check = false;
    for (int i = 0; i < tail.size(); i++) {
      PVector temp = tail.get(i);
      if (x == temp.x && y == temp.y) {
        check = true; 
        break;
      }
    }
    if (check) return true;
    else return false;
  }

  void create() {



    fill(255);
    for (int i = 0; i < tail.size(); i++ ) {
      PVector temp = tail.get(i);
      if (edges()) {
        controlEdges(int(temp.x), int(temp.y));
      } else {
        rect(temp.x, temp.y, 20, 20);
      }
    }
    if (edges()) {
      controlEdges(x, y);
    } else
      rect(x, y, scl, scl);
  }

  void dir(float x_, float y_) {
    xspeed=x_;
    yspeed=y_;
  }

  void update() {

    if (isDead()) {
      tail.clear();
    }

    if (s.eat(food)) {
      fill(255, 0, 0);
      CreateFood();
      tail.add(new PVector(x, y));
    } else {
      tail.add(new PVector(x, y));
      tail.remove(0);
    }


    if (edges()) {
      resetEdges();
    } else {
      x+=xspeed*scl;
      y+=yspeed*scl;
    }

    //x = constrain(x, 0, width-scl);
    // y = constrain(y, 0, height-scl);
  }

  boolean eat(PVector f) {
    float d = dist(x, y, f.x, f.y);
    if (d<1) {
      return true;
    } else 
    return false;
  }
}
