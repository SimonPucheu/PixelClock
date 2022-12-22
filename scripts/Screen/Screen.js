class Screen {
    constructor(canvas) {
        this.screen = canvas;
        this.screenContext = canvas.getContext('2d');
        this.style = {
            "background": {
                "color": "#000000"
            },
            "number": {
                "color": "#ffff00",
                "size": Math.round(canvas.width / 2 - canvas.width / 30) - 10
            },
            "margin": {
                "left": 10,
                "top": 10
            },
            "padding": Math.round(canvas.width / 15)
        };
    }
    drawNumber(x, y, w, h, number = 0, style = starck) {
        this.screenContext.fillStyle = this.style.number.color;
        for (var cy = y; cy < (y + h); cy += (h / 5)) {
            for (var cx = x; cx < (x + w); cx += (w / 5)) {
                if (style[number][(cy - y) / (w / 5)][(cx - x) / (h / 5)]) {
                    this.screenContext.fillRect(cx, cy, w / 5, h / 5);
                }
            }
        }
    }
    drawTime(time) {
        this.screen.style.backgroundColor = this.style.background.color;
        this.screenContext.clearRect(0, 0, this.screen.width, this.screen.height);
        var numbersList = [[], []];
        numbersList[0][1] = time.getHours() % 10;
        if (time.getHours() >= 10)
            numbersList[0][0] = Math.floor(time.getHours() / 10);
        numbersList[1][1] = time.getMinutes() % 10;
        if (time.getMinutes() >= 10)
            numbersList[1][0] = Math.floor(time.getMinutes() / 10);
        for (var y = 0; y < 2; y++) {
            for (var x = 0; x < 2; x++) {
                var X = (x * (this.style.number.size + this.style.padding)) + this.style.margin.left;
                var Y = (y * (this.style.number.size + this.style.padding)) + this.style.margin.top;
                this.drawNumber(X, Y, this.style.number.size, this.style.number.size, numbersList[y][x]);
            }
        }
    }
};
