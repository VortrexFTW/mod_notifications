disable_rtti()

file(GLOB_RECURSE SOURCES *.cpp *.h)

new_library_shared(mod_notifications "${SOURCES}" "")
set_target_properties(mod_notifications PROPERTIES FOLDER modules)