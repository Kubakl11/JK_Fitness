cmake_minimum_required(VERSION 3.5)

project(JK_Fitness_Semestralka VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent) #needed for pdf library automatic download

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main.cpp
        jk_fitness.cpp
        jk_fitness.h
        jk_fitness.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(JK_Fitness_Semestralka
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        form.h form.cpp form.ui


        #SEM DOPLNIT VSECHNY KODY

        exportpdf.h exportpdf.cpp exportpdf.ui
        #Backend kody - ondra

        src/backend/FitnessPerson.cpp
        src/backend/FitnessPerson.hpp
        src/backend/Food.cpp
        src/backend/Food.hpp
        src/backend/FoodMenu.cpp
        #knihovny single header
        src/libs/nlohmann_json/json.hpp
        #pdf handler backend kod
        src/backend/pdfhandler.h src/backend/pdfhandler.cpp
        src/fonts/jk_fonts.qrc
        src/sources_main.qrc
        src/backend/pdf/titlepage.h src/backend/pdf/titlepage.cpp
        src/backend/pdf/contentpage.h src/backend/pdf/contentpage.cpp

    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET JK_Fitness_Semestralka APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(JK_Fitness_Semestralka SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(JK_Fitness_Semestralka
            ${PROJECT_SOURCES}
        )
    endif()
endif()

#This automatically downloads and includes pdf library PDF-Writer / PDF-Hummus
FetchContent_Declare(
  PDFHummus
  GIT_REPOSITORY https://github.com/galkahana/PDF-Writer.git
  GIT_TAG        v4.6.2
  FIND_PACKAGE_ARGS
)
FetchContent_MakeAvailable(PDFHummus)

target_link_libraries(JK_Fitness_Semestralka PRIVATE Qt${QT_VERSION_MAJOR}::Widgets PDFHummus::PDFWriter)
#adding font source DEPRECATED Windows fonts used
#FILE(COPY yourImg.png DESTINATION "${CMAKE_BINARY_DIR}")

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.JK_Fitness_Semestralka)
endif()
set_target_properties(JK_Fitness_Semestralka PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS JK_Fitness_Semestralka
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(JK_Fitness_Semestralka)
endif()
