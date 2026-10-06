TEMPLATE = subdirs

SUBDIRS += \
    app \
    app \
    tests

tests.depends = app
