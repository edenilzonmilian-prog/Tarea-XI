#include <iostream>
#include <fstream>

using namespace std;


struct Producto {
    int codigo;
    char nombre[40];
    char categoria[30];
    int stock;
    float precio;
    bool activo;
};


void menu();
void registrarProducto();
void listarProductos();
void mostrarEncabezado();
void pausarSistema();


int main() {
    menu();
    return 0;
}


void mostrarEncabezado() {
    cout << "\n===============================";
    cout << "\n SISTEMA DE VENTAS E INVENTARIO";
    cout << "\n===============================";
    cout << "\nEstudiante: Hans Douglas Edenilzon Alvarado Milian";
    cout << "\n===============================\n";
}


void pausarSistema() {
    cout << "\nPresione ENTER para continuar...";
    cin.ignore();
    cin.get();
}


void menu() {
    int opcion;

    do {
        mostrarEncabezado();

        cout << "1. Registrar producto\n";
        cout << "2. Listar productos\n";
        cout << "3. Salir\n";
        cout << "\nSeleccione una opcion: ";
        cin >> opcion;

        switch(opcion) {

            case 1:
                registrarProducto();
                break;

            case 2:
                listarProductos();
                break;

            case 3:
                cout << "\nPrograma finalizado.\n";
                break;

            default:
                cout << "\nOpcion invalida.\n";
        }

    } while(opcion != 3);
}


void registrarProducto() {

    Producto producto;

    ofstream archivo("productos.dat", ios::binary | ios::app);

    if(!archivo) {
        cout << "\nError al abrir el archivo.\n";
        return;
    }

    cout << "\n========== REGISTRO DE PRODUCTO ==========\n";

    cout << "Codigo: ";
    cin >> producto.codigo;
    cin.ignore();

    cout << "Nombre: ";
    cin.getline(producto.nombre, 40);

    cout << "Categoria: ";
    cin.getline(producto.categoria, 30);

    cout << "Stock: ";
    cin >> producto.stock;

    cout << "Precio: ";
    cin >> producto.precio;

    producto.activo = true;

    
    archivo.write((char*)&producto, sizeof(producto));

    archivo.close();

    cout << "\nProducto registrado correctamente.\n";

    pausarSistema();
}


void listarProductos() {

    Producto producto;

    ifstream archivo("productos.dat", ios::binary);

    if(!archivo) {
        cout << "\nNo existe informacion almacenada.\n";
        return;
    }

    cout << "\n========== LISTADO DE PRODUCTOS ==========\n";

    while(archivo.read((char*)&producto, sizeof(producto))) {

        if(producto.activo == true) {

            cout << "\n----------------------------------";
            cout << "\nCodigo: " << producto.codigo;
            cout << "\nNombre: " << producto.nombre;
            cout << "\nCategoria: " << producto.categoria;
            cout << "\nStock: " << producto.stock;
            cout << "\nPrecio: Q" << producto.precio;
            cout << "\nEstado: Activo";
            cout << "\n----------------------------------\n";
        }
    }

    archivo.close();

    pausarSistema();
}
