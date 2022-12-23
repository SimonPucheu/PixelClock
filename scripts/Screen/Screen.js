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
                "size": Math.round(canvas.width / 2 - canvas.width / 20) - 10
            },
            "margin": {
                "left": 10,
                "top": 10
            },
            "padding": Math.round(canvas.width / 10)
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
    async drawNumberSlowly(startX, startY, end, directionX, directionY, w, h, number = 0, oldNumber = 0, waitTime = 10, quality = 1, style = starck) {
        for (var i = 0; i < end; i += quality) {
            this.drawNumber(startX + (directionX ? i : -i), startY, w, h, oldNumber, style);
            await new Promise(resolve => setTimeout(resolve, waitTime * quality));
            this.screenContext.clearRect(startX + (directionX ? i : -i), startY, w, h);
        }
        for (var i = end; i >= 0; i -= quality) {
            this.screenContext.clearRect(startX, startY + (directionY ? i + 1 : -(i + 1)), w, h);
            this.drawNumber(startX, startY + (directionY ? i : -i), w, h, number, style);
            await new Promise(resolve => setTimeout(resolve, waitTime * quality));
        }
    }
    drawTime(time, all = false) {
        this.screen.style.backgroundColor = this.style.background.color;
        var numbersList = [[], []];
        numbersList[0][1] = time.getHours() % 10;
        if (time.getHours() >= 10)
            numbersList[0][0] = Math.floor(time.getHours() / 10);
        numbersList[1][1] = time.getMinutes() % 10;
        if (time.getMinutes() >= 10)
            numbersList[1][0] = Math.floor(time.getMinutes() / 10);
        for (var y = 0; y < 2; y++) {
            for (var x = 0; x < 2; x++) {
                if (this.oldTime[y][x] != numbersList[y][x] || all) {
                    this.drawNumberSlowly((x * (this.style.number.size + this.style.padding)) + this.style.margin.left, (y * (this.style.number.size + this.style.padding)) + this.style.margin.top, this.style.number.size + this.style.margin.left, x, y, this.style.number.size, this.style.number.size, numbersList[y][x], this.oldTime[y][x], 5, 1);
                }
            }
        }
        this.oldTime = numbersList;
    }
    oldTime = [[], []];
};
