//----------------------------------------------
//
// trapezoidal integration in javascript.
//
// currently borked. 
//
//----------------------------------------------
function trapezium(f, x, h) {
    return (f(x) + f(x+h))/2.0;
}

function f(x) {
    return 2*x;
}

function integrate(f, a, b, steps, method) {
    var h = (b-a) / steps;
    for (i=1; i<=steps; i++) {
        var ival = h * sum(method(f, a+i*h, h));
    }
    return ival;
}

function sum(n) {
    var v = function (x) {
        return sum (n + x);
    };

    v.valueOf = v.toString = function () {
        return n;
    };
    return v;
}

var result = integrate(f, 1, Math.PI, 100, trapezium)
WScript.Echo(result);


