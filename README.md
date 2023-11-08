# AGP-GPS-UDP
# Receptor NMEA a través de UDP

Este proyecto utiliza un ESP32 para recibir sentencias NMEA desde un dispositivo serie y las transmite a través de UDP a una dirección multicast en una red WiFi.

## Configuración

Asegúrate de configurar correctamente las siguientes variables en el archivo `main.cpp` antes de compilar y cargar el código en tu ESP32:

- `ssid`: Nombre de tu red WiFi.
- `password`: Contraseña de tu red WiFi.
- `multicastIP`: Dirección IP multicast a la que se enviarán los datos NMEA.
- `RXPin`: Puerto RX utilizado para la comunicación serie.
- `baudRate`: Velocidad de baudios para la comunicación serie.

## Cómo funciona

El ESP32 se conecta a la red WiFi especificada y luego espera recibir sentencias NMEA a través del puerto serie (Serial2). Cada sentencia NMEA recibida se envía a la dirección multicast configurada mediante UDP. El código está diseñado para funcionar de manera continua y enviar las sentencias NMEA en tiempo real.

## Uso

1. Cargue el código en su ESP32.
2. Asegúrese de que el ESP32 esté conectado a la red WiFi especificada.
3. Conecte el dispositivo serie que envía sentencias NMEA al ESP32.
4. El ESP32 recibirá y transmitirá las sentencias NMEA a la dirección multicast configurada.

## Contribuciones

Si deseas contribuir a este proyecto o realizar mejoras, ¡siéntete libre de hacerlo! Puedes enviar solicitudes de extracción o informar problemas.

## Licencia

Este proyecto se distribuye bajo la Licencia MIT. Para obtener más detalles, consulta el archivo [LICENSE](LICENSE).

---

Este proyecto ha sido desarrollado por Leonardo Bracco. Si tienes alguna pregunta o necesitas ayuda, no dudes en ponerte en contacto con nosotros.
