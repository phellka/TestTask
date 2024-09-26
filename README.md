# README

## Описание проекта

Этот проект представляет собой консольное C++ приложение, предназначенное для управления списком объектов. Основная функциональность включает загрузку объектов из базы данных, добавление новых объектов, группировку и вывод объектов на экран.

Суммарно на создание было потрачено **~12 часов**

### Особенности и возможности:

- **Учёт уникальных данных для объектов**:
  - Для обеспечения уникальности данных и их корректного создания используется абстрактный класс `Object`, указатели и класс-фабрика `ObjectFactory`. Это позволяет гибко управлять созданием различных типов объектов.
  
- **Поддержка различных СУБД**:
  - Приложение поддерживает возможность использования различных систем управления базами данных. Это достигается через использование абстрактного класса `AbstractDBManager`, который может быть расширен для поддержки других СУБД помимо PostgreSQL.
  - Для использования другой СУБД, необходимо расширить абстрактный класс `AbstractDBManager` и реализовать необходимые методы для новой базы данных. Затем подключите новый класс в основной программе.
  
- **Интеграция с Docker**:
  - Проект включает Docker Compose файл, который позволяет легко поднять необходимую инфраструктуру для запуска PostgreSQL базы данных.
  - Также предусмотрен SQL-скрипт для автоматического заполнения базы данных при её первом запуске.

## Сборка и запуск проекта

### Предварительные требования:

- **Компилятор C++**: Для компиляции проекта необходим компилятор, поддерживающий C++20.
- **Visual studio**: Установите Visual studio для сборки проекта.
- **Docker и Docker Compose**: Для запуска базы данных.

### Сборка проекта:

1. **Клонирование репозитория**:

   ```bash
   git clone https://github.com/phellka/TestTask
   cd TestTask
   ```

2. **Сборка проекта с помощью Visual Studio**

***Открытие проекта в Visual Studio***

- Запустите Visual Studio.
- Откройте файл решения (`.sln`).

***Выбор конфигурации сборки***

- В верхней части окна Visual Studio выберите конфигурацию сборки: **Debug** или **Release**.

***Сборка проекта***

- Перейдите в меню **Сборка** и выберите **Собрать решение** (или нажмите `Ctrl + Shift + B`).


### Запуск проекта:

1. **Запуск PostgreSQL с использованием Docker: В корневой директории проекта выполните команду**:

    ```bash
    docker-compose up -d
	```
Это поднимет контейнер с PostgreSQL и заполнит базу данных с помощью предустановленного SQL-скрипта.

2. **Запуск приложения: После успешной сборки и запуска базы данных, выполните команду для запуска приложения**:
    ```bash
    ./TestTask
	```

Приложение предложит вам меню для взаимодействия, где вы сможете загружать объекты из базы данных, добавлять новые объекты, группировать их и просматривать результаты.
