@GUI::Widget {
    fixed_width: 480
    fixed_height: 384

    fill_with_background_color: true
    layout: @GUI::VerticalBoxLayout {
        spacing: 2
    }

    @GUI::ToolbarContainer {
        name: "toolbar_container"

        @GUI::Toolbar {
            name: "toolbar"
        }
    }

    @GUI::HorizontalSplitter {
        name: "splitter"

        @GUI::ListView {
            name: "contact_list_view"
            fixed_width: 175
        }

        @GUI::Widget {
        }
    }

    @GUI::Statusbar {
        name: "statusbar"
    }
}
