cmake_minimum_required(VERSION 3.5)

project(BrickGame VERSION 0.1 LANGUAGES CXX)

set(CMAKE_PREFIX_PATH "/Users/nikita/Qt/6.6.2/macos/lib/cmake")

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror")

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)
find_package(Curses REQUIRED)

set(PROJECT_SOURCES
        main.cpp

        game_params.h

        desktop_controller.h
        cli_controller.h

        brick_game/snake/snake_game.cpp
        brick_game/snake/snake_game.h
        brick_game/tetris/tetris_game.cpp
        brick_game/tetris/tetris_game.h

        gui/cli/cli_view.cpp
        gui/cli/cli_view.h

        gui/desktop/desktop_view.cpp
        gui/desktop/desktop_view.h
        gui/desktop/desktop_view.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(BrickGame
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
else()
    add_executable(BrickGame
        ${PROJECT_SOURCES}
    )
endif()

target_compile_options(BrickGame PRIVATE -Wall -Wextra -Werror)

target_link_libraries(BrickGame PRIVATE 
    Qt${QT_VERSION_MAJOR}::Widgets 
    ${CURSES_LIBRARIES}
)

if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.BrickGame)
endif()

set_target_properties(BrickGame PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)

install(TARGETS BrickGame  
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(BrickGame)
endif()