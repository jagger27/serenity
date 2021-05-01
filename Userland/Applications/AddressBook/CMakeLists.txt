compile_gml(AddressBookWindow.gml AddressBookWindowGML.h address_book_window_gml)

set(SOURCES
    AddressBook.cpp
    AddressBook.h
    AddressBookWidget.cpp
    AddressBookWidget.h
    AddressBookWindowGML.h
    main.cpp
)

serenity_bin(AddressBook)
target_link_libraries(AddressBook LibGUI LibCore)
