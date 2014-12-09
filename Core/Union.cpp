 /*
 * \file  VariableArguments.cpp
 * \brief
 */


#include <string>
#include <iostream>
#include <assert.h>

//-------------------------------------------------------------------------------------------------
#define TRACE_VAR(v) \
    #v ": " << (v)
//-------------------------------------------------------------------------------------------------
int main(int argsNum, char **args)
{
    union Printer
    {
        int         i;
        float       f;
        char        c;
        const char *s;
    };

    Printer printer;
    printer.i = 1978;
    printer.f = 7.0f;
    printer.s = "xxx";
    printer.c = 'a'; // Элементы объединения перекрывают друг друга

    std::cout
        << TRACE_VAR(printer.i) << "\n"
        << TRACE_VAR(printer.f) << "\n"
        << TRACE_VAR(printer.c) << "\n"
        << TRACE_VAR(printer.s) << "\n";

    return 0;
}
//-------------------------------------------------------------------------------------------------

#if OUTPUT

printer.i: 4196961
printer.f: 5.8812e-39
printer.c: a // Элементы объединения перекрывают друг друга
printer.s:

#endif

//-------------------------------------------------------------------------------------------------
/**
Объединения


Объединения — это тип класса, в котором все данные разделяют одну и туже область памяти.
В языке c++ объединение может включать как функции-, так и данные- члены.
Все члены объединения открыты по умолчанию. Для создания закрытых элементов необходимо использовать
ключевое слово private. Общая форма объявления объединения выглядит следующим образом.

union имя_класса
{
    // Открытые члены по умолчанию.
private:
    // Закрытые члены.
} список_объектов;


В языке C объединения могут содержать только данные-члены и ключевое слово private не поддерживается.

Элементы объединения перекрывают друг друга. Например, в записи

union tom
{
    char ch;
    int x;
} t;

объявляется объединение tom, которое предполагает следующее расположение памяти
(при использовании двухбайтовых целых).


Как и в классе, на отдельные переменные, составляющие объединение, можно ссылаться с помощью
оператора "точка". Оператор "стрелка" используется для доступа к объединению с помощью указателя.

Применительно к объединениям существуют несколько ограничений. Объединение не может наследовать
любые другие классы любого типа. Объединение не может быть базовым классом. Объединение не может
иметь виртуальные функции-члены. Никакие члены не могут быть объявлены как статические. Объединение
не может иметь в качестве члена объект, перегружающий оператор "равно" (=). Наконец ни какой объект
не может быть членом объединения, если класс этого объекта явно определяет функцию конструктора
или деструктора. (иначе говоря, приемлемы объекты, которые имеют только стандартные конструкторы
и деструкторы.)

В языке C++ существует специальный тип объединения, называемый анонимным объединением. В анонимном
объединении не содержится имени класса и не объявляются никакие объекты. Анонимное объединение
просто уведомляет компилятор о том, что его переменные-члены должны иметь одну и туже область
памяти. Однако к самим переменным можно обращаться напрямую, не прибегая к обычному синтаксису
операторов "точка" и "стрелка".

union
{
    int a;
    float f;
};

//...

a = 10;  //доступ к переменной a
cout << f;  //доступ к переменной f

Анонимные объединения должны содержать только данные, никакие функции-члены не допускаются.
Анонимное объединение, действующее в области видимости, определённой с заданным пространством имён
(namespace), должно быть объявлено с использованием модификатора типа данных static.

*/
