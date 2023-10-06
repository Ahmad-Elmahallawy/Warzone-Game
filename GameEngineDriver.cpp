#include "GameEngineDriver.h"

#include "GameEngine.h"
#include <string>


// Sample actions
// TODO: Implement/replace the actual functions


void start()
{
    std::cout << "started game\n"
    <<std::endl;
    std::cout << "options: loadMap" <<std::endl;
}
void loadMap()
{
    std::cout <<"Map loaded\n"
    <<std::endl;
    std::cout<< "options: 'loadMap', 'validateMap'" << std::endl;

}
void validateMap()
{
    std::cout <<"validated map\n"
    <<std::endl;
    std::cout <<"options: 'addPlayer'"<<std::endl;
}
void addPlayer()
{
    std::cout <<"Added Player\n"
              <<std::endl;
    std::cout <<"options: 'addPlayer', 'assignCountries'"<<std::endl;
}
void assignCountries()
{
    std::cout <<"Assigned countries\n"
              <<std::endl;
    std::cout <<"options: 'issueOrder'"<<std::endl;
}
void issueOrder()
{
    std::cout <<"issued Order\n"
              <<std::endl;
    std::cout <<"options: 'issueOrder', 'endIssueOrders'"<<std::endl;
}
void endIssueOrders()
{
    std::cout <<"Ended issuing Orders\n"
              <<std::endl;
    std::cout <<"options: 'executeOrder', 'endExecuteOrders', 'win' "<<std::endl;
}
void executeOrder()
{
    std::cout <<"executed Order\n"
              <<std::endl;
    std::cout <<"options: 'executeOrder', 'endExecuteOrders', 'win'  '"<<std::endl;
}
void endExecuteOrders()
{
    std::cout <<"DOne executing Orders\n"
              <<std::endl;
    std::cout <<"options: 'issueOrder' "<<std::endl;
}
void win()
{
    std::cout <<"congrats you won!\n"
              <<std::endl;
    std::cout <<"options: 'play', end' "<<std::endl;
}
void end()
{
    std::cout << "Thank you for playing!\n"
              << std::endl;
}


void testGameEngine()
{

}