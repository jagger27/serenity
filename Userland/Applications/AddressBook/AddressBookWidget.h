/*
 * Copyright (c) 2021, Jagger De Leo <jcdl@fastmail.com>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#include "AddressBook.h"
#include <LibGUI/ListView.h>
#include <LibGUI/Widget.h>
class AddressBookWidget final : public GUI::Widget {
    C_OBJECT(AddressBookWidget);

public:
    virtual ~AddressBookWidget() override;

private:
    explicit AddressBookWidget(RefPtr<AddressBook>);

    RefPtr<AddressBook> m_address_book;
    RefPtr<GUI::ListView> m_list_view;
};
