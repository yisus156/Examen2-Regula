var express = require('express');
var app = express();
var server = require('http').Server(app);


app.use("/",express.static('public'));
//app.use("/",express.static('public'));

server.listen(80, function(){
	console.log("Servidor corriendo en http://localhost:80");
});

const socketIo = require('socket.io');
const io = socketIo(server);

io.on('connection', (socket)=>{
	socket.on('msg', (msg) => {
        console.log(msg);
				io.emit('msg', msg);
    });

	socket.on('respuesta', (respuesta) => {
        //console.log(respuesta);
        io.emit('respuesta',respuesta);
    });

  socket.on('disconnect', function() {
      console.log('client disconnected');
   });
	console.log('new connection', socket.id);
})
