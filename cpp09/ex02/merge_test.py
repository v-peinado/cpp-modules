import subprocess # Para ejecutar el programa PmergeMe
import sys       # Para obtener argumentos de línea de comandos
import re       # Para buscar decimales en la salida

# Definición de colores
COLOR_SUCCESS = "\033[32m"  # Verde
COLOR_FAILURE = "\033[31m"  # Rojo
COLOR_DEFAULT = "\033[0m"   # Sin color

def print_in_color(color_code, text): # Función para imprimir texto con color
    print(f"{color_code}{text}{COLOR_DEFAULT}") # Imprime el texto con el color especificado, la f y las llaves son para formatear el texto y que se imprima en color
    
# Verifica si el nombre del ejecutable está definido
if len(sys.argv) < 2: # Si no se proporciona el nombre del ejecutable
    print("Usage: python3 script.py <path-to-executable>") # Imprime el mensaje de uso
    sys.exit(1) # Sale del programa con código de error 1

# El nombre del ejecutable
EXECUTABLE = sys.argv[1] # Obtiene el nombre del ejecutable de la línea de comandos

print("------------------------------------")
print("          Failing test.")
print("------------------------------------")

# Lista de entradas que se espera que fallen
failing_tests = [
    "1 2 3 4 5",
    "3 4 1 1",
    "6 -1 1",
    "8 7 1a",
    "2 3 4 * +",
    "1",
    "",
    "2 1 3333333333333333333333333",
    "0.1 0 2"
]

for expr in failing_tests:
    result = subprocess.run([EXECUTABLE, expr], capture_output=True, text=True)
    erroutput = result.stderr.strip()
    
    if erroutput:
        print_in_color(COLOR_SUCCESS, f"Test passed (correctly failed): {expr}")
        print_in_color(COLOR_FAILURE,f"-->Output from program: {erroutput}")

