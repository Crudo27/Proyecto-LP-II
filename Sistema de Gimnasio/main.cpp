#include "Gimnasio.h"
#include "Miembro.h"
#include "Entrenador.h"
#include "SuscripcionBasica.h"
#include "SuscripcionPro.h"
#include "SuscripcionVIP.h"
#include <iostream>
#include <limits>
#include <cstdlib>
using namespace std;

// ── Utilidades ──────────────────────────────────────────────────────────────

void limpiarBuffer()
{
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int leerEntero(const string& mensaje)
{
    int valor;
    while(true)
    {
        cout << mensaje;
        if(cin >> valor) { limpiarBuffer(); return valor; }
        cout << "  [!] Entrada inválida. Ingrese un número entero.\n";
        cin.clear();
        limpiarBuffer();
    }
}

double leerDouble(const string& mensaje)
{
    double valor;
    while(true)
    {
        cout << mensaje;
        if(cin >> valor) { limpiarBuffer(); return valor; }
        cout << "  [!] Entrada inválida. Ingrese un número válido.\n";
        cin.clear();
        limpiarBuffer();
    }
}

string leerString(const string& mensaje)
{
    string valor;
    cout << mensaje;
    getline(cin, valor);
    return valor;
}

// ── Submenús ────────────────────────────────────────────────────────────────

Suscripcion* elegirSuscripcion()
{
    cout << "\n  Tipo de suscripción:\n";
    cout << "    1. Básica  ($50)\n";
    cout << "    2. Pro     ($100)\n";
    cout << "    3. VIP     ($150)\n";
    int op = leerEntero("  Opción: ");
    switch(op)
    {
        case 1: return new SuscripcionBasica();
        case 2: return new SuscripcionPro();
        case 3: return new SuscripcionVIP();
        default:
            cout << "  [!] Opción inválida. Se asignará suscripción Básica.\n";
            return new SuscripcionBasica();
    }
}

void menuMiembros(Gimnasio& gym)
{
    int op;
    do
    {
        cout << "\n╔══════════════════════════╗\n";
        cout << "║      GESTIÓN MIEMBROS    ║\n";
        cout << "╠══════════════════════════╣\n";
        cout << "║  1. Agregar miembro      ║\n";
        cout << "║  2. Eliminar miembro     ║\n";
        cout << "║  3. Buscar miembro       ║\n";
        cout << "║  4. Mostrar todos        ║\n";
        cout << "║  0. Volver               ║\n";
        cout << "╚══════════════════════════╝\n";
        op = leerEntero("  Opción: ");

        switch(op)
        {
            case 1:
            {
                try
                {
                    string nombre = leerString("  Nombre: ");
                    int edad      = leerEntero("  Edad: ");
                    Suscripcion* s = elegirSuscripcion();
                    gym.agregarMiembro(new Miembro(nombre, edad, s));
                    cout << "  [✓] Miembro agregado correctamente.\n";
                }
                catch(const invalid_argument& e)
                {
                    cout << "  [!] Error de validación: " << e.what() << "\n";
                }
                catch(const exception& e)
                {
                    cout << "  [!] Error inesperado: " << e.what() << "\n";
                }
                break;
            }
            case 2:
            {
                int id = leerEntero("  ID del miembro a eliminar: ");
                if(gym.buscarMiembro(id) != nullptr)
                {
                    gym.eliminarMiembro(id);
                    cout << "  [✓] Miembro eliminado.\n";
                }
                else
                {
                    cout << "  [!] No se encontró un miembro con ID " << id << ".\n";
                }
                break;
            }
            case 3:
            {
                int id = leerEntero("  ID del miembro a buscar: ");
                Miembro* m = gym.buscarMiembro(id);
                if(m != nullptr)
                {
                    cout << "\n";
                    m->mostrarInfo();
                }
                else
                {
                    cout << "  [!] No se encontró un miembro con ID " << id << ".\n";
                }
                break;
            }
            case 4:
            {
                cout << "\n── Miembros registrados ──\n";
                gym.mostrarMiembros();
                break;
            }
            case 0: break;
            default:
                cout << "  [!] Opción inválida.\n";
        }
    } while(op != 0);
}

void menuEntrenadores(Gimnasio& gym)
{
    int op;
    do
    {
        cout << "\n╔════════════════════════════╗\n";
        cout << "║    GESTIÓN ENTRENADORES    ║\n";
        cout << "╠════════════════════════════╣\n";
        cout << "║  1. Agregar entrenador     ║\n";
        cout << "║  2. Eliminar entrenador    ║\n";
        cout << "║  3. Buscar entrenador      ║\n";
        cout << "║  4. Mostrar todos          ║\n";
        cout << "║  5. Registrar hora         ║\n";
        cout << "║  0. Volver                 ║\n";
        cout << "╚════════════════════════════╝\n";
        op = leerEntero("  Opción: ");

        switch(op)
        {
            case 1:
            {
                try
                {
                    string nombre      = leerString("  Nombre: ");
                    int    edad        = leerEntero("  Edad: ");
                    string especialidad = leerString("  Especialidad: ");
                    double tarifa      = leerDouble("  Tarifa por hora: ");
                    gym.agregarEntrenador(new Entrenador(nombre, edad, especialidad, tarifa));
                    cout << "  [✓] Entrenador agregado correctamente.\n";
                }
                catch(const invalid_argument& e)
                {
                    cout << "  [!] Error de validación: " << e.what() << "\n";
                }
                catch(const exception& e)
                {
                    cout << "  [!] Error inesperado: " << e.what() << "\n";
                }
                break;
            }
            case 2:
            {
                int id = leerEntero("  ID del entrenador a eliminar: ");
                if(gym.buscarEntrenador(id) != nullptr)
                {
                    gym.eliminarEntrenador(id);
                    cout << "  [✓] Entrenador eliminado.\n";
                }
                else
                {
                    cout << "  [!] No se encontró un entrenador con ID " << id << ".\n";
                }
                break;
            }
            case 3:
            {
                int id = leerEntero("  ID del entrenador a buscar: ");
                Entrenador* e = gym.buscarEntrenador(id);
                if(e != nullptr)
                {
                    cout << "\n";
                    e->mostrarInfo();
                }
                else
                {
                    cout << "  [!] No se encontró un entrenador con ID " << id << ".\n";
                }
                break;
            }
            case 4:
            {
                cout << "\n── Entrenadores registrados ──\n";
                gym.mostrarEntrenadores();
                break;
            }
            case 5:
            {
                int id = leerEntero("  ID del entrenador: ");
                Entrenador* e = gym.buscarEntrenador(id);
                if(e != nullptr)
                {
                    e->registrarHora();
                    cout << "  [✓] Hora registrada. Total: " << e->getHorasTrabajadas() << " hs.\n";
                }
                else
                {
                    cout << "  [!] No se encontró un entrenador con ID " << id << ".\n";
                }
                break;
            }
            case 0: break;
            default:
                cout << "  [!] Opción inválida.\n";
        }
    } while(op != 0);
}

// ── Main ────────────────────────────────────────────────────────────────────

int main()
{
    system("chcp 65001 > nul");

    Gimnasio* gym = nullptr;

    // Inicialización del gimnasio
    while(gym == nullptr)
    {
        try
        {
            string nombre = leerString("Ingrese el nombre del gimnasio: ");
            gym = new Gimnasio(nombre);
        }
        catch(const invalid_argument& e)
        {
            cout << "[!] " << e.what() << " Intente de nuevo.\n";
        }
    }

    // Carga de datos persistidos
    try
    {
        gym->cargarCSV();
        cout << "[✓] Datos cargados correctamente.\n";
    }
    catch(const runtime_error& e)
    {
        cout << "[!] No se encontraron archivos previos. Iniciando vacío.\n";
    }

    // Menú principal
    int op;
    do
    {
        cout << "\n╔══════════════════════════════╗\n";
        cout << "║  " << gym->getNombre();
        // Padding dinámico simple
        int pad = 28 - (int)gym->getNombre().length();
        for(int i = 0; i < pad; i++) cout << " ";
        cout << "║\n";
        cout << "╠══════════════════════════════╣\n";
        cout << "║  1. Gestionar miembros       ║\n";
        cout << "║  2. Gestionar entrenadores   ║\n";
        cout << "║  3. Guardar datos            ║\n";
        cout << "║  0. Salir                    ║\n";
        cout << "╚══════════════════════════════╝\n";
        op = leerEntero("  Opción: ");

        switch(op)
        {
            case 1: menuMiembros(*gym);     break;
            case 2: menuEntrenadores(*gym); break;
            case 3:
            {
                try
                {
                    gym->guardarCSV();
                    cout << "  [✓] Datos guardados correctamente.\n";
                }
                catch(const runtime_error& e)
                {
                    cout << "  [!] Error al guardar: " << e.what() << "\n";
                }
                break;
            }
            case 0:
            {
                try
                {
                    gym->guardarCSV();
                    cout << "  [✓] Datos guardados. ¡Hasta luego!\n";
                }
                catch(const runtime_error& e)
                {
                    cout << "  [!] Error al guardar al salir: " << e.what() << "\n";
                }
                break;
            }
            default:
                cout << "  [!] Opción inválida.\n";
        }
    } while(op != 0);

    delete gym;
    return 0;
}