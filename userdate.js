function formatDate(userDate) {
    var date = [];
    date = userDate.split("/"); 
    m = date[0], d = date[1], y = date[2];
    function fixDate(s) {
        if (s.length < 2) {
            return 0+s;
        }
        return s;
    }
    m = fixDate(m); 
    d = fixDate(d);
    return String(y+m+d); 
}

WScript.Echo(formatDate("12/31/2014")); 
WScript.Echo(formatDate("2/3/2014")); 

