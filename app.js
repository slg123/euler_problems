var express = require('express');
var path = require('path');
var bodyParser = require('body-parser'); 

var app = express();

// configure app

app.set('view engine', 'ejs');
app.set('views', path.join(__dirname, 'views'));

// use middleware

app.use(bodyParser()); 

app.use(express.static(path.join(__dirname, 'bower_components/bootstrap/dist')));

// define routes

var todoItems = [
	    { id: 1, desc: 'battlestar galactica' },
	    { id: 2, desc: 'babylon 5' },
	    { id: 3, desc: 'cowboy bebop' }
];

app.get('/', function (req, res) {
    res.render('index', {
        title: 'My App',
        items: todoItems
    });
});

app.post('/add', function (req, res) {
    var newItem = req.body.newItem;
    todoItems.push({
	    id: todoItems.length + 1,
	    desc: newItem
    });

    res.redirect('/');

});

app.listen('1337', function() {
    console.log('ready on port 1337'); 
});
