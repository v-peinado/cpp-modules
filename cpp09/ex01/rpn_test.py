import subprocess # Para ejecutar el programa RPN
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
    print("Usage: python3 script.py <path-to-RPN-executable>") # Imprime el mensaje de uso
    sys.exit(1) # Sale del programa con código de error 1

# El nombre del ejecutable
EXECUTABLE = sys.argv[1] # Obtiene el nombre del ejecutable de la línea de comandos

# Función para verificar si el programa maneja decimales
def check_decimal_support(): # Función para verificar si el programa maneja decimales
    decimal_test = "7 2 - 3 /" # Expresión que debería dar un decimal
    result = subprocess.run([EXECUTABLE, decimal_test], capture_output=True, text=True) # Ejecuta el programa con la expresión que debería dar un decimal, capture_output=True captura la salida del programa, text=True convierte la salida a texto
    output = result.stdout.strip() # Obtiene la salida del programa y elimina los espacios en blanco al inicio y al final
    return re.search(r'\d+\.\d+', output) is not None # Busca un decimal en la salida del programa y devuelve True si lo encuentra, de lo contrario False , is not None es para verificar si la expresión regular encontró un decimal

# Verificar el soporte de decimales
USE_DECIMALS = check_decimal_support()
if USE_DECIMALS:
    print("------------------------------------")
    print("     Decimal support detected.")
    print("------------------------------------")
else:
    print("------------------------------------")
    print("    No decimal support detected.")
    print("------------------------------------")

# Declaración de expresiones y resultados esperados
# Usaremos un diccionario para almacenar las expresiones y los resultados esperados, 
# un diccionario es una colección de elementos que están indexados por claves,
# en este caso las claves son las expresiones y los valores son los resultados esperados
if USE_DECIMALS: # Si el programa maneja decimales
    tests = { 
        "2 3 4 * +": "14",
        "5 1 2 + 0.4 * + 3 -": "14",
        "7 8 + 3 2 + /": "3",
        "3 4 5 * + 6 -": "17",
        "6 5 2 3 + 8 * + 3 + *": "288",
        "7 2 - 3 /": "1.66667",
        "2 3 4 * 5 + -": "-15"
    }
else:
    tests = {
        "2 3 4 * +": "14",
        "5 1 2 + 4 * + 3 -": "14",
        "7 8 + 3 2 + /": "3",
        "3 4 5 * + 6 -": "17",
        "6 5 2 3 + 8 * + 3 + *": "288",
        "7 2 - 3 /": "1",  # Ajustado para enteros
        "2 3 4 * 5 + -": "-15",
        "2 -3 +": "-1"  # Numero negativo
    }

# Agregar pruebas que deberían fallar
failing_tests = {
    "2 3 + *": "Invalid",
    "7 8 * 3 / 2 + *": "Invalid",
    "1 2 3 + * +": "Invalid",
    "+ 1 2 3 + ": "Invalid",
    "9 9 9 9": "Invalid",
    "4 0 /": "Invalid", # Division entre 0
    "55 1 +" : "Invalid",
    "2 3 4 * 5 + - 6": "Invalid",
    "3a 4 5 * + 6 -": "Invalid"
}

# Evaluar expresiones que deberían pasar
# Itera sobre las expresiones y los resultados esperados,
# ejecuta el programa con la expresión y captura la salida,
# expr es el índice de la expresión y expected es el valor esperado
for expr, expected in tests.items():
    print(f"Evaluating expression: {expr}")
    result = subprocess.run([EXECUTABLE, expr], capture_output=True, text=True)
    output = result.stdout.strip()

    if output == expected:
        print_in_color(COLOR_SUCCESS, "Test PASSED")
    else:
        print_in_color(COLOR_FAILURE, "Test FAILED")
    
    print(f"Output from program: {output}")
    print(f"Expected result: {expected}")
    print("-----")

# Evaluar expresiones que deberían fallar
# Usaremos el mismo enfoque que en las pruebas que deberían pasar,
# pero esta vez esperamos que el programa falle, por lo que verificamos
# que el código de salida sea diferente de 0
for expr, expected in failing_tests.items():
    print(f"Evaluating expression (should fail): {expr}")
    result = subprocess.run([EXECUTABLE, expr], capture_output=True, text=True)
    output = result.stdout.strip()
    error_output = result.stderr.strip()
    exit_status = result.returncode

    if exit_status != 0:
        print_in_color(COLOR_SUCCESS, "Test FAILED as expected")
        print(f"Error output from program: {error_output}")
    else:
        print_in_color(COLOR_FAILURE, "Test FAILED (unexpectedly passed)")
        print(f"Output from program: {output}")
    print("-----")

