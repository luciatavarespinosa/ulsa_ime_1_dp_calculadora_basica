# Práctica 4: Calculadora básica

> **Las secciones 1 a 6 ya están resueltas por el profesor.** Léelas con atención, pero no las modifiques. Tu trabajo empieza en la sección 7.

## 1. Descripción del problema (Fase 1, resuelta)

El programa muestra un menú con cuatro operaciones (suma, resta, multiplicación y división). El usuario elige una, escribe dos números y el programa muestra el resultado de la operación. Es la base de cualquier calculadora y del tipo de menú que se usa, por ejemplo, en el panel de control de una máquina.

## 2. Entradas y salidas (Fase 1, resuelta)

**Entradas:**
1. `opcion` (`int`): la operación elegida, de 1 a 4. Se lee con `leerEntero`.
2. `a` (`double`): el primer número. Se lee con `leerDecimal`.
3. `b` (`double`): el segundo número. Se lee con `leerDecimal`.

**Salidas:**
1. `resultado` (`double`): el resultado de la operación.
2. Se muestra en la forma `a símbolo b = resultado`, por ejemplo `7 / 2 = 3.5`. El símbolo se guarda en `simbolo` (`char`).

**Operaciones:** 1) `a + b`   2) `a - b`   3) `a * b`   4) `a / b`

## 3. Restricciones e invariante (Fases 1 y 2, resuelta)

**Restricciones:**
- La opción debe estar entre 1 y 4. Si no, el programa la vuelve a pedir.
- Si la operación es división, `b` no puede ser 0. Si lo es, el programa vuelve a pedir solo `b`.
- En la resta y en la división el orden importa: siempre se calcula `a` op `b`.

**¿Quién detecta cada error?**
- `leerEntero` y `leerDecimal` detectan el **formato**: texto (`abc`) o, en el caso de `leerEntero`, decimales (`2.5`).
- El programa detecta el **rango**: una opción fuera de 1 a 4 y un divisor igual a 0.

**Invariante:** al llegar al Paso 7 (el cálculo), `opcion` está entre 1 y 4 y, si la opción es 4 (división), `b` es distinto de 0. Por eso el cálculo siempre es válido.

## 4. Casos resueltos a mano (Fase 1, resuelta)

| Caso | Opción | a | b | Resultado |
|---|---|---|---|---|
| 1 | 1 (suma) | 8 | 5 | 8 + 5 = 13 |
| 2 | 2 (resta) | 3 | 5 | 3 - 5 = -2 |
| 3 | 3 (multiplicación) | 2.5 | 4 | 2.5 * 4 = 10 |
| 4 | 4 (división) | 7 | 2 | 7 / 2 = 3.5 |
| 5 | 4 (división) | 5 | 0, luego 2 | vuelve a pedir `b`; 5 / 2 = 2.5 |

## 5. Receta en pseudocódigo (Fase 2, resuelta)

La receta completa está en el archivo `RECETA.md`. No la modifiques: si encuentras algo que no contempla, anótalo en la sección 11.

## 6. Cómo compilar y ejecutar (Fase 3)

```bash
g++ -Wall -Wextra -std=c++17 main.cpp -o calculadora
./calculadora
```

## 7. Ejemplo de ejecución (Fase 3)
<!-- Pega aquí lo que muestra tu programa en pantalla con una división donde primero escribes 0 como segundo número. -->
Calculadora b├ísica
Ingresa el primer n├║mero: 1
Ingresa el segundo n├║mero: 1
Selecciona una operacion: 
1.Suma 
2.Resta 
3.Multiplicacion 
4.Division 
Ingresa tu opci├│n: 1
El resultado de la suma es: 2
_____
```
_____
```

## 8. De la receta al código (Fase 3)
<!-- Para cada paso de la receta, escribe la instrucción (o instrucciones) de C++ que lo implementa. -->

