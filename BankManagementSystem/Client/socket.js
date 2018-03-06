'use strict';

var net = require('net');

function encode_data(data)
{
    var encodedData = "";

    var dataArr = data.split("");

    for (var i = 0; i < data.length; i++)
    {
        var charCode = dataArr[i].charCodeAt(0);

        for (var j = 0; j < 7; j++)
        {
            charCode ^= (1 << j);
        }
        
        dataArr[i] = String.fromCharCode(charCode);
    }

    encodedData = dataArr.join("");

    return encodedData;
}

function sendData(client_data)
{
    var net = require('net');

    var client = new net.Socket();
    client.connect(27015, '127.0.0.1', function() {
        console.log('Connected');
        client.write(client_data);
    });

    client.on('data', function(data) {
        console.log('Received: ' + data);
        client.destroy(); // kill client after server's response
    });

    client.on('close', function() {
        console.log('Connection closed');
    });
}
