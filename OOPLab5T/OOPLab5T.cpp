// OOPLab5T.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


#include <iostream>
#include <fstream>
#include <string>


using namespace std;

//---------------------------------------------------task1---------------------------------------------------------------------;

class Pair {
    int x, y;
public:
    Pair();
    Pair(int xx, int yy);
    void SetXY(int xx, int yy);
    void GetXY(int& xx, int& yy);
    int GetT();
};

Pair::Pair() {
    x = 2; y = 2;
}

Pair::Pair(int xx, int yy) {
    x = xx; y = yy;
}

void Pair::SetXY(int xx, int yy) {
    x = xx; y = yy;
}

void Pair::GetXY(int& xx, int& yy) {
    xx = x; yy = y;
}

int Pair::GetT() {
    return x * y;
}

class  Rectanglee : public Pair {
public:
    Rectanglee() : Pair() {}
    Rectanglee(int xx, int yy) : Pair(xx, yy) {}
    int GetP();
    int GetS();
    void PrintXY();
};

int Rectanglee::GetP() {
    int x, y;
    GetXY(x, y);
    return (x + y) * 2;
}

int Rectanglee::GetS() {
    return GetT();
}

void Rectanglee::PrintXY() {
    int xx, yy;
    GetXY(xx, yy);
    cout << "x= " << xx << endl;
    cout << "y= " << yy << endl;
}

//---------------------------------------------------task2---------------------------------------------------------------------;

class Node {
public:
    int value;
    Node* l;
    Node* r;

    Node(int val);
};

Node::Node(int val) {
    value = val;
    l = 0;
    r = 0;
}

class BinaryTree {
public:
    Node* root;

    BinaryTree();

    void insertRecursive(Node* current, int value);

    void insert(int value);

    int treeHeight(Node* node);

    void printLevel(Node* node, int level);

    void AllNode();
};

BinaryTree::BinaryTree() {
    root = 0;
}

void BinaryTree::insertRecursive(Node* current, int value) {
    if (value < current->value) {
        if (!current->l) {
            current->l = new Node(value);
        }
        else {
            insertRecursive(current->l, value);
        }
    }
    else {
        if (!current->r) {
            current->r = new Node(value);
        }
        else {
            insertRecursive(current->r, value);
        }
    }
}

void BinaryTree::insert(int value) {
    if (!root) {
        root = new Node(value);
    }
    else {
        insertRecursive(root, value);
    }
}

int BinaryTree::treeHeight(Node* node) {
    if (!node) return 0;
    int leftHeight = treeHeight(node->l);
    int rightHeight = treeHeight(node->r);
    return max(leftHeight, rightHeight) + 1;
}

void BinaryTree::printLevel(Node* node, int level) {
    if (!node) return;
    if (level == 1) {
        cout << node->value << " ";
    }
    else {
        printLevel(node->l, level - 1);
        printLevel(node->r, level - 1);
    }
}

void BinaryTree::AllNode() {
    int height = treeHeight(root);
    for (int i = 1; i <= height; i++) {
        printLevel(root, i);
    }
    cout << endl;
}

//---------------------------------------------------task3---------------------------------------------------------------------;

class Point {
public:
    int x, y;

    Point(int x = 0, int y = 0) : x(x), y(y) {}

    Point(const Point& other);

    friend istream& operator>>(istream& in, Point& p);

    friend ostream& operator<<(ostream& out, const Point& p);

    Point& operator=(const Point& other);
};

Point::Point(const Point& other) {
    x = other.x; y = other.y;
}

istream& operator>>(istream& in, Point& p) {
    in >> p.x >> p.y;
    return in;
}

ostream& operator<<(ostream& out, const Point& p) {
    out << "(" << p.x << ", " << p.y << ")";
    return out;
}

Point& Point::operator=(const Point& other) {
    if (this != &other) {
        x = other.x;
        y = other.y;
    }
    return *this;
}

