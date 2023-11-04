#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<string> allMaterials;

// иерархия классов сущностей.
class Window
{
public:
    virtual void Open() = 0;
    //virtual void Material() = 0;
};
class WindowWood: public Window
{
public:
    void Open() {cout << "Open wood Window" << endl;}
    WindowWood() {allMaterials.push_back("wood");}
};

class WindowPlastic: public Window
{
public:
    void Open() {cout << "Open plastic Window" << endl;}
    WindowPlastic() {allMaterials.push_back("plastic");}
};

class WindowMetal: public Window
{
 public:
    void Open() {cout << "Open metal Window" << endl;}
    WindowMetal() {allMaterials.push_back("metal");}
};
/*******************/
// Фабрики объектов.
class Factory
{
public:
    virtual Window* CreateWindow() = 0;
    virtual Window* InstallWindow() = 0;
};

class SupplierOneFact: public Factory
{
public:
    Window* CreateWindow() { return new WindowWood();}
    Window* InstallWindow()
    {
        Window* w = CreateWindow();
        cout << "Installed wood window" << endl;
        return w;
    }
};

class SupplierTwoFact: public Factory
{
public:
    Window* CreateWindow() { return new WindowPlastic();}
    Window* InstallWindow()
    {
        Window* w = CreateWindow();
        cout << "Installed plastic window" << endl;
        return w;
    }
};

class SupplierThreeFact: public Factory
{
public:
    Window* CreateWindow() { return new WindowMetal();}
    Window* InstallWindow()
    {
        Window* w = CreateWindow();
        cout << "Installed metall window" << endl;
        return w;
    }
};
/*********************/
int main()
{
//    SupplierOneFact* supplierOneFact = new SupplierOneFact();
//    Window* window = supplierOneFact->CreateWindow();
//    window->Open();

//    SupplierTwoFact* supplierTwoFact = new SupplierTwoFact();
//    window = supplierTwoFact->CreateWindow();
//    window->Open();

//    SupplierThreeFact* supplierThreeFact = new SupplierThreeFact();
//    window = supplierThreeFact->CreateWindow();
//    window->Open();
/**********************/
//    SupplierOneFact* supplierOneFact = new SupplierOneFact();
//    Window* window = supplierOneFact->InstallWindow();
//    window->Open();

//    SupplierTwoFact* supplierTwoFact = new SupplierTwoFact();
//    window = supplierTwoFact->InstallWindow();
//    window->Open();

//    SupplierThreeFact* supplierThreeFact = new SupplierThreeFact();
//    window = supplierThreeFact->InstallWindow();
//    window->Open();

/**********************/
    // массив поставщиков.
    vector<Factory*> vectorFact;
    vectorFact.push_back(new SupplierOneFact());
    vectorFact.push_back(new SupplierTwoFact());
    vectorFact.push_back(new SupplierThreeFact());

    for(Factory* supplier : vectorFact)
    {
        Window* window = supplier->InstallWindow();
        window->Open();
    }

    cout << "Materials:" << endl;
    for(string material : allMaterials)
        cout << material << endl;

    cout << "Hello World!" << endl;
    return 0;
}
