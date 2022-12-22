window.onload = function () {
    var canvas = document.querySelector('canvas');
    var dialog = document.querySelector('dialog');
    var form = dialog.querySelector('form');
    var screen = new Screen(canvas);
    form.elements[2].value = screen.style.number.size;
    form.elements[5].value = screen.style.padding;
    screen.drawTime(new Date(), true);
    setInterval(function () {
        screen.drawTime(new Date());
    }, 1000);
    canvas.ondblclick = function () {
        dialog.showModal();
    }
    form.onsubmit = function (event) {
        event.preventDefault();
        const data = {};
        for (let i = 0; i < form.elements.length; i++) {
            data[form.elements[i].id] = form.elements[i].value;
        }
        screen.style.background.color = data.backgroundColor;
        screen.style.number.color = data.numberColor;
        screen.style.number.size = parseInt(data.numberSize);
        screen.style.margin.left = parseInt(data.marginLeft);
        screen.style.margin.top = parseInt(data.marginTop);
        screen.style.padding = parseInt(data.padding);
        screen.drawTime(new Date(), true);
        dialog.close();
    };
}