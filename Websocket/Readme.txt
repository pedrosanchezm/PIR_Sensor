Para utilizar este scrip debes instalar el siguiente paquete el cual incluye las librerias necesarias para su
correcto funcionamiento:

$sudo apt-get install tornado

Tambien debes conocer el comando $sudo ifconfig ,el cual te permitira conocer tu IP
para poder establecer la conexion a traves del websocket

Ademas debes utilizar el navegador chrome, ya que en este se puedes utilizar una extension la cual se llama 
Simple WebSocket Client ingresa en el siguiente enlace para agregarla: 
https://chrome.google.com/webstore/detail/simple-websocket-client/pfdhoblngboilpfeibdedpjgfnlcodoo
En el campo URL: debes colocar tu IP y utilizar el puerto 8000

Ejemplo: URL: ws://192.168.1.100:8000

De esta forma podras enviar ordenes al scrip escrito en Python el cual puedes modificar a tu gusto
para enviar ordenes a una placa Arduino o utilizar una Raspberry PI para ejecutar intrucciones en modulos 
compatibles con estas placas. 
