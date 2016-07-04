# Sistema de seguridad

Este sistema de seguridad incluye los siguientes modulos: 

-Sensor de presencia PIR: este dispositivo detecta el calor humano y activa una alarma si detecta el movimiento de un intruso.

-Sensor de humo y otros gases (MQ-2): este  dispositivo nos ayudara a detectar si hay presencia de humo o gas en el lugar donde este implantado el sistema de seguridad y activara un buzzer.

-RFID-RC522: este dispositivo detecta la extraccion de objetos los cuales tengan el codigo de barra.

-Camara web: la cual tomara una rafaga de fotos cuando el modulo RFID-RC522 detecte la extraccion de uno de los objetos que tenga pegados uno de los codigos de barra, Se utilizara una Raspberry PI 3, para que almacene dichas fotos.

Ver diagrama fritzing para mayor informacion de como conectar todos estos dispositivos, en caso de no contar con fritzing lo puedes instalar desde tu terminal ejecutando el siguiente comando :~$sudo apt-get install fritzing, en caso que quieras la version mas actualizada puedes descargarla del siguiente enlace: http://fritzing.org/download/ .
