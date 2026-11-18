#include <stdio.h>
#include <matriz.h>

/* Elimina la matriz existente, pide dimensiones, crea la nueva y captura valores */
static void CapturarMatriz(Matriz_t *m, char nombre)
{
    int r, c;

    LiberarMatriz(m);

    printf("Matriz %c - Renglones: ", nombre);
    scanf("%d", &r);
    printf("Matriz %c - Columnas: ", nombre);
    scanf("%d", &c);

    if (!AsignarMemoria(m, r, c))
    {
        printf("No se pudo crear la matriz (dimensiones invalidas o sin memoria).\n");
        return;
    }
    CapturarValores(m);
}

int main(void)
{
    Matriz_t A = {0, 0, NULL};
    Matriz_t B = {0, 0, NULL};
    Matriz_t R;
    int opcion;

    do
    {
        printf("\n===== MENU =====\n");
        printf("1. Capturar matriz A\n");
        printf("2. Capturar matriz B\n");
        printf("3. Desplegar matrices\n");
        printf("4. Multiplicar matrices\n");
        printf("5. Terminar programa\n");
        printf("Opcion: ");
        if (scanf("%d", &opcion) != 1)
        {
            while (getchar() != '\n');
            opcion = 0;
        }

        switch (opcion)
        {
        case 1:
            CapturarMatriz(&A, 'A');
            break;
        case 2:
            CapturarMatriz(&B, 'B');
            break;
        case 3:
            printf("\nMatriz A (%dx%d):\n", A.Renglones, A.Columnas);
            DesplegarMatriz(&A);
            printf("\nMatriz B (%dx%d):\n", B.Renglones, B.Columnas);
            DesplegarMatriz(&B);
            break;
        case 4:
            if (A.Valores != NULL && B.Valores != NULL && A.Columnas == B.Renglones)
            {
                R = MultiplicarMatrices(&A, &B);
                printf("\nMatriz A*B (%dx%d):\n", R.Renglones, R.Columnas);
                DesplegarMatriz(&R);
                LiberarMatriz(&R);
            }
            else
            {
                printf("Error: matrices incompatibles (columnas de A debe ser igual a renglones de B) o no capturadas.\n");
            }
            break;
        case 5:
            LiberarMatriz(&A);
            LiberarMatriz(&B);
            printf("Programa terminado.\n");
            break;
        default:
            printf("Opcion invalida.\n");
        }
    } while (opcion != 5);

    return 0;
}
