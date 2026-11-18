#include <stdio.h>
#include <stdlib.h>
#include <matriz.h>

int AsignarMemoria(Matriz_t *m, int renglones, int columnas)
{
    int i, j;

    m->Renglones = 0;
    m->Columnas = 0;
    m->Valores = NULL;

    if (renglones <= 0 || columnas <= 0)
        return 0;

    m->Valores = (float **)malloc(renglones * sizeof(float *));
    if (m->Valores == NULL)
        return 0;

    for (i = 0; i < renglones; i++)
    {
        m->Valores[i] = (float *)malloc(columnas * sizeof(float));
        if (m->Valores[i] == NULL)
        {
            for (j = 0; j < i; j++)
                free(m->Valores[j]);
            free(m->Valores);
            m->Valores = NULL;
            return 0;
        }
    }

    m->Renglones = renglones;
    m->Columnas = columnas;
    return 1;
}

void CapturarValores(Matriz_t *m)
{
    int i, j;

    if (m->Valores == NULL)
    {
        printf("La matriz no existe.\n");
        return;
    }

    for (i = 0; i < m->Renglones; i++)
    {
        for (j = 0; j < m->Columnas; j++)
        {
            printf("Elemento [%d][%d]: ", i + 1, j + 1);
            scanf("%f", &m->Valores[i][j]);
        }
    }
}

void DesplegarMatriz(const Matriz_t *m)
{
    int i, j;

    if (m->Valores == NULL)
    {
        printf("(matriz vacia)\n");
        return;
    }

    for (i = 0; i < m->Renglones; i++)
    {
        for (j = 0; j < m->Columnas; j++)
            printf("%8.2f", m->Valores[i][j]);
        printf("\n");
    }
}

Matriz_t MultiplicarMatrices(const Matriz_t *a, const Matriz_t *b)
{
    Matriz_t r = {0, 0, NULL};
    int i, j, k;

    if (a->Valores == NULL || b->Valores == NULL || a->Columnas != b->Renglones)
        return r;

    if (!AsignarMemoria(&r, a->Renglones, b->Columnas))
        return r;

    for (i = 0; i < r.Renglones; i++)
    {
        for (j = 0; j < r.Columnas; j++)
        {
            r.Valores[i][j] = 0;
            for (k = 0; k < a->Columnas; k++)
                r.Valores[i][j] += a->Valores[i][k] * b->Valores[k][j];
        }
    }
    return r;
}

void LiberarMatriz(Matriz_t *m)
{
    int i;

    if (m->Valores != NULL)
    {
        for (i = 0; i < m->Renglones; i++)
            free(m->Valores[i]);
        free(m->Valores);
    }
    m->Valores = NULL;
    m->Renglones = 0;
    m->Columnas = 0;
}
