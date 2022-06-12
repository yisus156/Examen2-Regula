from unicodedata import name
import socketio
import serial
from time import sleep

#Parametros para la configuracion de arduino
portArduino = 'COM3'
baudios = 9600

#Se crea el objeto arduino asginandole el puerto COM y la velocidad en baudios
try:
	arduino = serial.Serial(portArduino, baudios)
except:
	print('Cannot conect to the port')

sio=socketio.Client()

@sio.event
def connect():
	print('Conexión establecida')

@sio.on('respuesta')
def on_message(respuesta):
    #print(respuesta)
    if respuesta==13:
    	print("Activa Buzzer Disparo")
    	arduino.write(b'S')
    if respuesta==12:
    	print("Activa Buzzer Win")
    	arduino.write(b'W')
    if respuesta==11:
    	print("Enciende led de choque")
    	arduino.write(b'C')
    if respuesta==10:
    	print("Activa Buzzer")
    	arduino.write(b'B')
    if respuesta==9:
    	print("Enciende led de derecha")
    	arduino.write(b'D')
    if respuesta==8:
    	print("Enciende led de izquierda")
    	arduino.write(b'I')

@sio.event
def disconnect():
	print('Desconectado del servidor')
	
sio.connect('http://josuegregorio.duckdns.org/')

while True:
	try:
		on_message()
	except:
		sleep(0);
	sleep(0.1)
	#Finaliza la conexion a arduino
arduino.close()
sio.disconnect()