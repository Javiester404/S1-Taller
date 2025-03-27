#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int opc, cantidad = 0, venta, supply,v1,v2,v3,v4;
    float precio = 0.0, gananciaT = 0.0,descuento=20,vdescuento=0.0;
    char nombre[60], id[50];

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
        switch (opc)
        {
        case 1:
            fflush(stdin);
            printf("Ingrese el ID del producto: ");
            fgets(id, sizeof(id), stdin);
            int len1 = strlen(id);
            if (id[len1 - 1] == '\n')
            {
                id[len1 - 1] = '\0';
            }
            fflush(stdin);
            printf("Ingrese el nombre del producto: ");
            fgets(nombre, sizeof(nombre), stdin);
            int len = strlen(nombre);
            if (nombre[len - 1] == '\n')
            {
                nombre[len - 1] = '\0';
            }
            do
            {
                printf("Ingrese la cantidad en stock del producto: ");
                fflush(stdin);
                v1 = scanf("%d", &cantidad);
                if (v1 != 1)
                {
                    printf("El valor es incorrecto\n");
                }
                if (cantidad<1)
                {
                    printf("Ingrese un valor mayor que 1\n");
                }
                
            } while (v1 != 1||cantidad<1);
            do
            {
                printf("Ingrese el precio unitario del producto: ");
                fflush(stdin);
                v2=scanf("%f", &precio);
                if (v2 != 1)
                {
                    printf("El valor es incorrecto\n");
                }
                if (precio<=0)
                {
                    printf("Ingrese un valor positivo\n");
                }
                
            } while (precio <= 0||v2!=1);

            break;

        case 2:
            if (precio == 0)
            {
                printf("------Ingrese un producto primero------");
                break;
            }
            do
            {
                printf("\nIngrese las unidades a vender: ");
                fflush(stdin);
                v4 = scanf("%d", &venta);
                if (venta < 1)
                {
                    printf("El valor de las unidades a vender es incorrecto, porfavor ingrese de nuevo\n");
                }
                if (venta > cantidad)
                {
                    printf("No hay suficiente stock para realizar la venta, porfavor ingrese de nuevo\n");
                }
                if (v4 != 1)
                {
                    printf("El valor es incorrecto, ingrese un numero\n");
                }
            } while (venta > cantidad || venta < 1 || v4 != 1);

            if (venta > 20)
            {
                vdescuento = (descuento / 100) * precio;
                printf("El valor del descuento por comprar mas de 20 unidades es: %.2f\n", vdescuento);
            }
            else{
                vdescuento=0;
            }

            cantidad -= venta;
            gananciaT += venta * (precio - vdescuento);

            break;

        case 3:
            if (precio == 0)
            {
                printf("------Ingrese un producto primero------");
                break;
            }
            else
            {
                do
                {
                    printf("\nIngrese las unidades a reabastecer: ");
                    fflush(stdin);
                    v3=scanf("%d", &supply);
                    if (supply<=0)
                    {
                        printf("Ingrese un numero valido");
                    }
                    if (v3 != 1)
                {
                    printf("El valor es incorrecto\n");
                }
                    
                } while (supply <= 0||v3!=1);
                cantidad += supply;
            }
            break;

        case 4:
            if (precio == 0)
            {
                printf("------Ingrese un producto primero------");
                break;
            }
            printf("\nInformacion del producto:\n");
            printf("ID: %s\n", id);
            printf("Nombre: %s\n", nombre);
            printf("Stock disponible: %d\n", cantidad);
            printf("Precio unitario: %.2f\n", precio);
            break;

        case 5:
            if (precio == 0)
            {
                printf("------Ingrese un producto primero------");
                break;
            }
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

