#include<iostream>
#include"../../headers/factory/linuxUI.h"
#include"../../headers/declaration/linux/linux_button.h"
#include"../../headers/declaration/linux/linux_checkbox.h"
#include"../../headers/declaration/linux/linux_scrollbar.h"

Button* LinuxUI::createButton(){
    return new LinuxButton();
}

Checkbox* LinuxUI::createCheckBox(){
    return new LinuxCheckbox();
}

Scrollbar* LinuxUI::createScrollbar(){
    return new LinuxScrollbar();
}