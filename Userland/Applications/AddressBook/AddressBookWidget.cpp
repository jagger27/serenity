/*
 * Copyright (c) 2021, Jagger De Leo <jcdl@fastmail.com>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#include "AddressBookWidget.h"
#include "AddressBook.h"
#include <Applications/AddressBook/AddressBookWindowGML.h>

AddressBookWidget::AddressBookWidget(RefPtr<AddressBook> address_book)
    : m_address_book(address_book)
{
    load_from_gml(address_book_window_gml);

    m_list_view = *find_descendant_of_type_named<GUI::ListView>("contact_list_view");
    m_list_view->set_model(AddressBookModel::create());
    m_list_view->horizontal_scrollbar().set_visible(false);
}

AddressBookWidget::~AddressBookWidget()
{
}