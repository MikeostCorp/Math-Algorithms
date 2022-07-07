# Math-Algorithms
🇺🇸 Math library with algorithms for c++
<br/>
🇷🇺 Библиотека с++ с математическими алгоритмами

🇺🇸 Navigation:
- [Simple arithmetic](https://github.com/MikeostCorp/Math-Algorithms#simple-arithmetic)
  - [Prime number](https://github.com/MikeostCorp/Math-Algorithms#prime-number)
- [Probability Theory and Combinatorics](https://github.com/MikeostCorp/Math-Algorithms#probability-theory-and-combinatorics)
  - [Factorial](https://github.com/MikeostCorp/Math-Algorithms#factorial)
  - [Probability](https://github.com/MikeostCorp/Math-Algorithms#probability)
  - [Placement (order is important)](https://github.com/MikeostCorp/Math-Algorithms#placement-order-is-important)
- [Numerical methods for solving nonlinear equations](https://github.com/MikeostCorp/Math-Algorithms#numerical-methods-for-solving-nonlinear-equations)
  - [Half-division method](https://github.com/MikeostCorp/Math-Algorithms#half-division-method)
  - [Secant method](https://github.com/MikeostCorp/Math-Algorithms#secant-method)
  - [Parabola method](https://github.com/MikeostCorp/Math-Algorithms#parabola-method)

🇷🇺 Навигация:
- [Простая арифметика](https://github.com/MikeostCorp/Math-Algorithms#%D0%BF%D1%80%D0%BE%D1%81%D1%82%D0%B0%D1%8F-%D0%B0%D1%80%D0%B8%D1%84%D0%BC%D0%B5%D1%82%D0%B8%D0%BA%D0%B0)
  - [Проверка числа на простоту](https://github.com/MikeostCorp/Math-Algorithms#%D0%BF%D1%80%D0%BE%D0%B2%D0%B5%D1%80%D0%BA%D0%B0-%D1%87%D0%B8%D1%81%D0%BB%D0%B0-%D0%BD%D0%B0-%D0%BF%D1%80%D0%BE%D1%81%D1%82%D0%BE%D1%82%D1%83)
- [Теория вероятности и комбинаторика](https://github.com/MikeostCorp/Math-Algorithms#%D1%82%D0%B5%D0%BE%D1%80%D0%B8%D1%8F-%D0%B2%D0%B5%D1%80%D0%BE%D1%8F%D1%82%D0%BD%D0%BE%D1%81%D1%82%D0%B8-%D0%B8-%D0%BA%D0%BE%D0%BC%D0%B1%D0%B8%D0%BD%D0%B0%D1%82%D0%BE%D1%80%D0%B8%D0%BA%D0%B0)
  - [Факториал](https://github.com/MikeostCorp/Math-Algorithms#%D1%84%D0%B0%D0%BA%D1%82%D0%BE%D1%80%D0%B8%D0%B0%D0%BB)
  - [Вероятность](https://github.com/MikeostCorp/Math-Algorithms#%D0%B2%D0%B5%D1%80%D0%BE%D1%8F%D1%82%D0%BD%D0%BE%D1%81%D1%82%D1%8C)
  - [Размещение (порядок важен)](https://github.com/MikeostCorp/Math-Algorithms#%D1%80%D0%B0%D0%B7%D0%BC%D0%B5%D1%89%D0%B5%D0%BD%D0%B8%D0%B5-%D0%BF%D0%BE%D1%80%D1%8F%D0%B4%D0%BE%D0%BA-%D0%B2%D0%B0%D0%B6%D0%B5%D0%BD)
- [Численные методы решения нелинейных уравнений](https://github.com/MikeostCorp/Math-Algorithms#%D1%87%D0%B8%D1%81%D0%BB%D0%B5%D0%BD%D0%BD%D1%8B%D0%B5-%D0%BC%D0%B5%D1%82%D0%BE%D0%B4%D1%8B-%D1%80%D0%B5%D1%88%D0%B5%D0%BD%D0%B8%D1%8F-%D0%BD%D0%B5%D0%BB%D0%B8%D0%BD%D0%B5%D0%B9%D0%BD%D1%8B%D1%85-%D1%83%D1%80%D0%B0%D0%B2%D0%BD%D0%B5%D0%BD%D0%B8%D0%B9)
  - [Метод бисекции(деление пополам)](https://github.com/MikeostCorp/Math-Algorithms#%D0%BC%D0%B5%D1%82%D0%BE%D0%B4-%D0%B1%D0%B8%D1%81%D0%B5%D0%BA%D1%86%D0%B8%D0%B8%D0%B4%D0%B5%D0%BB%D0%B5%D0%BD%D0%B8%D0%B5-%D0%BF%D0%BE%D0%BF%D0%BE%D0%BB%D0%B0%D0%BC)
  - [Метод секущих](https://github.com/MikeostCorp/Math-Algorithms#%D0%BC%D0%B5%D1%82%D0%BE%D0%B4-%D1%81%D0%B5%D0%BA%D1%83%D1%89%D0%B8%D1%85)
  - [Метод парабол](https://github.com/MikeostCorp/Math-Algorithms#%D0%BC%D0%B5%D1%82%D0%BE%D0%B4-%D0%BF%D0%B0%D1%80%D0%B0%D0%B1%D0%BE%D0%BB)

# 🇺🇸 **English category**
## **Simple arithmetic**
- ### _Prime number_
```c++ 
bool isPrime(uint64_t number)
```
The function takes as its input argument the number "number" to be checked. The function returns ``true`` if the number is prime and ``false`` if it is composite.

## **Probability Theory and Combinatorics**
- ### _Factorial_
```c++ 
uint64_t fac(uint64_t number)
```
As an input argument, the function takes the number "number" to be raised to the factorial. The function returns the factorial of the entered number.

- ### _Probability_
```c++ 
long double prob(long double m, long double n)
```
As input arguments "m" takes the number of favorable outcomes, "n" takes the total number of test outcomes. The function returns the probability of the event.

- ### _Placement (order is important)_
```c++ 
uint64_t comA(uint64_t n, uint64_t m)
```
<img src="https://camo.githubusercontent.com/ed02a340a9f48b95bb35619ae2af7f29d6665a3536ed8df8b3986ba22c2189a4/68747470733a2f2f7374756466696c652e6e65742f68746d6c2f323730362f3533302f68746d6c5f6b5975646f34726c77552e327532682f696d672d495a6e6e524c2e706e67" alt="Формула размещения" data-canonical-src="https://studfile.net/html/2706/530/html_kYudo4rlwU.2u2h/img-IZnnRL.png" width="200" height="96">
As input arguments "n" and "m", their meaning can be expressed by the question: how many ways can "m" of "m" different objects be chosen and placed in "n" different places? It is important that n > m. The function returns the number of placements.

## **Numerical methods for solving nonlinear equations**
- ### _Half-division method_
```c++
template<typename F>
long double halfDivisionMethod(F func, long double a, long double b, long double e = 0.001)
```
The function takes as input arguments the equation "func", the left and right limits of the interval "a" & "b" and the optional precision parameter "e". The function returns the root of the equation on a given interval, with a given accuracy.
<br/>
> Example of usage:
<br/>
```c++
double f(double x)
{
  return (tan(0.3 * x + 0.4) - pow(x, 2));
}

int main
{
  cout << "halfDivisionMethod: " << mathAlgo::halfDivisionMethod(&f, 0, 2) << endl;
}
```
> Output:
<br/>
```
halfDivisionMethod: 0.88623
```

- ### _Secant method_
```c++
template<typename F>
long double secantMethod(F func, long double x0, long double x1, long double e = 0.001)
```
The function takes as input arguments the equation "func", the left and right limits of the interval "x0" & "x1" and the optional precision parameter "e". The function returns the root of the equation on a given interval, with a given accuracy.
<br/>
> Example of usage:
```c++
double f(double x)
{
  return (tan(0.3 * x + 0.4) - pow(x, 2));
}

int main
{
  cout << "secantMethod: " << mathAlgo::secantMethod(&f, 0, 2) << endl;
}
```
> Output:
```
secantMethod: 0.886345
```

- ### _Parabola method_
```c++
template<typename F>
long double parabolaMethod(F func, long double a, long double b, long double e = 0.001)
```
The function takes as input arguments the equation "func", the left and right limits of the interval "a" & "b" and the optional precision parameter "e". The function returns the root of the equation on a given interval, with a given accuracy.
<br/>
> Example of usage:
```c++
double f(double x)
{
  return (tan(0.3 * x + 0.4) - pow(x, 2));
}

int main
{
  cout << "parabolaMethod: " << mathAlgo::parabolaMethod(&f, 0, 2) << endl;
}
```
> Output:
```
parabolaMethod: 0.886345
```



# 🇷🇺 **Русская категория**
## **Простая арифметика**
- ###  _Проверка числа на простоту_
```c++ 
bool isPrime(uint64_t number)
```
В качестве входного аргумента функция принимает число «number», которое нужно проверить. Функция возвращает ```true``` - если число простое и ```false``` - если составное.

## **Теория вероятности и комбинаторика**
- ### _Факториал_
```c++ 
uint64_t fac(uint64_t number)
```
В качестве входного аргумента функция принимает число «number», которое нужно возвести в факториал. Функция возвращает факториал введенного числа.

- ### _Вероятность_
```c++ 
long double prob(long double m, long double n)
```
В качестве входных аргументов «m» принимает число благоприятных исходов, «n» - общее число исходов испытаний. Функция возвращает вероятность события.

- ### _Размещение (порядок важен)_
```c++ 
uint64_t comA(uint64_t n, uint64_t m)
```
<img src="https://camo.githubusercontent.com/ed02a340a9f48b95bb35619ae2af7f29d6665a3536ed8df8b3986ba22c2189a4/68747470733a2f2f7374756466696c652e6e65742f68746d6c2f323730362f3533302f68746d6c5f6b5975646f34726c77552e327532682f696d672d495a6e6e524c2e706e67" alt="Формула размещения" data-canonical-src="https://studfile.net/html/2706/530/html_kYudo4rlwU.2u2h/img-IZnnRL.png" width="200" height="96">
В качестве входных аргументов «n» и «m», их смысл можно выразить вопросом: сколькими способами можно выбрать и разместить по «m» различным местам «m» из «n» различных предметов? Важно, чтобы n > m. Функция возвращает количество размещений.

## **Численные методы решения нелинейных уравнений**
- ### _Метод бисекции(деление пополам)_
```c++
template<typename F>
long double halfDivisionMethod(F func, long double a, long double b, long double e = 0.001)
```
В качестве входных аргументов функция принимает уравнение «func», левую и правую границы отрезка «a» & «b» и необязательный параметр точности «e». Функция возвращает корень уравнения на заданном промежутке, с заданной точностью.
<br/>
> Пример использования:
```c++
double f(double x)
{
  return (tan(0.3 * x + 0.4) - pow(x, 2));
}

int main
{
  cout << "halfDivisionMethod: " << mathAlgo::halfDivisionMethod(&f, 0, 2) << endl;
}
```
> Вывод:
```
halfDivisionMethod: 0.88623
```

- ### _Метод секущих_
```c++
template<typename F>
long double secantMethod(F func, long double x0, long double x1, long double e = 0.001)
```
В качестве входных аргументов функция принимает уравнение «func», левую и правую границы отрезка «x0» & «x1» и необязательный параметр точности «e». Функция возвращает корень уравнения на заданном промежутке, с заданной точностью.
<br/>
> Пример использования:
```c++
double f(double x)
{
  return (tan(0.3 * x + 0.4) - pow(x, 2));
}

int main
{
  cout << "secantMethod: " << mathAlgo::secantMethod(&f, 0, 2) << endl;
}
```
> Вывод:
```
secantMethod: 0.886345
```

- ### _Метод парабол_
```c++
template<typename F>
long double parabolaMethod(F func, long double a, long double b, long double e = 0.001)
```
В качестве входных аргументов функция принимает уравнение «func», левую и правую границы отрезка «a» & «b» и необязательный параметр точности «e». Функция возвращает корень уравнения на заданном промежутке, с заданной точностью.
<br/>
> Пример использования:
```c++
double f(double x)
{
  return (tan(0.3 * x + 0.4) - pow(x, 2));
}

int main
{
  cout << "parabolaMethod: " << mathAlgo::parabolaMethod(&f, 0, 2) << endl;
}
```
> Вывод:
```
parabolaMethod: 0.886345
```
