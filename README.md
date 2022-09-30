# MEDICION-ANGULAR

Este proyecto presenta la concepción, diseño, implementación y operación de un sistema capaz de medir posición angular por medio de un Synchro/Resolver.
Como caracteristicas funcionales de este proyecto se tienen:

•	Se diseño e implemento un oscilador “puente de wien”, el cual es capaz de oscilar a una frecuencia de 400 Hz, con máxima excursión en su salida. 

•	Se diseño e implemento un circuito Scott-t, un Multiplicador y un Filtro pasa bajas.

  o	El circuito Scott-t, es para poder realizar la transformación de 3 señales provenientes del Synchro a dos señales, las cuales son aproximaciones de una onda seno y coseno respectivamente.

•	Se implemento un circuito multiplicador, el cual realiza la operación entre las señales seno y coseno provenientes del circuito Scott-t. 

•	Se diseño e implemento un Filtro pasa bajas a la señal proveniente del circuito multiplicador para obtener un valor DC. 

•	Se acondiciona la señal proveniente del filtro pasa bajas para que esta pueda ser leída y analizada por un Arduino. 

•	Se diseño e implemento el código con el cual se determina la posición angular del rotor del Synchro haciendo uso de la señal descrita previamente, este código se realizó en el programa Arduino Software IDE. 
