window.onload = function () {
    var screen = new Screen(document.querySelector('canvas#screen'));
    screen.drawTime(new Date());
    setInterval(function () {
        screen.drawTime(new Date());
    }, 1000);
}