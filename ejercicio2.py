# -*- coding: utf-8 -*-
"""ejercicio2.ipynb

Automatically generated by Colaboratory.

Original file is located at
    https://colab.research.google.com/drive/1b3cV19aIlXbRxESM7EuO41V0GKaWWGw5
"""

import re
import numpy as np
import multiprocessing as mp

def pal(frase):
    palabras = frase.split(" ")
    grupo1 = []
    grupo2 = []
    for i in range(len(palabras)):
        if i % 2 == 0:
            grupo1.append(palabras[i])
        else:
            grupo2.append(palabras[i])
    return grupo1, grupo2

frase = "tres tristes tigres trigaban trigo por culpa del bolivar"

with mp.Pool(processes=2) as pool:
    resultados = pool.map(pal, [frase])
for grupo1, grupo2 in resultados:
    print("Grupo 1:", grupo1)
    print("Grupo 2:", grupo2)
