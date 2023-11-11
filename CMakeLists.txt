cmake_minimum_required(VERSION 3.22)
project(Project_1)

set(CMAKE_CXX_STANDARD 14)

add_executable(Project_1 Map/Map.cpp Map/Map.h Map/MapDriver.cpp Cards/Cards.cpp Cards/Cards.h Cards/CardsDriver.cpp Orders/Orders.cpp Orders/Orders.h Orders/OrdersDriver.cpp Players/Player.cpp Players/Player.h Players/PlayerDriver.cpp MainDriver.cpp GameEngine.cpp GameEngine.h GameEngineDriver.cpp GameEngineDriver.h Command/CommandProcessing.cpp Command/CommandProcessing.h Command/CommandProcessingDriver.cpp Command/CommandProcessingDriver.h)
