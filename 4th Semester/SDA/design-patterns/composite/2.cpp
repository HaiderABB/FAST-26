#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <cmath>
#include <map>
#include <stack>
#include <list>
#include <cstring>
using namespace std;

class graphicalComponent
{
public:
    virtual int area() = 0;
};

class square : public graphicalComponent
{
    int width;

public:
    square(int a)
    {
        width = a;
    }
    int area()
    {
        return width * width;
    }
};

class rectangle : public graphicalComponent
{
    int width;
    int height;

public:
    rectangle(int a, int b)
    {
        width = a;
        height = b;
    }
    int area()
    {
        return width * height;
    }
};

class graphicalDiagram : public graphicalComponent
{
private:
    int id;
    vector<graphicalComponent *> components;

public:
    graphicalDiagram(int i)
    {
        id = i;
    }
    void addcomponent(graphicalComponent *obj)
    {
        components.push_back(obj);
    }
    int area()
    {
        int total_area = 0;
        for (int i = 0; i < components.size(); i++)
        {
            total_area = total_area + components[i]->area();
        }
        return total_area;
    }
};