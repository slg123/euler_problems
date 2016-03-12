//----------------------------------------------
//
// trapezoidal integration in javascript.
//
//----------------------------------------------
function sum(n) {
    var v = function (x) {
        return sum (n + x);
    };

    v.valueOf = v.toString = function () {
        return n;
    };
    return v;
}

function trapezium(f, x, h) {
    return (f(x) + f(x+h))/2.0;
}

function f(x) {
    return 2*x;
}

function integrate(f, a, b, steps, method) {
    var h = (b-a) / steps;
    var total = 0; 
    for (var i=1; i<=steps; i++) {
        var ival = parseFloat(h * sum(method(f, a+i*h, h)));
        print(ival);
        total += ival;
    }
    return total; 
}

print(Math.PI);

function print(obj) {
    WScript.Echo(obj);
}

var result = integrate(f, 1, Math.PI, 100, trapezium)
print(result); 
