function Snake() {
    this.x = 5*scl;
    this.y = 5*scl;
    this.xspeed = 1;
    this.yspeed = 0;
    this.total = 0;
    this.tail = [];
    this.currentScore = 0;
    this.bestScore = 0;

    this.AdjustScore = function () {
        this.currentScore++;
        document.getElementById("currentScore").innerHTML = this.currentScore;
    }

    this.edges = function () {
        if (this.x > width - scl || this.x < 0 || this.y > height - scl || this.y < 0) return true;
        else return false;
    }
    
    this.resetEdges = function(){
        if (this.x > width-scl) {
            this.x = 0;
        } else if (this.x < 0) {
            this.x = width - scl ;
        } else if (this.y > height-scl) {
            this.y = 0;
        } else if (this.y < 0) {
            this.y = height - scl ;
        }
    }

    this.eat = function (pos) {
        var d = dist(this.x, this.y, pos.x, pos.y);
        if (d < 1) {
            this.total++;
            return true;
        } else {
            return false;
        }
    }

    this.dir = function (x, y) {
        this.xspeed = x;
        this.yspeed = y;
    }

    this.death = function () {
        for (var i = 0; i < this.tail.length; i++) {
            var pos = this.tail[i];
            var d = dist(this.x, this.y, pos.x, pos.y);
            if (d < 1) {
                console.log('starting over');
                this.total = 0;
                this.tail = [];

                   if (this.currentScore > this.bestScore) { 
                      this.bestScore = this.currentScore;
                       document.getElementById("bestScore").innerHTML = this.bestScore;
                       document.getElementById("currentScore").innerHTML = 0;
                   }

                this.currentScore = 0;

                gamePlay = false;
              
               document.getElementById("scoreBoard").style.display = "block";             
               document.getElementById("Replay").style.display = "block";
               document.getElementById("scoreBoard").style.transform = "rotate(0deg)";
                

            }
        }
    }

    this.update = function () {
        for (var i = 0; i < this.tail.length - 1; i++) {
            this.tail[i] = this.tail[i + 1];
        }
        if (this.total >= 1) {
            this.tail[this.total - 1] = createVector(this.x, this.y);
        }

        if (this.edges()) {
            this.resetEdges();
        } else {
            this.x = this.x + this.xspeed * scl;
            this.y = this.y + this.yspeed * scl;
        }
        

       //this.x = constrain(this.x, 0, width - scl);  // limitation of a game field
       //this.y = constrain(this.y, 0, height - scl);
    }

    this.show = function () {
        fill(255);
        for (var i = 0; i < this.tail.length; i++) {           
                rect(this.tail[i].x, this.tail[i].y, scl, scl);  
        }      
        rect(this.x, this.y, scl, scl);

    }
}