/*
 * Copyright (c) 2021, Jagger De Leo <jcdl@fastmail.com>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#pragma once

#include <AK/JsonArray.h>
#include <AK/JsonObject.h>
#include <LibCore/File.h>
#include <LibCore/Object.h>
#include <LibGUI/Model.h>
class AddressBook final : public Core::Object {
    C_OBJECT(AddressBook)

public:
    virtual ~AddressBook() override;

private:
    AddressBook(String);
};

class AddressBookModel final : public GUI::Model {
public:
    static NonnullRefPtr<AddressBookModel> create() { return adopt_ref(*new AddressBookModel); }

    virtual ~AddressBookModel() override { }

    virtual int row_count(const GUI::ModelIndex& = GUI::ModelIndex()) const override { return m_keys.size(); }
    virtual int column_count(const GUI::ModelIndex& = GUI::ModelIndex()) const override { return 1; }
    virtual void update() override { }

    String key(const GUI::ModelIndex& index) const { return m_keys[index.row()]; }

    void set_from(const JsonObject& object)
    {
        m_keys.clear();
        object.for_each_member([this](auto& name, auto&) {
            m_keys.append(name);
        });
        did_update();
    }

    virtual GUI::Variant data(const GUI::ModelIndex& index, GUI::ModelRole role = GUI::ModelRole::Display) const override
    {
        if (role == GUI::ModelRole::Display) {
            return key(index);
        }

        return {};
    }

private:
    AddressBookModel() { }
    Vector<String> m_keys;
};