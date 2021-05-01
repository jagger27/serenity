/*
 * Copyright (c) 2018-2020, Andreas Kling <kling@serenityos.org>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#include "AddressBook.h"
#include "AddressBookWidget.h"

#include <LibCore/File.h>
#include <LibGUI/Application.h>
#include <LibGUI/Icon.h>
#include <LibGUI/Window.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char** argv)
{
    String filename = "/res/contacts.json";

    if (pledge("stdio recvfd sendfd thread rpath accept unix cpath wpath fattr unix", nullptr) < 0) {
        perror("pledge");
        return 1;
    }

    auto app = GUI::Application::construct(argc, argv);

    if (pledge("stdio recvfd sendfd thread rpath accept cpath wpath unix", nullptr) < 0) {
        perror("pledge");
        return 1;
    }

    auto app_icon = GUI::Icon::default_icon("filetype-executable");
    auto address_book = AddressBook::construct(filename);

    auto main_window = GUI::Window::construct();
    main_window->set_main_widget<AddressBookWidget>(address_book);
    main_window->set_title("Address Book");
    main_window->show();

    return app->exec();
}
