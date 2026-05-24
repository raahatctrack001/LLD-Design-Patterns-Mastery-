#include<iostream>
#include"./headers/factory/linuxUI.h"
#include"./headers/factory/windowsUI.h"
#include"./headers/factory/macUI.h"

using namespace std;


int main(){
    int n;
    cout<<"1. windowsUI\n 2. macUI\n 3. linuxUI\n";
    
    cin>>n;

    if(n == 1){
        WindowsUI *w = new WindowsUI();
        w->createButton()->render();
        w->createCheckBox()->check();
        w->createScrollbar()->scroll();
    }
    else if(n == 2){
        MacUI *m = new MacUI();
        m->createButton()->render();
        m->createCheckBox()->check();
        m->createScrollbar()->scroll();
    }
    else {
        LinuxUI *l = new LinuxUI();
        l->createButton()->render();
        l->createCheckBox()->check();
        l->createScrollbar()->scroll();
    }
    return 0;
}