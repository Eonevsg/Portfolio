var s;
var scl = 20;


var food;
var gamePlay = false;


function setup() {
    var cnv = createCanvas(600, 600);
    frameRate(10);
    cnv.parent('gameHolder');

    s = new Snake();
    pickLocation();

    /* var button= createButton("reset");
      button.mousePressed(resetSketch);*/
}

/*function resetSketch() {
   
   // s = new Snake();
   // pickLocation();
    gamePlay = true;
}*/

function pickLocation() {
    var cols = floor(width / scl);
    var rows = floor(height / scl);
    food = createVector(floor(random(cols)), floor(random(rows)));
    food.mult(scl);
}


function draw() {

    if (gamePlay) {
        background(51);

        if (s.eat(food)) {
            s.AdjustScore();
            pickLocation();
        }
        s.death();
        s.update();
        s.show();


        fill(255, 0, 100);
        rect(food.x, food.y, scl, scl);
    }
}



function RestartGame() {
    document.getElementById("scoreBoard").style.transform = "rotate(360deg)";
    gamePlay = true;

    setTimeout(function () {
        var board = document.getElementById("scoreBoard").style.display = "none";
        var rep = document.getElementById("Replay").style.display = "none";
    }, 700);

}

function StartGame() {
    gamePlay = true;

    var buttons = document.getElementsByClassName("gameButtons");
    for (i = 0; i < buttons.length; i++) {
        buttons[i].style.display = "none";
    }

    var score = document.getElementsByClassName("score");
    for (i = 0; i < score.length; i++) {
        score[i].style.display = "block";
    }

    var name = document.getElementsByClassName("name");
    name[0].hidden = true;

}

function mousePressed() {
    s.total++;
}

function keyPressed() {
    if (keyCode === UP_ARROW) {
        if (s.yspeed != 1)
            s.dir(0, -1);
    } else if (keyCode === DOWN_ARROW) {
        if (s.yspeed != -1)
            s.dir(0, 1);
    } else if (keyCode === RIGHT_ARROW) {
        if (s.xspeed != -1)
            s.dir(1, 0);
    } else if (keyCode === LEFT_ARROW) {
        if (s.xspeed != 1)
            s.dir(-1, 0);
    }
}



