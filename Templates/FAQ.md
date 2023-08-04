# Templates

[ ] Template metaprogramming

## FAQ

- [ ] [Wiki - Template metaprogramming](https://en.wikipedia.org/wiki/Template_metaprogramming)
- [ ] [C++ Core Guidelines - Rules for Template Metaprogramming](https://www.modernescpp.com/index.php/c-core-guidelines-rules-for-template-metaprogramming)
- [ ] [www.geeksforgeeks.org - Templates in C++ with Examples](https://www.geeksforgeeks.org/templates-cpp/)
- [ ] [PVS-Studio - Лекция 9. Метапрограммирование в С++](https://www.youtube.com/watch?v=-PKyagrtIfs)
- [ ] [www.linkedin.com, Rainer Grimm - Template Arguments](https://www.linkedin.com/pulse/template-arguments-rainer-grimm/?trackingId=SI5WFEOiON2PvHjhlbAPyA%3D%3D)
- [ ] [Intellias - Variadic templates. Magic & truth behind std::tuple & std::variant](https://www.youtube.com/watch?v=9rp3MhMHpxI)
- [ ] [CppCon 2017, Nicolai Josuttis - C++ Templates Revised](https://www.youtube.com/watch?v=ULX_VTkMvf8)
- [ ] [CppCon 2021, Jody Hagins - Template Metaprogramming: Practical Application](https://www.youtube.com/watch?v=4YC6_77-iEY)

## Classes

* You can't have a virtual function template in a class — this would be meaningless —
but a virtual function in a class template is fine.

* Member function templates cannot be declared virtual. This constraint is imposed because the usual implementation of the virtual function call mechanism uses a fixed-size table with one entry per virtual function. However, the number of instantiations of a member function template is not fixed until the entire program has been translated. Hence, supporting virtual member function templates would require support for a whole new kind of mechanism in C++ compilers and linkers. In contrast, the ordinary members of class templates can be virtual because their number is fixed when a class is instantiated

## Junior

- Що таке шаблонний клас і шаблонна функція?
- Що таке конструктори? Які типи знаєте?
- Чи може конструктор бути шаблонною функцією?
- Чи може віртуальна функція бути шаблонною?
- Що таке інстанціація шаблону?
- Що таке спеціалізація шаблону? Часткова спеціалізація шаблону?
- Розкажіть про імплементацію шаблонних класів у срр-файлі?

## Middle

- Які є правила виведення типу в шаблоні?
- Чим відрізняється using від typedef?
- Скільки пам’яті займає довільна структура? Що таке вирівнювання об’єкта?
- Чому порожня структура займає 1 байт? Яка мінімальна одиниця адресування у С++?

## Senior
