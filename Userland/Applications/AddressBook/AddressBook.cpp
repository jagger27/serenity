/*
 * Copyright (c) 2021, Jagger De Leo <jcdl@fastmail.com>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#include "AddressBook.h"

AddressBook::~AddressBook() { }

AddressBook::AddressBook(String filename)
{
    auto file_or_error = Core::File::open(filename, Core::IODevice::ReadOnly);
    if (file_or_error.is_error()) {
        warnln("Could not open '{}' for reading: {}", filename, file_or_error.error());
        return;
    }
    auto file_contents = file_or_error.value()->read_all();
    auto json = JsonValue::from_string(file_contents);
    json.value().as_array();
}
