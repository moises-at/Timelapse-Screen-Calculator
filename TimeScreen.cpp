#include <cstdlib>
#include <iostream>
#include <direct.h> //mkdir
#include <windows.h>
#include <locale.h>

using namespace std;

const int BEEP_HIGH = 600;
const int BEEP_LOW = 400;
const int BEEP_DURATION = 130;

void intervalo_disparo();
void duracion_evento();
void duracion_clip();
void realizar_beeps();
void mostrar_menu();
void calculadora_timelapse();
void screenshot(char* project_name);

// Calculadora de timelapse
void calculadora_timelapse() {
    int opcion = 0, repetir = 0;

    setlocale(LC_ALL, "SPANISH");

    do {
        realizar_beeps();
        system("cls");
        mostrar_menu();
        cin >> opcion;

        switch (opcion) {
            case 1:
                intervalo_disparo();
                break;
            case 2:
                duracion_evento();
                break;
            case 3:
                duracion_clip();
                break;
            case 4:
                return;
            default:
                cout << "Opción no válida. Intente de nuevo." << endl;
        }

        cout << "\nREINTENTAR = 1, TERMINAR = 2, MENU = 3: ";
        cin >> repetir;

    } while (repetir != 2);
}

// Menú principal de opciones
void mostrar_menu() {
    cout << " CALCULADORA PARA TIMELAPSE" << endl << endl;
    cout << "¿QUÉ DESEA CALCULAR?" << endl << endl;
    cout << "1. INTERVALO DE DISPARO" << endl;
    cout << "2. DURACIÓN DEL EVENTO" << endl;
    cout << "3. DURACIÓN DEL CLIP" << endl;
    cout << "4. SALIR" << endl;
    cout << "\nOPCIÓN: ";
}

// Calcular intervalo de disparo
void intervalo_disparo() {
    int duracion_evento, duracion_clip, fps, intervalo;
    
    system("cls");
    cout << "\n->>> INTERVALO DE DISPARO <<<-" << endl;
    cout << "\nDuración del evento a fotografiar (minutos): "; cin >> duracion_evento;
    cout << "Duración final del clip (segundos): "; cin >> duracion_clip;
    cout << "FPS para el video: "; cin >> fps;

    intervalo = (duracion_evento * 60) / (duracion_clip * fps);
    
    cout << "\nIntervalo en segundos: " << intervalo;
    if (intervalo > 60) {
        cout << "\nIntervalo h - m - s: " << (intervalo / 3600) << "h " << (intervalo % 3600) / 60 << "min " << (intervalo % 3600) % 60 << " seg";
    }
    cout << "\nTotal de fotos: " << fps * duracion_clip << endl;
}

// Calcular duración del evento
void duracion_evento() {
    int intervalo, duracion_clip, fps, duracion_evento;
    
    system("cls");
    cout << "->>> DURACIÓN DEL EVENTO <<<-" << endl;
    cout << "\nIntervalo (segundos): "; cin >> intervalo;
    cout << "Duración del clip (segundos): "; cin >> duracion_clip;
    cout << "FPS: "; cin >> fps;

    duracion_evento = intervalo * duracion_clip * fps;
    
    cout << "\nDuración del evento en h - m - s: " << (duracion_evento / 3600) << "h " << (duracion_evento % 3600) / 60 << "min " << (duracion_evento % 3600) % 60 << " seg";
    cout << "\nTotal de fotos: " << duracion_clip * fps << endl;
}

// Calcular duración del clip
void duracion_clip() {
    float duracion_evento, intervalo, fps, duracion_clip;

    system("cls");
    cout << "->>> DURACIÓN DEL CLIP <<<-" << endl;
    cout << "\nDuración del evento a fotografiar (minutos): "; cin >> duracion_evento;
    cout << "Intervalo usado (segundos): "; cin >> intervalo;
    cout << "FPS: "; cin >> fps;

    duracion_clip = (duracion_evento * 60 / intervalo) / fps;

    cout << "\nDuración del clip: " << duracion_clip;
    cout << "\nTotal de fotos: " << (duracion_evento * 60 / intervalo) << endl;
}

// Generar beeps al mostrar el menú
void realizar_beeps() {
    Beep(BEEP_LOW, BEEP_DURATION);
    Beep(BEEP_LOW, BEEP_DURATION);
    Beep(BEEP_HIGH, 250);
}

int main() {
    int calcular_timelapse;
    cout << "¿Desea calcular timelapse (sí -> 0)? "; cin >> calcular_timelapse;

    if (calcular_timelapse == 0) {
        calculadora_timelapse();
    }

    system("cls");
    screenshot("captura");

    cout << "\nFin de la captura." << endl;
    cout << "Se guardó en la carpeta del programa, dentro de la carpeta 'captura'." << endl;
    realizar_beeps();

    system("PAUSE");
    return EXIT_SUCCESS;
}

// No modificar esta función
void screenshot(char* project_name) {
    int loop;
    long time;

    cout << "No. de capturas (si no sabe cuántas hará, ingrese '-1'): "; cin >> loop;
    cout << "\nIntervalo (milisegundos): "; cin >> time;
    cout << "Iniciando captura..." << endl;

    if (loop == -1) {
        loop = 999999;
    }

    char cmd[1000];
    mkdir(project_name);
    sprintf(cmd, "nircmd.exe loop %d %d savescreenshot %s/~$currdate.MM_dd_yyyy$-~$currtime.HH_mm_ss$.png", loop, time, project_name);

    system(cmd);
}
