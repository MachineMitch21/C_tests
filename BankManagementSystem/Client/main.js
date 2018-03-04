'use strict';

const electron  = require('electron');
const url       = require('url');
const path      = require('path');

const {app, BrowserWindow, Menu, ipcRenderer, globalShortcut} = electron;

let mainWindow;
let devToolsWindow;

app.on('ready', function() {

    globalShortcut.register('Ctrl+T', function(){
        mainWindow.openDevTools();
    });

    mainWindow = new BrowserWindow({
        width:  300,
        height: 250,
        title:  'BMS Sign In',
        icon:   __dirname + 'icons/bms-icon.ico'
    });

    mainWindow.loadURL(url.format({
        pathname:   path.join(__dirname, 'signIn.html'),
        protocol:   'file:',
        slashes:    true
    }));

    mainWindow.on('closed', function(){
        app.quit();
    });

    const mainMenu = Menu.buildFromTemplate(signInMenuTemplate);

    Menu.setApplicationMenu(mainMenu);
});

const signInMenuTemplate = [
    {
        label: 'CreateAccount',
        click() {
            mainWindow.loadURL(url.format({
                pathname: path.join(__dirname, 'accounts.html'),
                protocol: 'file',
                slashes: true
            }));
            const accountsMenu = Menu.buildFromTemplate(accountsMenuTemplate);
            Menu.setApplicationMenu(accountsMenu);
        }
    }
];

const accountsMenuTemplate = [
    {
        label: 'SignIn',
        click() {
            mainWindow.loadURL(url.format({
                pathname: path.join(__dirname, 'signIn.html'),
                protocol: 'file',
                slashes: true
            }));
            const signInMenu = Menu.buildFromTemplate(signInMenuTemplate);
            Menu.setApplicationMenu(signInMenu);
        }
    }
];

const mainMenuTemplate = [
    {
        label: 'Accounts',
        submenu:[
            {
                label: 'Sign In'
            },
            {
                label: 'Create Account',
                click() {
                    mainWindow.loadURL(url.format({
                        pathname:   path.join(__dirname, 'accounts.html'),
                        protocol:   'file:',
                        slashes:    true
                    }));
                }
            },
            {
                label: 'Delete Account'
            }
        ]
    },
    {
        label: 'Exit',
        accelerator: process.platform == 'darwin' ? 'Command+Q' : 'Ctrl+Q',
        click() {
            app.quit();
        }
    }
];



// Mac == 'darwin'
if (process.platform == 'darwin')
{
    mainMenuTemplate.unshift({});
}
