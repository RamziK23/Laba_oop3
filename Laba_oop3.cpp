
#include <iostream>
#include <time.h>
#include <math.h>
using namespace std;

class Form {
public:
    Form() {
    }
    virtual void show_info() {
        cout << " Абстрактная фигура " << endl;
    }
    ~Form() {
        cout << "Фигура удалилась" << endl;
    }
};

class Point : public Form {
public:

    int x, y;
    Point() {
        x = 0;
        y = 0;
        printf("Конструктор Point().\n");
    }
    Point(int x, int y) {
        this->x = x;
        this->y = y;
        printf("Конструктор Point(int x, int y).\n");
    }
    Point(Point &p) {
        x = p.x;
        y = p.y;
        printf("Конструктор Point(Point &p).\n");
    }
    virtual void show_info() {
        cout << " Это точка" << endl;
        cout << " Координаты = " << x << " , " << y << endl;
    }
    ~Point() {
        printf("Удаление точки.\n");
    }

};

class Circle : public Form {
public:
    int x, y, rad;
    Circle() {
        printf("Конструктор Circle().\n");
    }
    Circle(int x, int y, int rad) {
        this->x = x;
        this->y = y;
        this->rad = rad;
        printf("Конструктор Circle(int x, int y, int rad).\n");
    }
    Circle(Circle& c) {
        x = c.x;
        y = c.y;
        rad = c.rad;
        printf("Конструктор Circle(Circle& c).\n");
    }
    virtual void show_info() {
        cout << " Это круг " << endl;
    }
    ~Circle() {
        printf("Удаление круга.\n");
    }

};

class Storage {
private:
    Form** objects;
    Form* object;
    int size;
public:
    Storage(int size)
    {
        this->size = size;
        objects = new Form * [size];
    }

    void add(int index, Form* object) {
        objects[index] = object;
    }

    void del(int index) {
        objects[index] = NULL;
        printf("Удаление объекта arr[%i]\n",index);
    }

    void met(int index) {
        objects[index]->show_info();
    }

    int length() {
        return size;
    }

    Form& GetObject(int index) {
        return *objects[index];
    }

    bool Empty(int index) {
        if (objects[index] == NULL)
            return true;
        else
            return false;
    }
    ~Storage(){

    }
};

void create(Storage x) {
    for (int i = 0; i < x.length(); ++i)
        x.add(i, new Point());
};

Form* rand_obj(int variant) {
    switch (variant) {
    case 1:
        return new Point;
    case 2:
        return new Circle;

    }
}

int main()
{
    setlocale(LC_ALL, "Rus");
    srand(time(0));
    int size = 10;
    Storage storage(size);
    create(storage);
    int n = 10;
    for (int i = 0; i < n; ++i) {
        int variant = 1 + rand() % 3;
        printf("%i)",i);
        switch (variant) {
        case 1:
            printf("Создание и вставка\n");
            storage.add(rand() % size, rand_obj(1 + rand() % 3));
            break;
        case 2:
            printf("Удаление\n");
            storage.del(rand() % 10);
            break;
        case 3:
            int num = rand() % size;
            printf("Метод\n");
            if (!storage.Empty(num))
                storage.met(num);
            else
                printf("Не удалось");
            break;
        }
    }
    storage.del(rand() % 10);

    system("pause");
    return 0;
}

