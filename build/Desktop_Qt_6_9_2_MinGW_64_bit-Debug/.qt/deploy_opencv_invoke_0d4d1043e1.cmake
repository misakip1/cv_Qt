include("E:/Qt_projet/opencv_invoke/build/Desktop_Qt_6_9_2_MinGW_64_bit-Debug/.qt/QtDeploySupport.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/opencv_invoke-plugins.cmake" OPTIONAL)
set(__QT_DEPLOY_I18N_CATALOGS "qtbase;qtmultimedia;qtmultimedia")

qt6_deploy_runtime_dependencies(
    EXECUTABLE "E:/Qt_projet/opencv_invoke/build/Desktop_Qt_6_9_2_MinGW_64_bit-Debug/opencv_invoke.exe"
    GENERATE_QT_CONF
)
