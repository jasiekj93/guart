// #include "ButtonObserver.hpp"

// #include <memory>

// #include <libguart/widget/Toast.hpp>

// void ButtonObserver::actionCallback(guart::Widget& widget, std::string_view action)
// {
//     if(not screen)
//         return;

//     auto toast = std::make_shared<guart::widget::Toast>(guart::Point{20, 20}, "Button clicked: " + std::string(action));
//     screen->addWidget(toast);
//     screen->invalidate();
//     widget.dispose();
// }