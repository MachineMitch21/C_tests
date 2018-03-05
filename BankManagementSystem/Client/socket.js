'use strict';

var net = require('net');

function encode_data(data)
{
    console.log(data);
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
        console.log(charCode);
    }

    encodedData = dataArr.join("");

    console.log(encodedData);

    return encodedData;
}

function toAscii(bin) {
    return bin.replace(/\s*[01]{8}\s*/g, function(bin) {
        return String.fromCharCode(parseInt(bin, 2))
    });
}

function toBinary(str, spaceSeparatedOctets) {
    return str.replace(/[\s\S]/g, function(str) {
        return !1 == spaceSeparatedOctets ? str : str + " "
    });
}

function intToBin(number)
{
    var result = "";

    while (number > 0)
    {
        var bit = Math.floor(number % 2) != 0 ? '1' : '0';
        result = bit + result;

        number = Math.floor(number / 2);
    }

    return result;
}

function flipBitsInBinStr(binStr)
{
    var binStrArr = [...binStr];

    for (var i = 0; i < binStr.length; i++)
    {
        binStrArr[i] = binStrArr[i] == '1' ? '0' : '1';
    }

    binStr = binStrArr.join("");

    return binStr;
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
