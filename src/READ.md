# SmartCalc v1.0

## Инструкция для работы
Ввод цифр, математических операций и функций осуществляется при нажатии мышкой на соответсвующую кнопку. Если при нажатии кнопки ничего не происходит, то выражение, которые вы пытаетесь ввести, является ошибочным. 
Максимальная длина выражения 255 символов. 
Калькулятор также поддерживает вычисление выражений, содержащих "x". Для вычисления таких выражений необходимо ввести значение, которое будет принимать "x". Ввод "x" осуществляется через клавиатуру.
Можно вводить числа, операции и функции с клавиатуры. Операторы вводятся нажатием на соответсующие кнопки на клавиатуре, а для функции выделены следующие клавиши:
    sin - s, asin - shift+s
    cos - c, acos - shift+c
    tan - t, atan - shigt+t
    sqrt - r
    ln - l, log - shift+l

## Создание графиков
Также можно строить графики. Для этого нужно ввести выражение и нажать на кнопку "plot".

## Кредитный калькулятор
Для переключения в режим кредитного калькулятора нужно нажать на вторую вкладку. Далее нужно заполнить поля сумма кредита(Total Amount), срок кредита в месяцах (Term) и процентную ставку (Rate). Затем выбрать аннуитетный или дифференцированный платеж и нажать на кнопку "Calculate".

## Поддерживаются следующие опереации:
**Arithmetic operators**:

| Operator name | Infix notation <br /> (Classic) | Prefix notation <br /> (Polish notation) |  Postfix notation <br /> (Reverse Polish notation) |
| --------- | ------ | ------ | ------ |
| Brackets | (a + b) | (+ a b) | a b + |
| Addition | a + b | + a b | a b + |
| Subtraction | a - b | - a b | a b - |
| Multiplication | a * b | * a b | a b * |
| Division | a / b | / a b | a b \ |
| Power | a ^ b | ^ a b | a b ^ |
| Modulus | a mod b | mod a b | a b mod |
| Unary plus | +a | +a | a+ |
| Unary minus | -a | -a | a- |
**Functions**:

| Function description | Function |
| ------ | ------ |
| Computes cosine | cos(x) |
| Computes sine | sin(x) |
| Computes tangent | tan(x) |
| Computes arc cosine | acos(x) |
| Computes arc sine | asin(x) |
| Computes arc tangent | atan(x) |
| Computes square root | sqrt(x) |
| Computes natural logarithm | ln(x) |
| Computes common logarithm | log(x) |

## Установка
Для сборки нужно выполнить цель "install". Затем в папке "build" запустить программу './SmartCalc"