#!/bin/bash

# Función para imprimir en colores
print_in_color() {
    local color_code=$1
    local text=$2
    echo -e "\033[${color_code}m${text}\033[0m"
}

# Definición de colores
COLOR_SUCCESS="32"  # Verde
COLOR_FAILURE="31"  # Rojo
COLOR_DEFAULT="0"   # Sin color

# Verifica si el nombre del ejecutable está definido
if [ -z "$1" ]; then
  echo "Usage: $0 <path-to-RPN-executable>"
  exit 1
fi

# El nombre del ejecutable
EXECUTABLE="$1"

# Función para verificar si el programa maneja decimales
check_decimal_support() {
    local decimal_test="7 2 - 3 /"
    local output=$($EXECUTABLE "$decimal_test" 2>&1)
    echo "$output" | grep -qE '[0-9]*\.[0-9]+'
}

# Verificar el soporte de decimales
if check_decimal_support; then
    echo "------------------------------------"
    echo "     Decimal support detected."
    echo "------------------------------------"
    USE_DECIMALS=true
else
    echo "------------------------------------"
    echo "    No decimal support detected."
    echo "------------------------------------"
    USE_DECIMALS=false
fi

# Declaración de expresiones y resultados esperados
declare -A tests
if $USE_DECIMALS; then
  tests=(
    ["2 3 4 * +"]="14"
    ["5 1 2 + 0.4 * + 3 -"]="14"
    ["7 8 + 3 2 + /"]="3"
    ["3 4 5 * + 6 -"]="17"
    ["6 5 2 3 + 8 * + 3 + *"]="288"
    ["7 2 - 3 /"]="1.66667"  # Ajustado para decimales
    ["2 3 4 * 5 + -"]="-15"
  )
else
  tests=(
    ["2 3 4 * +"]="14"
    ["5 1 2 + 4 * + 3 -"]="14"
    ["7 8 + 3 2 + /"]="3"
    ["3 4 5 * + 6 -"]="17"
    ["6 5 2 3 + 8 * + 3 + *"]="288"
    ["7 2 - 3 /"]="1"  # Ajustado para enteros
    ["2 3 4 * 5 + -"]="-15"
    ["2 -3 +"]="-1" # Numero negativo
  )
fi

# Agregar pruebas que deberían fallar
declare -A failing_tests
failing_tests=(
  #["5 1 2 + +"]="Invalid"  # Es valido, para demostrar que sirve
  ["2 3 + *"]="Invalid"  # Operadores adicionales sin suficientes operandos
  ["7 8 * 3 / 2 + *"]="Invalid"  # Operaciones y resultados incorrectos
  ["1 2 3 + * +"]="Invalid"  # Operaciones sin suficientes operandos
  ["+ 1 2 3 + "]="Invalid"  # Operador sin operando
  ["9 9 9 9"]="Ivalid"
  ["4 0 /"]="Invalid" # Division entre 0
)

# Evaluar expresiones que deberían pasar
for expr in "${!tests[@]}"; do
  expected="${tests[$expr]}"
  echo "Evaluating expression: $expr"
  
  # Ejecutar el programa y capturar la salida y errores
  output=$($EXECUTABLE "$expr" 2>&1)
  
  # Mostrar el resultado y la comparación
  if [ "$output" == "$expected" ]; then
    print_in_color "$COLOR_SUCCESS" "Test PASSED"
    echo "Output from program: $output"
    echo "Expected result: $expected"
  else
    print_in_color "$COLOR_FAILURE" "Test FAILED"
    echo "Output from program: $output"
    echo "Expected result: $expected"
  fi
  
  echo "-----"
done

# Evaluar expresiones que deberían fallar
for expr in "${!failing_tests[@]}"; do
  expected="${failing_tests[$expr]}"
  echo "Evaluating expression (should fail): $expr"
  
  # Ejecutar el programa y capturar la salida y errores
  output=$($EXECUTABLE "$expr" 2>&1)
  exit_status=$?

  # Mostrar el resultado y la comparación
  if [ $exit_status -ne 0 ]; then
    print_in_color "$COLOR_SUCCESS" "Test FAILED as expected"
    echo "Error output from program: $output"
  else
    print_in_color "$COLOR_FAILURE" "Test FAILED (unexpectedly passed)"
    echo "Output from program: $output"
  fi
  
  echo "-----"
done