| Paso de la receta | Instrucción de C++ que lo implementa |
|---|---|
| 1 y 2. Título y menú | _cout<< "Calculadora básica\n";____ |
| 3. Leer y validar la opción | _cout<< "Selecciona una operacion: \n";____ |
| 4 y 5. Leer `a` y `b` | cout<< "Ingresa el primer número: ";_____ |
| 6. Validar el divisor | if(numero2 == 0){ cout<< "Error: No se puede dividir entre cero." << endl; | 
| 7. Decisión múltiple (un case) | switch(opcion){ case 1: |
| 8. Mostrar el resultado | cout<< "El resultado de la suma es: " |

**¿Hubo algún paso de la receta que te costó traducir a C++? ¿Cuál y por qué?**
___La parte del case, para seleccionar la opcion de operación__

## 9. Experimentos (Fase 3)

Experimento A: sin el break del case 1, ¿qué mostró el programa con 8 + 5? ¿Qué te dijo el compilador? ¿Por qué pasó? Dio el resultado de la suma y de la resta, me advirtió sobre una posible falla, porque el break no detuvo la operacion en la suma y siguio hasta la resta

Experimento B: sin la validación del Paso 6, ¿qué mostró el programa con 5 / 0? ¿Tiene sentido? va a mostrar "Error: No se puede dividir entre 0". Si

Experimento C (opcional): con a y b de tipo int, ¿qué resultado dio 7 / 2? ¿Te avisó el compilador?

## 10. Tabla de pruebas (Fase 4)

| Caso | Entradas (opción, a, b) | Esperado | Obtenido | ¿Pasó? |
|---|---|---|---|---|
| Suma | 1, 8, 5 | 8 + 5 = 13 | ___13__ | __si___ |
| Resta negativa | 2, 3, 5 | 3 - 5 = -2 | __-2___ | __si___ |
| Multiplicación con decimales | 3, 2.5, 4 | 2.5 * 4 = 10 | __10___ | __si___ |
| Multiplicación con negativo | 3, -3, 4 | -3 * 4 = -12 | __-12___ | ___si__ |
| División | 4, 7, 2 | 7 / 2 = 3.5 | ___si__ | ____si_ |
| Dividendo cero | 4, 0, 5 | 0 / 5 = 0 | __si___ | __si___ |
| Divisor cero | 4, 5, 0 (luego 2) | vuelve a pedir `b`; 5 / 2 = 2.5 | ___si__ | __si___ |
| Suma con cero | 1, 5, 0 | 5 + 0 = 5 (**no** vuelve a pedir `b`) | __5___ | _____ |
| Opción fuera de rango | 5 (luego 1), 8, 5 | vuelve a pedir la opción; 8 + 5 = 13 | si_____ | _____ |
| Opción cero | 0 (luego 1), 8, 5 | vuelve a pedir la opción; 8 + 5 = 13 | __si___ | si_____ |
| Opción decimal | 2.5 (luego 2), 3, 5 | `leerEntero` vuelve a pedir; 3 - 5 = -2 | me da resta_____ | _____ |
| Opción con texto | `suma` (luego 1), 8, 5 | `leerEntero` vuelve a pedir; 8 + 5 = 13 | __si___ | _____ |
| Número con texto | 1, `abc` (luego 8), 5 | `leerDecimal` vuelve a pedir; 8 + 5 = 13 | _si____ | _____ |
| Caso propio 1 | ___2__ | ___34-56__ | __-22___ | _____ |
| Caso propio 2 | ___4__ | __87/3___ | __29___ | _____ |

## 11. Bitácora de mejoras (Fase 4)

| # | ¿Qué falló o qué quise mejorar? | ¿Qué cambié? | ¿Funcionó? |
|---|---|---|---|
| 1 | __lo de los numeros que apareciera el texto ___ | _____ | _____ |
| 2 | _____ | _____ | _____ |

**¿Encontré algo que la receta no contemplaba? ¿Qué?**
_____

**Reto elegido (opcional):** _____

## 12. Dudas para el profesor (Fase 3)

| Duda | Lo que ya intenté |
|---|---|
| _____ | _____ |

## 13. Reflexión final

**¿Qué aprendí con esta práctica?**
_____ah hacer bien el codigo

**Ahora que terminé, ¿qué cambiaría de mi proceso?**
_____
el modo de entender para hacerl el codigo
**¿Qué fue lo más difícil y cómo lo resolví?**
_____el q no se me olvidara a poner ;  

**¿Qué pregunta me quedó sin responder?**
_____
ninguna
**¿Fue más fácil programar a partir de una receta ajena que de la mía? ¿Por qué?**
_____
apartir de una receta , porque ya nomas era pensar en el codigo 
**Si yo hubiera diseñado la receta, ¿qué le cambiaría?**
_pues q fuera con variables de a y b ____

## 14. Lista de verificación antes de entregar (Fase 5)

- [ ] Llené las secciones 7 a 13 (no quedan `_____`)
- [ ] No modifiqué las secciones 1 a 6 ni la receta de `RECETA.md`
- [ ] Cada bloque de `main.cpp` tiene su comentario `// Paso N`
- [ ] Mi programa compila sin advertencias
- [ ] Probé todos los casos de la tabla
- [ ] Hice los Experimentos A y B y dejé el código correcto al terminar
- [ ] No modifiqué `utilerias.h`
- [ ] Hice al menos 4 commits con mensajes claros
- [ ] Hice `git push` y verifiqué mi fork en GitHub
- [ ] Entregué el enlace de mi fork en Classroom