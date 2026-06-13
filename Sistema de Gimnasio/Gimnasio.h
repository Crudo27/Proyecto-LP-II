#pragma once
#include "Miembro.h"
#include "Entrenador.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <functional>
#include <map>

class Gimnasio
{
    private:
        std::string nombre;
        std::vector<Miembro*> miembros;
        std::vector<Entrenador*> entrenadores;
        
        template <typename T>
        T* buscarPorID(const std::vector<T*>& vec, int id) const;

        std::map<std::string, function<Suscripcion*()>> factorySuscripcion;

        void registrarSuscripciones();
        Suscripcion* cargarSuscripciones(const string& tipo);
    
    public:
        Gimnasio(std::string nombre);

        //Getters
        std::string getNombre() const;

        //Miembros
        void agregarMiembro(Miembro* m);
        void eliminarMiembro(int id);
        Miembro* buscarMiembro(int id) const;
        void mostrarMiembros() const;
        void cargarMiembros(const string& amiembros);

        //Entrenadores
        void agregarEntrenador(Entrenador* e);
        void eliminarEntrenador(int id);
        Entrenador* buscarEntrenador(int id) const;
        void mostrarEntrenadores() const;
        void cargarEntrenadores(const string& aentrenadores);

        //Persistencia
        void cargarCSV();
        void guardarCSV();

        ~Gimnasio();
};