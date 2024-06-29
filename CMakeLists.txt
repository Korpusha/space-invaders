cmake_minimum_required(VERSION 3.16)
project(space_invaders LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

include(FetchContent)
FetchContent_Declare(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

add_executable(main src/main.cpp
        src/models/headers/Game.h
        src/models/Game.cpp
        src/models/Entity.cpp
        src/models/headers/Entity.h
        src/models/Spaceship.cpp
        src/models/headers/Spaceship.h
        src/models/AllySpaceship.cpp
        src/models/headers/AllySpaceship.h
        src/models/EnemySpaceship.cpp
        src/models/headers/EnemySpaceship.h
        src/models/Player.cpp
        src/models/headers/Player.h
        src/models/Record.cpp
        src/models/headers/Record.h
        src/models/EnemySpaceshipSquadron.cpp
        src/models/headers/EnemySpaceshipSquadron.h
        src/models/WindowState.cpp
        src/models/headers/WindowState.h
        src/models/IntroWindowState.cpp
        src/models/headers/IntroWindowState.h
        src/models/WindowContext.cpp
        src/models/headers/WindowContext.h
        src/models/GameWindowState.cpp
        src/models/headers/GameWindowState.h
        src/models/ScoreWindowState.cpp
        src/models/headers/ScoreWindowState.h
        src/models/EndScreenWindowState.cpp
        src/models/headers/EndScreenWindowState.h
        src/models/SpriteEntity.cpp
        src/models/headers/SpriteEntity.h
        src/models/RectangleShapeEntity.cpp
        src/models/headers/RectangleShapeEntity.h
        src/models/Gun.cpp
        src/models/headers/Gun.h
        src/models/Bullet.cpp
        src/models/headers/Bullet.h
        src/models/StaticManager.cpp
        src/models/headers/StaticManager.h
        src/models/PlayerGun.cpp
        src/models/headers/PlayerGun.h
        src/models/BotGun.cpp
        src/models/headers/BotGun.h
        src/models/CreditsWindowState.cpp
        src/models/headers/CreditsWindowState.h
        src/models/MenuWindowState.cpp
        src/models/headers/MenuWindowState.h
        src/models/FinalScoreWindowState.cpp
        src/models/headers/FinalScoreWindowState.h
        src/models/ViewScoreWindowState.cpp
        src/models/headers/ViewScoreWindowState.h
)
target_link_libraries(main PRIVATE sfml-graphics)
target_compile_features(main PRIVATE cxx_std_17)

INCLUDE_DIRECTORIES(src)

if(WIN32)
    add_custom_command(
            TARGET main
            COMMENT "Copy OpenAL DLL"
            PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:main>
            VERBATIM)
endif()