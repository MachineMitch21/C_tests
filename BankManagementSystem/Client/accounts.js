'use strict';

const electron  = require('electron');
const url       = require('url');
const path      = require('path');

const {app, BrowserWindow, Menu, ipcRenderer} = electron;

var divAccountsHolder;

window.webContents.executeJavaScript("document.querySelector('#divAccountsHolder')", function(result){
    divAccountsHolder = result;
});
