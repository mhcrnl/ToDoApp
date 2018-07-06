#include "TreeModel.h"
#include <iostream>

TreeModel::TreeModel() {
    set_column_types(p_Columns);
}

Glib::RefPtr<TreeModel> TreeModel::create() {
    return Glib::RefPtr<TreeModel>( new TreeModel() );
}


// TODO: VCPKG