###UNO – C++23
Proyecto de juego de cartas desarrollado en C++23, organizado en una arquitectura por capas (domain, application, core, infrastructure) y compilado con CMake 3.26 o superior.
Incluye estructuras de datos implementadas manualmente (listas enlazadas simples, dobles, circulares y pila), motor de juego, manejo de excepciones y utilidades auxiliares.

Requisitos:
- CMake ≥ 3.26
- Compilador con soporte para C++23
- GCC 13 o superior recomendado
- Clang 16 o superior recomendado
- Sistema Linux o macOS recomendado (por soporte de sanitizers)

Verificar versiones instaladas:
- cmake --version
- g++ --version
- clang++ --version
- Configuración del proyecto

El proyecto define:
- Estándar: C++23
- Flags de compilación:
- fsanitize=address,undefined
-fno-omit-frame-pointer
-g (símbolos de depuración)

Se genera un ejecutable llamado:
SourceCode
Compilación

1. Clonar el repositorio
git clone https://github.com/tu-usuario/tu-repo.git
cd tu-repo

3. Crear directorio de build
mkdir build
cd build

5. Generar el sistema de construcción
cmake ..
Si se desea especificar compilador:
cmake -DCMAKE_CXX_COMPILER=g++ ..
o
cmake -DCMAKE_CXX_COMPILER=clang++ ..
4. Compilar
cmake --build .
o alternativamente:
make

Ejecución
Desde el directorio build:
./SourceCode
Sanitizers

El proyecto está configurado para utilizar:
AddressSanitizer (ASan) para detección de errores de memoria.
UndefinedBehaviorSanitizer (UBSan) para detectar comportamiento indefinido.
En caso de errores, se mostrará un reporte detallado en consola durante la ejecución.

Estructura del proyecto:
.
├── src/
│   ├── application/
│   ├── core/
│   ├── domain/
│   └── infrastructure/
├── include/
│   └── card_game/
├── CMakeLists.txt

Organización por capas

- domain: Entidades principales como Card, Deck y Player.
- application: Lógica de juego y motor de ejecución.
- core: Estructuras de datos, utilidades y excepciones.
- infrastructure: Interacción con el usuario y visualización.

- Depuración
El proyecto se compila con símbolos de depuración (-g). Para usar gdb:
gdb ./SourceCode

Notas
Se genera un único ejecutable.
La configuración actual está orientada a entorno de desarrollo (debug).
En Windows con MSVC los sanitizers no están disponibles por defecto.
