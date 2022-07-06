# Math-Algorithms
🇺🇸 Math library with algorithms for c++
<br/>
🇷🇺 С++ библиотека с математическими алгоритмами

🇺🇸 Currently the library includes algorithms and formulas for topics such as simple arithmetic, geometry, probability theory and combinatorics, arithmetic and geometric progressions, recursion.
<br/>
🇷🇺 На данный момент библиотека включает в себя алгоритмы и формулы таких тем: простая арифметика, геометрия, теория вероятности и комбинаторика, арифметическая и геометрическая прогрессии, рекурсия.

# 🇺🇸 English category
## Simple arithmetic
### Prime number
```c++ 
bool isPrime(uint64_t number)
```
The function takes as its input argument the number "number" to be checked. The function returns ``true`` if the number is prime and ``false`` if it is composite.

## Probability Theory and Combinatorics
### Factorial
```c++ 
uint64_t fac(uint64_t number)
```
As an input argument, the function takes the number "number" to be raised to the factorial. The function returns the factorial of the entered number.

### Probability
```c++ 
long double prob(long double m, long double n)
```
As input arguments "m" takes the number of favorable outcomes, "n" takes the total number of test outcomes. The function returns the probability of the event.

### Placement (order is important)
```c++ 
uint64_t comA(uint64_t n, uint64_t m)
```
<img src="https://camo.githubusercontent.com/ed02a340a9f48b95bb35619ae2af7f29d6665a3536ed8df8b3986ba22c2189a4/68747470733a2f2f7374756466696c652e6e65742f68746d6c2f323730362f3533302f68746d6c5f6b5975646f34726c77552e327532682f696d672d495a6e6e524c2e706e67" alt="Формула размещения" data-canonical-src="https://studfile.net/html/2706/530/html_kYudo4rlwU.2u2h/img-IZnnRL.png" width="200" height="96">
As input arguments "n" and "m", their meaning can be expressed by the question: how many ways can "m" of "m" different objects be chosen and placed in "n" different places? It is important that n > m. The function returns the number of placements.

# 🇷🇺 Русская категория
## Простая арифметика
### Проверка числа на простоту
```c++ 
bool isPrime(uint64_t number)
```
В качестве входного аргумента функция принимает число «number», которое нужно проверить. Функция возвращает ```true``` - если число простое и ```false``` - если составное.

## Теория вероятности и комбинаторика
### Факториал
```c++ 
uint64_t fac(uint64_t number)
```
В качестве входного аргумента функция принимает число «number», которое нужно возвести в факториал. Функция возвращает факториал введенного числа.

### Вероятность
```c++ 
long double prob(long double m, long double n)
```
В качестве входных аргументов «m» принимает число благоприятных исходов, «n» - общее число исходов испытаний. Функция возвращает вероятность события.

### Размещение (порядок важен)
```c++ 
uint64_t comA(uint64_t n, uint64_t m)
```
<img src="https://camo.githubusercontent.com/ed02a340a9f48b95bb35619ae2af7f29d6665a3536ed8df8b3986ba22c2189a4/68747470733a2f2f7374756466696c652e6e65742f68746d6c2f323730362f3533302f68746d6c5f6b5975646f34726c77552e327532682f696d672d495a6e6e524c2e706e67" alt="Формула размещения" data-canonical-src="https://studfile.net/html/2706/530/html_kYudo4rlwU.2u2h/img-IZnnRL.png" width="200" height="96">
В качестве входных аргументов «n» и «m», их смысл можно выразить вопросом: сколькими способами можно выбрать и разместить по «m» различным местам «m» из «n» различных предметов? Важно, чтобы n > m. Функция возвращает количество размещений.
