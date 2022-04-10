#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// Constantes a incluir
#define LIMIT 5000
// Prototipado de funciones
short leerArchivo(char*, char*);
short escribirArchivo(char*);

// Funcion Principal
int main(void)
{
    char fichero_entrada[] = "./analizadorLexico/fuentes/fuente.txt";
    char fichero_salida[] = "./analizadorLexico/fuentes/output.txt";

    char cadena[LIMIT];
    char cadena2[LIMIT];
    short res = leerArchivo(cadena, fichero_entrada);
    
    // Si ocurren errores en la lectura del archivo, se cierra el programa.
    if(res == -1){
        printf("Ocurrio un error al intentar abrir archivo\n");
        exit(-1);
    }

    res = leerArchivo(cadena2, fichero_salida);

    if(res == -1){
        printf("Ocurrio un error al intentar abrir archivo\n");
        exit(-1);
    }

    res = escribirArchivo(cadena2);
    if(res == -1){
        printf("NO se pudo escribir en el archivo.\n");
        exit(-1);
    }

    return 0;
}

/**
 * @brief Funcion que lee un archivo, y guarda el contenido dentro de una cadena.
 * 
 * @author Lucas Vega.
 * @param cadena Cadena donde se guardaran todas las lineas extraidas del archivo. 
 * @param nombre Ubicacion del fichero a leer.
 * @return short Retorna 0 si la lectura fue exitosa, -1 si ocurrio un error.
 */
short leerArchivo(char* cadena, char* nombre){
    FILE *fichero;
    fichero = fopen(nombre, "r");
    char aux[LIMIT];
    if (fichero == NULL)
    {
        printf("No se pudo abrir el archivo.\n");
        return -1;
    } else {
        while(fgets(aux, LIMIT, fichero) != NULL ){
            strcat(cadena, aux);
        }
        fclose(fichero);
        return 0;        
    }
}


/**
 * @brief Funcion que crea un archivo y escribe una cadena en el mismo.
 * @author Lucas Vega 
 * 
 * @param cadena Cadena que se va a escribir en el archivo.
 * @return short 0 si fue exitoso, -1 si ocurrio un error.
 */
short escribirArchivo(char* cadena){
    FILE *fichero;
    fichero = fopen("output.txt", "w");
     if (fichero == NULL)
    {
        printf("No se pudo abrir el archivo.\n");
        return -1;
    } else {
        fputs(cadena, fichero);
        fclose(fichero);
        return 0;        
    }
    return 0;
}