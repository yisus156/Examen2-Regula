from unicodedata import name
import socketio
import serial
from time import sleep


sio=socketio.Client()
@sio.event
def connect():
	print('Conexión establecida')
def send_msg(msg):
	sio.emit('msg', msg)
@sio.event
def disconnect():
	print('Desconectado del servidor')
	
sio.connect('http://josuegregorio.duckdns.org/')

portArduino = 'COM3'
baudios = 9600

try:
	arduino = serial.Serial(portArduino, baudios)
except:
	print('Cannot conect to the port')

while True:
	lectura = arduino.readline().decode(encoding="ascii", errors="ignore")
	send_msg(lectura)
	print(lectura)
	sleep(0.1)
arduino.close()
sio.disconnect()