# **MOTOR DE BUSQUEDA**
## Descripción general:

**Realizado 100% en C** con la capacidad de leer palabras de varios documentos de texto y cargarlas en un archivo **"Diccionario"** el cual almacena la información de cada palabra leída (N° del documento al que pertenece y el N° de la posición en dicho documento).
Luego, estas palabras son transferidas a un **"Motor"** que tiene la estructura de un **arbol binario de busqueda (ABB)**, en el cual contendra, en cada nodo, las palabras cargadas desde el diccionario (ordenadas en orden alfabetico), junto con el N° de frecuencias con las que se repite cada una, posiciones, y una **lista (simplemente enlazada)** que contendra la informacion de aquellas palabras que se repitan.

## Operaciones del usuario:
1. Buscar todas las apariciones de un termino en algun documento.
> **Descripción:** Se ingresa una palabra y esta se busca en el motor mostrando toda la informacion de la palabra encontrada en cualquiera de los documentos (Operacion OR).

2. Buscar Todas las apariciones de un termino en dos documentos especificos.
> **Descripción:** Se ingresa una palabra y 2 ID de documentos.
Solo se mostrara la informacion de la palabra si esta se encuentra en ambos documentos ingresados (Operacion AND).

3. Buscar la aparicion de mas de un termino en el mismo documento.
> **Descripción:** El usuario puede ingresar mas de una palabra y se van a buscar en el motor, mostrando la informacion de todas apariciones de las mismas en algún documento especifico.

4. Buscar una frase.
> **Descripción:** Se ingresa una frase y se busca su coincidencia en el motor basandonos en la informacion de el N° Documento y el N° posición. Se verifica que cada palabra que se ingrese sea contigua con respecto a la palabra anterior y que pertenezcan al mismo documento.

5.  Buscar la palabra de mas frecuencia en alguno de los documentos.
> **Descripción:** El usuario ingresa un N° de ID documento y se le mostrará la palabra que mas veces se repite en el mismo.

6. Sugerir palabras similares (Utilizando Levenshtein).
> **Descripcion:** Se calcula la similitud entre una palabra ingresada por el usuario y alguna palabra almacenada en el motor utilizando el algoritmo de Levenshtein el cual devuelve la distancia entre 2 palabras.
La funcion para sugerir palabras similares mostrara la informacion de aquella palabra cuya distancia con respecto a la ingresada sea <=3.

### **Imagen del menu del proyecto:**
![Motor de Busqueda (Menu)](https://user-images.githubusercontent.com/86176280/144514442-94a32cef-e37a-469f-b21f-ae884932aed8.png)
