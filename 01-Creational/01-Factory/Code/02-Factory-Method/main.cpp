#include<iostream>
#include"./factory/king_factory.h"
#include"./factory/singh_factory.h"
#include"./factory/factory.h"

using namespace std;

int main(){
    BurgerFactory *f;

    int n;
    cout<<"1: King Burger\n 2: Singh Burger\n";
    cin>>n;

    if(n == 1) f = new KingBurgerFactory();
    else if(n == 2) f = new SinghBurgerFactory();

    cout<<"Which type of burger you want?\n 1. Basic\n 2. Premium\n 3. Standrd\n";
    cin>>n;

    Burger *burger;
    if(n == 1) burger = f->createBurger("basic");
    else if(n == 2) burger = f->createBurger("premium");
    else if(n == 3) burger = f->createBurger("standard");

    burger->prepare();

    delete burger;
    delete f;
    

    return 0;
}