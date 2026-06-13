# Sistema de Gestión de Gimnasio

*Sistema de administración de miembros y entrenadores para un gimnasio, desarrollado en C++ con principios SOLID y programación orientada a objetos.*

---

## Descripción

Aplicación de consola que permite gestionar los recursos de un gimnasio: registro de **miembros**, **entrenadores** y sus **suscripciones**, con persistencia de datos mediante archivos CSV.

---

## Estructura del Proyecto

```
gimnasio/
├── include/
│   ├── Persona.h
│   ├── Miembro.h
│   ├── Entrenador.h
│   ├── Suscripcion.h
│   └── Gimnasio.h
├── src/
│   ├── Miembro.cpp
│   ├── Entrenador.cpp
│   ├── Suscripcion.cpp
│   ├── Gimnasio.cpp
│   └── main.cpp
├── data/
│   ├── miembros.csv
│   └── entrenadores.csv
└── README.md
```

---

## Funcionalidades

- Registrar miembros y entrenadores
- Eliminar miembros y entrenadores por ID
- Buscar por ID usando templates
- Listar todos los registros
- Persistencia de datos en archivos CSV
- Suscripciones de tipo Básica, Pro y VIP

---

## Principios Aplicados

| Principio | Aplicación |
|---|---|
| **Open/Closed** | Factory Map para extender tipos de suscripción sin modificar lógica existente |
| **Liskov Substitution** | `Miembro` y `Entrenador` sustituyen a `Persona` sin alterar el comportamiento |
| **Dependency Inversion** | `Gimnasio` depende de la abstracción `Suscripcion`, no de implementaciones concretas |

---

## Autor

Desarrollado como proyecto universitario de **Programación Orientada a Objetos**.