import os
import sys
import logging

# ñoñerias
p = os.path.abspath('../../Utils')
if p not in sys.path:
    sys.path.append(p)

from utils import print_logo

def BUSCA_LIN(A, k, comp):
    '''
    Busqueda lineal de un número en un arreglo.
    A: Arreglo de números
    k: número entero a buscar
    comp: booleano de comparaciones
    Returns: if comp == True =>  Número de comparaciones
             if comp == False => Posición arreglo 
    '''
    contador_comparaciones = 0
    pos = -1
    for pos_arr, item in enumerate(A):
        contador_comparaciones += 1
        if item == k:
           pos = pos_arr
           break
    if comp:
        return contador_comparaciones
    return pos

def BUSCA_BIN(A, k, comp):
    '''
    Busqueda binaria de un número en un arreglo.
    A: Arreglo de números
    k: número entero a buscar
    comp: booleano de comparaciones
    Returns: if comp == True =>  Número de comparaciones
             if comp == False => Posición arreglo
    '''
    inicio = 0
    final = len(A) - 1
    contador_comparaciones = 0
    pos = -1
    while inicio <= final:
        contador_comparaciones += 1
        mitad = (inicio + final) // 2
        if A[mitad] == k:
            pos = mitad
            break
        elif A[mitad] > k:
            inicio = mitad + 1
        else:
            final = mitad - 1
    if comp:
        return contador_comparaciones
    return pos

def abrir_archivo(nombre):
    arr = []
    logging.info("Abriendo archivo {}".format(nombre))
    with open(nombre, 'r') as file:
        for line in file:
            arr.append(int(line))
    logging.info("Arreglo tiene {} datos".format(len(arr)))
    return arr

def menu():
    print('##########  Tarea 1 ################')
    print('Elige una de las siguientes soluciones: ')
    print('Ingresa 1 Si quieres probar todos los casos de correción')
    print('Ingresa 0 Si quieres salir')

def test():
    print("NUMEROS A BUSCAR: 1, 10, 68, 99")
    a_buscar = [1, 10, 68, 99]
    for i in range(4):
        print('\n\n ########## TEST {} ##########\n\n'.format(i))
        name_file = 't_{}.txt'.format(i+1)
        array = abrir_archivo(name_file)
        print("El contenido del arreglo es: {}".format(array))
        print(' -------- BUSQUEDA LINEAL --------')
        for k in a_buscar:
            print('Cantidad de comparaciones caso k={}: {}'.format(k, BUSCA_LIN(array, k, True)))
            print('Posición del entero caso k={}: {}'.format(k, BUSCA_LIN(array, k, False)))
            print(' ')
        print(' -------- BUSQUEDA BIN --------')
        for k in a_buscar:
            print('Cantidad de comparaciones caso k={}: {}'.format(k, BUSCA_BIN(array, k, True)))
            print('Posición del entero caso k={}: {}'.format(k, BUSCA_BIN(array, k, False)))
            print(' ')
if __name__ == '__main__':
    print_logo()
    while True:
        menu()
        x = input("---> ")
        if x == '1':
            test()
        elif x == '0':
            break
    