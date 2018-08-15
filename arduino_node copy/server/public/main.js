//main.js

const socket = io()

socket.on('flex', (data) => console.log(data))