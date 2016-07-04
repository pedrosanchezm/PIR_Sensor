#!/usr/bin/python
# -*- coding: utf-8 -*-

import tornado.httpserver 
import tornado.ioloop 
import tornado.options 
import tornado.web 
import tornado.websocket 
import RPi.GPIO as GPIO

GPIO.setmode(GPIO.BOARD)
GPIO.setup(11, GPIO.OUT)
GPIO.output(11, False)

class ArduinoHandler(tornado.websocket.WebSocketHandler): 
	def open(self): 
		print "Conexion Abierta desde: {}".format(self.request.remote_ip) 
		self.write_message("Conexion Abierta") 
	def check_origin(self, origin): 
		return True 
	def on_message(self, message):
		estadoactual = GPIO.input(11)
		print "Cliente dice: {}".format(message)
		
		if message == "LedOn":
			if estadoactual == True:
				self.write_message("Led is already ON")
				
			else:
				GPIO.output(11, True)
				self.write_message("ON")
		
		elif message == "LedOff":
			if estadoactual == False:
				self.write_message("Led is already OFF")
				
			else:
				GPIO.output(11, False)
				self.write_message("OFF")
			
		else:
			self.write_message("Comando Desconocido") 
		
	def on_close(self): 
		print "Conexion Cerrada"
		
		
if __name__ == "__main__": 
	tornado.options.parse_command_line() 
	app = tornado.web.Application(handlers=[(r"/", ArduinoHandler)]) 
	server = tornado.httpserver.HTTPServer(app) 
	server.listen(8000)
	tornado.ioloop.IOLoop.instance().start()
