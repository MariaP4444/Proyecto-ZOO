
## Funcionamiento del programa

En este proyecto, se implementa un programa en C++ que simula el funcionamiento de un zoológico. 

El programa cuenta con 3 clases:

- Clase Zoo = Esta es la clase contenedora, en la cual se basa todo el sistema, dentro de ella guardamos y añadimos hábitats.
- Clase Habitat = Esta clase también es una clase contenedora de la clase Animal.
- Clase Animal = Esta clase representa la plantilla para crear más animales para nuestro zoológico.

Durante toda la ejecución de nuestro programa estas clases interactúan entre ellas. Al iniciar el programa este rectifica si ya ha creado por lo menos un hábitat, después de esta rectificación el programa puede tomar dos posibles caminos:

<br>

### **CAMINO 1- no hay hábitats creados**

Si no hay hábitats todavía en nuestro zoológico, el programa solo le habilita al usuario dos opciones, las cuales son:

- ***Agregar un hábitat***: Si el usuario escoge esta opción, el programa le pedirá:

  - Nombre: Hace referencia al nombre del hábitat.
  
  - tMax:Hace referencia a la temperatura máxima del hábitat.
  
  - tMin: Hace referencia a la temperatura mínima del hábitat.

El programa se encarga de revisar si en la lista de hábitats disponibles ya se encuentra un hábitat con las mismas características, si ya existe uno similar, el hábitat nuevo no es creado y se le informal usuario que ya hay un hábitat existente 

- Salir: como se indica, esta opción permite acabar con la ejecución del programa.

<br>

### **CAMINO 2- si hay hábitats creados**

Esta ruta, a diferencia de la otra, le brinda al usuario otras opciones, además de las ya mencionadas.

- ***Agregar animal***: Esta opción le permite agregar un nuevo animal al zoológico, para ello se le pide al usuario lo siguiente 

  - tempMinA: Hace referencia a la temperatura mínima que soporta el animal 

  - tempMaxA: Hace referencia a la temperatura máxima que soporta el animal
  
  Antes de continuar pidiéndole datos al usuario, se mira en el sistema si ya existe un hábitat adecuado para el animal, si no lo hay se le notifica al usuario que     debe primero crear un hábitat en el que pueda permanecer el animal y luego regresar y hacer el ingreso del animal, en cambio, si ya hay al menos un hábitat           disponible para el animal, se le pide que seleccione uno de los hábitats disponibles para el animal para continuar pidiéndole datos al usuario con respeto al         animal, todo este proceso se realiza en el main, sin embargo, de aquí en adelante la clase hábitat es la encargada de realizarlo.
  
  - nombreTemp: Hace referencia al nombre del animal 
  
  - especie: Hace referencia al tipo de especie del animal
  
  - estadoDeSalud:Hace referencia al estado de salud del animal
  
  - edad: Hace referencia a la edad del animal
  
  - cantMaxDormir: Hace referencia a la cantidad de horas de sueño de un animal
  
  - juguetes: Hace referencia a cuantos y cuáles juguetes se agregara al vector que tiene el animal

  - alimentacion: Hace referencia a qué tipo de dieta va a llevar el animal. Ahora para la recolección de datos se encargará la clase animal, según el tipo de           alimentacion se le piden las cantidades que debe comer el animal según el alimento.

<br>

### Alimentación de un animal:

Cada animal tiene una dieta personalizada, esta se maneja en el mapa no ordenado “alimentos” de esta forma:

clave: un string que corresponde al nombre del alimento.

valor: un int que corresponde a el número de kg que el animal debe comer de dicho alimento.

Un animal puede tener uno de los siguientes tipos de alimentación: herbívora, carnívora y omnívora. Esta es asignada por el usuario al crear el animal, y según cada tipo, se añaden algunos alimentos por defecto, y sus cantidades son pedidas al usuario.

La cantidad de kg que corresponden a cada alimento se puede editar en la opción “Modificar información de animal”. Para agregar un alimento, usamos los vectores “dietaCarnivora” y “dietaHervibora” de la clase “Zoo” los cuales contienen potenciales alimentos para agregar a cada animal según su dieta. De este modo, podemos agregar y eliminar alimentos en la opción “Visitar hábitat”.

Por último, los booleanos de juegos y comer comienza en falso, y el contador de horas dormidas por día en 0, ya que suponemos que el animal no ha comido ni jugado ni dormido una vez ingresado al zoo se crea el animal y se agrega en el hábitat elegido

<br>

