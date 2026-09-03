cmake_minimum_required(VERSION 3.19)
project(opencv_invoke LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets LinguistTools Network Sql Multimedia MultimediaWidgets)
find_package(Qt6 REQUIRED COMPONENTS Core)
find_package(Qt6 REQUIRED COMPONENTS Core)
find_package(Qt6 REQUIRED COMPONENTS Core)
find_package(Qt6 REQUIRED COMPONENTS Core)
find_package(Qt6 REQUIRED COMPONENTS Core)
find_package(Qt6 REQUIRED COMPONENTS Core)

qt_standard_project_setup()

qt_add_executable(opencv_invoke
    WIN32 MACOSX_BUNDLE
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    icon.qrc
    loding.h loding.cpp loding.ui
    account.h account.cpp account.ui
    regfrom.h regfrom.cpp regfrom.ui
    forgetfrom.h forgetfrom.cpp forgetfrom.ui
    ctrform.h ctrform.cpp ctrform.ui
    titelicon.h titelicon.cpp titelicon.ui
    multiselectcombobox.h multiselectcombobox.cpp
    Singleton.h
    httpserver.h httpserver.cpp
    threadpoll.h threadpoll.cpp
    form.h form.cpp form.ui
    const.h
    cameramanager.h cameramanager.cpp
    cameraworker.h cameraworker.cpp
    cameraprocessor.h cameraprocessor.cpp
    cvinvoke.h cvinvoke.cpp


)

qt_add_translations(
    TARGETS opencv_invoke
    TS_FILES opencv_invoke_en_AS.ts
)
# 把项目根目录加入包含路径，uic和编译器都能找到头文件
include_directories(${CMAKE_SOURCE_DIR})
target_link_libraries(opencv_invoke
    PRIVATE
        Qt::Core
        Qt::Widgets
        Qt::Network
        Qt::Sql
        Qt::Multimedia
        Qt::MultimediaWidgets
)
target_link_libraries(opencv_invoke PRIVATE Qt6::Core)
target_link_libraries(opencv_invoke PRIVATE Qt6::Core)
target_link_libraries(opencv_invoke PRIVATE Qt6::Core)
target_link_libraries(opencv_invoke PRIVATE Qt6::Core)
target_link_libraries(opencv_invoke PRIVATE Qt6::Core)
target_link_libraries(opencv_invoke PRIVATE Qt6::Core)

include(GNUInstallDirs)

install(TARGETS opencv_invoke
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET opencv_invoke
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
