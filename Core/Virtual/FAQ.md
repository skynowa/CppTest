# FAQ

## [x] Virtual dtor

> А я вот читал что нельза наследоваться от стандартных контейнеров, у них нет виртуальных
> деструкторов и в некоторых нежелательных случаях может быть ай! яй! яй!

Вот по поводу виртуальных деструкторов — это какой-то ложный аргумент, кочующий по форумам и собеседованиям.
**Классу нужен виртуальный деструктор только если его требуется удалять через указатель базы**,
а значительная часть приёмов C++ программирования вообще не требует виртуальных таблиц.
И уж требовать виртуальных деструкторов от контейнеров — вообще экзотика.