- ***Lista de habitats y animales***: si el usuario escoge esta función, el sistema le listará los hábitats disponibles con su información (nombre, temperatura máxima y temperatura mínima); esto lo realiza mediante el método de la clase Zoo “listarHabitatsConAnimales” la cual recorre el vector de habitats y luego con el puntero de hábitat se muestran los animales pertenecientes a este, sé mostrar toda la información que sabemos del animal (nombre, id, estado de salud, etc.); esto lo realiza mediante el método de la clase Habitat “infoCompletaAn”


- ***Modificar información de animal***: Esta opción dirige a la función “cuartaOpcion”. En esta, se le pedirá al usuario ingresar el nombre del hábitat del animal, y se le presentará la información básica de los animales de dicho hábitat. A continuación, el usuario escribe el ID del animal deseado. Después se dirige a la función “menuAnimal” de la clase Animal, en donde se presentan en forma de menú los datos que puede cambiar el usuario, los cuales son:

 1. Edad: Actualiza la edad. Se verifica que la edad sea mayor a la anterior, y que sea menor de 100.
 2. Estado de salud: se ingresa un string y se actualiza el estado de salud.
 3. Horas de sueño máximas: Actualiza la cantidad de horas que un animal puede dormir por día. Se verifica que sea al menos una hora.
 4. Cantidad de kg en dieta: Actualiza la cantidad de kg de un alimento específico que puede comer el animal. Se presentan cada uno de los alimentos (en orden de        agregación) y el usuario decide editarlo o dejarlo como estaba. Se verifica que sea al menos 1 kg por alimento.
 5. Agregar juguetes: Agrega juguetes al vector “juguetes” del animal. Se pide al usuario la cantidad de juguetes a ingresar y verifica que sea al menos uno. A          continuación, se pide ingresar cada uno de los nombres de los juguetes dependiendo de la cantidad ingresada.
 6. Eliminar juguete: Elimina un juguete del vector “juguetes” del animal. Se ingresa el nombre del juguete a eliminar e imprime un mensaje.
 7. Agregar alimento: En primer lugar, se identifica el tipo de dieta del animal. Si es carnívoro o herbívoro, se dirige a la función “agregarAlimento”. Donde se        verifica si el animal tiene en su vector “alimentos” todos los alimentos disponibles de su tipo de alimentación. En caso positivo, se imprime un mensaje y            vuelve al menú. En caso negativo, se ingresa el alimento deseado, se verifica si pertenece al tipo de alimentación correspondiente, y se verifica si ya estaba        agregado. Este mismo procedimiento en la función “agregarAlimOmn” pero incluyendo las dietas de herbívoro y carnívoro.
 8. Eliminar alimento: Elimina un alimento de la dieta del animal. Se ingresa el alimento a eliminar y se verifica que el alimento se halle en el vector                “alimentos” del animal.
  
- ***Visitar hábitat***: Esta opción representa la interacción con un animal, es decir, darle órdenes al animal, las cuales son: comer, dormir, y jugar. Esta busca al animal con la función “cuartaOpcion”, y gracias a un condicional que nos permite saber que estamos en la quinta opción, pide al usuario ingresar la actividad que quiere hacer con el animal. Luego, nos dirige a la función “interactAnimal” de la clase animal, en la cual se realizará una de las siguientes actividades:

1. Jugar: Para jugar, el animal cuenta con un vector tipo string de juguetes. Los cuales se pueden agregar o eliminar en la opción “Modificar información de animal”.
Se verifica si el animal ya ha jugado el día de hoy. En caso negativo, se le presenta al usuario la lista de juguetes del animal e ingresa un número para escoger uno de ellos. 

2. Comer: Se verifica que el animal no haya comido en el día, luego se ingresa un alimento y se verifica que exista en la dieta del animal. Se ingresa la cantidad de kg y se verifica que sea la establecida por el mapa.

3. Dormir: Se verifica si el animal ya durmió el máximo de horas permitidas. En caso negativo, se ingresa el número de horas y se verifica que no excedan el máximo permitido.

En los tres casos se envían mensajes confirmando o negando si se realizó la acción.

Pruebas del funcionamiento de [Proyecto Zoo](https://docs.google.com/document/d/1W198tO81pz3dJOqBWjtysm2cVstQITECEUdDgRzavBQ/edit?usp=sharing)

[Diagrama de clases](https://javerianacaliedu-my.sharepoint.com/:u:/g/personal/vfgustin_javerianacali_edu_co/EQAyT3xCJ3BNoPLRaXTLLlABR6wN6kKZpJffcS8LYm14xQ?e=e9QAbu)
