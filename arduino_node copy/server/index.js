//SERVER SETUP
const http = require('http')
const express = require('express')
const app = express()
const server = http.createServer(app)

//WEBSOCKET SETUP
const socketIO = require('socket.io')
const io = socketIO.listen(server)


app.use(express.static(__dirname + '/public'))
server.listen(3000, () => console.log('server listening on port', 3000))

//SERIAL COMMUNICATION
//library allows communication between 
const Serialport = require('serialport')
const Readline = Serialport.parsers.Readline
const port = new Serialport('/dev/cu.usbmodem1421', {
	baudRate: 9600
})

const parser = port.pipe(new Readline({ delimiter: '\n'}))

parser.on('open', () => console.log('connection is open')) 

parser .on('data', (data) => {
	console.log(data)
	io.emit('flex',data)
})

port.on('error', (err) =>  console.log(err))