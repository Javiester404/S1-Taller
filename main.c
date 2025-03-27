#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int opc, id, cantidad = 0, venta, supply;
    float precio = 0.0, gananciaT = 0.0;
    char nombre[60];

    do {
        printf("\t\n***Seleccione una opcion***\n");
        printf("1. Registrar producto\n");
        printf("2. Vender producto\n");
        printf("3. Reabastecer el producto\n");
        printf("4. Consultar informacion\n");
        printf("5. Mostrar ganancias\n");
        printf("6. Salir\n");
        printf(">>>>> ");
        scanf("%d", &opc);
        switch (opc) {
        case 1:
            printf("Ingrese el ID del producto: ");
            scanf("%d", &id);
            fflush(stdin);
            printf("Ingrese el nombre del producto: ");
            fgets(nombre, sizeof(nombre), stdin);
            int len = strlen(nombre);
            if (nombre[len - 1] == '\n') {
                nombre[len - 1] = '\0';}
            printf("Ingrese la cantidad en stock del producto: ");
            scanf("%d", &cantidad);
            do {
                printf("Ingrese el precio unitario del producto: ");
                scanf("%f", &precio); 
            } while(precio<=0);
            
            break;

        case 2:
            printf("\nIngrese las unidades a vender: ");
            scanf("%d", &venta);
            if (venta > cantidad) {
                printf("No hay suficiente stock para realizar la venta.\n");
            } else {
                cantidad -= venta;
                gananciaT += venta * precio;
            }
            break;

        case 3:
            if (precio==0)
            {
                printf("------Ingrese un producto primero------");
                break;
            }
            else{
            do {
                printf("\nIngrese las unidades a reabastecer: ");
                scanf("%d", &supply); 
            } while(supply<=0);
            cantidad += supply;}
            break;

        case 4:
            printf("\t\nIngrese el ID del producto a consultar: ");
            scanf("%d", &id);
            printf("\nInformacion del producto:\n");
            printf("ID: %d\n", id);
            printf("Nombre: %s\n", nombre);
            printf("Stock disponible: %d\n", cantidad);
            printf("Precio unitario: %.2f\n", precio);
            break;

        case 5:
            printf("\nLas ganancias totales obtenidas hasta el momento son: $%.2f\n", gananciaT);
            break;

        case 6:
            printf("\n**Gracias por usar el programa**\n");
            break;

        default:
            printf("Opcion no valida. Intente de nuevo.\n");
            break;
        }

    } while (opc != 6);
    
    return 0;
}