class ColorPoint : public Point {
private:
    string color;

public:
    ColorPoint(int x, int y, string color);

    friend istream& operator>>(istream& in, ColorPoint& cp);

    friend ostream& operator<<(ostream& out, const ColorPoint& cp);

    ColorPoint(const ColorPoint& other);

    ColorPoint& operator=(const ColorPoint& other);
};

ColorPoint::ColorPoint(int x = 0, int y = 0, string color = "black") : Point(x, y) {
    this->color = color;
}

istream& operator>>(istream& in, ColorPoint& cp) {
    in >> cp.x >> cp.y >> cp.color;
    return in;
}

ostream& operator<<(ostream& out, const ColorPoint& cp) {
    out << "(" << cp.x << ", " << cp.y << ", Color: " << cp.color << ")";
    return out;
}

ColorPoint::ColorPoint(const ColorPoint& other) : Point(other) {
    color = other.color;
}

ColorPoint& ColorPoint::operator=(const ColorPoint& other) {
    if (this != &other) {
        Point::operator=(other);
        color = other.color;
    }
    return *this;
}

// Ваші файли загловки 

void MenuTask()
{
    cout << "    Menu Task \n";
    cout << "    1.  task1 \n";
    cout << "    2.  task2 \n";
    cout << "    3.  task3 \n";
    cout << "    4.  Exit  \n";
}

#include "Lab5Exmaple.h"
int main()
{
    std::cout << " Lab #5  !\n";

    char ch = '4';
    do {
        setlocale(LC_CTYPE, "ukr");
        system("cls");
        MenuTask();
        ch = cin.get();

        cin.get();

        switch (ch) {
        case '1': {
            int e;
            Rectanglee a, a2(6, 8);
            a.PrintXY();
            cout << "\n";

            cout << "Периметр = " << a.GetP() << endl;

            cout << "Площа = " << a.GetS() << endl;
            cout << "\n";

            a.SetXY(4, 6);

            a.PrintXY();
            cout << "\n";

            cout << "Периметр = " << a.GetP() << endl;

            cout << "Площа = " << a.GetS() << endl;
            cout << "\n";


            a2.PrintXY();
            cout << "\n";

            cout << "Периметр = " << a2.GetP() << endl;

            cout << "Площа = " << a2.GetS() << endl;

            cin >> e;

        }break;
        case '2': {
            int e;

            BinaryTree tree;
            tree.insert(1);
            tree.insert(20);
            tree.insert(3);
            tree.insert(40);
            tree.insert(5);
            tree.insert(60);
            tree.insert(7);
            tree.insert(80);
            tree.insert(9);
            tree.insert(100);
            tree.insert(11);
            tree.insert(120);
            tree.insert(13);
            tree.insert(140);
            tree.insert(15);

            cout << endl;

            std::cout << "AllNode: ";
            tree.AllNode();
            cout << endl;
            cout << "Значення вузлiв: "; tree.printLevel(tree.root, 4);
            cout << endl;
            cout << "Висота дерева: " << tree.treeHeight(tree.root);

            cin >> e;        
        }break;
        case '3': {
            int e;
            ColorPoint p1(456, 190, "grey");
            ColorPoint p2 = p1;

            cout << "Original: " << p1 << endl;
            cout << "Copied: " << p2 << endl;

            ColorPoint p3;
            cout << "Enter x, y, color: ";
            cin >> p3;
            cout << "Your color point: " << p3 << endl;
            cin >> e;      
        }break;
        case '4': return 0;
        }
        cout << " Press any key and enter\n";
        ch = cin.get();
    } while (ch != '5');

    return 0;
    //  Код виконання завдань
    //  Головне меню завдань
    //  Функції та класи можуть знаходитись в інших файлах проекту

    int chain = 1;
    if (chain == 1) chain = mainExample1();
    if (chain == 2) chain = mainExample2();
    if (chain == 3) chain = mainExample3();
    if (chain == 4) chain = mainExample4();
    if (chain == 5) chain = mainExample5();

}
