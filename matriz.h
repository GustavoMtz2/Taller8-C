#ifndef MATRIZ_H
#define MATRIZ_H

/* Matriz dinámica de números flotantes */
typedef struct
{
    int Renglones;      /* Cantidad de renglones */
    int Columnas;       /* Longitud de los renglones */
    float **Valores;    /* Apuntador doble: dirección del primer renglón de elementos */
} Matriz_t;

/* Reserva memoria dinámica para Renglones x Columnas elementos.
   Retorna 1 si tuvo éxito, 0 si falló. */
int AsignarMemoria(Matriz_t *m, int renglones, int columnas);

/* Captura los valores de los elementos de la matriz */
void CapturarValores(Matriz_t *m);

/* Despliega los elementos de la matriz como tabla */
void DesplegarMatriz(const Matriz_t *m);

/* Multiplica 2 matrices dinámicas y retorna el resultado en una matriz.
   Si no son compatibles, retorna una matriz con Valores NULL y dimensiones 0. */
Matriz_t MultiplicarMatrices(const Matriz_t *a, const Matriz_t *b);

/* Libera la memoria de la matriz, asigna NULL al apuntador y 0 a sus dimensiones */
void LiberarMatriz(Matriz_t *m);

#endif
