#include<iostream>
#include"../../headers/factory/windowsUI.h"
#include"../../headers/declaration/windows/windows_button.h"
#include"../../headers/declaration/windows/windows_checkbox.h"
#include"../../headers/declaration/windows/windows_scrollbar.h"

Button* WindowsUI ::createButton(){
    return new WindowsButton();
}

Checkbox* WindowsUI::createCheckBox(){
    return new WindowsCheckbox();
}

Scrollbar* WindowsUI::createScrollbar(){
    return new WindowsScrollbar();
}