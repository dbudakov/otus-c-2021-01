# clang-format

Форматирование кода в указанном стиле, есть возможность модифицировать формат, есть интеграции с **vim** и **VScode**, позволяет обрабатывать вывод **diff**  
<https://clang.llvm.org/docs/ClangFormat.html>

## Создание файла с параметрами формата

```sh
clang-format -style=llvm -dump-config > .clang-format
```

Параметры для настройки стиля:  
<https://clang.llvm.org/docs/ClangFormatStyleOptions.html>

Проверка на соответствие кода стилю:

```sh
clang-format --dry-run file_name
```
