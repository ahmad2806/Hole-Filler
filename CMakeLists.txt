cmake_minimum_required(VERSION 3.13)
project(fill_hole)

#set(CMAKE_CXX_STANDARD 98)
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
add_executable(
        fill_hole main.cpp
        includes/imageUtil/ImageUtil.h
        view/cliView/CliView.h view/IView.h
        runner/mainRunner/MainRunner.cpp
        runner/mainRunner/MainRunner.h
        runner/IRunner.h
        command/commandsStore/CommandsStore.cpp
        command/commandsStore/CommandsStore.h
        command/ICommand.h
        command/fillHoleCommand/FillHoleCommand.cpp
        command/fillHoleCommand/FillHoleCommand.h
        fillHoleLibrary/HoleFillerLib.h
        fillHoleLibrary/connectivity/IPixelConnectivity.h
        fillHoleLibrary/connectivity/FourConnectivity.h
        fillHoleLibrary/connectivity/EightConnectivity.h
        fillHoleLibrary/weight/IWeight.h
        fillHoleLibrary/weight/defaultWeight/DefaultWeight.h
        fillHoleLibrary/weight/defaultWeight/DefaultWeight.cpp
        fillHoleLibrary/HoleFillerLib.cpp
        includes/imageUtil/ImageUtil.cpp
        exceptions/ExceptionValidator.cpp
        exceptions/ExceptionValidator.h
        fillHoleLibrary/connectivity/connectivityStore/ConnectivityStore.cpp
        fillHoleLibrary/connectivity/connectivityStore/ConnectivityStore.h)
target_link_libraries(fill_hole ${OpenCV_LIBS})