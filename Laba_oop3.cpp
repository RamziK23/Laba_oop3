
#include <iostream>
#include <time.h>
#include <math.h>
using namespace std;

class Form {
public:
    Form() {
    }
    virtual void show_info() {
        cout << " Абстрактная фигура\n " << endl;
    }
    ~Form() {
        cout << "Фигура удалилась\n" << endl;
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
        x = 0;
        y = 0;
        rad = 0;
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
        cout << " Координаты = " << x << " , " << y << " , " << rad << endl;
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
        for (int i; i < size; ++i)
            objects[i] = NULL;
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

    void Passing_Objects() {
        for (int i = 0; i < size; ++i)
        {
            cout << i << ") ";
            if (Empty(i))
                printf("Здесь пусто!\n");
            else
                met(i);
        }
    }
    ~Storage(){

    }
};

void create(Storage x) {
    for (int i = 0; i < x.length(); ++i)
        //x.add(i, new Point());
        x.add(i, NULL);
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
    int n = 100;

    while (n != 100000) {
        Storage storage(n);
        create(storage);
        system("pause");
        unsigned int start_time = clock();
        for (int i = 0; i < n; ++i) {
            int variant = 1 + rand() % 3;
            int num = rand() % n;
            printf("%i)", i);
            switch (variant) {
            case 1:
                printf("Создание и вставка\n");
                if (storage.Empty(num))
                    storage.add(rand() % n, rand_obj(1 + rand() % 2));
                else
                    printf("Создание не удалось\n");
                break;
            case 2:
                num = rand() % n;
                printf("Удаление\n");
                if (!storage.Empty(num))
                    storage.del(rand() % n);
                else
                    printf("Удаление не удалось\n");
                break;
            case 3:
                num = rand() % n;
                printf("Метод\n");
                if (!storage.Empty(num))
                    storage.met(num);
                else
                    printf("Вызвать метод не удалось\n");
                break;
            }
        }
        unsigned int end_time = clock();
        unsigned int search_time = end_time - start_time;
        cout << "Потраченное Время:"<<(double)search_time/1000<<"сек." << endl;
        n *= 10;
        system("pause");
        storage.Passing_Objects();
        system("pause");
        system("clr");
    }

    system("pause");
    return 0;
}

