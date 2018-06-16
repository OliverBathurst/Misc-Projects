var width = 500;//window.screen.availWidth
var height = 500;//window.screen.availHeight
var map = [[],[]];
var circles = [];
var canvas = document.getElementById('myCanvas');
var context = canvas.getContext('2d');

function init(){
    resetMap();
    randomifyMap();
    printMap();

    var intervalID = window.setInterval(myCallback, 1000);
    function myCallback() {
        reCalculate();//recalculate positions
        printMap();//reprint
    }
}

self.addEventListener('message', function(e) {
    init();
});

function reCalculate(){
    for (i = 0; i <= width; i++){
        for(j = 0; j <= height; j++){
            if(map[i][j] === ' '){ //if it's dead or empty
                if (liveNeighbours(i,j) === 3){ //rule 4
                    map[i][j] = 1;// rule 4: Any dead cell with exactly three live neighbors becomes a live cell.
                }
            }else{ //it is alive
                if(liveNeighbours(i,j) < 2 || liveNeighbours(i,j) > 3){
                    map[i][j] = 0;//rule 2: Any live cell with more than three live neighbors dies, as if by overcrowding.
                    circles = circles.filter(function(item) {
                        return item.xPos === i && item.yPos === j;//remove dead
                    })
                }//rule 1: Any live cell with fewer than two live neighbors dies, as if caused by underpopulation.
            }// rule 3: Any live cell with two or three live neighbors lives on to the next generation.

        }
    }
}

function liveNeighbours(x, y) {
    var count = 0;
    if (!(x + 1 > width) && map[x + 1][y] === 1) {
        count++;
    }
    if(!(x+1 > width) && !(y+1 > height) && map[x+1][y+1] === 1){
        count++;
    }
    if(!(x+1 > width) && !(y-1 < 0) && map[x+1][y-1] === 1){
        count++;
    }
    if(!(y+1 > height) && map[x][y+1] === 1){
        count++;
    }
    if(!(y-1 < 0) && map[x][y-1] === 1){
        count++;
    }
    if(!(y+1 > height) && !(x-1 < 0) && map[x-1][y+1] === 1){
        count++;
    }
    if(!(x-1 < 0) && map[x-1][y] === 1){
        count++;
    }
    if(!(x-1 < 0) && !(y-1 < 0) && map[x-1][y-1] === 1){
        count++;
    }
    return count;
}

function printMap(){
    for (i = 0; i <= width; i++){
        for(j = 0; j <= height; j++){
            if(map[i][j] === 1){
                circles.push(new Circle(i, j));
            }
        }
    }
    draw();
}

function Circle(xPos, yPos) {
    this.xPos = xPos;
    this.yPos = yPos;
}

function draw() {
    canvas.width = width;
    canvas.height = height;
    context.clearRect(0, 0, canvas.width, canvas.height);
    context.globalAlpha = 1;
    for (var i = 0; i < circles.length; i++) {
        circles[i].update();
    }
}

Circle.prototype.update = function() {
    context.beginPath();
    context.arc(this.xPos, this.yPos, 1, 0, 2 * Math.PI, false);
    context.fillStyle = 'black';
    context.fill();
};

function resetMap(){//reset all values to empty
    for (var i = 0; i <= width; i++) {
        map[i] = [];
        for (var j = 0; j <= height; j++) {
            map[i][j] = 0;
        }
    }
}

function randomifyMap(){ //random config
    for (i = 0; i <= width; i++){
        for(j = 0; j <= height; j++){
            if (Math.floor((Math.random() * 10) + 1) >  5){ // 8 in 10 chance of spawning life
                map[i][j] = 1;//can be modified to change style
            }else{
                map[i][j] = 0;
            }
        }
    }
}