#include<iostream>
#include"../../headers/factory/macUI.h"
#include"../../headers/declaration/mac/mac_button.h"
#include"../../headers/declaration/mac/mac_checkbox.h"
#include"../../headers/declaration/mac/mac_scrollbar.h"

Button* MacUI::createButton(){
    return new MacButton();
}

Checkbox* MacUI::createCheckBox(){
    return new MacCheckbox();
}

Scrollbar* MacUI::createScrollbar(){
    return new MacScrollbar();
}