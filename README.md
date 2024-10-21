# ScreenTimelapse Calculator

**ScreenTimelapse** es una herramienta en C++ que captura pantallas automáticamente a intervalos regulares, creando una secuencia de imágenes ideal para generar un timelapse. Utiliza la utilidad [NirCmd](http://www.nirsoft.net/utils/nircmd.html) para tomar las capturas de pantalla y permite a los usuarios personalizar el intervalo entre capturas, la cantidad de capturas y la duración total del evento a capturar. Además, incluye una calculadora para determinar el intervalo de disparo, la duración del evento o la duración del clip basado en la configuración de fotogramas por segundo (FPS).

## Características:
- **Captura automática de pantallas**: Genera una secuencia de imágenes a intervalos personalizados.
- **Cálculo del timelapse**: Calculadora integrada para determinar el intervalo entre capturas, la duración del evento y la duración del clip.
- **Configuración flexible**: Permite al usuario definir el número de capturas y el intervalo en milisegundos.

## Créditos:
Este proyecto se basó en el tutorial de captura de pantalla en C++ publicado en [jquery-manual.blogspot.com](https://jquery-manual.blogspot.com/2015/06/38-tutorial-de-c-en-espanol-screenshot.html), adaptándolo para incluir nuevas funcionalidades como la calculadora de timelapse y mejorando la experiencia del usuario.

## Requisitos:
- **NirCmd**: La herramienta requiere [NirCmd](http://www.nirsoft.net/utils/nircmd.html) para capturar las pantallas. Asegúrate de descargarla y colocarla en la carpeta del proyecto.

